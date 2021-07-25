#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

const ll _INF = 1e18;
const ll INF = 1e9;

void solve(int t) {
    string S; cin >> S;

    stack <char> s;

    for (int i = 0; i < S.size(); i++) {
        string tmp;

        tmp += S[i];
        if (s.size() > 2) {
            for (int j = 0; j < 3; j++) {
                tmp += s.top(); s.pop();
            }

            reverse(tmp.begin(), tmp.end());

            if (tmp == "PPAP")
                s.push('P');
            else {
                s.push(tmp[0]); s.push(tmp[1]);
                s.push(tmp[2]); s.push(tmp[3]);
            }
        }
        else
            s.push(S[i]);
    }

    string ret;
    while (s.size()) {
        ret += s.top();
        s.pop();
    }

    reverse(ret.begin(), ret.end());

    if (ret == "P" || ret == "PPAP")
        cout << "PPAP";
    else
        cout << "NP";
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    //int t; cin >> t;
    //rep(i, t)
        solve(1);

        return 0;
}
