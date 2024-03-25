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
class Pair{
    public:
        Node*head;
        Node*tail;
};
using namespace std;
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
// t(n)=O(n^2)
Node *reverseLLR1(Node *head)
{
    //Write your code here
	if(head==NULL||head->next==NULL){
		return head;
	}
	Node*small=reverseLLR1(head->next);
	Node*temp=small;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=head;
	head->next=NULL;
	return small;

}
// t(n)=O(n)
Pair reverseLLR2_class(Node *head)
{
    //Write your code here
	if(head==NULL||head->next==NULL){
        Pair ans;
        ans.head=head;
        ans.tail=head;
		return ans;
	}
	Pair small=reverseLLR2_class(head->next);
	
	small.tail->next=head;
	head->next=NULL;
    Pair ans;
    ans.head=small.head;
    ans.tail=head;
	return ans;
}
Node* reverseLLR2(Node *head){
    return reverseLLR2_class(head).head;
}
Node *reverseLLR3(Node *head)
{
	if(head==NULL||head->next==NULL){
		return head;
	}
	Node*small=reverseLLR3(head->next);
    Node*tail=head->next;
    tail->next=head;
	head->next=NULL;
	return small;
}
int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		Node *head = takeinput();
		// head = reverseLLR1(head);
		// head = reverseLLR2(head);
		head = reverseLLR3(head);
		print(head);
	}

	return 0;
}