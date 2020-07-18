//This program checks if a linked list is a palindrome
#include<iostream>

#include"LinkedList.h"
#include"LinkedListNode.h"

using namespace std;

int main() {
	while (true) {
		LinkedList List;
		List.getList();
		List.print();
		if (List.isPal()) {
			cout << "Yes, this is a palindrome list" << endl;
		}
		else {
			cout << "Nope, not a plaindrome" << endl;
		}
	}
}