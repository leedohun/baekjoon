#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int N;

bool visited[1005] = { false, }; //남은 day를 표시
int ans = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	priority_queue <pair<int, int>> pq; //weight 순으로 정렬
	for (int i = 0; i < N; i++) {
		int d, w; cin >> d >> w;

		pq.push({ w, d });
	}

	while (!pq.empty()) {
		int day = pq.top().second;
		int weight = pq.top().first;

		pq.pop();

		while (0 < day) {
			if (!visited[day]) { //1 ~ 제출 마감일까지 확인하면서 가장 마지막으로 낼 수 있는 day를 선택
				visited[day] = true;
				ans += weight;
				break;
			}
			day--;
		}
	}

	cout << ans;
}
