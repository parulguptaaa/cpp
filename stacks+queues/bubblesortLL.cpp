//bubble sort iterative
#include <iostream>
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

using namespace std;
// #include "solution.h"
Node *bubbleSort(Node *head)
{
	// Write your code here
	if(head==NULL||head->next==NULL){
		return head;
	}
	int n=0;
	Node*temp=head;
	while(temp->next!=NULL){
		  temp=temp->next;
		  n++;
    }
	
	for(int i=0;i<n;i++){
		Node*prev=NULL;
		Node*curr=head;
		while(curr->next!=NULL){
			if(curr->data>curr->next->data){
				if(prev!=NULL){
					Node*p=curr->next;
				prev->next=p;
				curr->next=p->next;
				p->next=curr;
				prev=prev->next;
				}else{
					head=curr->next;
					curr->next=head->next;
					head->next=curr;
					prev=head;
				}
				
			}else{
				prev=curr;
				curr=curr->next;
			}
		}
	}
	return head;
}
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
int main()
{
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}