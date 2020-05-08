#include <iostream>

using namespace std;

struct activity {
	int start;
	int end;
}

void activitySelect(vector<activity> v) {
	int i = 0;
	cout << v[i].start << ", " << v.[i].end << endl;

	for (int j = 1; j < v.size(); ++j) {
		if (v[j].start >= v[j].end) {
			cout << v[j].start << ", " << v[j].end << endl;
			i = j;
		}
	}
}

int main() {
	
	return 0;
}