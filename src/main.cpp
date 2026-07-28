#include<iostream>
#include"bignum.h"

int main(){
    bignum::bigint big("10");
    bignum::bigint big1("-100");
    std::cout<<big.negate().to_str()<<std::endl;
    std::cout<<big1.negate().to_str()<<std::endl;
    return 0;
}