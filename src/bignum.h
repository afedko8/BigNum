#pragma once
#include<iostream>
#include<vector>
namespace bignum {
    class bigint {
        public:
        bigint();
        bigint(std::string value);
        ~bigint();

        bool negative = 0;
        std::vector<uint64_t> parts;
        bigint& add(const bigint &add);
        bigint& sub(const bigint &other);
        std::string to_str();
        bigint operator~() &&;
        bigint operator~() const &;
        bigint& operator+=(bigint& other){
            return add(other);
        }
        bigint operator-() &&;
        bigint operator-() const &;
        bool operator==(bigint &other) const;
        bool operator!=(bigint &other) const;
        bool operator>=(bigint &other) const;
        bool operator<=(bigint &other) const;
        bool operator>(bigint &other) const;
        bool operator<(bigint &other) const;
        bool compare_abs(bigint &other) const;
        bigint& negate();
        
        private:
        std::vector<uint64_t> powers = {
        0x1ULL,
        0xAULL,
        0x64ULL,
        0x3E8ULL,
        0x2710ULL,
        0x186A0ULL,
        0xF4240ULL,
        0x989680ULL,
        0x5F5E100ULL,
        0x3B9ACA00ULL,
        0x2540BE400ULL,
        0x174876E800ULL,
        0xE8D4A51000ULL,
        0x9184E72A000ULL,
        0x5AF3107A4000ULL,
        0x38D7EA4C68000ULL,
        0x2386F26FC10000ULL,
        0x16345785D8A0000ULL,
        0xDE0B6B3A7640000ULL,
        0x8AC7230489E80000ULL
        };
        const size_t MAX_GROUP_DIGITS = 19;
        uint64_t str_to_uint64_t(const char* start,size_t count);
        uint64_t div_by_1e19(std::vector<uint64_t> &vec, uint64_t divisor);
        bigint& add_unsigned(const bigint &add);
        bigint& add_signed(const bigint &add);
        void multiply_add(uint64_t mult, uint64_t add);
        bool is_zero() const;
        
    };
}
