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

void solved() {
    int N, M; cin >> N >> M;
    bitset <100> s;
    bitset <100> v[20];
    
    string st; cin >> st;
    for (int i = 0; i < st.size(); i++) {
        if (st[i] == '1') s.set(i);
    }

    rep(i, M) {
        cin >> st;
        for (int j = 0; j < st.size(); j++) {
            if (st[j] == '1') v[i].set(j);
        }
    }

    vector <int> ans[205];
    bool flag[205] = { false, };

    for (int i = 0; i < (1 << M); i++) {
        bitset <100> tmp;
        vector <int> temp;

        for (int j = 0; j < M; j++) {
            if (i & (1 << j)) {
                temp.push_back(j + 1);
                tmp ^= v[j];
            }
        }

        tmp ^= s;

        int cnt = tmp.count();
        if (ans[cnt * 2].empty()) 
            ans[cnt * 2] = temp;
    }
    int cnt = s.count();
    for (int i = 0; i < 2 * N + 1; i++) {
        if (i == cnt * 2) {
            cout << 0 << "\n";
        }
        else if (ans[i].empty()) {
            cout << "-1\n";
        }
        else {
            cout << ans[i].size() << " ";
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
