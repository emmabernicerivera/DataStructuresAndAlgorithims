#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void print(vector<vector<int>> m) {
	for (auto row : m) {
		for (auto element : row) {
			cout << element << ' ';
		}
		cout << endl;
	}

	cout << endl;
}

void init(vector<vector<int>>& m, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		vector<int> row(columns);
		m.push_back(row);
	}
}

pair<vector<vector<int>>, vector<vector<int>>> matrixMult(vector<int> p) {
	int sz = p.size();
	vector<vector<int>> m;
	init(m, sz, sz);
	vector<vector<int>> s;
	init(s, sz - 1, sz); 

	for (int i = 0; i < sz; ++i) {
		m[i][i] = 0;
	}

	for (int chainLength = 2; chainLength < sz; ++chainLength) {
		for (int i = 1; i < sz - chainLength + 1; ++i) {
			int j = i + chainLength - 1;
			m[i][j] = INT_MAX;
			cout << "i: " << i << " j: " << j << endl;
			for (int index = i; index < j - 1; ++index) {
				cout << "i dont make it in here" << endl;
				int q = m[i][index] + m[index + 1][j] + (p[i - 1]) * (p[index]) * (p[j]);
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = index;
				}
			}
		}
	}

	return make_pair(m, s);
}

int main() {
	vector<int> p = {40, 20, 30, 10, 30};

	auto result = matrixMult(p);

	cout << "m" << endl;
	print(result.first);

	cout << "s" << endl;
	print(result.second);
	
	return 0;
}