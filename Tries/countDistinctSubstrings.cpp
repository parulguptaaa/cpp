#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// #include "solution.h"
class TrieNode{
    public:
    char data;
    TrieNode** children;
    bool isTerminal;
    TrieNode(char data){
        this->data=data;
        children=new TrieNode*[26];
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};
class Trie{
    TrieNode*root;
    public:
    Trie(){
        root= new TrieNode('\0');
    }

    void insert(TrieNode*root,TrieNode*child,int index){
        root->children[index]=child;
        return;
    }
    bool search(TrieNode*root,char c, int i){
        int index=c-'a';
        if(root->children[index]==NULL){
            return false;
        }else{
            return true;
        }
    }

    TrieNode* getCH(TrieNode*root,char c){
        return root->children[c-'a'];
    }
    
};
int countDistinctSubstrings(string &s)
{
    //    Write your code here
    Trie t;
    int count=0;
    int n=s.size();
    TrieNode*root=new TrieNode('\0');
    for (int i=0;i<n;i++){
        TrieNode*currNode=root;
        for(int j=i;j<n;j++){
            int index=s[j]-'a';
            if(!t.search(currNode,s[j],index)){
                count+=1;
                TrieNode*child=new TrieNode(s[j]);
                t.insert(currNode,child,index);
            }
            currNode=t.getCH(currNode, s[j]);
        }
    }
    return count+1;
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
            cin >> arr[tc];
        }
    }

    vector<string> getCopy()
    {
        vector<string> arrCopy = arr;

        return arrCopy;
    }

    void execute()
    {
        vector<string> arrCopy = arr;
        for (int i = 0; i < t; i++)
        {
            int ans = countDistinctSubstrings(arrCopy[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            int ans = countDistinctSubstrings(arr[i]);

            cout << ans << endl;
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