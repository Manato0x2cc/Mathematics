//
//  main.cpp
//  Amicable Numbers
//
//  Created by Manato0x2cc on 2017/07/03.
//  Copyright © 2017年 Manato0x2cc. All rights reserved.
//

#include <iostream>

unsigned long getSumOfDivisors(unsigned long l);


unsigned long getSumOfDivisors(unsigned long l){
    unsigned long result = 1;
    unsigned long lastDiv = 1;
    unsigned long i = 0;
    while ((lastDiv != l / (lastDiv + i)) && lastDiv + i < l){
        ++i;
        if(l % (lastDiv + i) == 0){
            lastDiv += i;
            result += l / lastDiv;
            result += lastDiv;
            i = 0;
        }
    }
    
    return result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "(^ ^)I'm ready!! Thank you for using this program!!\n";
    
    unsigned long f = 2;
    unsigned long pair = 0;
    
    for (unsigned long i = 0; i < ULONG_MAX - 2; ++i) {
        if((pair = getSumOfDivisors(f)) == 1) {
            std::cout << std::to_string(f) + "...こいつは素数やなぁ!" << std::endl;
        }
        if(f == (getSumOfDivisors(pair))){
            if(f == pair){
                std::cout << std::to_string(f) + "...こいつは完全数やなぁ!" << std::endl;
            }else{
                std::cout << std::to_string(f) + "," + std::to_string(pair) + "...こいつは友愛数やなぁ!"<< std::endl;
            }
        }
        f ++;
    }
    return 0;
}
