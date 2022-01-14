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
#include <climits>

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

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll r = a % b;
        a = b; b = r;
    }
    return a;
}

// 볼록 다각형
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    int temp = x1 * y2 + x2 * y3 + x3 * y1;
    temp = temp - y1 * x2 - y2 * x3 - y3 * x1;
    if (temp > 0) return 1;
    else if (temp < 0) return -1;
    else return 0;
}

// 최대 공약수, 최소 공배수
ll GCP(ll a, ll b) {
    ll c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

ll LCM(ll a, ll b) {
    return a * b / GCP(a, b);
}


// manacher 알고리즘 출처 : https://www.crocus.co.kr/1075
int manacher[11];
void manachers(string S, int N) {
    int r = 0, p = 0;
    for (int i = 0; i < N; i++) {
        if (i <= r) manacher[i] = min(manacher[2 * p - i], r - i);
        else manacher[i] = 0;

        while (i - manacher[i] - 1 >= 0 && i + manacher[i] + 1 < N
            && S[i - manacher[i] - 1] == S[i + manacher[i] + 1])
            manacher[i]++;

        if (r < i + manacher[i]) {
            r = i + manacher[i];
            p = i;
        }
    }
}


//trie(트라이) https://ghdic.github.io/ps/boj-9202/
struct trie {
    trie* next[26];
    bool isFinish;

    trie() {
        memset(this->next, NULL, sizeof(this->next));
        this->isFinish = false;
    }
    ~trie() {
        for (int i = 0; i < 26; i++) {
            if (this->next[i])
                delete this->next[i];
        }
    }
    void insert(string key) {
        trie* pNode = this;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'A';
            if (!pNode->next[index])
                pNode->next[index] = new trie();
            pNode = pNode->next[index];
        }
        pNode->isFinish = true;
    }
};


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

vector <int> v(100005);
int N = 0, tmp;

int dp[100005][5][5] = { 0, };

int move(int from, int to) {    // from -> to로 이동시 비용
    if (from == 0) return 2;
    if (from == to) return 1;
    return (4 - (abs(from - to) % 2));
}

int dfs(int n, int x, int y) {  // DFS를 통해서 n번째의 위치에서 x, y의 발이 서로 갔을 때의 최솟값
    if (n == N - 1) return 0;
    if (dp[n][x][y] > 0) return dp[n][x][y];

    int left = dfs(n + 1, v[n], y) + move(x, v[n]);
    int right = dfs(n + 1, x, v[n]) + move(y, v[n]);

    return dp[n][x][y] = min(left, right);
}

void solved() {
    while (cin >> tmp) {
        v[N++] = tmp;
        if (tmp == 0) break;
    }
    cout << dfs(0, 0, 0);
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
