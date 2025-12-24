#include <stdc++.h>
using namespace std;

vector<bool> state(1000001, true);
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
	int m, n;
	cin >> m;
	while (m--) {
		int cnt = 0;
		cin >> n;
		sieve(n);
		for (int i = 2; i <= n / 2; i++) {
			
			if (state[i] && state[n - i]) { 
				cnt++;
			
			}
			
		}
		cout << cnt << '\n';
	}
	return 0;
}
