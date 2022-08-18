#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Q {
	int y; int x; int cnt; int chk;
};

int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };

int N, M;
string MAP[50];

int startY, startX;

void userInput() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> MAP[i];

		for (int j = 0; j < M; j++) {
			if (MAP[i][j] == '0') {
				startY = i;
				startX = j;
			}
		}
	}
}

int bfs() {
	queue <Q> que;
	set <pair<pair<int, int>, int>> st;

	que.push({ startY, startX, 0, 0 });
	st.insert({ { startY, startX }, 0 });

	while (!que.empty()) {
		int curY = que.front().y;
		int curX = que.front().x;
		int cnt = que.front().cnt;
		int curChk = que.front().chk;

		que.pop();

		if (MAP[curY][curX] == '1') return cnt;

		for (int i = 0; i < 4; i++) {
			int y = curY + dy[i];
			int x = curX + dx[i];

			if (y < 0 || x < 0 || N <= y || M <= x) continue;

			if (st.find({ { y, x }, curChk }) == st.end() && (MAP[y][x] == '.' || MAP[y][x] == '0' || MAP[y][x] == '1')) {
				que.push({ y, x, cnt + 1, curChk });
				st.insert({ { y, x }, curChk });
			}
			else if ('a' <= MAP[y][x] && MAP[y][x] <= 'f') {	//열쇄 잡기
				int chk = curChk | (1 << (MAP[y][x] - 'a'));
				if (st.find({ { y, x }, chk }) == st.end()) {
					que.push({ y, x, cnt + 1, chk });
					st.insert({ { y, x }, chk });
				}
			}
			else if (st.find({ { y, x }, curChk }) == st.end()
				&& 'A' <= MAP[y][x]
				&& MAP[y][x] <= 'F'
				&& curChk & (1 << (MAP[y][x] - 'A'))) {	//문 열기
				que.push({ y,x, cnt + 1, curChk });
				st.insert({ { y, x }, curChk });
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	userInput();
	cout << bfs();
	
	return 0;
}
