#include <bits/stdc++.h>
#define MAX_MAP 50

using namespace std;

int N, M;
int MAP[MAX_MAP][MAX_MAP];

int board[MAX_MAP * MAX_MAP];
int new_board[MAX_MAP * MAX_MAP] = { 0, };

int dx[4] = { 0,1,0,-1 };	//우측, 아래, 좌측, 위
int dy[4] = { 1,0,-1,0 };

int d, s;
int first = 0, second = 0, third = 0;

//마법사 상어가 2차원에서 공격한 위치를 1차원 배열로 저장
int attack_Loc[4][25] = {
	//위
	{ 7,22,45,76,115,162,217,280,351,430,517,612,715,826,945,1072,1207,1350,1501,1660,1827,2002,2185,2376 },
	//아래
	{ 3,14,33,60,95,138,189,248,315,390,473,564,663,770,885,1008,1139,1278,1425,1580,1743,1914,2093,2280 },
	//좌측
	{ 1,10,27,52,85,126,175,232,297,370,451,540,637,742,855,976,1105,1242,1387,1540,1701,1870,2047,2232 },
	//우측
	{ 5,18,39,68,105,150,203,264,333,410,495,588,689,798,915,1040,1173,1314,1463,1620,1785,1958,2139,2328 }
};

void userInput() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
}

void init() {
	int cnt = N * N - 1;
	int x = 0, y = 0, dir = 0;

	while (-1 < cnt) {
		board[cnt--] = MAP[x][y];
		MAP[x][y] = -1;

		x += dx[dir]; y += dy[dir];
		if ((x == 0 && y == 0) || (x == N - 1 && y == 0)
			|| (x == 0 && y == N - 1) || (x == N - 1 && y == N - 1) ||
			(MAP[x + dx[dir]][y + dy[dir]] == -1)) {
			dir += 1;
		}
		if (dir == 4) {
			dir %= 4;
		}
	}
}

void update() {
	for (int i = 2; i < N * N; i++) {
		while (1 < i && board[i] != 0 && board[i - 1] == 0) {
			swap(board[i], board[i - 1]);
			i -= 1;
		}
	}
}

bool pop_marble() {
	bool flag = false;

	int tmp, cnt, i = 1;
	while (board[i] != 0) {
		tmp = board[i++]; cnt = 1;

		while (tmp == board[i]) {
			cnt += 1; i += 1;
		}

		if (3 < cnt) {
			flag = true;

			if (tmp == 1) first += cnt;
			else if (tmp == 2) second += cnt;
			else if (tmp == 3) third += cnt;

			for (int j = i - 1; i - cnt - 1 < j; j--) {
				board[j] = 0;
			}
		}
	}

	return flag;
}

void new_setting() {
	memset(new_board, 0, sizeof(new_board));

	int tmp, cnt, i = 1, j = 1;
	while (board[i] != 0) {
		tmp = board[i++]; cnt = 1;

		while (tmp == board[i]) {
			cnt += 1; i += 1;
		}

		new_board[j] = cnt;
		new_board[j + 1] = tmp;

		j += 2;
	}

	for (int i = 0; i < N * N; i++) {
		board[i] = new_board[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	userInput();
	//2차원 배열 1차원으로 이동
	init();

	while (M--) {
		//마법사 상어 공격
		cin >> d >> s;
		for (int i = 0; i < s; i++) {
			board[attack_Loc[d - 1][i]] = 0;
		}
		
		//공격으로 인해 빈 위치 앞으로 당기기
		update();
		
		//구슬 폭발하는 단계
		while (pop_marble()) {
			update();
		}
		new_setting();
	}

	cout << first + second * 2 + third * 3;
}
