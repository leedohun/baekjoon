#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

struct P {
	ll x1; ll y1; ll x2; ll y2;
};

int root[3005] = { 0, };
int res[3005] = { false, };

int Find(int x) { //유니온 파인으로 선분의 그룹을 나눠 줍니다.
	if (x == root[x]) {
		return x;
	}
	else {
		int p = Find(root[x]);
		return root[x] = p;
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	root[y] = x;
}

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

	int N; cin >> N;
	vector <P> v;

	for (int i = 0; i <= N; i++) {
		root[i] = i;
	}

	for (int i = 0; i < N; i++) {
		ll tmpx1, tmpy1, tmpx2, tmpy2; cin >> tmpx1 >> tmpy1 >> tmpx2 >> tmpy2;

		v.push_back({ tmpx1, tmpy1, tmpx2, tmpy2 });
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (ans(v[i].x1, v[i].y1, v[i].x2, v[i].y2, v[j].x1, v[j].y1, v[j].x2, v[j].y2)) { //선분이 교차하면 Union Find
				Union(i + 1, j + 1);
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		res[Find(i)]++;
	}

	int M = 0, cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (res[i] > 0) cnt++;
		
		M = max(M, res[i]);
	}

	cout << cnt << "\n" << M;
}

/*
CCW 알고리즘을 이용해 선분 교차를 찾고, Union Find를 가지고 교차한 선분들 집합 형태로 나눠준다.
*/
