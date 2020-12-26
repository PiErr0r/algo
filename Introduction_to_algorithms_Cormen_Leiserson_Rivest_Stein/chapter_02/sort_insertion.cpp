#include "../std_lib_facilities.h"


// add & after vector<int> if you want for fnc to mutate the vector
void sort_insertion(vector<int>& v, bool increase) {
	for (int j = 1; j < v.size(); j++) {
		int key = v[j];
		int i = j - 1;
		if (increase) {
			while (i >=0 && v[i] > key){
				v[i + 1] = v[i];
				--i;
			}
		} else {
			while (i >=0 && v[i] < key){
				v[i + 1] = v[i];
				--i;
			}
		}
		v[i + 1] = key;
	}
	for (int el: v){
		cout << el<< " ";
	}
	cout << '\n';
}

int main() {
	vector<int> a = {1, 43, 53, 6, 2, 6, 3, 574, 7, 2, 4, 32};
	vector<int> b = {3, 45, 4, 56, 23, 4, 123, 5, 76, 7, 567};
	vector<int> c = {6, 5, 4, 3, 2, 1};
	vector<int> d = {5, 5, 5, 5, 5, 5, 5, 5};

	sort_insertion(a, false);
	sort_insertion(b, false);
	sort_insertion(c, false);
	sort_insertion(d, false);

	sort_insertion(a, true);
	sort_insertion(b, true);
	sort_insertion(c, true);
	sort_insertion(d, true);

	return 0;
}