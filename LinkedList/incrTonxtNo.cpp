#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;
// #include "Solution.h"
Node*reverseLL(Node*head){
    if(head==NULL||head->next==NULL){
		return head;
	}
	Node*small=reverseLL(head->next);
    Node*tail=head->next;
    tail->next=head;
	head->next=NULL;
	return small;
}
Node* NextLargeNumber(Node *head) {
     if(head==NULL){
         return head;
     }
     Node*h1=reverseLL(head);
     Node*temp=h1;
     int carry=1;
     while(temp!=NULL&&carry>0){
         temp->data+=carry;
         carry=temp->data/10;
         temp->data%=10;
         if(temp->next==NULL&&carry>0){
             temp->next= new Node (carry);
             carry=0;
         }
         temp=temp->next;
     }
     Node*h2=reverseLL(h1);
    return h2;
}

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
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
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    
    head = NextLargeNumber(head);
    print(head);
    return 0;
}