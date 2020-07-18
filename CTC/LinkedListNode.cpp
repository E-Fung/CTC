#include "LinkedListNode.h"
#include<iostream>



LinkedListNode::LinkedListNode(int d) {
	next = nullptr;
	data = d;
}

LinkedListNode::~LinkedListNode() {

}

LinkedListNode::LinkedListNode() {
	next = nullptr;
	data = NULL;
}

void LinkedListNode::print() {
	LinkedListNode* n = this;
	while (n != nullptr) {
		std::cout << n->data << "->";
		//std::cout << n << "->";
		n = n->next;
	}
	std::cout << std::endl;
}

void LinkedListNode::append(int d) {
	LinkedListNode* n = this;
	LinkedListNode* temp = new LinkedListNode(d);
	while (n->next != nullptr) {
		n = n->next;
	}
	n->next = temp;
}

LinkedListNode* LinkedListNode::getNext() {
	return next;
}

int LinkedListNode::getData() {
	return data;
}

void LinkedListNode::setNext(LinkedListNode* n) {
	this->next = n;
}

void LinkedListNode::setData(int d) {
	this->data = d;
}

int LinkedListNode::getLength() {
	int output = 1;
	LinkedListNode* n = this;
	while (n != nullptr) {
		n = n->next;
		output++;
	}
	return output;
}