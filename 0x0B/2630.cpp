#include <stdc++.h>
using namespace std;

int board[130][130];
int res = 0;
void func(int n, int r, int c, int size) {

	int flag = 0;
	if (size == 1) {
		if (board[r][c] == n) res++;
		return;
	}
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			if (board[i][j] != n) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			break;
		}
	}

	if (flag == 0) {
		res++;
		return;
	}
	else {
		int size1 = size / 2;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				func(n, r + i * size1, c + j * size1, size1);
			}
		}
	}


}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	func(0, 0, 0, n);
	cout << res << '\n';
	res = 0;
	func(1, 0, 0, n);
	cout << res ;
	return 0;
}
