#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string>

typedef long long ll;
using namespace std;

deque <char> deq[5]; //톱니바퀴 (deque는 양방향으로 push, pop 가능)

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
    
	for (int i = 1; i < 5; i++) {
		string temp; cin >> temp;
		for (int j = 0; j < 8; j++) {
			deq[i].push_back(temp[j]); // 톱니바퀴 deque에 저장
		}
	}

	int K; cin >> K;

	while (K--) {
		int sel; int dir; cin >> sel >> dir;

		queue <pair<int, int>> que;

		que.push({ sel, dir });

		int i = sel - 1; int j = sel + 1;

		int temp;
		if (dir == -1) temp = 1;
		else temp = -1;

		while (0 < i) {
			if (deq[i + 1][6] != deq[i][2]) que.push({ i, temp });
			else break;

			if (temp == -1) temp = 1;
			else temp = -1;

			i--;
		}

		if (dir == -1) temp = 1;
		else temp = -1;

		while (j < 5) {
			if (deq[j - 1][2] != deq[j][6]) que.push({ j, temp });
			else break;

			if (temp == -1) temp = 1;
			else temp = -1;

			j++;
		}

		while (!que.empty()) {
			int x = que.front().first;
			int y = que.front().second;

			que.pop();

			if (y == 1) {
				deq[x].push_front(deq[x].back());
				deq[x].pop_back();
			}
			else {
				deq[x].push_back(deq[x].front());
				deq[x].pop_front();
			}
		}
	}
	int ans = 0, cnt = 1;
	for (int i = 1; i < 5; i++) {
		ans += (deq[i][0] - '0') * cnt;
		cnt *= 2;
	}

	cout << ans;
}

/*
처음 문제를 잘못 읽어서 많이 헤매긴 했지만 문제를 차근차근 읽어보니 쉬운 문제였다. 이 문제에서 헷갈릴 수 있는 것이 톱니바퀴를 돌린 뒤에 양 옆을 비교하는 것이 아닌 돌리기 전 비교를 전부
해 놓은 뒤 그 후에 해당 조건에 맞는 톱니바퀴를 한꺼번에 돌려야 되는 문제였다.

deque를 사용해 톱니바퀴의 회전을 표현하고, queue를 사용해 돌려야 되는 톱니바퀴와 방향을 표시해 주었다.
*/
