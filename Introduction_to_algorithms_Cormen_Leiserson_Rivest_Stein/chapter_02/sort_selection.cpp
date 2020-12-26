#include "../std_lib_facilities.h"

vector<int> sort_selection(vector<int> v, bool increase) {

	for (int curr_pos = 0; curr_pos < v.size(); ++curr_pos) {
		int min = curr_pos, max = curr_pos;
		for (int i = curr_pos; i < v.size(); ++i) {
			if (v[i] < v[min]) min = i;
			if (v[i] > v[max]) max = i;
		}
		int tmp = (increase ? v[min] : v[max]);
		if (increase) v[min] = v[curr_pos];
		else v[max] = v[curr_pos];
		v[curr_pos] = tmp;
	} 

	for (int el: v){
		cout << el<< " ";
	}
	cout << '\n';
	return v;
}

int main() {

	vector<int> a = {1, 43, 53, 6, 2, 6, 3, 574, 7, 2, 4, 32};
	vector<int> b = {3, 45, 4, 56, 23, 4, 123, 5, 76, 7, 567};
	vector<int> c = {6, 5, 4, 3, 2, 1};
	vector<int> d = {5, 5, 5, 5, 5, 5, 5, 5};

	sort_selection(a, false);
	sort_selection(b, false);
	sort_selection(c, false);
	sort_selection(d, false);

	sort_selection(a, true);
	sort_selection(b, true);
	sort_selection(c, true);
	sort_selection(d, true);


	return 0;
}