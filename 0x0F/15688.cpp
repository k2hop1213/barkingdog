#include <bits/stdc++.h>
using namespace std;

int cnt[2000001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		cnt[temp + 1000000]++;
	}


	for (int i = 0; i <= 2000000; i++) {
		if (cnt[i]) {
			for (int j = 0; j < cnt[i]; j++) {
				cout << i - 1000000 << '\n';
			}
		}
	}

	return 0;
}
