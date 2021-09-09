#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;

struct P {
    int x; int y; int xx; int yy;
};

bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
        else if (a.y == b.y) {
            if (a.xx < b.xx) return true;
            else if (a.xx == b.xx) {
                if (a.yy < b.yy) return true;
                else return false;
            }
        }
    }
    return false;
}

void solved() {
    int N; cin >> N;
    vector <P> v(N);
    rep(i, N) cin >> v[i].x >> v[i].y >> v[i].xx >> v[i].yy;

    sort(v.begin(), v.end(), cmp);
    
    int ans = 0;
    int x = 3, y = 1;

    for (int i = 0; i < v.size(); i++) {
        if (12 == x) break;

        bool flag = false;
        int tmp_x = 0;
        int tmp_y = 0;
        while (i < N && (v[i].x < x || (v[i].x == x && v[i].y <= y))) {
            flag = true;
            if (tmp_x < v[i].xx) {
                tmp_x = v[i].xx;
                tmp_y = v[i].yy;
            }
            else if (tmp_x == v[i].xx) {
                if (tmp_y < v[i].yy) {
                    tmp_x = v[i].xx;
                    tmp_y = v[i].yy;
                }
            }
            i++;
        }
        
        if (flag) {
            x = tmp_x;
            y = tmp_y;
            ans++;
            i--;
        }
    }

    if (x == 12)
        cout << ans;
    else
        cout << 0;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
