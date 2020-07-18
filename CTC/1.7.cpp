//This program rotates an N by N matrix by 90 degrees in place

#include<vector>
#include<iostream>
#include<string>

using namespace std;

void print(vector<vector<string>>& vec) {
	int size = vec.size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void rotate(vector<vector<string>>& vec) {
	int size = vec.size();
	string temp;
	for (int i = 0; i < size / 2; i++) {
		for (int j = i; j < size - i-1; j++) {//this code is ugly af
			temp = vec[i][i + j];
			vec[i][i + j] = vec[size - 1 - i - j][i];
			vec[size - 1 - i - j][i] = vec[size - 1 - i][size - 1 - i - j];
			vec[size - 1 - i][size - 1 - i - j] = vec[i+j][size - 1 - i];
			vec[j+i][size - 1 - i] = temp;
			print(vec);
		}
	}
}

int main() {
	vector<vector<string>> vec;
	vec.push_back({ "00","01","02","03","04" });
	vec.push_back({ "10","11","12","13","14" });
	vec.push_back({ "20","21","22","23","24" });
	vec.push_back({ "30","31","32","33","34" });
	vec.push_back({ "40","41","42","43","44" });


	print(vec);
	rotate(vec);
	//print(vec);
	string input;
	cin >> input;
	return 0;
}