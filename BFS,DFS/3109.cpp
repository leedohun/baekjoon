#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int R, C;
string Map[10005];

bool check_Map[10005][505] = { false, }; //방문한 위치를 체크

int dx[3] = { -1, 0, 1 }; //북동, 동, 남동 순으로 탐색
int dy[3] = { 1, 1, 1 };

int temp = 0; //bfs를 통해서 파이프가 연결되었는지 확인
int ans = 0;

void bfs(int a, int b) { //bfs
	if (b == C - 1) {
		ans++; temp = 1;
		return;
	}

	for (int i = 0; i < 3; i++) { //북동, 동, 남동 탐색
		int x = a + dx[i];
		int y = b + dy[i];

		if (x < 0 || y < 0 || R <= x || C <= y) continue;

		if (Map[x][y] == '.' && !check_Map[x][y]) {
			check_Map[x][y] = true;
			bfs(x, y);

			if (temp == 1)
				return;
      
      //check_Map[x][y] = false가 없는 이유 : 한번 가본 곳인데 답이 없다면 그 길은 다음번에 가도 틀린 길
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> Map[i];
	}

	for (int i = 0; i < R; i++) {
		temp = 0;
		bfs(i, 0);
	}

	cout << ans;
}

