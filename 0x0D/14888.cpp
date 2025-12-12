#include <stdc++.h>
using namespace std;

int n;
int num[12];
int num1[12];
bool isused[12];
int res1 = INT_MIN;
int res2 = INT_MAX;
string s(10, ' ');
string s1(10, ' ');
void func(int k) {
	char last_val = 0;
	if (k == n - 1) {
		int res = num[0];
		for (int i = 0; i < n - 1; i++) {
			if (s1[i] == '+') {
				res += num[i + 1];
			}
			if (s1[i] == '-') {
				res -= num[i + 1];
			}
			if (s1[i] == '*') {
				res *= num[i + 1];
			}
			if (s1[i] == '/') {
				
				res /= num[i + 1];
			}
		}
		res2 = min(res2, res);
		res1 = max(res1, res);
		return;
	}
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == last_val) continue;
		if (!isused[i]) {
			s1[k] = s[i];
			isused[i] = 1;
			last_val = s[i];
			func(k + 1);
			isused[i] = 0;
		}
	}

}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	int idx = 0;
	for (int i = 0; i < 4; i++) {
		cin >> num1[i];
		for (int j = 0; j < num1[i]; j++) {
			if (i == 0) {
				s[idx++] = '+';
			}
			if (i == 1) {
				s[idx++] = '-';
			}
			if (i == 2) {
				s[idx++] = '*';
			}
			if (i == 3) {
				s[idx++] = '/';
			}
		}
	}


	func(0);
	cout << res1 << '\n' << res2;
	return 0;
}
