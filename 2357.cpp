#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int N, M;

ll a[100005] = { 0, };
ll minTree[100005] = { 0, }; //최소값 세그먼트 트리
ll maxTree[100005] = { 0, }; //최댓값 세그먼트 트리

ll minTree_init(int node, int start, int end) { //최소값 세그먼트 트리 생성
	if (start == end) {
		return minTree[node] = a[start];
	}
	else {
		return minTree[node] = min(minTree_init(node * 2, start, (start + end) / 2), minTree_init(node * 2 + 1, (start + end) / 2 + 1, end));
	}
}

ll maxTree_init(int node, int start, int end) { //최대값 세그먼트 트리 생성
	if (start == end) {
		return maxTree[node] = a[start];
	}
	else {
		return maxTree[node] = max(maxTree_init(node * 2, start, (start + end) / 2), maxTree_init(node * 2 + 1, (start + end) / 2 + 1, end));
	}
}

ll min_ans(int node, int start, int end, int left, int right) { //최솟값 세그먼트 트리 찾기
	if (left > end || right < start)
		return 9876543210;
	if (left <= start && end <= right) {
		return minTree[node];
	}
	return min(min_ans(node * 2, start, (start + end) / 2, left, right), min_ans(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

ll max_ans(int node, int start, int end, int left, int right) { //최댓값 세그먼트 트리 찾기
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right) {
		return maxTree[node];
	}
	return max(max_ans(node * 2, start, (start + end) / 2, left, right), max_ans(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}

	minTree_init(1, 1, N);
	maxTree_init(1, 1, N);

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;

		cout << min_ans(1, 1, N, a, b) << " " << max_ans(1, 1, N, a, b) << "\n";
	}
}
