//This program determines if one string is a permutation of the other

//should ask if case sensitivity is present and if whitespace is relevant
#include <iostream>
#include<string>
#include<unordered_map>
#include<iterator>
using namespace std;

bool isPerm(string input1,string input2) {
	int size1 = input1.size();
	int size2 = input2.size();
	if (size1 != size2) {//if sizes are not equal then the two strings cant be permutations
		cout << "Not even the same size\n";
		return false;
	}
	//hash maps are keys with corresponding values, we runt through the first string and record 
	//all characters before moving on to the second string
	//if any character is not found or the set data is exhausted, we can return false
	unordered_map<char, int> umap;//key of char, int gets incremented
	for (int i = 0; i < size1; i++) {
		umap[input1[i]]++;
	}
	unordered_map<char, int>::iterator itr;
	for (int j = 0; j < size2; j++) {
		itr = umap.find(input2[j]);
		if (itr == umap.end()) {
			return false;
		}
		umap[input2[j]]--;
		if (umap[input2[j]] == 0) {
			umap.erase(input2[j]);
		}
	}
	return true;
}

int main() {
	string input1,input2;
	while (true) {
		cout << "Enter first input\n";
		cin >> input1;
		cout << "Enter second input\n";
		cin >> input2;
		if (isPerm(input1,input2)) {
			cout << input1 << " and " <<input2<<" are permutations" << endl;
		}
		else {
			cout << input1 << " and " << input2 << " are not permutations" << endl;
		}
		cout << endl;
	}
}