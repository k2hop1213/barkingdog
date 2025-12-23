#include <stdc++.h>
using namespace std;

struct Date {
	int start, end;
};



bool compare(Date a, Date b) {
	if (a.start != b.start) return a.start < b.start;
	return a.end > b.end; 
}

Date arr[100001];
/*
날짜 순으로 정렬
처음 고르는 꽃은 피는 날짜와 지는 날짜 사이에 3/1 이 있어야함
다음에 고르는 꽃들은 그 전 꽃이 지는 날짜전에 펴야함
마지막 꽃은 피는 날짜와 지는 날짜 사이에 11/30 이 있어야함
*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int sm, sd, em, ed;
		cin >> sm >> sd >> em >> ed;
		arr[i].start = 100 * sm + sd;
		arr[i].end = 100 * em + ed;
	}

	sort(arr, arr + n, compare);

	int cur_end = 301; 
	int max_end = 0;       
	int cnt = 0;
	int idx = 0;

	while (cur_end <= 1130) {
		bool flag = false;
		max_end = 0;
		for (int i = idx; i < n; i++) {
			if (arr[i].start > cur_end) break; 

			if (arr[i].end > max_end) {
				max_end = arr[i].end;
				idx = i + 1; 
				flag = true;
			}
		}

		if (flag) {
			cnt++;
			cur_end = max_end;
		}
		else {
			cout << 0;
			return 0;
		}
	}

	cout << cnt;

	return 0;
}
