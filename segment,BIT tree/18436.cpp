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


// 콤비네이션 횟수 : 시간초과 계산 잘하기
ll combination(ll n, ll r) {
    if (n == r || r == 0) return 1;
    else return combination(n - 1, r - 1) + combination(n - 1, r);
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


/* 다익 스트라 알고리즘
vector <pair<int, int>> dijkstraGraph[1000001];

vector <int> dijkstra(int start, int vertex) {
    vector <int> distance(vertex, INF);
    distance[start] = 0;

    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;

        pq.pop();

        if (distance[cur] < cost)
            continue;

        for (int i = 0; i < dijkstraGraph[cur].size(); i++) {
            int neighbor = dijkstraGraph[cur][i].first;
            int neighborDistance = cost + dijkstraGraph[cur][i].second;

            if (distance[neighbor] > neighborDistance) {
                distance[neighbor] = neighborDistance;
                pq.push({ neighborDistance, neighbor });
            }
        }
    }

    return distance;
}*/


// Union-Find
int parent[25] = { 0, };
void init(int N) { rep(i, N + 1) parent[i] = i; }

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x < y) parent[y] = x;
    else parent[x] = y;
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


// 느리게 갱신되는 세그먼트 트리 : https://everenew.tistory.com/84
/*vector<ll> tree(41);
vector<ll> lazy(41);
ll arr[11];

ll init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    else {
        return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
    }
}

void updateLazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) { //리프노드가 아닌경우
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void updateRange(int node, int start, int end, int left, int right, long long diff) {
    updateLazy(node, start, end);
    if (right < start || end < left) {
        return;
    }
    else if (left <= start && end <= right) {
        tree[node] += (end - start + 1) * diff;
        if (start != end) {
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return;
    }
    updateRange(node * 2, start, (start + end) / 2, left, right, diff);
    updateRange(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
    return;
}

long long sum(int node, int start, int end, int left, int right) {
    updateLazy(node, start, end);
    if (right < start || end < left) {
        return 0;
    }
    else if (left <= start && end <= right) {
        return tree[node];
    }
    return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}*/


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

int N, M;
int A[100005] = { 0, };
vector <pair<int, int>> tree(4 * 100005);

pair<int, int> segment_init(int start, int end, int index) {
    if (start == end) {
        if (A[start] % 2 == 0) return tree[index] = { 0, 1 };
        else return tree[index] = { 1, 0 };
    }
    int mid = (start + end) / 2;

    pair <int, int> tmpA = segment_init(start, mid, index * 2);
    pair <int, int> tmpB = segment_init(mid + 1, end, index * 2 + 1);

    return tree[index] = { tmpA.first + tmpB.first, tmpA.second + tmpB.second };
}

void segment_update(int start, int end, int index, int target, int z) {
    if (target < start || end < target) return;
    
    if (z % 2 == 0) tree[index] = { tree[index].first - 1, tree[index].second + 1 };
    else tree[index] = { tree[index].first + 1, tree[index].second - 1 };

    if (start == end) return;
    
    int mid = (start + end) / 2;
    
    segment_update(start, mid, index * 2, target, z);
    segment_update(mid + 1, end, index * 2 + 1, target, z);
}

int query(int start, int end, int index, int left, int right, int x) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) {
        if (x == 2) return tree[index].second;
        else return tree[index].first;
    }
    
    int mid = (start + end) / 2;
    return query(start, mid, index * 2, left, right, x) +
        query(mid + 1, end, index * 2 + 1, left, right, x);
}

void solved() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];

    segment_init(1, N, 1);

    cin >> M;
    for (int i = 0; i < M; i++) {
        int x, y, z; cin >> x;
        if (x == 1) {
            cin >> y >> z;
            if (A[y] % 2 == z % 2) continue;
            A[y] = z;
            segment_update(1, N, 1, y, z);
        }
        else {
            cin >> y >> z;
            cout << query(1, N, 1, y, z, x) << "\n";
        }
    }
}


int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
