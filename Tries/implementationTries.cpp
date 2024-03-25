#include<iostream>
#include <string>
using namespace std;
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
    void helper(TrieNode*root,string word){
        // base case
        if(word.size()==0){
            root->isTerminal=true;
            return;
        }

        // small calculation
        int index=word[0]-'a';
        TrieNode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        // recursive call
        helper(child,word.substr(1));
    }
    void insertWord(string word){
        helper(root,word);
    }
    bool searchHelper(TrieNode*root,string word){
        if(word.size()==0){
            if(root->isTerminal){
                return true;
            }else{
                return false;
            }
        }
        int index=word[0]-'a';
        if(root->children[index]==NULL){
            return false;
        }else{
            TrieNode*child=root->children[index];
            return searchHelper(child,word.substr(1));
        }
    }
    bool search(string word){
        return searchHelper(root,word);
    }
    void removeHelper(TrieNode*root,string word){
        // base case
        if(word.size()==0){
            root->isTerminal=false;
            return;
        }
        // small calculation
        TrieNode*child;
        int index=word[0]-'a';
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            return;
            // word not found
        }
        removeHelper(child,word.substr(1));

        // remove child if useless
        if(child->isTerminal==false){
            for(int i=0;i<26;i++){
                if(child->children[i]!=NULL){
                    break;
                }
            }
            delete child;
            root->children[index]=NULL;
        }
    }
    
};
int main() {
    int choice;
    cin >> choice;
    Trie t;

    while (choice != -1) {
        string word;
        bool ans;
        switch (choice) {
            case 1:  // insert
                cin >> word;
                t.insertWord(word);
                break;
            case 2:  // search
                cin >> word;
                cout << (t.search(word) ? "true\n" : "false\n");
                break;
            default:
                return 0;
        }
        cin >> choice;
    }

    return 0;
}