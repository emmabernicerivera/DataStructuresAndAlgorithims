#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lis(vector<int> A, int n) {
  if (n == 0) {
    return 1;
  }

  int maximum = 1;
  for (int i = 0; i < n; ++i) {
    int longestSoFar = lis(A, i);
    if (A[i] < A[n]) {
      maximum = max(maximum, 1 + longestSoFar);
    }
  }

  return maximum;
}

int main(int argc, char const *argv[]) {
  // int maximum = 0;
  vector<int> A = {10, 22, 9, 33, 21, 50, 41, 60, 80};

  cout << lis(A, A.size() - 1) << endl;

  return 0;
}