#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll N, M, K;

ll arr[1000005] = { 0, }; //기존 N개의 값 저장
ll tree[1000005] = { 0, }; //BIT tree

void update(ll i, ll num) { //BIT tree 업데이트
	while (i <= N) {
		tree[i] += num;
		i += (i & -i);
	}
}

ll sum(ll i) { //BTI tree로 구간 합
	ll ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];

		update(i, arr[i]);
	}

	for (int i = 0; i < M + K; i++) {
		ll a, b, c; cin >> a >> b >> c;

		if (a == 1) {
			update(b, c - arr[b]);
			arr[b] = c;
		}
		else {
			cout << sum(c) - sum(b - 1) << "\n";
		}
	}
}
