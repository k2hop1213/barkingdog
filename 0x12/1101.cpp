#include <stdc++.h>
using namespace std;

vector<bool> state(10000001, true);
void sieve(int n) {
	state[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (!state[i]) continue;
		for (int j = i * i; j <= n; j += i)
			state[j] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long A, B;
	cin >> A >> B;

	sieve(10000000);
	long long cnt = 0;
	for (int i = 2; i <= 10000000; i++) {
		if (state[i]) {
			long long temp = i;
			int a = 1;
			while ((double)i <= (double)B / temp) {
				if ((double)i >= (double)A / temp) {
					cnt++;
				}
				temp *= i;
			}

		}

	}
	cout << cnt;
	return 0;
}
