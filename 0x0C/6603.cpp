#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[15];
int num[15];
bool isused[15];
void func(int k) {
	if (k == 6) {
		for (int i = 1; i < 6; i++) {
			if (arr[i] < arr[i - 1]) {
				return;
			}
		}
		for (int i = 0; i < 6; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!isused[i]) {
			arr[k] = num[i];
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0;
		}
	}

}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);


	while (1) {
		cin >> n;
		if (n == 0) return 0;
		fill(num, num + 15, -1);
		fill(isused, isused + 15, 0);
		for (int i = 1; i <= n; i++) {
			cin >> num[i];
		}
		func(0);
		cout << '\n';
	}

	return 0;
}
