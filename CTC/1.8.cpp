//This program looks for 0s in a matrix and sets its respective row and column to 0
#include<unordered_set>
#include<iostream>
#include<vector>

using namespace std;

void print(vector<vector<int>>& vec) {
	cout << endl;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[0].size();j ++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
}

void setZero(vector<vector<int>>& vec) {
	unordered_set<int> row, col;
	row.clear();
	col.clear();
	int r = vec.size();
	int c = vec[0].size();
	if (r == 0 || c == 0) {
		return;
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (vec[i][j] == 0) {
				row.insert(i);
				col.insert(j);
			}
		}
	}
	for (auto k:row) {
		for (int i = 0; i < c; i++) {
			vec[k][i] = 0;
		}
	}
	for (auto l : col) {
		for (int i = 0; i < c; i++) {
			vec[i][l] = 0;
		}
	}
}

int main() {
	vector<vector<int>> vec;
	vec.push_back({ 1,1,1,0,1 });
	vec.push_back({ 1,1,1,1,1 });
	vec.push_back({ 1,0,1,1,1 });
	vec.push_back({ 1,1,1,1,1 });
	vec.push_back({ 1,1,1,1,1 });
	print(vec);
	setZero(vec);
	print(vec);

	return 0;
}