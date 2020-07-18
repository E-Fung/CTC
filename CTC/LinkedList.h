#include"LinkedListNode.h"
#include <string>
#include<iostream>
#include<vector>
#pragma once
using namespace std;
class LinkedList
{
private:
	LinkedListNode head;
public:
	LinkedList();
	LinkedList(int d);
	~LinkedList();
	void print();
	void getList();
	void removeHead();
	void appendHead(int d);
	int getLength();
	void addWith(LinkedList& list2);
	int add(LinkedListNode* node1,LinkedListNode* node2);
	bool isPal();
	void clear();
};

