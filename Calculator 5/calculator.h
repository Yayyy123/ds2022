#include <stack>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> Pfix;
string Infix;

void Blank()
{
    cout<<"Error：表达式为空"<<endl;
    exit(0);
}

void FirstOp()
{
    cout<<"Error：第一个字是无法计算的符号"<<endl;
    exit(0);
}

void TwoOperator()
{
    cout<<"Error: 两个符号相连"<<endl;
    exit(0);
}

void MissingBraket()
{
    cout<<"Error: 左右括号不对等"<<endl;
    exit(0);
}

void UnableRecognize()
{
    cout<<"Error: 无法识别其中某一符号"<<endl;
    exit(0);
}

void DevidedZero()
{
    cout<<"Error: 除数为0"<<endl;
    exit(0);
}



//分辩他们各自的优先权，指数优先，然后 * / 在到 + - 
int Priority(char & ch)
{
    int i;
    if (ch == '+' || ch == '-')
    {
        i = 1;
    }
    else if (ch == '*' || ch == '/')
    {
        i = 2;
    }
    else if (ch == '^')
    {
        i = 3;
    }
   
    else
    {
        i = 0;
    }
    return i;
}
//确认是否为符号
int Operator(char & ch)
{
    int i;
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '.' )
       {
           i = 1;
       }
       else
       {
           i = 0;
       }
       return i;
}
    

void CalculatorFunction()
{
    //在这里，我们把多余的空格全部去掉
    Infix.erase(remove(Infix.begin(),Infix.end(),' '),Infix.end());
    
    if (Infix.empty())
    {
        Blank();
    }
    //开头如果是符号，返回错误
    if(Operator(Infix[0]))
    {
        FirstOp();
    }
    
    stack<char> Op;
    string temp;
    //侦测每一个输入的字符
    for (int i = 0; i < Infix.length(); i++)
    {
        //如果符号后下一个还是符号，则报错
        if(Operator(Infix[i]))
        {
            if(Operator(Infix[i+1]))
            {
                TwoOperator();
            }
        }
        temp = "";
        //如果是普通的运算符，则进行下列运算
        if (Infix[i] == '+' ||Infix[i] == '-' ||Infix[i] == '*' ||Infix[i] == '/' ||Infix[i] == '^' )
        {
            if (Op.empty() || Op.top() == '(' )
            {
                Op.push(Infix[i]);
            }
            else
            {
                //这里我们根据优先级进行判别，让Operator入栈
                while (!Op.empty() && (Priority(Op.top()) >=Priority(Infix[i])))
                {
                    temp.push_back(Op.top());Pfix.push_back(temp);
                    Op.pop();
                    temp = "";
                }
                Op.push(Infix[i]);
            }
        }
        //如果是'('，直接把他压入栈里
        else if(Infix[i] == '(')
        {
            Op.push(Infix[i]);
        }
        else if(Infix[i] == ')')
        {
            //如果是')',在配对到我们的'(‘前，我们将中间的元素弹出
            while (!Op.empty() && Op.top() != '(')
            {
                temp.push_back(Op.top());Pfix.push_back(temp);
                Op.pop();
                temp = "";
            }
            if (!Op.empty() && Op.top() == '(')
            {
                Op.pop();
            }
            if(Op.empty())
            {
                MissingBraket();
            }
        }
        //如果输入的的东西是0～9的数字
       else if ((Infix[i] >= '0' && Infix[i] <= '9'))
        {
            temp.push_back(Infix[i]);
            //连续数字判别式，则一直加下去
            while (i  < Infix.length() - 1 && (Infix[i + 1] >= '0' && Infix[i + 1] <= '9' || Infix[i + 1] == '.'))
            {
                i++;

                temp.push_back(Infix[i]);
            }
            
            if (temp[temp.length() - 1] == '.')
            {
                temp.push_back('0');
            }
            Pfix.push_back(temp);
        }
        else
        {
            UnableRecognize();
        }
    }
    //将栈中剩余的元素弹出，并且加到Pfix里
    while(!Op.empty())
    {
        temp = Op.top();
        Pfix.push_back(temp);
        Op.pop();
    }
}

//将最近添加的两个元素弹出，方便后面隔个元素的计算
void cal(double &a, double &b, stack<double> &Num)
{
    if (!Num.empty())
    {
        a = Num.top();Num.pop();
        b = Num.top();Num.pop();
    }
}
//用double格式输出答案
double Answer;
//以下为计算方法
void calculate()
{
    stack<double> Num;
    double a = 0;
    double b = 0;
   

    for (int i = 0; i < Pfix.size(); i++)
    {
        if (Pfix[i] == "+")
        {
            cal(a,b,Num);
            Num.push(b + a);
        }
        else if (Pfix[i] == "-")
        {
            cal(a,b,Num);
            Num.push(b - a);
        }
        else if (Pfix[i] == "*")
        {
            cal(a,b,Num);
            Num.push(b * a);
        }
        else if (Pfix[i] == "/")
        {
            cal(a,b,Num);
            if (a == 0)
            {
                DevidedZero();
            }
            Num.push(b / a);
        }
        else if (Pfix[i] == "^")
        {
            cal(a,b,Num);
            Num.push(pow(b, a));
        }
        else
        {
            Num.push(atof(Pfix[i].c_str()));
        }
    }
    if (!Num.empty())
    {
        Answer = Num.top();
    }
}


