#include <bits/stdc++.h>
#define ll long long

using namespace std;

int N;
vector <pair<int, int>> v;

int ans = 0;

void userInput() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int d, t; cin >> d >> t;
		v.push_back({ t, d });
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	userInput();
	sort(v.begin(), v.end());

	int left = 1, right = v[N - 1].first;
	while (left <= right) {
		int mid = (left + right) / 2;

		bool flag = true;
		for (int i = 0; i < N; i++) {
			if (v[i].first < mid + v[i].second) {
				flag = false;
				break;
			}
			
			mid += v[i].second;
		}

		if (flag) {
			ans = (left + right) / 2;
			left = (left + right) / 2 + 1;
		}
		else {
			right = (left + right) / 2 - 1;
		}
	}
	cout << ans; 

	return 0;
}
