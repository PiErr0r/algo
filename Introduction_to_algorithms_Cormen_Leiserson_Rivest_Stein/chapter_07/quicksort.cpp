#include "../std_lib_facilities.h"

void operator<< (ostream& os, const vector<int>& v) {
	for (int i : v)
		os << i << " ";
	os << '\n';
}

int partition(vector<int>& v, int p, int r) {
	int x = v[r];
	int i = p - 1;
	bool all_same = true;
	for (int j = p; j < r; ++j) {
		if (v[j] != v[j + 1])
			all_same = false;
		if (v[j] < x) {
			++i;
			swap( v[i], v[j] );
		}
	}
	swap( v[i + 1], v[r] );
	return all_same ? (p + r) / 2 : (i + 1);
}

void quicksort(vector<int>& v, int p, int r) {
	int q = partition(v, p, r);
	cout << q << '\n';
	if (p < q) 
		quicksort(v, p, q - 1);
	if (q + 1 < r)
		quicksort(v, q + 1, r);
}

int main() {
	// vector<int> v {13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};
	vector<int> v {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
	quicksort(v, 0, v.size() - 1);
	cout << v;
	return 0;
}