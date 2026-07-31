#include <iostream>
#include <bignum.h>
#include <string>

bignum::bigint::~bigint(){}

bignum::bigint::bigint(){
    this->parts = {0};
}

uint64_t bignum::bigint::str_to_uint64_t(const char* start, size_t count) {
    if (!start || count == 0) throw std::invalid_argument("Empty string");
    size_t start_idx = 0;
    if (start[0] == '+') {
        start_idx = 1;
    } else if (start[0] == '-') throw std::invalid_argument("Negative numbers not allowed");
    if (start_idx == count) throw std::invalid_argument("Invalid character sequence");
    while (start_idx < count && start[start_idx] == '0') start_idx++;
    if (start_idx == count) return 0;
    size_t digit_count = count - start_idx;
    if (digit_count > 19) throw std::out_of_range("Number exceeds 19 digits limit");
    uint64_t result = 0;
    for (size_t i = start_idx; i < count; ++i) {
        if (start[i] < '0' || start[i] > '9') {
            throw std::invalid_argument("Invalid character found");
        }
        result = result * 10 + (start[i] - '0');
    }
    return result;
}

bignum::bigint::bigint(std::string value){
    this->parts = {0};
    size_t index = 0;
    if(value[0]=='-'){ 
        this->negative = 1;
    }else if(value[0]=='+'){ 
        this->negative = 0;
    }
    size_t digit_start = (value[0]=='-' || value[0]=='+') ? 1:0; 
    size_t total_digits = value.length()-digit_start;
    size_t groups = total_digits/MAX_GROUP_DIGITS;
    size_t first_group_size = total_digits%MAX_GROUP_DIGITS;
    if(first_group_size == 0) first_group_size = 19;
    size_t offset = digit_start;
    uint64_t val = str_to_uint64_t(value.data()+offset,first_group_size);
    multiply_add(powers[first_group_size],val); 
    offset+=first_group_size;
    while (offset<value.size()){
        val = str_to_uint64_t(value.data()+offset,MAX_GROUP_DIGITS);
        multiply_add(powers[MAX_GROUP_DIGITS],val);
        offset+=MAX_GROUP_DIGITS;
    }
    if(this->is_zero()) this->negative = 0;
}

void bignum::bigint::multiply_add(uint64_t mult,uint64_t add){
    if(mult==0){
        this->parts.clear();
        this->parts.push_back(add);
        return;
    }
    uint64_t carry = add;
    for (size_t i = 0; i < parts.size(); ++i) {
        __int128 product = static_cast<__int128>(parts[i]) * mult + carry;
        parts[i] = static_cast<uint64_t>(product);
        carry = static_cast<uint64_t>(product >> 64);
    }
    if (carry > 0) {
        this->parts.push_back(carry);
    }
    while (this->parts.size() > 1 && this->parts.back() == 0) {
        this->parts.pop_back();
    }
    if (this->parts.size() == 1 && this->parts[0] == 0) {
        this->negative = 0;
    }
}

uint64_t bignum::bigint::div_by_1e19(std::vector<uint64_t> &words, uint64_t divisor){
    __uint128_t rem = 0;
    for (size_t i = words.size(); i-- > 0; )
    {
        __uint128_t curr = static_cast<__uint128_t>(rem<<64)|words[i];
        words[i] = static_cast<uint64_t>(curr/divisor);
        rem = static_cast<uint64_t>(curr%divisor);
    }
    while (words.size()>1 && words.back()==0)
    {
        words.pop_back();
    }
    return rem;
}

std::string bignum::bigint::to_str(){
    if (this->parts.size() == 1 && this->parts[0] == 0) {
        return "0";
    }
    std::vector<uint64_t> local = this->parts;
    uint64_t base = this->powers[19];
    std::vector<std::string>blocks;
    while (!(local.size()==1 && local[0]==0))
    {
        std::string block_str = std::to_string(div_by_1e19(local,base));
        if (!(local.size() == 1 && local[0] == 0)) {
            block_str = std::string(MAX_GROUP_DIGITS - block_str.length(), '0') + block_str;
        }
        blocks.push_back(block_str);
    }
    std::string result="";
    if (this->negative) result+='-';
    for (auto x = blocks.rbegin(); x != blocks.rend();++x) result += *x;
    return result;
}

bignum::bigint& bignum::bigint::add_signed(bigint& other) {
    int cmp = this->abs_compare(other);
    if (cmp == 0) {
        this->parts = {0};
        this->negative = false;
        return *this;
    }
    constexpr unsigned __int128 BASE = (unsigned __int128)1 << 64;
    if (cmp == 1) {
        uint64_t borrow = 0;
        for (size_t i = 0; i < this->parts.size(); ++i) {
            uint64_t subtrahend = (i < other.parts.size()) ? other.parts[i] : 0;
            unsigned __int128 sub = (unsigned __int128)this->parts[i] - subtrahend - borrow;
            if (sub >= BASE) {
                sub += BASE;
                borrow = 1;
            } else {
                borrow = 0;
            }
            this->parts[i] = (uint64_t)sub;
        }
    } else { 
        std::vector<uint64_t> res = other.parts;
        uint64_t borrow = 0;
        for (size_t i = 0; i < res.size(); ++i) {
            uint64_t subtrahend = (i < this->parts.size()) ? this->parts[i] : 0;
            unsigned __int128 sub = (unsigned __int128)res[i] - subtrahend - borrow;
            if (sub >= BASE) {
                sub += BASE;
                borrow = 1;
            } else {
                borrow = 0;
            }
            res[i] = (uint64_t)sub;
        }
        this->parts = std::move(res);
        this->negative = other.negative;
    }
    while (this->parts.size() > 1 && this->parts.back() == 0)
        this->parts.pop_back();

    return *this;
}

bignum::bigint& bignum::bigint::add(bigint & add){
    if (this->negative == add.negative)
    {
        this->add_unsigned(add);
    }else{
        this->add_signed(add);
    }
    return *this;   
}

bignum::bigint& bignum::bigint::add_unsigned(bigint &add) {
    size_t maxi = std::max(this->parts.size(), add.parts.size());
    this->parts.resize(maxi, 0);
    bool carry = 0;
    for (size_t i = 0; i < maxi; ++i) {
        uint64_t a = this->parts[i];
        uint64_t b = (i < add.parts.size()) ? add.parts[i] : 0;
        uint64_t sum = a + b;
        bool carry1 = (sum < a);
        if (carry) {
            uint64_t sum2 = sum + 1;
            bool carry2 = (sum2 < sum);  
            carry = carry1 || carry2;
            this->parts[i] = sum2;
        } else {
            carry = carry1;
            this->parts[i] = sum;
        }
    }
    if (carry) this->parts.push_back(1ULL);
    return *this;
}

bignum::bigint bignum::bigint::operator~() const & {
    bigint result = *this;
    for (size_t i = 0; i < result.parts.size(); ++i) { 
        result.parts[i] = ~result.parts[i];
    }
    return result; 
}

bignum::bigint bignum::bigint::operator~() &&{
    for (size_t i = 0; i < this->parts.size(); ++i)
    { 
        this->parts[i] = ~this->parts[i];
    }
    return std::move(*this);
}

bignum::bigint& bignum::bigint::sub(bigint &other){
    other.reverse_negative();
    this->add(other);
    return *this;
}

bool bignum::bigint::is_zero() const{
    return this->parts.size()==1 && this->parts[0]==0;
}

bignum::bigint bignum::bigint::operator-() const & {
    bigint result = *this;        
    if (!result.is_zero()) {
        result.negative = !result.negative;
    }
    return result;
}
    
bignum::bigint bignum::bigint::operator-() && {
    if (!this->is_zero()) {
        this->negative = !this->negative;
    }
    return std::move(*this);
 }

bignum::bigint& bignum::bigint::negate(){
    if(!is_zero()) this->negative = !this->negative;
    return *this;
}

bool bignum::bigint::operator==(bigint &other) const{
    if(is_zero() && other.is_zero()) return 1;
    if(this->negative != other.negative) return 0;
    if(this->parts.size() != other.parts.size()) return 0;
    for (size_t i = 0; i < this->parts.size(); i++)
    {
        if (this->parts[i]!=other.parts[i]) return 0;
    }
    return 1;
}

bool bignum::bigint::operator<(bigint &other) const{
    if(is_zero() && other.is_zero()) return 0;
    if (this->negative && !other.negative) return 1;
    if (!this->negative && other.negative) return 0;
    if (this->negative == 0 && other.negative == 0){
        if (this->parts.size()<other.parts.size()) return 1;
        if (this->parts.size()>other.parts.size()) return 0;
        for (size_t i = this->parts.size(); i >0 ; i--)
        {
            size_t idx = i-1;
            if(this->parts[idx]< other.parts[idx]) return 1;
        }
    }
    if (this->negative == 1 && other.negative == 1){
        if (this->parts.size()<other.parts.size()) return 0;
        if (this->parts.size()>other.parts.size()) return 1;
        for (size_t i = this->parts.size(); i >0 ; i--)
        {
            size_t idx = i-1;
            if(this->parts[idx]>other.parts[idx]) return 1;
        }
    }
    return 0;
}

bool bignum::bigint::operator>(bigint &other) const{
    if(is_zero() && other.is_zero()) return 0;
    if (this->negative && !other.negative) return 0;
    if (!this->negative && other.negative) return 1;
    if (this->negative == 0 && other.negative == 0){
        if (this->parts.size()<other.parts.size()) return 0;
        if (this->parts.size()>other.parts.size()) return 1;
        for (size_t i = this->parts.size(); i > 0 ; i--)
        {
            size_t idx = i-1;
            if(this->parts[idx]>other.parts[idx]) return 1;
        }
    }
    if (this->negative == 1 && other.negative == 1){
        if (this->parts.size()<other.parts.size()) return 1;
        if (this->parts.size()>other.parts.size()) return 0;
        for (size_t i = this->parts.size(); i >0 ; i--)
        {
            size_t idx = i-1;
            if(this->parts[idx]<other.parts[idx]) return 1;
        }
    }
    return 0;
}

bool bignum::bigint::operator!=(bigint &other) const{
    return !(*this==other);
}

bool bignum::bigint::operator>=(bigint &other) const {
    return !(*this<other);
}

bool bignum::bigint::operator<=(bigint &other) const {
    return !(*this>other);
}

int bignum::bigint::abs_compare(bigint& other) const {
    if (parts.size() != other.parts.size())
        return parts.size() < other.parts.size() ? -1 : 1;
    for (size_t i = parts.size(); i-- > 0; )
            if (parts[i] != other.parts[i])
                return parts[i] < other.parts[i] ? -1 : 1;
    return 0;
}
