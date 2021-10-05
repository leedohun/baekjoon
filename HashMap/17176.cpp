#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
#include <map>

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

map <int, string> m;

void solved() {
    m[0] = " ";
    for (int i = 0; i < 26; i++) {
        m[i + 1] = 'A' + i;
        m[i + 27] = 'a' + i;
    }

    int N; cin >> N;
    vector <int> v(N);
    rep(i, N) cin >> v[i];
    string ans;

    for (int i = 0; i < v.size(); i++) {
        ans += m[v[i]];
    }

    vector <int> tmp;
    string s; getline(cin, s);
    getline(cin, s);
    
    sort(ans.begin(), ans.end());
    sort(s.begin(), s.end());

    if (ans == s) cout << "y";
    else cout << "n";
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
