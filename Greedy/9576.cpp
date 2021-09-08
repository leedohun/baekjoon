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
    if (a.y < b.y) return true;
    else if (a.y == b.y) {
        if (a.x < b.x) return true;
        else return false;
    }
    return false;
}

void solved() {
    int t; cin >> t;
    while (t--) {
        int N, M; cin >> N >> M;
        
        vector <P> v(M);
        rep(i, M) cin >> v[i].x >> v[i].y;

        sort(v.begin(), v.end(), cmp);

        set <int> s;
        rep(i, N) s.insert(i + 1);

        int ans = 0;
        rep(i, M) {
            int tmp = -1;
            if(!s.empty())
                tmp = *s.lower_bound(v[i].x);
            
            if (tmp != -1 && tmp <= v[i].y) {
                ans++;
                s.erase(tmp);
            }
        }
        cout << ans << "\n";
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
