#include <iostream>
#include <string>
#include <vector>
using namespace std;
class TrieNode {
public:
  char data;
  TrieNode **child;
  bool isTerminal;
  int childCount;

  TrieNode(char data) {
    this->data = data;
    childCount = 0;
    child = new TrieNode *[26];
    for (int i = 0; i < 26; i++) {
      child[i] = NULL;
    }
    isTerminal = false;
  }
};

class Trie {
  TrieNode *root;

public:
  Trie() { root = new TrieNode('\0'); }

  void insert(TrieNode *root, string &word) {
    TrieNode *cur = root;

    for (int idx = 0; idx < word.size(); ++idx) {
      int diff = word[idx] - 'a';
      // If the child[diff] of cur is an empty node
      if (cur->child[diff] == NULL) {
        cur->child[diff] = new TrieNode(word[idx]);
        cur->childCount += 1;
      }
      cur = cur->child[diff];
    }

    // Marking the endOfWord of last character as true.
    cur->isTerminal = true;
  }
  string helper(TrieNode*root,string res) {
    // if(root==NULL||root->child==NULL){
    //     return res;
    // }
    if(root->isTerminal==true){
      res+=root->data;
      return res;
    }
    int count = 0;
    TrieNode *child;
    for (int i = 0; i < 26; i++) {
      if (root->child[i] != NULL) {
        count++;
        child=root->child[i];
      }
    }
    if(count==1||count==0){
        res += root->data;
        return helper(child,res);
    }else{
        res+=root->data;
        return res;
    }
  }
  string longestCommonPrefix(vector<string> &arr, int n) {
    // Write your code here
    Trie t;
    TrieNode *root=new TrieNode('\0');
    int maxlen = 0;
    int len = 0;
    for (int i = 0; i < n; i++) {
      t.insert(root, arr[i]);
      len = arr[i].size();
      if (len > maxlen) {
        maxlen = len;
      }
    }
    string res = "";
    return helper(root, res);
  }
};
int main() {
    int t;
    cin>>t;
    while(t--){
    Trie t1;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    cout<<t1.longestCommonPrefix(vect, n)<<endl;
    }
}