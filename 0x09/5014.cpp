#include <stdc++.h>
using namespace std;
int dis[1000002];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	fill(&dis[0], &dis[0] + 1000002, -1);
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	dis[s] = 0;
	int dx[2] = { u,-d };
	queue<int> Q;
	Q.push(s);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (int i = 0; i < 2; i++) {
			int temp = cur + dx[i];
			if (temp<1 || temp>f) continue;
			if (dis[temp] != -1)continue;
			dis[temp] = dis[cur] + 1;
			Q.push(temp);
		}

	}



	if (dis[g] == -1) cout << "use the stairs";
	else cout << dis[g];

	return 0;
}
