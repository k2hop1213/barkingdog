#include <stdc++.h>
using namespace std;

long long cnt[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n;
	cin >> n;

	for (int i = 1; i <= n; i*=10) {
		long long a = n / (i * 10);
		long long b = (n / i) % 10;
		long long c = n % i;
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				if (a > 0)
					cnt[j] += (a - 1) * i;
			}
			else cnt[j] += a * i;

			if (j < b) {
				if (!(j == 0 && a == 0)) 
					cnt[j] += i;
			}
			else if (j == b) {
				if (!(j == 0 && a == 0))
					cnt[j] += c + 1;
			}
		}

	}

	for (int i = 0; i < 10; i++)cout << cnt[i] << ' ';



	return 0;

}
