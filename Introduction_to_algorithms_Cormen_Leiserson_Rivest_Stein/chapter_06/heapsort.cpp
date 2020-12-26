// #include "heapsort.h"
#include "../std_lib_facilities.h"
// #include <math.h>       /* log */

#define LEFT(x) ((x + 1) << 1 - 1)
#define RIGHT(x) (((x + 1) << 1) | 1 - 1) 
#define PARENT(x) ((x - 1) >> 1)

int log_b(double x, double base) {
	return log(x) / log(base);
}

void operator<< (ostream& os, const vector<int>& v) {
	int size = log_b(v.size(), 2);
	int curr = 1;
	int j = 0;

	for (int i = 1; i <= v.size(); ++i) {
		const int tmp = pow(2, size + 1);
		os << setw(tmp) << v[i - 1] << setw(tmp) << "";

		if (i == curr) {
			curr += curr + 1;
			os << '\n';
			--size;
		}
	}
	os << '\n';
}

void max_heapify(vector<int>& A, int i, int size) {
	int l = LEFT(i);
	int r = RIGHT(i);
	int largest = -1;

	if (l < size && A[l] > A[i])
		largest = l;
	else
		largest = i;

	if (r < size && A[r] > A[largest])
		largest = r;

	if (largest != i) {
		swap(A[i], A[largest]);
		max_heapify(A, largest, size);
	}
}

void build_max_heap (vector<int>& v) {
	int size = v.size();
	for (int i = size / 2; i >= 0; --i) 
		max_heapify(v, i, v.size());
}

void heapsort(vector<int>& A) {
	build_max_heap(A);
	int size = A.size();
	for (int i = A.size() - 1; i >= 1; --i) {
		swap(A[0], A[i]);
		--size;
		max_heapify(A, 0, size);
	}
}

int heap_maximum(vector<int>& v) {
	return v[0];
}

int heap_extract_max(vector<int>& v) {
	int max = v[0];
	v[0] = v[ v.size() - 1 ];
	v.pop_back();
	max_heapify(v, 0, v.size() - 1);
	return max;
}

void heap_inc_key(vector<int>& v, int i, int key) {
	if (key < v[i]) {
		error("Key musst not be smaller that element!");
	}

	v[i] = key;

	if (i == 0) {
		return;
	}

	while (i > 0 && v[i] > v[ PARENT(i) ]) {
		swap(v[i], v[ PARENT(i) ]);
		i = PARENT(i);
	}
}

void max_heap_insert(vector<int>& v, int key) {
	v.push_back(-1);
	heap_inc_key(v, v.size() - 1, key);
}

void heap_delete(vector<int>& v, int i) {
	swap(v[i], v[ v.size() - 1 ]);
	v.pop_back();
	max_heapify(v, i, v.size() - 1);
}

int main() {
	vector<int> v {34, 234, 1, 23, 5, 13, 2, 25, 7, 17, 20, 8, 4, 19};
	vector<int> v2 {15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1};
	build_max_heap(v);
	cout << v;
	heap_delete(v, 4);
	cout << v;

	return 0;
}