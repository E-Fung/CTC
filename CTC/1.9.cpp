//This program determines if two strings are rotations of one another
#include<iostream>
#include<string>

using namespace std;

bool isRot(string s1, string s2) {
	int size1 = s1.size();
	int size2 = s2.size();
	if (size1 != size2) {
		return false;
	}
	int i = 0;
	while (i < size1) {
		if (s1 == s2) {
			return true;
		}
		s2.push_back(s2[0]);
		s2.erase(s2.begin());
		i++;
	}
	
	return false;
}

int main() {
	string s1, s2;
	while (true) {
		cout << endl << "Enter first string:";
		cin >> s1;
		cout << endl << "Enter second string:";
		cin >> s2;
		if (isRot(s1, s2)) {
			cout << endl << "These strings are rotations of one another";
		}
		else {
			cout << endl << "These strings are not rotations of one another";
		}
	}

	return 0;
}