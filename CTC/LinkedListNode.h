#pragma once
class LinkedListNode
{
	
public:
	LinkedListNode();
	~LinkedListNode();
	LinkedListNode(int d);
	void print();
	void append(int d);
	LinkedListNode* getNext();
	int getData();
	void setNext(LinkedListNode* n);
	void setData(int d);
	int getLength(); 
	LinkedListNode* next;
	int data;
};

