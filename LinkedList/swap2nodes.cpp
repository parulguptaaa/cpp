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
// Node *swapNodes(Node *head, int i, int j)
// {
// 	//Write your code here
// 	Node*t1=head;
// 	Node*t2=head;
// 	int o=0,k=0;
// 	while(o<i-1){
// 		t1=t1->next;
// 		o++;
// 	}
// 	while(k<j-1){
// 		t2=t2->next;
// 		k++;
// 	}
// 	Node*b=t1->next;
// 	Node*a=t2->next;
// 	t2->next=t1->next;
// 	t1->next=a;
// 	Node*c=b->next;
// 	b->next=a->next;
// 	a->next=c;
// 	return head;
// }
Node *swapNodes(Node *head, int i, int j) {
    if (head == NULL || i == j) {
        return head;
    }

    Node *prev1 = NULL, *curr1 = head;
    int count1 = 0;
    while (curr1 != NULL && count1 < i) {
        prev1 = curr1;
        curr1 = curr1->next;
        count1++;
    }

    Node *prev2 = NULL, *curr2 = head;
    int count2 = 0;
    while (curr2 != NULL && count2 < j) {
        prev2 = curr2;
        curr2 = curr2->next;
        count2++;
    }

    if (curr1 == NULL || curr2 == NULL) {
        return head; // One or both indices out of bounds
    }

    // Update next pointers to swap nodes
    if (prev1 != NULL) {
        prev1->next = curr2;
    } else {
        head = curr2;
    }

    if (prev2 != NULL) {
        prev2->next = curr1;
    } else {
        head = curr1;
    }

    Node *temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;

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
	int t;
	cin >> t;
	while (t--)
	{
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}
