#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define MAXN 1000000

using namespace std;

int N, K;

deque <int> con;	//컨베이어 벨트 표시
deque <int> robot;	//로봇을 올린 순서 표시

int ans = 0;

void simulation() {
	while (true) {
		ans += 1;

		/*벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전*/
		con.push_front(con.back());
		con.pop_back();
		robot.push_front(robot.back());
		robot.pop_back();

		robot[N - 1] = false;	//로봇이 N번 위치에 오면 내려옴.

		/*로봇이 스스로 이동*/
		for (int i = N - 1; 0 <= i; i--) {
			if (robot[i] && !robot[i + 1] && con[i + 1] > 0) {	//내구도가 있다면 이동 가능
				con[i + 1]--;
				robot[i] = false, robot[i + 1] = true;	//로봇이 이동
			}
		}
		robot[N - 1] = false;	//로봇이 N번 위치에 오면 내려옴.

		/*로봇을 벨트에 올리기*/
		if (con[0] > 0) {
			con[0]--;
			robot[0] = true;
		}

		/*내구도 칸 개수 파악*/
		int cnt = 0;	//내구도 체크
		for (int i = 0; i < con.size(); i++) {
			if (con[i] == 0) cnt++;
		}
		if (K <= cnt) break;
	}
}

void userInput() {
	cin >> N >> K;
	for (int i = 0; i < N * 2; i++) {
		int tmp; cin >> tmp;
		con.push_back(tmp);
		robot.push_back(false);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);	//입, 출력 시간을 줄임.

	userInput();
	simulation();

	cout << ans;
}
