#include "node.h"
#include<iostream>
#include"check.h"

using namespace std;

node::node(int d) {
	data = d;
	next = nullptr;
}

node::node() {
	data = NULL;
	next = nullptr;
}

node node::partition(node& head2, int k,node& head3) {
	node* n = this;
	node* last;
	node* head2Tail = &head2;
	while (n != nullptr) {
		if (n->data >= k) {
			head3.append(n->data);
		}
		else {
			head2.append(n->data);
			head2Tail = head2Tail->next;
		}
		n = n->next;
	}
	head2.data = head2.next->data;
	head2.next = head2.next->next;
	head2Tail->next = head3.next;
	return head2;
}

int node::findLength(node& head) {
	int output = 0;
	node* n = this;
	while (n != nullptr) {
		output++;
		n = n->next;
	}
	return output;
}



void node::addBackwards(node& head2) {

}

void node::add(node& head2) {
	node* n = this;
	node* n2 = &head2;
	int carry = 0;
	while (n != nullptr && n2!=nullptr) {
		int sum = n->data + n2->data+carry;
		if (sum>9) {
			carry = 1;
		}
		else {
			carry = 0;
		}
		n->data = sum % 10;
		n = n->next;
		n2 = n2->next;
	}
	if (n==nullptr) {
		while (n2 != nullptr) {
			this->append(n2->data + carry);
			if (carry == 1) {
				carry = 0;
			}
			n2 = n2->next;
		}
	}
	else {
		n->data += carry;
	}
	
}

void node::remCurrNode(int k) {
	int temp = 1;
	node* n = this;
	while (temp != k && n->next!=nullptr) {
		if (n->next == nullptr) {
			n->~node();
		}
		n = n->next;
		temp++;
	}
	if (temp == k && n->next != nullptr) {
		n->data = n->next->data;
		if (n->next->next!=nullptr) {
			n->next = n->next->next;
		}
		else {
			n->next = nullptr;
		}
	}
}

node::~node() {
	//cout << "node deleted" << endl;
}

void node::removeDups() {
	node* n = this;
	node* itr;
	node* last;
	int data;
	while (n != nullptr) {
		data = n->data;
		itr = n->next;
		last = n;
		while (itr != nullptr) {
																//two scenarios, end or list or not end of list
			if (itr->data == data) {
				if (itr->next == nullptr) {				//not end
					last->next = nullptr;
				}
				else {
					last->next = itr->next;
					itr = itr->next;
					continue;
				}
			}
			last = last->next;
			itr = itr->next;
		}
		//this->print();
		n = n->next;
	}
}

void node::print() {
	node* n = this;
	while (n != nullptr) {
		cout <<n->data<<"->";
		n = n->next;
	}
	cout << endl;
}

void node::hashUniqueInsert(int key, int data) {
	node* n = this;
	bool found = false;
	if (n->next != nullptr) {
		n = n->next;
	}
	while (n->next!= nullptr) {
		if (n->data == key) {
			n = n->next;
			n->data = data;
			found = true;
			break;
		}
		n = n->next;
		n = n->next;
	}
	if (found == false) {
		this->append(key);
		this->append(data);
	}
}

void node::append(int d) {
	//dynamic programming requries that the variable points to the dynamics variable
	node* end = new node(d);
	node* n = this;//"this" is associated with the head of the list

	//"->" is used for pointers to an object
	while (n->next != nullptr) {
		n = n->next;
	}
	n->next = end;
}

int node::find(int key) {
	node* n = this;
	if (n->next == nullptr) {
		return -1;
	}
	n = n->next;
	while (n->next != nullptr) {
		if (n->data == key) {
			n = n->next;
			return n->data;
		}
		n = n->next;
		n = n->next;
	}
	return -1;
}

void node::changeHead(int data) {
	this->data = data;
}

check node::kth(int k) {
	check output;
	node* n = this;
	node* kAway = n;
	for (int i = 0; i < k-1; i++) {
		if (n->next != nullptr) {
			n = n->next;
		}
		else {
			return output;
		}
	}
	while (n->next != nullptr) {
		n = n->next;
		kAway = kAway->next;
	}
	output.setBool(true);
	output.setData(kAway->data);
	return output;
}