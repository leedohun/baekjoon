#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <bitset>
#include <stack>
#include <cmath>
#include <cstring>

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;
const int mod = 1000000007;
const int MAX = 1000005;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

struct P {
    ll x; ll y; ll cnt;
};

struct compare {
    bool operator()(P& a, P& b) {
        if (a.x != b.x)
            return a.x > b.x;
        return
            a.y > b.y;
    }
};
//priority_queue <P, vector<P>, compare> pq;

bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
    }
    return false;
}

int gcd(int a, int b) {
    while (b != 0) { int r = a % b; a = b; b = r; }
    return a;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    int temp = x1 * y2 + x2 * y3 + x3 * y1;
    temp = temp - y1 * x2 - y2 * x3 - y3 * x1;
    if (temp > 0) return 1;
    else if (temp < 0) return -1;
    else return 0;
}

int combination(int n, int r){
    if (n == r || r == 0) return 1;
    else return combination(n - 1, r - 1) + combination(n - 1, r);
}

int GCP(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int LCM(int a, int b) {
    return a * b / GCP(a, b);
}

// 다익 스트라 알고리즘
vector <pair<int, int>> graph[1001];

vector <int> dijkstra(int start, int vertex) {
    vector <int> distance(vertex, INF);
    distance[start] = 0;

    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;

        pq.pop();

        if (distance[cur] < cost)
            continue;

        for (int i = 0; i < graph[cur].size(); i++) {
            int neighbor = graph[cur][i].first;
            int neighborDistance = cost + graph[cur][i].second;

            if (distance[neighbor] > neighborDistance) {
                distance[neighbor] = neighborDistance;
                pq.push({ neighborDistance, neighbor });
            }
        }
    }

    return distance;
}


/*
####################################################################################
####################################################################################
####################################################################################
####################################################################################

                        풀   이   시   작

####################################################################################
####################################################################################
####################################################################################
####################################################################################
*/

int H, W, O, F, Xs, Ys, Xe, Ye;

bool vis[105][105] = { false, };
int obstacle[105][105] = { 0, };

bool DFS() {
    queue <P> que;
    que.push({ Xs, Ys, F });
    vis[Xs][Ys] = true;

    while (!que.empty()) {
        int x = que.front().x;
        int y = que.front().y;
        int f = que.front().cnt;

        que.pop();

        if (x == Xe && y == Ye) return true;

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx < 1 || yy < 1 || H < xx || W < yy) continue;

            if (!vis[xx][yy] && f != 0) {
                if (obstacle[xx][yy] - obstacle[x][y] <= f) {
                    vis[xx][yy] = true;
                    que.push({ xx, yy, f - 1 });
                }
            }
        }
    }
    return false;
}

void solved() {
    int T; cin >> T;
    while (T--) {
        rep(i, 105) rep(j, 105) {
            obstacle[i][j] = 0;
            vis[i][j] = false;
        }
     
        cin >> H >> W >> O >> F >> Xs >> Ys >> Xe >> Ye;

        rep(i, O) {
            int a, b, c; cin >> a >> b >> c;
            obstacle[a][b] = c;
        }

        bool ans = DFS();
        if (ans) cout << "잘했어!!\n";
        else cout << "인성 문제있어??\n";
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
