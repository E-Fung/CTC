//This program removes all duplicates from a singly linked list
//this will be down without any buffer

#include"node.h"
#include<iostream>
#include<string>

using namespace std;

int main() {
	//we could save the address of head
	while (true) {
		string input;
		cout << "Please enter the list with a space seperating the elements" << endl;
		getline(cin,input);
		if (!input.empty()) {
			bool first = true;
			int size = input.size();
			int temp=NULL;
			node head(NULL);
			for (char c : input) {
				if ((c >= '0' && c <= '9') || (c == ' ')) {
					if (c == ' ' && temp!=NULL) {
						if (first == true) {
							//create head
							//node *head=new node(temp);
							head.changeHead(temp);
							first = false;
						}
						else {
							head.append(temp);
						}
						temp = NULL;
					}
					if(c>='0'&& c<='9'){
						temp *= 10;
						temp += c - '0';
					}
				}
				else {
					continue;
				}
			}
			if (temp != NULL) {
				head.append(temp);
			}
			head.print();
			cout << "The list with dups removed is: "<<endl;
			//include code to remove dups here
			head.removeDups();
			head.print();
		}
		
	}
	return 0;
}