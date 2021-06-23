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

	if (a == b || c == d)
		cout << 0;
	else
		cout << 1;
}

/*
ccw 알고리즘을 이용해 한 선분을 기준으로 외적의 부호가 +, -인지 판별해 선분이 겹치는지 겹치지 않는지 판단하는 문제입니다.
*/
