#include<iostream>
#include"bignum.h"
using namespace bignum;
int main(){
    bigint a1("-1000");
    bigint b1("-500");
    bool f = a1>=b1;
    bool f1 = a1<b1;
    std::cout<< f << ' ' << f1;
    return 0;
}