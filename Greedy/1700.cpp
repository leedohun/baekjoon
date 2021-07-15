#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
//#include <iostream>
//#include <cstring>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//#include <string>
//#include <climits>
//#include <bitset>
//#include <queue>
//#include <map>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

int N, K;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    vector <int> v(K);

    rep(i, K) cin >> v[i];

    set <int> s;
    int ret = 0;

    rep(i, K){
        if (s.find(v[i]) != s.end()) continue;
        
        if (s.size() < N) {
            s.insert(v[i]);
            continue;
        }

        int ttmp, idx = -1;
        for (auto iter = s.begin(); iter != s.end(); iter++) {
            int idxTmp = 0;
            for (int j = i; j < K; j++) {
                if (*iter == v[j]) break;
                idxTmp++;
            }

            if (idxTmp > idx) {
                ttmp = *iter;
                idx = idxTmp;
            }
        }
        for (auto iter = s.begin(); iter != s.end(); iter++) {
            if (ttmp == *iter) {
                s.erase(iter);
                break;
            }
        }
        s.insert(v[i]);
        ret++;
    }

    cout << ret;
}
