#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int map[11][11] = { 0, }; //양분

vector <int> v[11][11]; //나무

int dx[8] = { -1,-1,0,1,1,1,0,-1 }; //상 하 좌 우 대각선
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, M, K; cin >> N >> M >> K;
	int add_food[11][11] = { 0, };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = 5; //초기 땅의 양분
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> add_food[i][j]; //S2D2가 겨울에 땅을 돌아다니면서 양분 추가
		}

	for (int i = 0; i < M; i++) {
		int x, y, z; cin >> x >> y >> z;
		v[x- 1][y - 1].push_back(z); //나무의 위치와 나이를 저장
	}

	while (K--) {
		//봄
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				sort(v[i][j].begin(), v[i][j].end());
			}
		}
		
		//여름
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < v[i][j].size(); k++) {
					if (v[i][j][k] > 0 && map[i][j] >= v[i][j][k]) {
						map[i][j] -= v[i][j][k];
						v[i][j][k] += 1;
					}
					else if (v[i][j][k] == 0)
						continue;
					else {
						int e = k;
						for (int l = k; l < v[i][j].size(); l++) {
							map[i][j] += (v[i][j][l] / 2);
							v[i][j][k] = 0;
						}
						v[i][j].erase(v[i][j].begin() + e, v[i][j].end());
						break;
					}
				}
			}
		}
		
		//가을
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < v[i][j].size(); k++) {
					if (v[i][j][k] > 0 && v[i][j][k] % 5 == 0) {
						for (int l = 0; l < 8; l++) {
							int x = dx[l] + i;
							int y = dy[l] + j;
							if (x < 0 || y < 0 || N <= x || N <= y)
								continue;
							v[x][y].push_back(1);
						}
					}
				}
			}
		}
		
		//겨울
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] += add_food[i][j];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < v[i][j].size(); k++) {
				if (v[i][j][k] > 0)
					ans++;
			}
		}
	}
	cout << ans;
}

/*
이 문제는 시뮬레이션 문제로 주어진 단계를 하나하나 해결해 나가다 보면 정답을 맞출 수 있습니다.
*/
