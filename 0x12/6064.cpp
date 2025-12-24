#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--) {


		int x, y, x1, y1;

		cin >> x >> y >> x1 >> y1;
		int i = 0;
		int temp = 0;
		while (temp <= x * y) {
			temp = x * i + x1;
			i++;
			if (temp % y == y1 % y) {
				break;
			}
		}


		if (temp > x * y) {
			cout << -1 << '\n';
		}
		else cout << temp << '\n';

	}



	return 0;
}
