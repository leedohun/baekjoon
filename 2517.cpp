#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int n, M;
vector <pair<int, int>> v;

int a[500005] = { 0, };
int tree[500005] = { 0, };

void update(int i, int num) { //BIT tree 업데이트
	while (i <= n) {
		tree[i] += num;
		i += (i & -i);
	}
}

int sum(int i) { //BIT tree에서 값을 가져옴
	int ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		v.push_back({ temp, i + 1 });
	}

//좌표 압축
	sort(v.begin(), v.end());
	int cnt = n;
	a[v[0].second] = cnt;
	for (int i = 1; i < n; i++) {
		if (v[i - 1].first == v[i].first) {
			a[v[i].second] = cnt;
		}
		else
			a[v[i].second] = --cnt;
	}

//BIT tree 작성 및 결과 출력
	for (int i = 1; i <= n; i++) {
		update(a[i], 1);

		cout << sum(a[i]) << "\n";
	}
}

/*
BIT tree, 세그먼트 트리를 이용해서 문제를 해결하면 됩니다. 저는 BIT tree를 이용해 문제를 해결했습니다.
가장 먼저 달리기를 하고 있는 선수들을 좌표 압축을 통해서 좌표를 압축해줬습니다.
그리고 BIT tree를 한명 씩 업데이트 하면서 결과를 출력했습니다.
*/
