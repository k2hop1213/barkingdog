#include <stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[302][302]; // 1이 파란 칸, 0이 빨간 칸에 대응
int dx[8] = { 1,1,2,2,-1,-1,-2,-2 };
int dy[8] = { 2,-2,1,-1,2,-2,1,-1 }; // 상하좌우 네 방향을 의미
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		queue<pair<int, int> > Q;

		fill(&board[0][0], &board[0][0] + 302 * 302, -1);
		int a;
		cin >> a;
		int v1, v2;
		cin >> v1 >> v2;
		Q.push({ v1,v2 });
		board[v1][v2] = 0;
		int x, y;
		cin >> x >> y;
		while (board[x][y] == -1) {
			pair<int, int> cur = Q.front(); Q.pop();
			int dis = board[cur.X][cur.Y];
			for (int dir = 0; dir < 8; dir++) { // 상하좌우 칸을 살펴볼 것이다.
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
				if (nx < 0 || nx >= a || ny < 0 || ny >= a) continue; // 범위 밖일 경우 넘어감
				if (board[nx][ny] != -1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
				board[nx][ny] = dis + 1; // (nx, ny)를 방문했다고 명시
				Q.push({ nx,ny });
			}
		}
		cout << board[x][y] << "\n";
	}
}
