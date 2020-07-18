#include<iostream>

#include"LinkedList.h"
#include"LinkedListNode.h"

using namespace std;

int main() {
	LinkedList List;
	List.getList();
	//for question 2.7 nd 2.8 we are asked to determine if 1) Two singly linked list intersect and 2) If a loop is present
	//for this, an easy implementation is to add a new bool variable to each node which is set to false, when checking for either, we set
	//the bool to true, if we ever find a true without switching we can know that where it intersects or loops
}