#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Q {
	ll S; ll L; ll O;
};

int N, G, K;
Q v[200005];

ll ans = 0;

void userInput() {
	cin >> N >> G >> K;
	for (int i = 0; i < N; i++) {
		cin >> v[i].S >> v[i].L >> v[i].O;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	userInput();
	
	ll left = 0, right = 10000000000;
	while (left <= right) {
		ll mid = (left + right) / 2;

		priority_queue <ll> pq;
		ll tmp = 0;
		for (int i = 0; i < N; i++) {
			if (v[i].O == 0) {
				tmp += v[i].S * max((ll)1, mid - v[i].L);
			}
			else {
				pq.push(v[i].S * max((ll)1, mid - v[i].L));
			}
		}

		for (int i = 0; i < K; i++) {
			if (!pq.empty()) pq.pop();
		}

		while (!pq.empty()) {
			tmp += pq.top(); pq.pop();
		}

		if (tmp <= G) {
			left = mid + 1;
			ans = mid;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans;

	return 0;
}
