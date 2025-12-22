#include <stdc++.h>
using namespace std;

pair<int, int> lectures[200001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> lectures[i].first >> lectures[i].second;
	}

	sort(lectures, lectures + n);

	priority_queue<int, vector<int>, greater<int>> pq;

	pq.push(lectures[0].second);

	for (int i = 1; i < n; i++) {
		if (pq.top() <= lectures[i].first) {
			pq.pop(); 
		}
		pq.push(lectures[i].second);
	}

	cout << pq.size() ;

	return 0;
}
