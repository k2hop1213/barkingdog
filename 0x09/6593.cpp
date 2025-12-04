#include <stdc++.h>
using namespace std;

string board[31][31];
int dis[31][31][31];
int dx[6] = { 1,0,0,-1,0,0 };
int dy[6] = { 0,1,0,0,-1,0 };
int dz[6] = { 0,0,1,0,0,-1 };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) {
			break;
		}
		fill(&dis[0][0][0], &dis[0][0][0] + 31 * 31 * 31, -1);
		queue<tuple<int, int, int>>Q;
		int flag = 0;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				cin >> board[i][j];
				if (flag == 0) {
					for (int k = 0; k < c; k++) {
						if (board[i][j][k] == 'S') {
							Q.push({ i,j,k });
							dis[i][j][k] = 0;
							flag = 1;
						}
					}
				}
			}
		}
		int t = 0;
		while (!Q.empty()) {
			tuple<int, int, int> cur = Q.front(); Q.pop();
			int cur_x = get<0>(cur);
			int cur_y = get<1>(cur);
			int cur_z = get<2>(cur);
			for (int i = 0; i < 6; i++) {
				int nx = cur_x + dx[i];
				int ny = cur_y + dy[i];
				int nz = cur_z + dz[i];
				if (nx < 0 || nx >= a || ny < 0 || ny >= b || nz < 0 || nz >= c) {
					continue;
				}
				if (dis[nx][ny][nz] != -1 || board[nx][ny][nz] == '#')continue;
				dis[nx][ny][nz] = dis[cur_x][cur_y][cur_z] + 1;
				if (board[nx][ny][nz] == 'E') {
					cout << "Escaped in " << dis[nx][ny][nz] << " minute(s).\n";
					t = 1;
					while (!Q.empty()) Q.pop();
					goto end_loop; // 이중 루프 탈출을 위해 goto 사용 또는 플래그/함수 사용
				}
				Q.push({ nx,ny,nz });

			}
		}
	end_loop:;
		if (t == 0) {
			cout << "Trapped!\n";
		}

	}


	return 0;
}
