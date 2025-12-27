#include <stdc++.h>
using namespace std;

long long arr[100001];
vector<long long>v;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)cin >> arr[i];

	int left = 0;
	int right = n - 1;
	long long res = arr[left] + arr[right];
	int flag = 0;
	while (left < right) {
		long long sum = arr[left] + arr[right];
		v.push_back(sum);
		res = min(abs(res), abs(sum));

		if (sum < 0) {
			left++;
		}
		else if (sum > 0) {
			right--;
		}
		else { 
			res = 0;
			break; 
		}
	}

	for (auto a : v) {
		if (abs(a) == res) {
			cout << a;
			return 0;
		}
	}



	return 0;
}
