#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
/*#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <bitset>
#include <stack>
#include <cmath>*/

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;
const int mod = 1000000007;
const int MAX = 1000005;

struct P {
    ll x; ll y; char cnt;
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

int total = 0;
string s;
set <string> st;

void bfs(int l, int r, int length, string tmp) {
    if (total == tmp.size()) {
        st.insert(tmp);
        return;
    }
    if (l - 1 >= 0) bfs(l - 1, r, length + 1, tmp + s.substr(l - 1, length + 1));
    if (r + 1 < s.size()) bfs(l, r + 1, length + 1, tmp + s.substr(l, length + 1));
}

void solved() {
    cin >> s;
    total = s.size() * (s.size() + 1) / 2;

    for (int i = 0; i < s.size(); i++) {
        string tmp;
        tmp += s[i];
        bfs(i, i, 1, tmp);
    }
    cout << st.size();
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
