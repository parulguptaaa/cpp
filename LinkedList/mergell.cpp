#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

// using namespace std;
// #include "solution.h"
Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
Node*midpt(Node*head){
	Node*slow=head;
	Node*fast=head;
	while(fast->next!=NULL&&fast->next->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}
Node*merge(Node*h1,Node*h2){
	Node*fh;
	Node*ft;
	if(h1->data<h2->data){
		fh=h1;
		ft=h1;
		h1=h1->next;
	}else{
		fh=h2;
		ft=h2;
		h2=h2->next;
	}
	while(h2!=NULL&&h1!=NULL){
		if(h1->data<h2->data){
			ft->next=h1;
			ft=h1;
			h1=h1->next;
		}else{
			ft->next=h2;
			ft=h2;
			h2=h2->next;
		}
	}
	while(h1!=NULL){
			ft->next=h1;
			ft=h1;
			h1=h1->next;
	}
	while(h2!=NULL){
			ft->next=h2;
			ft=h2;
			h2=h2->next;
	}
	return fh;
}
Node *mergeSort(Node *head)
{
	//Write your code here
	if(head==NULL||head->next==NULL){
		return head;
	}
	Node* c=midpt(head);
	Node*temp=head;
	int i=0;
	while(temp!=c){
		temp=temp->next;
		i++;
	}
	Node*t=temp->next;
	temp->next=NULL;
	head=mergeSort(head);
	t=mergeSort(t);
	return merge(head,t);

}
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}


