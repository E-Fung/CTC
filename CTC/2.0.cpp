//this program experiements with the singly linked list

//hash map

#include "node.h"
#include<vector>
#include"HashMap.h"
#include<iostream>
using namespace std;


int main() {
	HashMap myHashMap;
	myHashMap.insert(5, 4);
	myHashMap.insert(5, 123);
	myHashMap.insert(145, 7);
	myHashMap.insert(554, 123);
	myHashMap.print();
	int data = myHashMap.get(123);
	if (data == -1) {
		cout << "No matching key found"<<endl;
	}
	else {
		cout << "Data: " << data << endl;
	}
	return 0;
}