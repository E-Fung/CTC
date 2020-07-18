//this program compresses strings with the assumption that upper and lowercases are not distinct
#include<string>
#include<iostream>

using namespace std;

string compress(string input) {
	string output;
	output.clear();
	int size = input.size();
	if (size <= 2) {
		return input;
	}
	input.push_back('0');

	char temp = input[0];
	int counter = 1;
	for (int i = 1; i < size+1; i++) {
		if (temp != input[i]) {
			output.push_back(temp);
			output.push_back(48 + counter % 10);
			temp = input[i];
			while (counter >= 10) {
				counter /= 10;
				output.insert(output.end()-1, 48+counter % 10);
			}
			counter = 1;
		}
		else {
			counter++;
		}
	}


	if (output.size() > size) {
		return input;
	}
	return output;
}

int main() {
	string input = "aabcccccaaa";
	while (true) {
		cout << input << "|" << compress(input) << "|"<<endl;
		cin >> input;
	}
	return 0;
}