#include <iostream>
#include <stack>
#include <vector>
#include <stack>
#include <fstream>
#include <algorithm>
std::vector<char>line;
std::stack<char>num;
std::string search_brackets(std::string str);
void arithmetic(std::string str);

int main()
{
    std::string i_line;
    std::cin>>i_line;
    arithmetic(i_line);
    for (char n : line){
        std::cout<<n;
    }
    return 0;
}
void arithmetic(std::string str){
    for (int i=0; str[i]!='\0';i++){
        int j=i;
        if (str[i]>='0'&& str[i]<='9'){
                line.push_back(str[i]);
        }
        if(str[i]=='+'||str[i]=='-'){
            if((str[i]=='-' && str[i-1]=='(')||i==0){
                line.push_back('0');
            }
            if (num.empty()||num.top()=='('){
                num.push(str[i]);
            }
            else{
                while((num.empty()==false)&& (num.top()!='(')){
                    line.push_back(num.top());
                    num.pop();
                }
                num.push(str[i]);
            }

        }
        if(str[i]=='('){
            num.push(str[i]);
        }
        if(str[i]==')'){
            while(num.top()!='('){
                line.push_back(num.top());
                num.pop();
            }
            num.pop();
        }
        if(str[i]=='*'||str[i]=='/'){
            if(num.empty()||num.top()=='-'||num.top()=='+'||num.top()=='('){
                num.push(str[i]);
            }
            else{
                while((num.empty()==false)&& ((num.top()=='*')||(num.top()=='/'))){
                    line.push_back(num.top());
                    num.pop();
                }
                num.push(str[i]);
            }
        }
    }
    while (!num.empty()){
        line.push_back(num.top());
        num.pop();
    }
}


