#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;

struct P {
    int x; int y;
};

bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
        else return false;
    }
    return false;
}

void solved() {
    string s; cin >> s;

    rep(i, s.size()) {
        if (i + 3 < s.size() && s[i] == 'X' && s[i + 1] == 'X' && s[i + 2] == 'X' && s[i + 3] == 'X') {
            s[i] = s[i + 1] = s[i + 2] = s[i + 3] = 'A';
        }
        if (i + 1 < s.size() && s[i] == 'X' && s[i + 1] == 'X') {
            s[i] = s[i + 1] = 'B';
        }
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'X') {
            cout << -1;
            return;
        }
    }
    cout << s;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
