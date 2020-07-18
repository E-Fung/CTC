//This program replaces the whitespace between characters with %20
#include<string>
#include<iostream>
using namespace std;

void URLify(string& input,int true_len) {
	for (int i = 0; i < true_len; i++) {
		cout << "Now inspecting " << input[i] << endl;
		if (input[i] == ' ') {
			input.erase(input.begin() + i);
			input.insert(input.begin() + i, '0');
			input.insert(input.begin() + i, '2');
			input.insert(input.begin() + i, '%');
			i += 2;
			true_len += 2;
		}
	}
	while (input.size() != true_len) {
		input.pop_back();
	}
}

int main() {
	string input = "Mr John Smith   ";
	int len = 13;
	URLify(input, len);
	cout <<endl<< input << "|||"<<endl;
}
