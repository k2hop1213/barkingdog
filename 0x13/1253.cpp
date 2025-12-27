
#include <stdc++.h>
using namespace std;

vector<long long> arr;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	if (n == 2) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		long long t;
		cin >> t;
		arr.push_back(t);
	}


	sort(arr.begin(), arr.end());
	if (arr.size() == 2) {
		cout << 0;
		return 0;
	}
	int cnt = 0;
	for (int i = 0; i < arr.size(); i++) {
		int left = 0;
		int right = arr.size() - 1;

		while (left < right) {
			if (left == i) {
				left++;
				continue;
			}
			if (right == i) {
				right--;
				continue;
			}
			long long sum = arr[left] + arr[right];
			if (sum < arr[i]) {
				left++;
			}
			else if (sum > arr[i]) {
				right--;
			}
			else {
				cnt++;
				break;
			}
		}


	}

	cout << cnt;
	
	return 0;
}
