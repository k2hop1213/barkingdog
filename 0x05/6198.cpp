#include <stdc++.h>
using namespace std;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<long long> a;
	stack<long long> a1;
	stack<long long> a2;


	int n;
	cin >> n;
	long long max = 0;
	for (int i = 0; i < n; i++) {
		long long temp;
		cin >> temp;
		a2.push(temp);
	}
	long long res = 0;
	for (int i = 1; i <= n; i++) {
		long long temp = a2.top();
		a2.pop();
		if (i == 1) { // 초기값 설정, 맨 앞 건물은 아무것도 봇봄
			max = temp;

		}
		else {
			if (max >= temp) {
				if (a.top() >= temp) { // 바로 앞에 있는게 클때는 아무것도 볼 수  없음

				}
				else {
					while (a.top() < temp) {
						a.pop();
						a1.pop();
					}
					res += (i - a1.top() - 1); //현재 건물과 현재건물보다 큰 건물 사이에 몇개가 있는지
				}


			}
			else { // 현재 수가 최댓값이면 앞에 있는 모든 건물을 볼 수 있음
				res += (i - 1);
				max = temp;
			}
		}
		a.push(temp);
		a1.push(i);
	}


	cout << res;

	return 0;
}
