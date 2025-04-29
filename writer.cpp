/*
O(N^2) の解法
荷物がどこまで移動させられるかをスライド最小値の要領で計算
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 4;
void chmin(ll& a, ll b) {
    if (a > b) a = b;
}
void chmax(ll& a, ll b) {
    if (a < b) a = b;
}

pair<ll, ll> solve(vector<pair<ll, ll>> cargo) {
    const ll N = cargo.size();

    // 各境界の流量（正なら右に流れる，負なら左に流れる）
    // [左に流れる部分][中央 1 マス][右に流れる部分] という風に分かれる
    vector<ll> flow(N + 1);
    for (auto [id, w] : cargo) flow[id + 1]++;
    for (int i = 0; i < N; i++) flow[i + 1] += flow[i] - 1;

    // 中央を発見する
    int center = -1;
    for (int i = 0; i < N; i++) {
        if (flow[i] <= 0 && 0 <= flow[i + 1]) {
            center = i;
            break;
        }
    }
    assert(center != -1);

    // 中央より左を -1 倍
    for (ll& f : flow) f = abs(f);

    // flow の総和が必要な操作回数
    ll cnt = 0;
    for (ll i = 0; i < N + 1; i++) {
        cnt += flow[i];
    }

    // 中央から左に移動させるものの個数
    const ll cL = flow[center], cR = flow[center + 1] + 1;

    // 荷物を重みの昇順でソート
    sort(cargo.begin(), cargo.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    // dp[W の昇順に, i 個移動させた][中央から左に l 個移動させた] = 最小コスト
    vector dp(N + 1, vector(cL + 1, INF));
    dp[0][0] = 0;

    ll cnt_cen = 0;
    // fl: center をすべて無視した場合の各境界の残り容量
    auto fl = flow;
    for (ll i = 0; i < N; i++) {
        auto [id, w] = cargo[i];
        if (id < center) {
            // mx_l: 中心から左に移動させる荷物が最大何個まで id に到達するか？
            const ll mx_l = *min_element(fl.begin() + id + 1, fl.begin() + center + 1);
            // L[l] = 箱 i をどこまで左に流すことができるか？ = どこの境界で残り容量 0 に引っ掛かるか？
            vector<ll> L(cL + 1);
            for (ll j = 0; j <= id; j++) {
                if (fl[j] <= mx_l) L[fl[j]] = j;  // すでに中心から fl[j] 個を左に流している場合，箱 j で止まる
            }
            for (ll l = 0; l < cL; l++) chmax(L[l + 1], L[l]);

            for (ll l = max(0LL, cnt_cen - cR); l <= min(cL, cnt_cen); l++) {
                chmin(dp[i + 1][l], dp[i][l] + w * (id - L[l]));
            }
            // fl の更新
            for (ll j = L[0]; ++j <= id;) fl[j]--;
        } else if (id > center) {
            id++;
            // mx_r: r を増やしたとき最大何個まで id に降ってくるか？
            const ll mx_r = *min_element(fl.begin() + center + 1, fl.begin() + id);
            // R[r] = (箱 i をどこまで右に流すことができるか？) + 1 = どこの境界で残り容量 0 に引っ掛かるか？
            vector<ll> R(cR + 1, N);
            for (ll j = N; j >= id; j--) {
                if (fl[j] <= mx_r) R[fl[j]] = j;
            }
            for (ll r = 0; r < cR; r++) chmin(R[r + 1], R[r]);

            for (ll r = max(0LL, cnt_cen - cL); r <= min(cR, cnt_cen); r++) {
                chmin(dp[i + 1][cnt_cen - r], dp[i][cnt_cen - r] + w * (R[r] - id));
            }
            // fl の更新
            for (ll j = R[0]; --j >= id;) fl[j]--;
        } else {
            // 左右どちらに移動させるか選べる

            // L[l] = 箱 i をどこまで左に流すことができるか？ = どこの境界で残り容量 0 に引っ掛かるか？
            vector<ll> L(cL + 1);
            for (ll j = 0; j <= id; j++) {
                if (fl[j] <= cL) L[fl[j]] = j;
            }
            for (ll l = 0; l < cL; l++) chmax(L[l + 1], L[l]);

            for (ll l = max(0LL, cnt_cen - cR); l <= min(cL - 1, cnt_cen); l++) {
                chmin(dp[i + 1][l + 1], dp[i][l] + w * (id - L[l]));
            }

            // R[r] = (箱 i をどこまで右に流すことができるか？) + 1 = どこの境界で残り容量 0 に引っ掛かるか？
            id++;
            vector<ll> R(cR + 1, N);
            for (ll j = N; j >= id; j--) {
                if (fl[j] <= cR) R[fl[j]] = j;
            }
            for (ll r = 0; r < cR; r++) chmin(R[r + 1], R[r]);

            for (ll r = max(0LL, cnt_cen - cL); r <= min(cR, cnt_cen); r++) {
                chmin(dp[i + 1][cnt_cen - r], dp[i][cnt_cen - r] + w * (R[r] - id));
            }

            cnt_cen++;
        }
    }

    return {cnt, dp[N][cL]};
}

int main() {
    ll N;
    cin >> N;

    vector<int> A(N), W(N);
    for (int i = 0; i < N; i++) cin >> A[i], A[i]--;
    for (int i = 0; i < N; i++) cin >> W[i];

    // 荷物
    vector<pair<ll, ll>> cargo(N);
    for (int i = 0; i < N; i++) cargo[i] = {A[i], W[i]};

    // 各境界の流量が 0, i.e. 切れる場所 を発見する
    sort(cargo.begin(), cargo.end());
    vector<ll> bd = {0};
    for (ll i = 1; i < N; i++) {
        if (cargo[i - 1].first < i && i <= cargo[i].first) bd.push_back(i);
    }
    bd.push_back(N);

    pair<ll, ll> ans = {0LL, 0LL};
    for (ll i = 0; i + 1 < bd.size(); i++) {
        const ll l = bd[i], r = bd[i + 1];
        cout << l << ' ' << r << endl;
        vector C(cargo.begin() + l, cargo.begin() + r);
        for (auto& [id, w] : C) id -= l;
        // 独立した問題を解く
        auto [cnt, cost] = solve(C);
        ans.first += cnt;
        ans.second += cost;
    }

    cout << ans.first << ' ' << ans.second << '\n';

    return 0;
}
