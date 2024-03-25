#include <iostream>
#include <string>
using namespace std;
#include <unordered_map>
string uniqueChar(string str) {
	// Write your code here
	string output="";
	unordered_map<char,int>res;
	for(int i=0;i<str.length();i++){
		if(res.count(str[i])>0){
			continue;
		}
		output+=str[i];
		res[str[i]]++;
	}
	return output;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}