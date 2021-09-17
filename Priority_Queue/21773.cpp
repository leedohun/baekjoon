#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;

struct P {
    int x; int y; int time;
};

struct compare {
    bool operator()(P& a, P& b) {
        if (a.x != b.x)
            return a.x < b.x;
        return
            a.y > b.y;
    }
};

priority_queue <P, vector<P>, compare> pq;

void solved() {
    int N, T; cin >> N >> T;
    rep(i, T) {
        int a, b, c; cin >> a >> b >> c;
        pq.push({ c, a, b });
    }

    rep(i, N) {
        int a = pq.top().x;
        int b = pq.top().y;
        int t = pq.top().time;
        
        pq.pop();

        cout << b << "\n";
        if(t - 1 > 0)
            pq.push({ a - 1, b, t - 1 });
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
