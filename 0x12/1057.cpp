#include <stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int x, y;
	cin >> x >> y;

	int cnt = 0;
	while (x > 0 && y > 0) {
		x = (x + 1) / 2;
		y = (y + 1) / 2;
		cnt++;
		if (x == y) {
			break;
		}

	}

	cout << cnt;



	return 0;
}
