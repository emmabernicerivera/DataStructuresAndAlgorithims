#include <iostream>
#include <vector>

using namespace std; 

int findkth(vector<int> v1, vector<int> v2, int sz1, int sz2, int end1, int end2, int k) {

	// base case 
	if(sz1 == end1) {
		return v1[k];
	}
	if (sz2 == end2) {
		return v2[k];
	}
	// find mid 
	int mid1 = v1.size() / 2; 
	int mid2 = v2.size() / 2; 
	//divide and conquer 
	if (mid1 + mid2 < k) {
		if (v1.at(mid1) > v2.at(mid2)) {

		} else {
			
		}
	} else {

	}
}

int main() {


	return 0;
}
