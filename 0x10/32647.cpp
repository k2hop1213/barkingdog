#include <stdc++.h>

using namespace std;

vector<long long> prime;

int isPrime(long long n) {
	if (n < 2) return 0;
	if (n != 2 && n % 2 == 0) return 0;
	if (n == 2) return 1;
	for (long long i = 3; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b, c;
	cin >> a >> b >> c;

	for (long long i = a; i <= b; i++) {
		if (isPrime(i)) prime.push_back(i);
	}

	map<long long, long long> dp;
	dp[0] = 1;

	for (long long p : prime) {
		map<long long, long long> next_dp = dp;
		for (auto const& i : dp) {
			long long next_sum = i.first + p;
			if (next_sum <= c) {
				next_dp[next_sum] += i.second;
			}
		}
		dp = next_dp;
	}

	cout << dp[c]; 

	return 0;
}
