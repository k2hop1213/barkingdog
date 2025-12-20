#include <stdc++.h>
using namespace std;
long long dp[100001][3];
const long long INF = 1e15;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int k = 1;
	while (1) {
		int n;
		cin >> n;
		if (n == 0)break;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> dp[i][j];
			}
		}


		dp[0][0] = INF; 
		dp[0][2] += dp[0][1]; 


		for (int i = 1; i < n; i++) {
			dp[i][0] += min(dp[i - 1][0], dp[i - 1][1]);

			dp[i][1] += min({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i][0] });

			dp[i][2] += min({ dp[i - 1][1], dp[i - 1][2], dp[i][1] });
		}


		cout << k++ << ". " << dp[n - 1][1] << "\n";
	}
		


	
	return 0;
}
