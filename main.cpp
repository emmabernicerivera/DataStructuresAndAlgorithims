#include <iostream>
#include <vector>

using namespace std;

int minThree(int a, int b, int c) {
	return min(min(a,b),c);
}

vector<vector<int> > init(int m, int n) {
	vector<vector<int> > table;
	for (int i = 0; i < n + 1; ++i) {
		vector<int> row(m + 1);
		table.push_back(row);
	}
	for (int i = 0; i < m + 1; ++i) {
		table[0][i] = i;
	}
	for (int i = 0; i < n + 1; ++i) {
		table[i][0] = i;
	}
	return table;
}

int editDistance(string from, string to) {
	// table to store list of subproblems 
	vector<vector<int> > table = init(from.size(), to.size());

	// loops
	// rows
	for (int i = 1; i < to.size() + 1; ++i) {
		//columns
		// hello world :) 
		for (int j = 1; j < from.size() + 1; ++j) {
			// if the to[i - 1] == from[j - 1] you dont add any cost 
			if(to[i - 1] == from[j - 1]) {
				table[i][j] = table[i - 1][j - 1]; // the diagaonal before it 
			}
			// otherwise make an edit 
			// take min of all three edits
			else {
				table[i][j] = minThree(table[i][j - 1] + 1, table[i - 1][j] + 1, table[i - 1][j - 1] + 1);
			}
		}
	}

	// returns min amount of edits at last spot in table table[m][n]
	return table[to.size()][from.size()];
}

int main() {
	string str1 = "abcdef";
	string str2 = "azced";

	cout << "Min Edits: " << editDistance(str1, str2) << endl;;

	return 0;
}
