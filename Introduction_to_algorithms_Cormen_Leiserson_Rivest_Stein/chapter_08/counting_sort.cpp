#include "../std_lib_facilities.h"

void operator<<(ostream& os, vector<int> v) {
	for (int i : v) 
		os << i << " ";
	os << '\n';
}

void counting_sort(vector<int>& a, vector<int>& b, int k) {
	vector<int> c (k + 1, 0);
	for (int i : a) 
		++c[i];
	for (int i = 1; i <= k; ++i)
		c[i] += c[i - 1];
	for (int i = a.size() - 1; i >= 0; --i) {
		b[c[a[i]] - 1] = a[i];
		--c[a[i]];
	}
}

int main() {
	vector<int> a {2, 5, 3, 0, 2, 3, 0, 3};
	vector<int> b (a.size(), 0);
	int k = 5;
	counting_sort(a, b, k);
	cout << a;
	cout << b;
	return 0;
}