#include <stdc++.h>

using namespace std;

int dh[6] = { 0, 0, 0, 0, 1, -1 };
int dn[6] = { 1, 0, -1, 0, 0, 0 };
int dm[6] = { 0, 1, 0, -1, 0, 0 };

int board[102][102][102];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);


	queue<tuple<int, int, int> > Q;

	int m, n, h;
	cin >> m >> n >> h;


	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) {
					Q.push({ i, j, k });
				}
			}
		}
	}


	while (!Q.empty()) {
		tuple<int, int, int> cur = Q.front(); Q.pop();

		int cur_h = get<0>(cur);
		int cur_n = get<1>(cur);
		int cur_m = get<2>(cur);


		int day = board[cur_h][cur_n][cur_m];

		for (int dir = 0; dir < 6; dir++) {
			int nh = cur_h + dh[dir];
			int nn = cur_n + dn[dir];
			int nm = cur_m + dm[dir];
			if (nh < 0 || nh >= h || nn < 0 || nn >= n || nm < 0 || nm >= m) {
				continue;
			}


			if (board[nh][nn][nm] == 0) {
				board[nh][nn][nm] = day + 1; // ÀÍ´Â µ¥ °É¸° ½Ã°£ ±â·Ï
				Q.push({ nh, nn, nm });
			}
		}
	}


	int max_day = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (board[i][j][k] == 0) {
					cout << -1 << "\n";
					return 0;
				}

				if (board[i][j][k] > max_day) {
					max_day = board[i][j][k];
				}
			}
		}
	}

	cout << max_day - 1 << "\n";

	return 0;
}
