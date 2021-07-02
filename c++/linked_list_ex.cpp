#include "stdio.h"
#include <iostream>

class LinkedList {
private:
	struct Node {
		int data;
		Node *link;
	};

	Node *head; // the first Node
	bool f;

public:
	LinkedList();

	void InsertNode(int val);
	void DeleteNode(int val);
	void ShowData();
	void InsertPosition(Node* &prev_p, Node* &p, int &val);
	void DeletePosition(Node* &prev_p, Node* &p, int &val);
};

LinkedList::LinkedList() {
	head = new Node;
	head->link = NULL; // set head to NULL
}

void LinkedList::InsertNode(int val) {
	Node *n = new Node;   // create new Node
	n->data = val;          // set value
	n->link = NULL;         // make the node point to NULL.

	Node *r, *p;
	InsertPosition(r, p, n->data);

	n->link = r->link;
	r->link = n;
}

void LinkedList::InsertPosition(Node* &prev_p, Node* &p, int &val) {
	f = false;
	prev_p = p = head;
	while (p->link != NULL) {
		prev_p = p;
		p = p->link;
		if (p->data > val) {
			f = true;
			break;
		}else if (p->link == NULL && f == false) {
			prev_p = p;
		}
	}
}

void LinkedList::DeleteNode(int val) {
	Node *r, *p;
	DeletePosition(r, p, val);


	if (f == false) {
		std::cout << "there is no " << val << std::endl;
	}
	else {
		r->link = p->link;
		delete p;
	}
}

void LinkedList::DeletePosition(Node* &prev_p, Node* &p, int &val) {
	f = false;
	prev_p = p = head;
	while (p->link != NULL) {
		prev_p = p;
		p = p->link;
		if (p->data == val) {
			f = true;
			break;
		}
	}
}

void LinkedList::ShowData() {
	Node *tmp1;
	tmp1 = head->link;

	std::cout << "Head";

	while (tmp1 != NULL) {
		std::cout << " -> " << tmp1->data;
		tmp1 = tmp1->link;
	}

	std::cout << "\n";
}

int main()
{
	//연결리스트 생성
	LinkedList list = LinkedList();

	list.InsertNode(4);

	list.InsertNode(1);

	list.InsertNode(3);

	list.InsertNode(9);

	list.DeleteNode(1);

	list.ShowData();

    return 0;
}