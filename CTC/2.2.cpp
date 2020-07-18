//return kth to last element

#include<iostream>
#include"node.h"
#include<string>
#include"check.h"

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
	int k;
	while (true) {
		node* head= &inputList();
		head->print();
		cout << "Please input k:" << endl;
		cin >> k;
		check* isValid;
		isValid= &(head->kth(k));
		if (isValid->getBool()) {
			cout << "The kth "<<"\""<<k<<"\" "<<"to last element is:" << isValid->getData() << endl;
		}
		else {
			cout << "There is no valid answer" << endl;
		}
	}
	return 0;
}