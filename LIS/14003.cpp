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
    int x; int y;
};

struct compare {
    bool operator()(P& a, P& b) {
        if (a.x != b.x)
            return a.x < b.x;
        return
            a.y < b.y;
    }
};
priority_queue <P, vector<P>, compare> pq;

bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
    }
    return false;
}

vector <int> lis;
pair <int, int> answer[1000005];
vector <int> v(1000005);

int binarySerach(int left, int right, int target) {
    while (left < right) {
        int mid = (left + right) / 2;

        if (lis[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return right;
}

void solved() {
    int N; cin >> N;
    rep(i, N) cin >> v[i];

    lis.push_back(v[0]);
    answer[0] = { 0, v[0] };
    int i = 1;
    int idx = 0;

    while (i < N) {
        if (lis[lis.size() - 1] < v[i]) {
            lis.push_back(v[i]);
            answer[i] = { ++idx, v[i] };
        }
        else {
            int idx = binarySerach(0, lis.size(), v[i]);
            lis[idx] = v[i];

            answer[i] = { idx, v[i] };
        }
        i += 1;
    }

    cout << lis.size() << "\n";

    int num = lis.size() - 1;
    stack <int> s;
    for (int i = N - 1; 0 <= i; i--) {
        if (answer[i].first == num) {
            s.push(answer[i].second);
            num--;
        }
    }

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
