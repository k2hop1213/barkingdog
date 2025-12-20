#include <stdc++.h>
using namespace std;

int dp[1000001][2];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	if (n == 1) {
		cout << 0 << '\n' << 1;
		return 0;
	}
	dp[1][0] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + 1;
		dp[i][1] = i - 1;
		if (i % 2 == 0) {
			dp[i][0] = min(dp[i][0], dp[i / 2][0] + 1);
			if (dp[i][0] == dp[i / 2][0] + 1) dp[i][1] = i / 2;
		}
		if (i % 3 == 0) {
			dp[i][0] = min(dp[i][0], dp[i / 3][0] + 1);
			if (dp[i][0] == dp[i / 3][0] + 1) dp[i][1] = i / 3;
		}
	}
	cout << dp[n][0] << '\n';
	cout << n << ' ';
	int m = n;
	while (1) {
		int cur = dp[m][1];
		cout << cur << ' ';
		if (cur == 1) {
			break;
		}
		m = cur;
	}

	return 0;
}
