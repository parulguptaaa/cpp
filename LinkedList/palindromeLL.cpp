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
Node*getMidList(Node*head){
	Node*slow=head;
	Node*fast=head->next;
	while(fast!=NULL&&fast->next!=NULL ){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}
Node*reverseList(Node*currNode){
	Node*prev=NULL;
	Node*next=NULL;
	while(currNode!=NULL){
		next=currNode->next;
		currNode->next=prev;
		prev=currNode;
		currNode=next;
	}
	return prev;
}
bool isPalindrome(Node *head)
{
    //Write your code here
	if(head==NULL || head->next==NULL){
		return true;
	}
	Node*mid=getMidList(head);
	Node*revHead=reverseList(mid);
	while(revHead!=NULL && head!=NULL){
		if(revHead->data!=head->data){
			return false;
		}
		revHead=revHead->next;
		head=head->next;
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
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}