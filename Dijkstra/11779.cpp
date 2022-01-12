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

int dx[8] = { 0,0,-1,1,-1,-1,1,1 };
int dy[8] = { -1,1,0,0,-1,1,-1,1 };

struct P {
    ll x; ll y; ll cnt;
};

struct compare {
    bool operator()(P& a, P& b) {
        if (a.x != b.x)
            return a.x < b.x;
        return
            a.y < b.y;
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

struct node {
    ll vertex; ll weight;
    node() {};
    node(ll vertex, ll weight) : vertex(vertex), weight(weight) {};
    bool operator<(const node& other) const {
        return weight > other.weight;
    }
};

int N, M;
ll a, b, w;
int A, B;

vector <node> v[1005];
pair<ll, ll> dist[1005];

vector <ll> ans;

ll tmp = 0;

void solved() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> w;
        v[a].push_back(node(b, w));
    }
    cin >> A >> B;

    priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    for (int i = 1; i <= N; i++) dist[i].first = 9876543210;

    pq.push({ 0, A });
    dist[A].first = 0;

    while (!pq.empty()) {
        int now = pq.top().second;
        int weight = pq.top().first; pq.pop();

        if (tmp < weight) break;

        for (int i = 0; i < v[now].size(); i++) {
            node next = v[now][i];

            if (dist[next.vertex].first > weight + next.weight) {
                dist[next.vertex].first = weight + next.weight;
                tmp = weight + next.weight;

                dist[next.vertex].second = now;
                pq.push({ weight + next.weight, next.vertex });
            }
        }
    }
    for (int i = B; i != A; i = dist[i].second) ans.push_back(i);
    ans.push_back(A);

    cout << dist[B].first << "\n";
    cout << ans.size() << "\n";
    for (int i = ans.size() - 1; 0 <= i; i--) cout << ans[i] << " ";
}


int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
