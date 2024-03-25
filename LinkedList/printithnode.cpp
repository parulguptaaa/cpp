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
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}
void printIthNode(Node *head, int i)
{
    int c;
    Node *temp = head;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    if (i < c)
    {
        Node *t = head;
        if (i == 0)
        {
            cout << t->data << endl;
        }
        int j = 0;

        while (j<c)
        {
            j++;
            t = t->next;
            if (i == j)
            {
                cout << t->data;
                return;
            }
        }
        return;
    }
    else
    {
        return;
    }
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		printIthNode(head, pos);
		cout << endl;
	}
	return 0;
}