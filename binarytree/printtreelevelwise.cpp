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
void printLevelWise(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root==NULL){
		return;
	}
	queue<BinaryTreeNode<int> *>pendingNodes;
	pendingNodes.push(root);
	pendingNodes.push(NULL);
	while(pendingNodes.size()!=0){
		BinaryTreeNode<int> *front=pendingNodes.front();
		
		pendingNodes.pop();
		if(front==NULL&&pendingNodes.size()!=0){
			cout<<endl;
			pendingNodes.push(NULL);
		}else if(front==NULL&&pendingNodes.size()==0){
			return;
		}else{
			cout<<front->data<<" ";
			if(front->left){
				pendingNodes.push(front->left);
			}
			if(front->right){
				pendingNodes.push(front->right);
			}
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
    printLevelWise(root);
}