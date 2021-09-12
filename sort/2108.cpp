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
    }
    return false;
}

void solved() {
    int N; cin >> N;
    vector <int> v(N);
    rep(i, N) cin >> v[i];

    sort(v.begin(), v.end());

    ll ans = 0;
    rep(i, N) ans += v[i];

    cout << round(ans / (double)N) << "\n";
    cout << v[N / 2] << "\n";

    map <int, int> m;
    for (int i = 0; i < N; i++) {
        if (m.find(v[i]) != m.end()) m[v[i]]++;
        else m[v[i]] = 1;
    }
    
    int cnt = 0;
    vector <int> answer;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (cnt < iter->second) {
            cnt = iter->second;
            answer.clear();
            answer.push_back(iter->first);
        }
        else if (cnt == iter->second)
            answer.push_back(iter->first);
    }

    if (answer.size() == 1)
        cout << answer[0] << "\n";
    else
        cout << answer[1] << "\n";

    cout << v[N - 1] - v[0] << "\n";
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
