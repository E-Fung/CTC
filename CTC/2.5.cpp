#include<iostream>
#include"LinkedList.h"
#include"LinkedListNode.h"

using namespace std;

int main() {
	while (true) {
		LinkedList List1, List2;
		cout << "First List:" << endl;
		List1.getList();
		cout << "Second List:" << endl;
		List2.getList();
		int size1, size2;
		size1 = List1.getLength();
		size2 = List2.getLength();
		if (size1 > size2) {
			for (int i = 0; i < size1 - size2; i++) {
				List2.appendHead(0);
			}
		}
		if (size2 > size1) {
			for (int j = 0; j < size2 - size1; j++) {
				List1.appendHead(0);
			}
		}
		List1.print();
		List2.print();
		List1.addWith(List2);
		cout << "The added sum is ";
		List1.print();
	}
}