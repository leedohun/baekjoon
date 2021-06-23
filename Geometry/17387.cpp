#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll temp = x1 * y2 + x2 * y3 + x3 * y1 - (y1 * x2 + y2 * x3 + y3 * x1);

	if (temp > 0) return 1;
	else if (temp < 0) return -1;
	else return 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	ll x1, y1, x2, y2;

	ll x3, y3, x4, y4;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	int a = ccw(x1, y1, x2, y2, x3, y3);
	int b = ccw(x1, y1, x2, y2, x4, y4);

	int c = ccw(x3, y3, x4, y4, x1, y1);
	int d = ccw(x3, y3, x4, y4, x2, y2);

	if (a != b && c != d) { //외적을 통해 부호가 서로 다른 지 비교
		cout << 1;
		return 0;
	}

  
// 세 점이 있는 경우 예외처리
	if (a == 0) {
		if ((x1 <= x3 && x3 <= x2) || (x2 <= x3 && x3 <= x1)) {
			if ((y1 <= y3 && y3 <= y2) || (y2 <= y3 && y3 <= y1)) {
				cout << 1;
				return 0;
			}
		}
	}

	if (b == 0) {
		if ((x1 <= x4 && x4 <= x2) || (x2 <= x4 && x4 <= x1)) {
			if ((y1 <= y4 && y4 <= y2) || (y2 <= y4 && y4 <= y1)) {
				cout << 1;
				return 0;
			}
		}
	}

	if (c == 0) {
		if ((x3 <= x1 && x1 <= x4) || (x4 <= x1 && x1 <= x3)) {
			if ((y3 <= y1 && y1 <= y4) || (y4 <= y1 && y1 <= y3)) {
				cout << 1;
				return 0;
			}
		}
	}

	if (d == 0) {
		if ((x3 <= x2 && x2 <= x4) || (x4 <= x2 && x2 <= x3)) {
			if ((y3 <= y2 && y2 <= y4) || (y4 <= y2 && y2 <= y3)) {
				cout << 1;
				return 0;
			}
		}
	}

	cout << 0;
	return 0;
}

/*
ccw의 알고리즘을 사용해 문제를 해결하면 됩니다. 가장 먼저 ccw를 통해서 기준 점을 잡고 한 점을 외적 한 다음 그 점의 부호를 비교하면 됩니다.
또한 3점이 일직선 상에 있을 경우에는 따로 예외 처리를 해주면 됩니다. (기준 점 사이에 비교하는 점 x, y 값이 있어야 됨)
*/
