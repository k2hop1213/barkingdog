#include <bits/stdc++.h>
using namespace std;

long long arr[100001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int cnt = 0;
	long long mxval = LLONG_MIN;
	int mxcnt = 0;

	for (int i = 0; i < n ; i++) {
		if (i == 0 || arr[i - 1] == arr[i])cnt++;
		else {
			if (cnt > mxcnt) {
				mxcnt = cnt;
				mxval = arr[i - 1];
			}
			cnt = 1;
		}
		

	}
	if (cnt > mxcnt)mxval = arr[n - 1];
	cout << mxval;

	return 0;
}
