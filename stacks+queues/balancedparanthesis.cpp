#include <iostream>
#include <string>
using namespace std;
#include<stack>
// #include "solution.h"
bool isBalanced(string expression) {
    stack<char>s;
    for(int i=0;i<expression.length();i++){
      if(expression[i]=='('){
        s.push(expression[i]);
      }
      else if(expression[i]==')'){
        if(s.empty()){
          return 0;
        }
        char topchar=s.top();
        s.pop();
        if(expression[i]==')' &&topchar=='('){
          continue;
        }
        else{
          return 0;
        }
      }
    }
    return s.empty();
}
int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}