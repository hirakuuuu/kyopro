// レビュアー解法
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define inr(l, x, r) (l <= x && x < r)
using ll = long long;

int main() {
    ll N = 5000;
    cout << N << endl;

    // A は sqrt(N) 個ごとに区切れる箇所ができるようにする
    vector<ll> A(N);
    for (ll pos = 0; pos < N;) {
        ll len = rand() % 10 + 1;  // 長さが 1 ~ 10 になるようにする
        ll l = pos, r = min(N, pos + len);

        // [l, r) の区間を部分問題とする
        ll mid = rand() % (r - l) + l;
        while (pos <= l + max(mid - l, r - 1 - mid) + 1) {
            A[pos] = mid;
            pos++;
        }
        while (pos < r) {
            A[pos] = rand() % (r - l) + l;
            pos++;
        }
    }

    for(int i = 0; i < N; i++){
        cout << A[i] << ' ';
    }
    cout << endl;

    for(int i = 0; i < N; i++){
        cout << 1 << ' ';
    }
    cout << endl;



    return 0;
}