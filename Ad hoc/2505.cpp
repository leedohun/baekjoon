#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
/*#include <iostream>
#include <string>
#include <queue>
#include <set>*/

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;

struct P {
    int x; int y; int cnt;
};

/*struct compare {
    bool operator()(P& a, P& b) {
        if (a.x != b.x)
            return a.x < b.x;
        return
            a.y < b.y;
    }
};
priority_queue <P, vector<P>, compare> pq;*/

bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
    }
    return false;
}

string S;
set <string> visit;

int ans = 0;
void bfs() {

}

void solved() {
    int N; cin >> N;
    vector <int> v(N);
    rep(i, N) cin >> v[i];
    vector <int> tmp = v;

    int cnt = 0;
    vector <pair<int, int>> ans;
    while (true) {
        bool flag = true;
        for (int i = 0; i < N; i++) {
            if (v[i] != i + 1) {
                flag = false;

                int j = i + 1;
                while (j + 1 < N && v[j] != i + 1) j++;

                reverse(v.begin() + i, v.begin() + j + 1);
                ans.push_back({ i + 1, j + 1 });
                cnt++;
            }
        }

        if (cnt > 2 || flag) break;
    }

    if (cnt > 2) {
        cnt = 0;
        ans.clear();

        while (true) {
            bool flag = true;
            for (int i = N - 1; 0 <= i; i--) {
                if (tmp[i] != i + 1) {
                    flag = false;

                    int j = i - 1;
                    while (0 <= j - 1 && tmp[j] != i + 1) j--;
               
                    reverse(tmp.begin() + j, tmp.begin() + i + 1);
                    ans.push_back({ j + 1, i + 1 });
                    cnt++;
                }
            }

            if (cnt > 2 || flag) break;
        }
    }

    if (cnt == 2) {
        cout << ans[0].first << " " << ans[0].second << "\n";
        cout << ans[1].first << " " << ans[1].second << "\n";
    }
    else if (cnt == 1) {
        cout << 1 << " " << 1 << "\n";
        cout << ans[0].first << " " << ans[0].second << "\n";
    }
    else if (cnt == 0) {
        cout << 1 << " " << 1 << "\n";
        cout << 1 << " " << 1 << "\n";
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}

/*
왼쪽에서 그리디, 오른쪽에서 그리디 둘 중 하나가 정답이 된다.
*/
