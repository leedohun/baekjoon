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

void solved() {
    int N; cin >> N;
    vector <P> v(N);
    rep(i, N) cin >> v[i].x >> v[i].y;

    sort(v.begin(), v.end(), cmp);

    vector <int> ans;
    set <int> tmp;
    priority_queue <P, vector<P>, compare> pq;
    
    for (int i = 0; i < N; i++) {
        while (!pq.empty()) {
            if (pq.top().x <= v[i].x) {
                tmp.insert(pq.top().y);
                pq.pop();
            }
            else
                break;
        }
        if (tmp.empty()) {
            ans.push_back(1);
            pq.push({ v[i].y, ans.size() - 1 });
        }
        else {
            auto iter = tmp.begin();
            pq.push({ v[i].y, *iter });
            ans[*iter]++;
            tmp.erase(iter);
        }
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
