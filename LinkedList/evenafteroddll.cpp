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
Node *evenAfterOdd(Node *head)
{
	//write your code here
	Node*oh=NULL;
	Node*ot=NULL;
	Node*eh=NULL;
	Node*et=NULL;

	while(head!=NULL){
		if(head->data%2!=0){
			if(oh==NULL){
				oh=head;
				ot=head;
			}else{
				ot->next=head;
				ot=head;
			}
			head=head->next;
		}else{
			if(eh==NULL){
				eh=head;
				et=head;
			}else{
				et->next=head;
				et=head;
			}
			head=head->next;
		}
	}
	
	if(oh == NULL){
        return eh;
    }else{
        ot->next = eh;
    }
    if(et == NULL){
        return oh;
    }else{
        et->next = NULL;
    }
    return oh;
}
	

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}
