#include <bits/stdc++.h>

using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int N, K, L;
set <pair<int, int>> apple;
vector <pair<int, char>> dirChange;
int pointer = 0;

deque <pair<int, int>> snack;
int dir = 0, timer = 0;

int x, y; char C;

long long ans = 0;

bool move() {
	x = snack.front().first + dx[dir];
	y = snack.front().second + dy[dir];

	if (x < 1 || y < 1 || N < x || N < y)		//벽에 부딪히는 경우
		return true;

	for (int i = 0; i < snack.size(); i++) {	//자신의 몸에 부딪히는 경우
		if (x == snack[i].first && y == snack[i].second)
			return true;
	}

	snack.push_front({ x, y });
	if (apple.find({ x, y }) != apple.end()) {
		apple.erase({ x, y });
	}
	else {
		snack.pop_back();
	}

	return false;
}

void simulation() {
	snack.push_front({ 1 ,1 });
	while (true) {
		timer++; ans++;

		if (move())
			break;

		if (pointer < L && timer == dirChange[pointer].first) {
			if (dirChange[pointer].second == 'D') {
				dir += 1;
				if (dir == 4) dir = 0;
			}
			else {
				dir -= 1;
				if (dir == -1) dir = 3;
			}
			pointer++;
		}
	}
}

void userInput() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		apple.insert({ x, y });
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> x >> C;
		dirChange.push_back({ x, C });
	}
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	userInput();
	simulation();

	cout << ans;
	return 0;
}
