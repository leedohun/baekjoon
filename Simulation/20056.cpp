#include <bits/stdc++.h>

using namespace std;

struct Q {
	int m, s, d, k;
};

int N, M, K;
int r, c, m, s, d;

queue <Q> v[55][55];

int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

int sumFireBall() {
	int ret = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			while (!v[i][j].empty()) {
				ret += v[i][j].front().m;

				v[i][j].pop();
			}
		}
	}

	return ret;
}

void moveFireBall(int test_case) {
	/*파이어볼 이동*/
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			while (!v[i][j].empty()) {	//i, j번 위치에 파이어볼이 여러 개 위치
				if (v[i][j].front().k != test_case)
					break;

				r = i + dy[v[i][j].front().d] * (v[i][j].front().s % N);
				c = j + dx[v[i][j].front().d] * (v[i][j].front().s % N);

				if (r > N) r -= N;
				if (c > N) c -= N;
				if (r < 1) r += N;
				if (c < 1) c += N;

				v[r][c].push({
					v[i][j].front().m,
					v[i][j].front().s,
					v[i][j].front().d,
					test_case + 1
					});
				v[i][j].pop();
			}
		}
	}
}

void SumFireBall(int test_case) {
	/*같은 칸에 있는 파이어볼을 모두 하나로 합친다.*/
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			if (v[i][j].size() < 2) continue;

			int cnt = v[i][j].size();
			m = 0, s = 0;

			bool even = true, odd = true;

			while (!v[i][j].empty()) {
				m += v[i][j].front().m;
				s += v[i][j].front().s;
				if (v[i][j].front().d % 2 == 0) odd = false;
				else even = false;

				v[i][j].pop();
			}

			if (m / 5 > 0) {
				if (even || odd) {
					for (int dir = 0; dir < 8; dir += 2) {
						v[i][j].push({ m / 5, s / cnt, dir, test_case + 1 });
					}
				}
				else {
					for (int dir = 1; dir < 9; dir += 2) {
						v[i][j].push({ m / 5, s / cnt, dir, test_case + 1 });
					}
				}
			}
		}
	}
}

void simulation() {
	for (int test_case = 0; test_case < K; test_case++) {	//K번 시뮬레이션 수행

		/*파이어볼 이동*/
		moveFireBall(test_case);

		/*같은 칸에 있는 파이어볼을 모두 하나로 합친다.*/
		SumFireBall(test_case);
	}

	return;
}

void userInput() {
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> m >> s >> d;
		v[r][c].push({ m, s, d, 0 });
	}
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	userInput();
	simulation();

	int ans = sumFireBall();

	cout << ans;

	return 0;
}
