#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<int> h;

ll solve(int left, int right) {
    if (left == right)
        return h[left];

    int mid = (left + right) / 2;

    ll ret = max(solve(left, mid), solve(mid + 1, right));

    int lo = mid, hi = mid + 1;
    ll height = min(h[lo], h[hi]);

    ret = max(ret, height * 2);

    while (left < lo || hi < right) {
        if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
            hi++;
            height = min(height, (ll)h[hi]);
        }
        else {
            lo--;
            height = min(height, (ll)h[lo]);
        }
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    while (1) {
        int n; cin >> n;

        if (n == 0)
            break;

        h.clear();

        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp; h.push_back(tmp);
        }

        cout << solve(0, n - 1) << "\n";
    }
    
    return 0;
}
