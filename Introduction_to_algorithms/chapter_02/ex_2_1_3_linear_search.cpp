#include "../std_lib_facilities.h"

int find_index(vector<int> v, int n) {
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == n) return i;
	}
	return -1;
}

int main() {
	vector<int> a = {31, 41, 59, 26, 41, 58};
	int n = 23;

	cout << find_index(a, n) << '\n';

	return 0;
}