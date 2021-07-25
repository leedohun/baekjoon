#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

bool visit[4000005] = { false, };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	for (int i = 2; i * i <= 4000000; i++) {
		if (visit[i]) continue;
		for (int j = 2 * i; j <= 4000000; j += i)
			visit[j] = true;
	}

	vector <int> v;
	for (int i = 2; i <= 4000000; i++) {
		if (!visit[i])
			v.push_back(i);
	}

	int ans = 0;
	int N; cin >> N;

	int fir = 0, sec = 0;
	int temp = 0;
	while (sec < v.size()) {
		if (temp == N) {
			ans++; temp -= v[fir++]; temp += v[sec++];
		}
		else if (temp < N)
			temp += v[sec++];
		else
			temp -= v[fir++];
	}

	while (fir < v.size()) {
		if (temp == N) {
			ans++; break;
		}
		else {
			temp -= v[fir++];
		}
	}
	cout << ans;
}
