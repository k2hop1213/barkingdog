#include <stdc++.h>
using namespace std;
int arr[101];
int main() {



	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	vector<int>a(n);

	int idx1 = 0;
	int idx2 = 0;
	while (idx1 < n && idx2 < m) {
		bool exists = false;
		for (int i = 0; i < idx1; i++) {
			if (a[i] == arr[idx2]) {
				exists = true;
				break;
			}
		}

		if (exists) {
			idx2++;
		}
		else {
			a[idx1] = arr[idx2];
			idx1++;
			idx2++;
		}

	}
	int res = 0;
	
	for (int i = idx2; i < m; i++) {
		bool exists = false;
		for (int j = 0; j < n; j++) {
			if (a[j] == arr[i]) {
				exists = true;
				break;
			}
		}
		if (exists) {

		}
		else {
			int temp = -1;
			int idx = 0;
			for (int k = 0; k < n; k++) {
				int next = 101;
				for (int l = i + 1; l < m; l++) {
					if (a[k] == arr[l]) {
						next = l;
						break;
					}
				}
				if (next > temp) { // 가장 나중에 나타나는 놈 선택
					temp = next;
					idx = k;
				}
			}
			a[idx] = arr[i];
			res++;
		}
	}
		
	

	cout << res;
	return 0;
}
