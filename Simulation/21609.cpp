#include <bits/stdc++.h>
#define MAX_MAP 20

using namespace std;

int N, M;
int MAP[MAX_MAP + 5][MAX_MAP + 5];

bool chk[MAX_MAP + 5][MAX_MAP + 5];
bool chk_tmp[MAX_MAP + 5][MAX_MAP + 5];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int ans = 0;

void userInput() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
}

pair<int, int> search_BFS(int a, int b, int tmp) {
	memset(chk_tmp, false, sizeof(chk_tmp));

	int colorCnt = 1, rainbowCnt = 0;
	queue <pair<int, int>> que;

	que.push({ a, b });
	chk_tmp[a][b] = true; chk[a][b] = true;

	while (!que.empty()) {
		int curX = que.front().first;
		int curY = que.front().second;

		que.pop();

		for (int i = 0; i < 4; i++) {
			int x = curX + dx[i];
			int y = curY + dy[i];

			if (x < 0 || y < 0 || N <= x || N <= y) continue;

			if (!chk_tmp[x][y] && (MAP[x][y] == tmp || MAP[x][y] == 0)) {
				chk[x][y] = true; chk_tmp[x][y] = true;
				if (MAP[x][y] == 0) rainbowCnt += 1;
				else colorCnt += 1;
				que.push({ x, y });
			}
		}
	}

	return { colorCnt, rainbowCnt };
}

void remove_BFS(int a, int b, int tmp) {
	queue <pair<int, int>> que;

	que.push({ a, b });
	MAP[a][b] = -9;

	while (!que.empty()) {
		int curX = que.front().first;
		int curY = que.front().second;

		que.pop();

		for (int i = 0; i < 4; i++) {
			int x = curX + dx[i];
			int y = curY + dy[i];

			if (x < 0 || y < 0 || N <= x || N <= y) continue;

			if (MAP[x][y] == tmp || MAP[x][y] == 0) {
				MAP[x][y] = -9;
				que.push({ x, y });
			}
		}
	}
}

void gravity() {
	for (int i = 0; i < N; i++) {
		bool flag = false;

		int j = 0;
		while (j + 1 < N) {
			while (j + 1 < N && -1 < MAP[j][i] && MAP[j + 1][i] == -9) {
				swap(MAP[j][i], MAP[j + 1][i]);
				j += 1;
				flag = true;
			}
			j += 1;
		}

		if (flag) i -= 1;
	}
}

void cycle() {
	int tmp[MAX_MAP][MAX_MAP];

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			tmp[N - j - 1][i] = MAP[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			MAP[i][j] = tmp[i][j];
		}
	}
}

bool simulation() {
	memset(chk, false, sizeof(chk));

	//터트릴 위치 블록 찾기

	int curX = -1, curY = -1; pair<int, int> curCnt = { 0, 0 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!chk[i][j] && 0 < MAP[i][j]) {
				pair<int, int> tmpCnt = search_BFS(i, j, MAP[i][j]);

				if (curCnt.first + curCnt.second < tmpCnt.first + tmpCnt.second) {
					curX = i; curY = j; curCnt = tmpCnt;
				}
				else if (curCnt.first + curCnt.second == tmpCnt.first + tmpCnt.second
					&& curCnt.second <= tmpCnt.second) {
					curX = i; curY = j; curCnt = tmpCnt;
				}
			}
		}
	}
	if ((curX == -1 && curY == -1) || curCnt.first + curCnt.second == 1) return false;

	//터트리기
	remove_BFS(curX, curY, MAP[curX][curY]);
	ans += (curCnt.first + curCnt.second) * (curCnt.first + curCnt.second);

	//중력 작용
	gravity();

	//회전 작용
	cycle();

	//중력 작용
	gravity();

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	userInput();
	while (simulation());

	cout << ans;
}
