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

int cont[10][13] = { 0, };

void solved() {
    int N; cin >> N;
    string s[50];
    set <char> st;
    rep(i, N) {
        cin >> s[i];
        st.insert(s[i][0]);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < s[i].size(); j++) {
            cont[s[i][j] - 'A'][s[i].size() - j]++;
        }
    }

    map <char, int> m;
    for (int i = 9; 0 <= i; i--) {
        ll total = -1;
        char ttmp = '0';
        bool flag = true;

        for (int j = 0; j < 10; j++) {
            ll tmp = 0;
            for (ll k = 1, q = 1; k <= 12; k++, q *= 10) {
                tmp += i * q * cont[j][k];
            }

            if (m.find('A' + j) == m.end() && total < tmp) {
                if (i == 0) {
                    for (int k = 0; k < N; k++) {
                        if (s[k][0] == 'A' + j) 
                            flag = false;
                    }
                }
                ttmp = ('A' + j);
                total = tmp;
            }
        }
        if (!flag) {
            int lo = 10;
            for (auto iter = m.begin(); iter != m.end(); iter++) {
                if (st.find(iter->first) == st.end() && iter->second < lo)
                    lo = iter->second;
            }
            bool flag =  true;
            for (auto iter = m.begin(); iter != m.end(); iter++) {
                if (flag && lo == iter->second) {
                    flag = false;
                    iter->second = 0;
                }
                if (lo > iter->second && iter->second != 0) iter->second++;
            }
            m[ttmp] = 1;
        }
        else 
            m[ttmp] = i;
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll tmp = 0;
        for (ll j = s[i].size() - 1, k = 1; 0 <= j; j--, k *= 10) {
            tmp += (m[s[i][j]] * k);
        }
        ans += tmp;
    }
    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
