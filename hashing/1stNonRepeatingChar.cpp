#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
#include <bits/stdc++.h> 
#include<unordered_map>
char firstNonRepeatingCharacter(string str) {
  // Write your code here
  unordered_map<char,int>res;
  for(int i=0;i<str.length();i++){
    res[str[i]]++;
  }
  for(int i=0;i<str.length();i++){
    if(res[str[i]]==1){
      return str[i];
    }
  }
  return str[0];
}


class Runner
{
    int t;

    
    vector<string> arr;


public:
    void takeInput()
    {

 cin >> t;
        arr.resize(t);
        

        for (int tc = 0; tc < t; tc++)
        {
       cin>>arr[tc];

        }

        
    }

    void execute()
    {
         vector<string> arrCopy = arr;
        for (int i=0;i<t;i++){
            firstNonRepeatingCharacter(arrCopy[i]);
        }
    }


    void executeAndPrintOutput()
    {
        for (int tt=0;tt<t;tt++){
            char v=firstNonRepeatingCharacter(arr[tt]);
            {
              cout<<v;         
            }
            cout<<"\n";
        }
    }
};

int main()
{

    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}
