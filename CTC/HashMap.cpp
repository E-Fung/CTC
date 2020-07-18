#include "HashMap.h"
#include<vector>
#include"node.h"
using namespace std;

HashMap::HashMap() {
	node head1(NULL);
	node head2(NULL);
	node head3(NULL);
	node head4(NULL);
	node head5(NULL);
	node head6(NULL);
	node head7(NULL);
	node head8(NULL);
	node head9(NULL);
	node head10(NULL);
	node head11(NULL);
	node head12(NULL);
	node head13(NULL);
	node head14(NULL);
	node head15(NULL);
	node head16(NULL);
	myHashMap.push_back(head1);
	myHashMap.push_back(head2);
	myHashMap.push_back(head3);
	myHashMap.push_back(head4);
	myHashMap.push_back(head5);
	myHashMap.push_back(head6);
	myHashMap.push_back(head7);
	myHashMap.push_back(head8);
	myHashMap.push_back(head9);
	myHashMap.push_back(head10);
	myHashMap.push_back(head11);
	myHashMap.push_back(head12);
	myHashMap.push_back(head13);
	myHashMap.push_back(head14);
	myHashMap.push_back(head15);
	myHashMap.push_back(head16);
}

int HashMap::hash(int key) {	
	long long int temp=key;
	temp *= 3547;
	temp *= temp;
	int t1 = temp % 100;
	while (temp > 1000) {
		temp /= 10;
	}
	temp = temp * 1000 + t1+7;
	temp *= temp;
	int t2 = temp % 100;
	while (temp > 100) {
		temp /= 10;
	}
	temp = temp * 101 + t2+7;
	temp = temp %1523 +( temp % 31)*27;
	return temp;
}

void HashMap::insert(int key, int data) {
	int newKey = hash(key);
	node* n = &myHashMap[newKey % 16];
	n->hashUniqueInsert(newKey, data);
}

void HashMap::print() {
	for (int i = 0; i < 16; i++) {
		myHashMap[i].print();
	}
}

int HashMap::get(int key) {
	int newKey = hash(key);
	return myHashMap[newKey % 16].find(newKey);
}

HashMap::~HashMap() {

}