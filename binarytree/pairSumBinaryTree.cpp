#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
// #include "solution.h"
#include<stack>
#include <bits/stdc++.h>
vector<int> preOrder(BinaryTreeNode<int> * root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    stack<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>*front=pendingNodes.top();
        ans.push_back(front->data);
        pendingNodes.pop();
        if(front->right){
            pendingNodes.push(front->right);
        }
        if (front->left) {
            pendingNodes.push(front->left);
        }
    }
    return ans;
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
	if(root==NULL){
		return;
	}
	vector<int> preorderAns=preOrder(root);
	sort(preorderAns.begin(),preorderAns.end());
	int i=0;
	int j=preorderAns.size()-1;
	while(i<j){
		if(preorderAns[i]+preorderAns[j]==sum){
			cout<<preorderAns[i]<<" "<<preorderAns[j]<<endl;
			i++,j--;
		}else if (preorderAns[i]+preorderAns[j]>sum){
			j--;
		}else if (preorderAns[i]+preorderAns[j]<sum){
			i++;
		}
	}
	return;
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}
