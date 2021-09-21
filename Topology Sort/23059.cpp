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
    int x; int y;
};

struct compare {
    bool operator()(P& a, P& b) {
        if (a.x != b.x)
            return a.x < b.x;
        return
            a.y < b.y;
    }
};
priority_queue <P, vector<P>, compare> pq;

bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
    }
    return false;
}

map <string, int> m;
map <int, string> m2;
int inDegree[400005] = { 0, };
vector <int> a[400005];

vector <string> ans[400005];

void solved() {
    int N; cin >> N;
    
    int cnt = 1;
    rep(i, N) {
        string A, B; cin >> A >> B;

        if (m.find(A) == m.end()) {
            m2[cnt] = A;
            m[A] = cnt++;
        }
        if (m.find(B) == m.end()) {
            m2[cnt] = B;
            m[B] = cnt++;
        }

        a[m[A]].push_back(m[B]);
        inDegree[m[B]]++;
    }

    queue <pair<int, int>> q;
    for (int i = 1; i < cnt; i++) {
        if (inDegree[i] == 0) {
            q.push({ i, 1 });
            ans[1].push_back(m2[i]);
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < a[x].size(); i++) {
            int k = a[x][i];

            if (--inDegree[k] == 0) {
                q.push({ k, y + 1 });
                ans[y + 1].push_back(m2[k]);
            }
        }
    }

    int total = 0;
    for (int i = 1; i < cnt; i++) {
        total += ans[i].size();
        sort(ans[i].begin(), ans[i].end());
    }

    if (cnt - 1 != total) {
        cout << -1;
    }
    else {
        for (int i = 1; i < cnt; i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] << "\n";
            }
        }
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
