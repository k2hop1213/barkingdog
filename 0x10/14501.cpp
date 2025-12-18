#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[15];
int dp[15];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = n - 1; i >= 0; i--) {
		int time = arr[i].first;
		int price = arr[i].second;

		if (i + time < n + 1) {
			dp[i] = max(dp[i + 1], price + dp[i + time]);
		}
		else {
			dp[i] = dp[i + 1];
		}
	}

	cout << dp[0];

	return 0;
}
