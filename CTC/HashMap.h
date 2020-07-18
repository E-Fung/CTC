#pragma once
#include"node.h"
#include<vector>
using namespace std;
class HashMap
{
private:
	vector<node> myHashMap;
	int hash(int key);
public:
	HashMap();
	~HashMap();
	void insert(int key, int data);
	void print();
	int get(int key);
};

