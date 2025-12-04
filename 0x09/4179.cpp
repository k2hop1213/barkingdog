#include <stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
string board[1002];
int fire[1002][1002];
int jihun[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int, int> > Q;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'F') {
				flag = 1;
				Q.push({ i,j });
			}
		}
	}
	if (flag) {
		while (!Q.empty()) {
			pair<int, int> cur = Q.front(); Q.pop();
			int t = fire[cur.X][cur.Y];
			for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
				if (fire[nx][ny] || board[nx][ny] == '#') continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
				fire[nx][ny] = t + 1; // (nx, ny)를 방문했다고 명시
				Q.push({ nx,ny });
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'J') {
				if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
					cout << 1;
					return 0;
				}
				Q.push({ i,j });
				break;
			}
		}
	}
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		int t = jihun[cur.X][cur.Y];
		for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
			if (jihun[nx][ny] || board[nx][ny] == '#' || board[nx][ny] == 'F') continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
			jihun[nx][ny] = t + 1; // (nx, ny)를 방문했다고 명시
			Q.push({ nx,ny });
		}
	}
	int res = n * m;
	if (flag) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == '#') continue;
				if (fire[i][j] && fire[i][j] <= jihun[i][j]) {
					jihun[i][j] = 0;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (jihun[i][j] == 0) continue;
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
				res = min(res, jihun[i][j]);
			}

		}
	}
	if (res != m * n)cout << res + 1;
	else cout << "IMPOSSIBLE";
}
