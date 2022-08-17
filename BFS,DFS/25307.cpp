#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Q {
	int y; int x; int cnt;
};

int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };

int N, M, K;
int MAP[2005][2005] = { 0, };
bool chk[2005][2005] = { false, };

int yy, xx;

queue <Q> st;

int bfs() {
	queue <Q> que;
	
	que.push({ yy, xx, 0 });
	chk[yy][xx] = true;

	while (!que.empty()) {
		int curY = que.front().y;
		int curX = que.front().x;
		int cnt = que.front().cnt;

		que.pop();

		if (MAP[curY][curX] == 2) return cnt;

		for (int i = 0; i < 4; i++) {
			int y = curY + dy[i];
			int x = curX + dx[i];

			if (y < 0 || x < 0 || N <= y || M <= x) continue;

			if (!chk[y][x] && (MAP[y][x] == 2 || MAP[y][x] == 0)) {
				que.push({ y, x, cnt + 1 });
				chk[y][x] = true;
			}
		}
	}

	return -1;
}

void userInput() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];

			if (MAP[i][j] == 3) 
				st.push({ i, j, 0 });
			if (MAP[i][j] == 4) {
				yy = i, xx = j;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	userInput();

	while (!st.empty()) {
		int curY = st.front().y;
		int curX = st.front().x;
		int cnt = st.front().cnt;

		st.pop();

		for (int i = 0; i < 4; i++) {
			int y = curY + dy[i];
			int x = curX + dx[i];

			if (y < 0 || x < 0 || N <= y || M <= x) continue;
			if (MAP[y][x] != 4 && MAP[y][x] != 1 && cnt < K) {
				st.push({ y, x, cnt + 1 });
				MAP[y][x] = 1;
			}
		}
	}

	cout << bfs();

	return 0;
}
