#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
/*#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
#include <map>*/

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;
const int mod = 1000000007;
const int MAX = 1000005;

struct P {
    ll x; ll y;
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

struct Q {
    int cnt; string tmp;
};

string s[500];
Q ans[500][500];

void solved() {
    int N; cin >> N;
    rep(i, N) cin >> s[i];
    
    if (s[0][0] == 'M') {
        ans[0][0].cnt = 0; ans[0][0].tmp += 'M';
    }
    else {
        ans[0][0].cnt = 0; ans[0][0].tmp = "";
    }

    for (int i = 1; i < N; i++) {
        if (ans[0][i - 1].tmp == "" && s[0][i] == 'M') {
            ans[0][i].cnt = ans[0][i - 1].cnt;
            ans[0][i].tmp = "M";
        }
        else if (ans[0][i - 1].tmp == "M" && s[0][i] == 'O') {
            ans[0][i].cnt = ans[0][i - 1].cnt;
            ans[0][i].tmp = "MO";
        }
        else if (ans[0][i - 1].tmp == "MO" && s[0][i] == 'L') {
            ans[0][i].cnt = ans[0][i - 1].cnt;
            ans[0][i].tmp = "MOL";
        }
        else if (ans[0][i - 1].tmp == "MOL" && s[0][i] == 'A') {
            ans[0][i].cnt = ans[0][i - 1].cnt + 1;
            ans[0][i].tmp = "";
        }
        else {
            ans[0][i].cnt = ans[0][i - 1].cnt;
            if (s[0][i] == 'M') ans[0][i].tmp = "M";
            else ans[0][i].tmp = "";
        }
    }

    for (int i = 1; i < N; i++) {
        if (ans[i - 1][0].tmp == "" && s[i][0] == 'M') {
            ans[i][0].cnt = ans[i - 1][0].cnt;
            ans[i][0].tmp = ans[i - 1][0].tmp + "M";
        }
        else if (ans[i - 1][0].tmp == "M" && s[i][0] == 'O') {
            ans[i][0].cnt = ans[i - 1][0].cnt;
            ans[i][0].tmp = ans[i - 1][0].tmp + 'O';
        }
        else if (ans[i - 1][0].tmp == "MO" && s[i][0] == 'L') {
            ans[i][0].cnt = ans[i - 1][0].cnt;
            ans[i][0].tmp = ans[i - 1][0].tmp + 'L';
        }
        else if (ans[i - 1][0].tmp == "MOL" && s[i][0] == 'A') {
            ans[i][0].cnt = ans[i - 1][0].cnt + 1;
            ans[i][0].tmp = "";
        }
        else {
            ans[i][0].cnt = ans[i - 1][0].cnt;
            if (s[i][0] == 'M') ans[i][0].tmp = "M";
            else ans[i][0].tmp = "";
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            int cnt = 0; string tmp;
            if (ans[i - 1][j].cnt < ans[i][j - 1].cnt) {
                cnt = ans[i][j - 1].cnt;
                tmp = ans[i][j - 1].tmp;
            }
            else if (ans[i - 1][j].cnt > ans[i][j - 1].cnt) {
                cnt = ans[i - 1][j].cnt;
                tmp = ans[i - 1][j].tmp;
            }
            else {
                if (ans[i - 1][j].tmp == "M" && s[i][j] == 'O') {
                    cnt = ans[i - 1][j].cnt;
                    tmp = ans[i - 1][j].tmp;
                }
                else if (ans[i - 1][j].tmp == "MO" && s[i][j] == 'L') {
                    cnt = ans[i - 1][j].cnt;
                    tmp = ans[i - 1][j].tmp;
                }
                else if (ans[i - 1][j].tmp == "MOL" && s[i][j] == 'A') {
                    cnt = ans[i - 1][j].cnt;
                    tmp = ans[i - 1][j].tmp;
                }
                else {
                    cnt = ans[i][j - 1].cnt;
                    tmp = ans[i][j - 1].tmp;
                }
            }

            if (tmp == "" && s[i][j] == 'M') {
                ans[i][j].cnt = cnt;
                ans[i][j].tmp = "M";
            }
            else if (tmp == "M" && s[i][j] == 'O') {
                ans[i][j].cnt = cnt;
                ans[i][j].tmp = "MO";
            }
            else if (tmp == "MO" && s[i][j] == 'L') {
                ans[i][j].cnt = cnt;
                ans[i][j].tmp = "MOL";
            }
            else if (tmp == "MOL" && s[i][j] == 'A') {
                ans[i][j].cnt = cnt + 1;
                ans[i][j].tmp = "";
            }
            else {
                ans[i][j].cnt = cnt;
                if (s[i][j] == 'M') ans[i][j].tmp = "M";
                else ans[i][j].tmp = "";
            }
        }
    }
    int ret = ans[N - 1][N - 1].cnt;
    cout << ret;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
