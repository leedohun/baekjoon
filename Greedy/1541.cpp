#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

const ll _INF = 1e18;
const ll INF = 1e9;

void solved() {
    string s; cin >> s;

    vector <int> v;
    vector <char> o;
    rep(i, s.size()) {
        string tmp;

        while (i < s.size() && s[i] != '+' && s[i] != '-') {
            tmp += s[i];
            i++;
        }
        if (s[i] == '+' || s[i] == '-') {
            o.push_back(s[i]);
        }

        v.push_back(stoi(tmp));
    }

    for (int i = 0; i < o.size(); i++) {
        if (o[i] == '+') {
            v[i] = v[i] + v[i + 1];
            v.erase(v.begin() + i + 1);
            o.erase(o.begin() + i);
            i--;
        }
    }
    
    int ans = v[0];
    for (int i = 1; i < v.size(); i++) {
        ans -= v[i];
    }

    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
