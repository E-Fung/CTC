//This program partitions a singly linked list and sorts it
#include"node.h"
#include<iostream>
#include<string>

using namespace std;

node inputList() {//this takes an input from user, ignores non numeral numbers and creates a singly linked list
				  //where whitespaces in the string means a new element
	cout << "Please enter the list with a space seperating the elements" << endl;
	string input;
	input.clear();

	cin.ignore();//clears the input buffer to allow getline
	getline(cin, input);

	node tempHead(NULL);
	if (!input.empty()) {
		bool first = true;
		int size = input.size();
		int temp = NULL;
		for (char c : input) {
			if ((c >= '0' && c <= '9') || (c == ' ')) {
				if (c == ' ' && temp != NULL) {
					if (first == true) {
						//create head
						//node *head=new node(temp);
						tempHead.changeHead(temp);
						first = false;
					}
					else {
						tempHead.append(temp);
					}
					temp = NULL;
				}
				if (c >= '0' && c <= '9') {
					temp *= 10;
					temp += c - '0';
				}
			}
			else {
				continue;
			}
		}
		if (temp != NULL) {
			tempHead.append(temp);
		}
	}
	return tempHead;
}

int main() {
	while (true) {
		int k;
		node* head = &inputList();
		head->print();
		cout << "Please enter the number to partition" << endl;
		cin >> k;
		node head2 , head3;
		node newHead=head->partition(head2, k, head3);
		newHead.print();
	}
	return 0;
}