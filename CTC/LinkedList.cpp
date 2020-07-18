#include "LinkedList.h"


LinkedList::LinkedList() {

}

LinkedList::LinkedList(int d) {
	head.setData(d);
}

LinkedList::~LinkedList() {
	clear();
	cout << "List deleted" << endl;
}

void LinkedList::print() {
	head.print();
}

void LinkedList::getList() {
	string input;
	cin.clear();
	cout << "Enter the list with elements seperated by white space" << endl;
	getline(cin, input);
	int temp=NULL;
	for (char c : input) {
		if (c >= '0' && c <= '9') {
			temp *= 10;
			temp += (c - '0');
		}
		else if(c==' '){
			if (temp != NULL) {
				head.append(temp);
				temp = NULL;
			}
		}
		else {
			continue;
		}
	}
	if (temp != NULL) {
		head.append(temp);
	}
	removeHead();
}

void LinkedList::removeHead() {
	if (head.getNext() != nullptr) {
		head = *head.getNext();
	}
}

void LinkedList::appendHead(int d) {
	LinkedListNode* temp = new LinkedListNode(head.getData());
	temp->setNext(head.getNext());
	head.setNext(temp);
	head.setData(d);
}

int LinkedList::getLength() {
	return head.getLength();
}

void LinkedList::addWith(LinkedList& list2) {
	LinkedListNode* head1;
	LinkedListNode* head2;
	head1 = &(this->head);
	head2 = &list2.head;
	if (add(head1, head2)) {
		this->appendHead(1);
	}
}

int LinkedList::add(LinkedListNode* node1, LinkedListNode* node2) {
	node1->data += node2->data;
	if (node1->next != nullptr) {
		node1->data += add(node1->next,node2->next);
	}
	if (node1->data>=10) {
		node1->data -= 10;
		return 1;
	}
	else {
		return 0;
	}

}

bool LinkedList::isPal() {
	//if there is only 1 element it is a palindrome
	LinkedListNode* n = &this->head;
	if (n->next == nullptr) {
		return true;
	}
	LinkedList tempList(n->data);
	n = n->next;
	LinkedListNode* n2 = &tempList.head;
	LinkedListNode* temp;

	while (n != nullptr) {
		if (n->data == n2->data) {
			temp = n;
			while (n != nullptr && n2 != nullptr) {
				if (n->data == n2->data) {
					if (n->next == nullptr && n2->next == nullptr) {
						return true;
					}
				}
				else {
					break;
				}
				n = n->next;
				n2 = n2->next;
			}
			n = temp;
			n2 = &tempList.head;
		}
		if (n2->next != nullptr) {
			if (n->data == n2->next->data) {
				temp = n;
				while (n != nullptr && n2->next != nullptr) {
					if (n->data == n2->next->data) {
						if (n->next == nullptr && n2->next->next == nullptr) {
							return true;
						}
					}
					else {
						break;
					}
					n = n->next;
					n2 = n2->next;
				}
				n = temp;
				n2 = &tempList.head;
			}
		}
		tempList.appendHead(n->data);
		n = n->next;
	}
	return false;
}

void LinkedList::clear() {
}