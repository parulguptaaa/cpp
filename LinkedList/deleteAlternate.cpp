#include <iostream>

class Node {
public:
    int data;
    Node * next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    
    // ~Node() {
    //     if(next) {
    //         delete next;
    //     }
    // }
};

using namespace std;
// #include "solution.h"
void deleteAlternateNodes(Node *head) {
    //Write your code here
    if(head==NULL||head->next==NULL){
        return;
    }
    Node*temp=head;
    Node*b;
    while(temp->next!=NULL&&b!=NULL){
        Node*a=temp->next;
        Node*b=a->next;
        if(b==NULL){
            temp->next=NULL;
            delete temp->next;
            return;
        }
        temp->next=b;
        delete a;
        temp=temp->next;
    }
   
    return;
}

Node* takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    Node *head = takeinput();
    deleteAlternateNodes(head);
    print(head);
    delete head;
    return 0;
}