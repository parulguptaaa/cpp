#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
// #include "solution.h"
#include <bits/stdc++.h>
void helper(BinaryTreeNode<int>* root, int k1, int k2,vector<int>&ans){
	if(root==NULL){
		return;
	}
	if(root->data>=k1&&root->data<=k2){
		ans.push_back(root->data);
		helper(root->left, k1, k2,ans);
		helper(root->right, k1, k2,ans);
	}else if(root->data<k1){
		helper(root->right, k1, k2,ans);
	}else if(root->data>k2){
		helper(root->left, k1, k2,ans);
	}
	return;
}

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	if(root==NULL){
		return ;
	}
	vector<int> ans;
	helper(root, k1, k2, ans);
	sort(ans.begin(),ans.end());
	for(auto x:ans){
		cout<<x<<" ";
	}
	return;
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int k1, k2;
    cin >> k1 >> k2;
    elementsInRangeK1K2(root, k1, k2);
}