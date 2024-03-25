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
#include <stack>
void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root==NULL){
		return;
	}
	bool L2R=true;
	stack<BinaryTreeNode<int> *>curr;
	stack<BinaryTreeNode<int> *>next;
	curr.push(root);
	while(curr.size()!=0){
		BinaryTreeNode<int>* front=curr.top();
		curr.pop();
		cout<<front->data<<" ";
		if(L2R){
			if(front->left){
				next.push(front->left);
			}
			if(front->right){
				next.push(front->right);
			}
		}else{
			if(front->right){
				next.push(front->right);
			}
			if(front->left){
				next.push(front->left);
			}
		}
		if(curr.size()==0){
			L2R=!L2R;
			stack<BinaryTreeNode<int> *>temp;
			temp=curr;
			curr=next;
			next=temp;
			cout<<endl;
		}
		
	}

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
    zigZagOrder(root);
}