#include<iostream>
#include"bignum.h"
using namespace bignum;
int main(){
    bigint a("20"); 
    bigint b("100");
    std::cout<<(a+=b).to_str();
    return 0;
}