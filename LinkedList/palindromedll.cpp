#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node* prev;
	Node(int data)
	{
		
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
};


// #include "solution.h"

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}
Node*mid(Node*head){
	Node*slow=head;
	Node*fast=head;
	while(fast->next!=NULL && fast->next->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}
bool palindromeDLL(Node* head){
    if(head==NULL||head->next==NULL){
		return true;
	}
	Node*slow=mid(head);
	Node*a=slow->next;
	Node*b=slow->prev;
	while(a!=NULL&&b!=NULL){
		if(b->data==a->data){
			b=b->prev;
			a=a->next;
		}else{
			return false;
		}
	}
	return true;
}


int main()
{
    
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		bool ans = palindromeDLL(head);
		
		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}
	return 0;
}