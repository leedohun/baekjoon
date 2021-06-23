#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

struct P {
	int number; int dir;
};

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 }; //북, 북서, 서, 남서, 남, 남동, 동, 북동
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

int ans = 0;

void move(P fish_map[4][4], int x, int y, int cnt, int dir) { //상어와 물고기 이동
	if (fish_map[x][y].number == 0) {
		ans = max(ans, cnt);
		return;
	}

  //상어 이동
	cnt += fish_map[x][y].number;
	dir = fish_map[x][y].dir;
	fish_map[x][y].number = 0, fish_map[x][y].dir = 0;

  //상어 이동
	for (int i = 1; i < 17; i++) {
		bool frag = false;

		for (int q = 0; q < 4; q++) {
			if (frag) break;

			for (int p = 0; p < 4; p++) {
				if (frag) break;

				if (fish_map[q][p].number == i) {
					int xx = q + dx[fish_map[q][p].dir];
					int yy = p + dy[fish_map[q][p].dir];

					while (xx < 0 || yy < 0 || 4 <= xx || 4 <= yy || (x == xx && y == yy)) { //물고기가 공간을 벗어나거나 상어가 위치한 공간에 가면 45도 반시계 회전
						fish_map[q][p].dir++;

						if (fish_map[q][p].dir == 8)
							fish_map[q][p].dir = 0;

						xx = q + dx[fish_map[q][p].dir];
						yy = p + dy[fish_map[q][p].dir];
					}

					P temp = fish_map[xx][yy];

					fish_map[xx][yy] = fish_map[q][p];
					fish_map[q][p] = temp;
					frag = true;
				}
			}
		}
	}

	P save_map[4][4]; //상어가 원하는 방향으로 여러 칸을 움직일 수 있으므로 물고기의 기존 칸 저장
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			save_map[i][j] = fish_map[i][j];
		}
	}

	int xx = x, yy = y;

	while (1) {
		xx += dx[dir], yy += dy[dir];

		if (xx < 0 || yy < 0 || 4 <= xx || 4 <= yy) {
			ans = max(ans, cnt);
			return;
		}

		move(fish_map, xx, yy, cnt, dir); //상어 이동 경로 설정

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				fish_map[i][j] = save_map[i][j];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	P fish_map[4][4];
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b; cin >> a >> b;

			fish_map[i][j].number = a;
			fish_map[i][j].dir = b - 1;
		}
	}

	move(fish_map, 0, 0, 0, 0);

	cout << ans;
}
