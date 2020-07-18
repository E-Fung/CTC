//This function determines if given two strings, they are one away from becoming identical
//ask if uppercase and lower case are to be treated differently
#include <string>
#include<iostream>
#include<unordered_map>
#include<iterator>

using namespace std;

bool oneAway(string s1, string s2) {

	int size1 = s1.size();
	int size2 = s2.size();

	if (abs(size2 - size1) > 1) {//if one string is more than 1 character larger return false
		return false;
	}
	if (size1 < size2) {
		string temp = s1;
		s1 = s2;
		s2 = temp;
		int tempInt = size1;
		size1 = size2;
		size2 = tempInt;
	}

	char c;

	if ((size1 - size2)==1) {//s1 is larger than s2, therefore to be true all of s2 should be found in s1 
		int offset = 0;
		for (int j = 0; j < size2; j++) {
			if (tolower(s2[j]) == s1[j+offset]) {
				continue;
			}
			else {
				if (offset == 0) {
					offset = 1;
					j--;
					continue;
				}
				else {
					return false;
				}
			}
		}

	}
	else {//same size
		//when both strings are of equal length, this means only 1 character is different, all others are identical 
		//in terms of both placement and char
		int counter = 0;
		for (int j = 0; j < size2; j++) {
			if (tolower(s2[j]) == s1[j]) {
				continue;
			}
			else {
				counter++;
				if (counter == 2) {
					return false;
				}
			}
		}
		if (counter == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	string input1, input2;
	while(true) {
		cout << "Enter first input:";
		cin >> input1;
		cout << "\nEnter second input:";
		cin >> input2;
		cout << endl;
		if (oneAway(input1, input2)) {
			cout << "Is one away\n";
		}
		else {
			cout << "Is not one away\n";
		}
	}
	return 0;
}