#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int N, L; cin >> N >> L;

	vector <int> ans;
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;

		pq.push({ temp, i });

		while (L <= i - pq.top().second) {
			pq.pop();
		}

		cout << pq.top().first << " ";
	}
}

/*
이 문제는 우선순위 큐를 이용해서 간단하게 풀 수 있는 문제입니다. 가장 먼저 pq에 데이터를 넣은 뒤 그 데이터를 Ai-L+1 ~ Ai의 사이에 있는 값인지 확인하고
그 값을 ans의 결과 값에 넣어주면 됩니다.
*/
