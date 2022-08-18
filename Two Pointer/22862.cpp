#include <bits/stdc++.h>
#define ll long long

using namespace std;

int N, K;
int v[1000005] = { 0, };

int ans = 0;

void userInput() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	userInput();

	int left = 0, right = 0; int k = 0;
	while (right != N) {
		if (v[right] % 2 == 0) {
			right += 1;
		}
		else if (v[right] % 2 == 1) {
			if (k < K) {
				right += 1;
				k += 1;
			}
			else if (k == K) {
				k -= 1;
				while (left <= right && v[left] % 2 != 1) {
					left += 1;
				}
				left += 1;
			}
		}

		ans = max(ans, (right - left) - k);
	}
	cout << ans;
	return 0;
}
