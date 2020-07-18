//This program converts string to spongebob meme format
#include<string>
#include<iostream>
using namespace std;

int main() {
	string s1;
	getline(cin,s1);
	int size = s1.size();
	bool even = false;
	string output;
	for (char c : s1) {
		if (c >= 'a' && c <= 'z') {
			if (even) {
				output.push_back(tolower(c));
				even = false;
			}
			else {
				output.push_back(toupper(c));
				even = true;
			}
		}
		else {
			output.push_back(c);
		}
	}
	cout << output;
	return 0;
}