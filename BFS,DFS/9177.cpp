#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

const ll _INF = 1e18;
const ll INF = 1e9;

bool bfs(string a, string b, string c) {
    bool visit[205][205] = { false, };

    queue <pair<int, int>> que;
    que.push({ 0,0 });
    visit[0][0] = true;

    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;

        que.pop();

        if (x == a.size() && y == b.size())
            return true;

        if (x < a.size() && !visit[x + 1][y] && a[x] == c[x + y]) {
            visit[x + 1][y] = true;
            que.push({ x + 1, y });
        }
        if (y < b.size() && !visit[x][y + 1] && b[y] == c[x + y]) {
            visit[x][y + 1] = true;
            que.push({ x, y + 1 });
        }
    }
    return false;
}

void solve(int t) {
    string a, b, c; cin >> a >> b >> c;

    bool flag = bfs(a, b, c);

    if (flag) {
        cout << "Data set ";
        cout << t + 1;
        cout << ": yes\n";
    }
    else {
        cout << "Data set ";
        cout << t + 1;
        cout << ": no\n";
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    rep(i, t)
        solve(i);
}
