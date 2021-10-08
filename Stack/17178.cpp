#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
/*#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <bitset>
#include <stack>*/

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
    vector <string> v(5 * N), tmp(5 * N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            string temp; cin >> temp;
            if (temp.size() == 3) {
                string ttemp;
                ttemp += '0'; ttemp += '0'; ttemp += temp[2];
                temp.pop_back();

                temp += ttemp;
            }
            else if (temp.size() == 4) {
                string ttemp;
                ttemp += '0'; ttemp += temp[2]; ttemp += temp[3];
                temp.pop_back(); temp.pop_back();

                temp += ttemp;
            }
            v[i * 5 + j] = temp;
            tmp[i * 5 + j] = temp;
        }
    }
    sort(tmp.begin(), tmp.end());

    stack <string> s;
    int j = 0;

    for (int i = 0; i < N * 5; i++) {
        if (!s.empty() && s.top() == tmp[i]) {
            s.pop();
            continue;
        }
        while (j < N * 5 && v[j] != tmp[i]) {
            s.push(v[j]);
            j++;
        }
        if (j == N * 5) {
            cout << "BAD";
            return;
        }

        if (v[j] == tmp[i]) {
            j++;
            continue;
        }
    }
    cout << "GOOD";
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
