#include <bits/stdc++.h>
using namespace std;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[7] = { 0 };
	int b[7] = { 0 };

	int n;
	cin >> n;
	int n1;
	cin >> n1;

	for (int i = 0; i < n; i++) {
		int temp;
		int temp1;
		cin >> temp >> temp1;
		if (temp) {
			a[temp1]++;//여자학년
		}
		else {
			b[temp1]++;//남자학년
		}
	}
	int res = 0;
	for (int i = 1; i <= 6; i++) {
		if (a[i]) {
			
			if (a[i] > n1 && a[i] % n1) {
				res += ((a[i] / n1) + 1);
			}
			else if (a[i] > n1 && (a[i] % n1 == 0)) {
				res += (a[i] / n1);
			}
			else {
				res++;
			}
			
		}
		if (b[i]) {
			if (b[i] > n1 && b[i] % n1) {
				res += ((b[i] / n1) + 1);
			}
			else if (b[i] > n1 && (b[i] % n1 == 0)) {
				res += (b[i] / n1);
			}
			else {
				res++;
			}
			
		}
	}
	cout << res;

	return 0;
}