//This program determines if a string contains all unique characters

#include <iostream>
#include<string>
#include<set>
using namespace std;

bool isUnique(string input) {
	//characters are defined on a system that has a cap
	//ASCII and Unicode are two popular character representations where
	//numbers represent different characters

	//thus if we know it is ASCII for example, we know that there are a total of X
	//unique characters
	int size = input.size();

	if (size > 128) {//assuming theres a total of 128 different unique characters that ASCII provides
		return false;
	}
	set<char> mySet;
	//to check if the character is reoccuring we can use a hash set or a bit vector of size X
	for (int i = 0; i < size; i++) {
		if (mySet.find(input[i]) != mySet.end()) {
			return false;
		}
		mySet.insert(input[i]);
	}
	return true;
}

int main() {
	string input;
	while (true) {
		cout << "Enter input\n";
		cin >> input;
		if (isUnique(input)) {
			cout << input << " is unique" << endl;
		}
		else {
			cout << input << " is not unique" << endl;
		}
		cout << endl;
	}
}