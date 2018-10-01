#include <iostream>  
#include <algorithm>  
#include <array>  
#include <vector>  
#include <functional>  
#include <random>       // std::default_random_engine  
#include <chrono>       // std::chrono::system_clock  

using namespace std;  

int main(){  

    array<int,8> t1 = {3,5,7,11,13,17,19,23};  
    array<int,8> t2 = {3,5,7,11,14,17,19,23};  

    //第一组不匹配的元素，即13和14  
    pair<array<int,8>::iterator,array<int,8>::iterator> mypair;  
    mypair=mismatch(t1.begin(),t1.end(),t2.begin());  
    mypair=mismatch(t1.begin(),t1.end(),t2.begin(),equal_to<int>());  

    cout<<*mypair.first<<" "<<*mypair.second<<endl;  
    return 0;  
}  
