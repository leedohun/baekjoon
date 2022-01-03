#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <bitset>
#include <stack>
#include <cmath>
#include <cstring>
#include <list>
#include <numeric>

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
typedef vector<ll> vl;
typedef vector<string> vs;

const ll _INF = 1000000000000000000;
const ll INF = 1000000000;
const int MOD = 1000000007;
const int MAX = 1000005;


/*
####################################################################################
####################################################################################
####################################################################################
####################################################################################

                                 풀   이   시   작

####################################################################################
####################################################################################
####################################################################################
####################################################################################
*/

void solved() {
    int N, M; cin >> N >> M;
    vii v;
    rep(i, M) {
        int tmp; cin >> tmp;
        
        int j;
        bool flag = false;
        for (j = 0; j < v.size(); j++) {
            if (v[j].first == tmp) {
                flag = true;
                break;
            }
        }

        if (!flag) {
            if (v.size() < N) {
                v.push_back({ tmp, 1 });
            }
            else if (v.size() == N) {
                int cnt = MAX;
                for (int k = 0; k < v.size(); k++) {
                    if (v[k].second < cnt) {
                        cnt = v[k].second;
                        j = k;
                    }
                }
                v.erase(v.begin() + j);
                v.push_back({ tmp, 1 });
            }
        }
        else {
            v[j].second += 1;
        }
    }
    sort(v.begin(), v.end());
    rep(i, v.size()) cout << v[i].first << " ";
}


int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
