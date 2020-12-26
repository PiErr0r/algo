#include "../std_lib_facilities.h"


vector<int> sort_insertion(vector<int> v, int r) {
	if (r == 0) {
		vector<int> ret = {v[r]};
		return ret;
	}
	vector<int> tmp = sort_insertion(v, r - 1);
	tmp.push_back(-1);
	int key = v[r];
	cout << key << " " << tmp[0] << '\n';
	int i = r;
	while (i >= 0) {
		if (key > tmp[i]) {
			tmp[i] = key;
			return tmp;
		} else {
			tmp[i + 1] = tmp[i];
		}
		--i;
	}
	return tmp;
}

int main() {
	vector<int> a = {1, 43, 53, 6, 2, 6, 3, 574, 7, 2, 4, 32};
	vector<int> b = {3, 45, 4, 56, 23, 4, 123, 5, 76, 7, 567};
	vector<int> c = {6, 5, 4, 3, 2, 1};
	vector<int> d = {5, 5, 5, 5, 5, 5, 5, 5};

	vector<vector<int>> tmp = {a, b, c, d};
	for (vector<int> i : tmp) {
		i = sort_insertion(i, i.size() - 1);
		for (int j: i) {
			cout << j << ' ';
		}
		cout << '\n';
	}

	return 0;
}