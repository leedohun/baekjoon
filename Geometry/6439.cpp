#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

struct P {
	ll x; ll y;
};

int CCW(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) { //외적을 통해 선분의 우측에 점이 있는지 좌측에 점이 있는지 판단
	ll temp = x1 * y2 + x2 * y3 + x3 * y1
		- (y1 * x2 + y2 * x3 + y3 * x1);

	if (temp > 0) return 1;
	else if (temp < 0) return -1;
	else return 0;
}

bool ans(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
	if (CCW(x1, y1, x2, y2, x3, y3) * CCW(x1, y1, x2, y2, x4, y4) <= 0
		&& CCW(x3, y3, x4, y4, x1, y1) * CCW(x3, y3, x4, y4, x2, y2) <= 0) { //ccw 활용해 선분 교차 비교
    
    //선분과 점이 일직선 상에 있을 때 거리 비교
		if ((x1 < x3 && x1 < x4 && x2 < x3 && x2 < x4) ||
			(x3 < x1 && x3 < x2 && x4 < x1 && x4 < x2)) return false;
		if ((y1 < y3 && y1 < y4 && y2 < y3 && y2 < y4) ||
			(y3 < y1 && y3 < y2 && y4 < y1 && y4 < y2)) return false;
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		P l1, l2, r1, r2, r3, r4;

		cin >> l1.x >> l1.y >> l2.x >> l2.y; 
		
		ll tmpx1, tmpx2, tmpy1, tmpy2;
		cin >> tmpx1 >> tmpy1 >> tmpx2 >> tmpy2;
		
		r1 = { min(tmpx1, tmpx2), min(tmpy1, tmpy2) };
		r2 = { min(tmpx1, tmpx2), max(tmpy1, tmpy2) };
		r3 = { max(tmpx1, tmpx2), min(tmpy1, tmpy2) };
		r4 = { max(tmpx1, tmpx2), max(tmpy1, tmpy2) };

		if (ans(l1.x, l1.y, l2.x, l2.y, r1.x, r1.y, r2.x, r2.y) ||
			ans(l1.x, l1.y, l2.x, l2.y, r2.x, r2.y, r4.x, r4.y) ||
			ans(l1.x, l1.y, l2.x, l2.y, r4.x, r4.y, r3.x, r3.y) ||
			ans(l1.x, l1.y, l2.x, l2.y, r3.x, r3.y, r1.x, r1.y)) {
			cout << "T" << "\n";
		}
		else {
			if ((r1.x < l1.x && r1.x < l2.x && l1.x < r3.x && l2.x < r3.x) &&
				(r1.y < l1.y && r1.y < l2.y && l1.y < r4.y && l2.y < r4.y))
				cout << "T" << "\n";
			else
				cout << "F" << "\n";
		}
	}
}

/*
- xleft ytop xright ybottom 순으로 주어진댔는데 xleft > xright 도 가능.
- 선분의 두 점이 사각형 내부에 있을 때도 T (즉 내부가 채워진 사각형과의 교차여부 출력)
*/
