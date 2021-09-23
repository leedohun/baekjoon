#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
/*#include <iostream>
#include <string>
#include <queue>
#include <set>*/

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;

struct P {
    int x; int y; int cnt;
};

/*struct compare {
    bool operator()(P& a, P& b) {
        if (a.x != b.x)
            return a.x < b.x;
        return
            a.y < b.y;
    }
};
priority_queue <P, vector<P>, compare> pq;*/

bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
    }
    return false;
}

void solved() {
    int N, M; cin >> N >> M;
    string W, S; cin >> W >> S;

    map <char, int> origin, tmp;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        if (origin.find(S[i]) == origin.end()) {
            origin[S[i]] = 1;
        }
        else {
            origin[S[i]]++;
        }

        if (tmp.find(W[i]) == tmp.end()) {
            tmp[W[i]] = 1;
        }
        else {
            tmp[W[i]]++;
        }
    }

    int ans = 0;
    for (int i = N; i < M; i++) {
        if (tmp.size() == origin.size()) {
            bool flag = true;
            for (int k = 0; k < N; k++) {
                if (origin.find(W[k]) == origin.end() || (origin[W[k]] != tmp[W[k]])) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans++;
        }

        if (origin[S[i - N]] == 1) {
            origin.erase(S[i - N]);
        }
        else {
            origin[S[i - N]]--;
        }

        if (origin.find(S[i]) == origin.end()) {
            origin[S[i]] = 1;
        }
        else {
            origin[S[i]]++;
        }
    }
    if (tmp.size() == origin.size()) {
        bool flag = true;
        for (int k = 0; k < N; k++) {
            if (origin.find(W[k]) == origin.end() || (origin[W[k]] != tmp[W[k]])) {
                flag = false;
                break;
            }
        }
        if (flag) ans++;
    }

    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
