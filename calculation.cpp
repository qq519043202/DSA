#include <iostream>
#include <stack>
#include <string>
#include <math.h>
#include <map>
using namespace std;

bool isop(char x)
{
    char ops[] = {'+','-','*','/','(',')'};
    for(int i=0; i<6; i++)
    {
        if(x == ops[i])
        {
            return true;
        }
    }
    return false;
}

int jisuan(int num1, int num2, char op)
{
switch(op)
    {
    case '+':
        return num1+num2;
    case '-':
        return num1-num2;
    case '*':
        return num1*num2;
    case '/':
        return num1/num2;
    }
}
int main()
{

    map<char, int> priority;
    priority['+'] = 1;
    priority['-'] = 1;
    priority['*'] = 2;
    priority['/'] = 2;
    priority['('] = 3;
    priority[')'] = 3;
    string expression = "2+4*3+(5*2-3)*6";
    string afexp = "";
    stack<char> opstack;
    for(int i=0; i<expression.length();i++)
    {
        if (isop(expression[i])){
            if(opstack.empty() || expression[i] == '(')
            {
                opstack.push(expression[i]);
            }
            else if(expression[i] == ')')
            {
                 while(!opstack.empty() && opstack.top()!='(')
                 {
                     afexp.push_back(opstack.top());
                     //cout << opstack.top();
                     opstack.pop();
                 }
                 opstack.pop();
            }
            else{
                while(!opstack.empty() && priority[opstack.top()] >= priority[ expression[i] ] && opstack.top()!='(')
                {
                    afexp.push_back(opstack.top());
                     //cout << opstack.top();
                     opstack.pop();
                }
                opstack.push(expression[i]);
            }
        }
        else{
            afexp.push_back(expression[i]);
            //cout << expression[i];
        }
    }
    while(!opstack.empty())
    {
        afexp.push_back(opstack.top());
        //cout << opstack.top();
        opstack.pop();
    }
    cout << "原式："<<expression<<endl;
    cout  << "postfix："<< afexp;
    cout <<endl;
    stack<int> numstack;
    for(int i=0; i<afexp.length();i++)
    {
        if(isop(afexp[i]))
        {
            int num1 = numstack.top();
            numstack.pop();
            int num2 = numstack.top();
            numstack.pop();
            int num3 = jisuan(num2,num1,afexp[i]);
            //cout << num3 <<endl;
            numstack.push(num3);
        }
        else{
              //cout << afexp[i]  <<"\t"<<  (int)afexp[i] -48<<endl;

            numstack.push((int)afexp[i]-48);
        }
    }
    cout <<endl;
    cout <<"result："<< numstack.top();

    return 0;
}
