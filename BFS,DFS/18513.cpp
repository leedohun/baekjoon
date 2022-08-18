#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Q {
	ll point; ll cnt;
};

int N, K;
queue <Q> que;
set <ll> st;

ll ans = 0;

void userInput() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		ll tmp; cin >> tmp; 
		que.push({ tmp, 0 });

		st.insert(tmp);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	userInput();
	while (K) {
		ll point = que.front().point;
		ll cnt = que.front().cnt;

		que.pop();

		if (cnt != 0) {
			ans += cnt; K--;
		}

		if (st.find(point - 1) == st.end()) {
			que.push({ point - 1, cnt + 1 });
			st.insert({ point - 1 });
		}
		if (st.find(point + 1) == st.end()) {
			que.push({ point + 1, cnt + 1 });
			st.insert({ point + 1 });
		}
	}

	cout << ans;
	
	return 0;
}
