#include <stdc++.h>
using namespace std;

pair<long long, long long>arr[100001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i].second;
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
	}
	sort(arr, arr + n);

	long long res = 0;
	for (int i = 0; i < n; i++) {
		res += arr[i].second;
		res += (i) * arr[i].first;
	}
	cout << res;

	return 0;
}
