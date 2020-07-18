//This program checks if a given string is a permutation of a palindrome
//This means all letters must have matching pairs save for one

//one thing to note is if the function should be case sensitive
#include<set>
#include<iostream>
#include<string>
#include<iterator>
using namespace std;

bool PermPal(string input) {
	set<char> mySet;
	mySet.clear();
	set<char>::iterator itr;
	for (auto c : input) {
		if (c == ' ') {
			continue;
		}
		c = tolower(c);
		itr = mySet.find(c);
		if (itr != mySet.end()) {
			mySet.erase(itr);
		}
		else {
			mySet.insert(c);
		}
	}
	if (mySet.size() <= 1) {
		return true;
	}
	return false;
}

int main() {
	string input;
	while (true) {
		getline(cin, input);
		if (PermPal(input)) {
			cout << "\""<<input << "\"" << " is a permutation of a palindrome";
		}
		else {
			cout << "\"" << input << "\"" << " is not a permutation of a palindrome";
		}
		cout << endl;
	}

}