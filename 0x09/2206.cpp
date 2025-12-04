#include <stdc++.h>
using namespace std;
string board[1001];
int dis[1001][1001][2];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	fill(&dis[0][0][0], &dis[0][0][0] + 1001 * 1001 * 2, -1);

	queue<tuple<int, int, int>>Q;

	Q.push({ 0,0,0 });
	dis[0][0][0] = 1;
	int cnt = 0;
	while (!Q.empty()) {
		tuple<int, int, int>cur = Q.front(); Q.pop();
		int cur_x = get<0>(cur);
		int cur_y = get<1>(cur);
		int cur_z = get<2>(cur);
		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (board[nx][ny] == '0') {
				if (dis[nx][ny][cur_z] == -1) {
					dis[nx][ny][cur_z] = dis[cur_x][cur_y][cur_z] + 1;
					Q.push({ nx,ny,cur_z });
				}
			}
			else if (board[nx][ny] == '1') {
				if (cur_z == 0) {
					int next_z = 1;

					dis[nx][ny][next_z] = dis[cur_x][cur_y][cur_z] + 1;
					Q.push({ nx, ny, next_z });

				}

			}

		}
	}

	int result_k = dis[n - 1][m - 1][0];
	int result_k1 = dis[n - 1][m - 1][1];

	int final_result = -1;

	if (result_k != -1 && result_k1 != -1) {
		final_result = min(result_k, result_k1);
	}
	else if (result_k != -1) {
		final_result = result_k;
	}
	else if (result_k1 != -1) {
		final_result = result_k1;
	}


	cout << final_result;
	return 0;
}
