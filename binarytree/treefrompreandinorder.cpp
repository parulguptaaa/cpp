#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
// #include "solution.h"
BinaryTreeNode<int>* buildTreeHelper(int *preorder,int preLength, int *inorder, int inLength, int inS, int inE, int preS, int preE ) {
	// if(!preorder[0]){
	// 	return NULL;
	// }

	if(preS>=preLength || inS > inE){
		return NULL;
	}

	BinaryTreeNode<int>*root = new BinaryTreeNode<int>(preorder[preS]);
	int i=inS;
	for(;i<=inE;i++){
		if(inorder[i]==root->data){
			break;
		}
	}

	int leftInS = inS;
	int leftInE = i - 1;
	int leftPreS = preS+1;
	int leftPreE = leftPreS+(leftInE-leftInS);

	int rightInS = i+1;
	int rightInE = inE;
	int rightPreS = leftPreE + 1;
	int rightPreE = preE;

	root->left=buildTreeHelper(preorder, preLength, inorder, inLength, leftInS,leftInE, leftPreS, leftPreE);
	root->right=buildTreeHelper(preorder,preLength, inorder,inLength, rightInS,rightInE, rightPreS,rightPreE);
	return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
	int n=inLength;
	int p=preLength;
	return buildTreeHelper(preorder, p, inorder, n, 0, n-1, 0, p-1);
}

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int main() {
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}