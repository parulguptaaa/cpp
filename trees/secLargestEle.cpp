#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};
TreeNode<int>*maxData(TreeNode<int>*root,TreeNode<int>*node){
    if(root->data>node->data){
        return root;
    }else{
        return node;
    }
}
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    if(root==NULL){
        return root;
    }
   static TreeNode<int>*largest=new TreeNode<int>(0);
   static TreeNode<int>*secMax=new TreeNode<int>(0);
    if(root->data>largest->data){

            secMax=largest;
            largest=root;
            // largest=root->children[i];
        }
    if(root->data>secMax->data&&root->data<largest->data) secMax=root;
        
     for(int i=0;i<root->children.size();i++){
        getSecondLargestNode(root->children[i]);
     }
      if(secMax->data==0) return NULL;
    return secMax;
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

}