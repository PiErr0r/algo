#include "../std_lib_facilities.h"

vector<int> binary_addition(vector<int> a, vector<int> b) {
	int carry = 0;
	vector<int> c;
	for (int i = a.size() - 1; i >= 0; --i) {
		int tmp = a[i] + b[i] + carry;
		carry = (tmp & 2 ? 1 : 0);
		tmp = (tmp & 1 ? 1 : 0);
		c.push_back(tmp);
	}
	if (carry) c.push_back(carry);
	return c;
}

int main() {

	vector<int> a = {1, 0, 0, 1, 1, 1, 1, 1};
	vector<int> b = {1, 0, 1, 1, 1, 1, 1, 1};
	vector<int> c;

	c = binary_addition(a, b);
	for(int i = c.size() - 1; i >= 0; --i) cout << c[i];
	cout << '\n';
	return 0;
}