#pragma once
#include"check.h"
class node
{
private:
	node* next;
	int data;
public:
	node(int d);
	node();
	~node();
	void append(int d);
	void print();
	void hashUniqueInsert(int key,int data);
	int find(int key);
	void changeHead(int data);
	void removeDups();
	check kth(int k);
	void remCurrNode(int k);
	node partition(node& head2, int k, node& head3);
	void add(node& head2);
	void addBackwards(node& head2);
	int findLength(node& head);
};

