#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v) {
	for(auto item : v) {
		cout << item << ' ';
	}
	cout << endl;
}

int memRodCutHelper(vector<int> v, int sz,  vector<int> opt) {
	// print(opt);
	// desired value to compute 
	int value = 0;
	// base case 
	if (opt[sz] > 0) {
		return opt[sz];
	}

	if (sz == 0) {
		return value;
	} else {
		value = -1;
		int i;
		for (i = 0; i < sz; ++i) {
			value = max(value, v[i] + memRodCutHelper(v, sz - i - 1, opt));
		}
		opt[i] = value;
	}
	
	return opt[sz];
}

int memRodCut(vector<int> v) {
	vector<int> opt(v.size() + 1);
	for( int i = 0; i < v.size(); ++i) {
		opt[i] = -1;
	}

	return memRodCutHelper(v, v.size(), opt);
}

int main() {
	vector<int> v = {1, 5, 8, 9, 10, 17, 17, 20};
	cout << memRodCut(v) << endl;
	return 0;
}

