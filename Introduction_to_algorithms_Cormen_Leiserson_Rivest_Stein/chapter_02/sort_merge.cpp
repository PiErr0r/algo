#include "../std_lib_facilities.h"

vector<int> merge(vector<int> L, vector<int> R) {
	int nL = L.size();
	int nR = R.size();
	if (nL == 0) return R;
	if (nR == 0) return L;

	int i = 0, j = 0;
	vector<int> ret;

	while (i + j < nL + nR) {
		if (i == nL) {
			while (j < nR) {
				ret.push_back(R[j]);
				++j;
			}
			return ret;
		}
		if (j == nR) {
			while (i < nL) {
				ret.push_back(L[i]);
				++i;
			}
			return ret;
		}
		if (L[i] < R[j]) {
			ret.push_back(L[i]);
			++i;	
		}
		else {
			ret.push_back(R[j]);
			++j;
		}
	}
	return ret;
}

vector<int> merge_sort(vector<int> A, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		vector<int> L = merge_sort(A, p, q);
		vector<int> R = merge_sort(A, q + 1, r);
		return merge(L, R);
	}
	vector<int> ret {A[p]};
	return ret;
}

int main() {
	vector<int> a = {1, 43, 53, 6, 2, 6, 3, 574, 7, 2, 4, 32};
	vector<int> b = {3, 45, 4, 56, 23, 4, 123, 5, 76, 7, 567};
	vector<int> c = {6, 5, 4, 3, 2, 1};
	vector<int> d = {5, 5, 5, 5, 5, 5, 5, 5};

	vector<vector<int>> tmp = {a, b, c, d};

	for (vector<int> i : tmp) {
		vector<int> asd = merge_sort(i, 0, i.size() - 1);
		for (int j : asd) {
			cout << j << " ";
		}
		cout << '\n';
	}

	return 0;
}