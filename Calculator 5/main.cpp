#include <stack>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include "calculator.h"
using namespace std;


        
int main()
{
    cout<<"input:";
    string function;
    getline(cin,function);
    Infix = function;
    CalculatorFunction();
    calculate();
    
    cout<<"output:"<<function<<"="<<Answer<<endl;
}
/*
 以下为测试数据：
 2^(1+3)-5*(15.23)/(1 + 2)*3-5
 1.25+(3*(1+2^2)*3-43)^(4-2)
 2^(1+3))-5*(15.23)/(1+2)*3-5
 2^(1+3)-5*(15.23)/(1-1)*3-5
 
 ^(1+3)-5*(15.23)/(1-1)*3-5
 1.25+(3*(1+2^2)*3-43)^(4-2)+-3
 ””
 2^(1+3)-5*(15.23)/(1 + 2)*3-5a
 */
