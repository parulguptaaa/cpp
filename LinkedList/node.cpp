#include <iostream>
class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;
// #include "solution.h"

Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}
int length(Node *head) {
    // Write your code here
	if (head==NULL){
		return 0;
	}else if(head->next==NULL){
		return 1;
	}
	int lengthofsmallerll=length(head->next);
	return 1+lengthofsmallerll;
}
void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        Node *head = takeinput();
        cout << length(head) << "\n";
    }
}