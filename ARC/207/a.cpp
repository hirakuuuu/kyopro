#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

const int vmax = 20005; // ここは問題ごとに考慮が必要
mint fact[vmax], finv[vmax];
void initfact(){
	fact[0]= 1;
	for(int i = 1; i < vmax; i++) fact[i] = fact[i-1]*i; // 階乗の計算
	finv[vmax-1] = fact[vmax-1].inv();
	for(int i = vmax-2; i >=0; i--) finv[i] = finv[i+1]*(i+1); // 階乗の逆元
}
// nCk
mint choose(int n,int k){
    if(n < 0 || k < 0 || n < k) return 0;
    if(n == 0 && k == 0) return 1;
	return fact[n]*finv[n-k]*finv[k];
}
// (a+b)!/(a!b!)
mint binom(int a,int b){
	return 0<=a&&0<=b?fact[a+b]*finv[a]*finv[b]:0;
}
// カタラン数（括弧列とか）
mint catalan(int n){
	return binom(n,n)-(n-1>=0?binom(n-1,n+1):0);
}
// 重複組み合わせ
mint homogeneous(int n, int k){
    return choose(n+k-1, k);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    initfact();

    int N;
    ll X;
    cin >> N >> X;

    vector<ll> A(N);
    vector<int> cnt(N, 0);
    int R = 0; // コスト N 以上のランプの数
    ll sum_a = 0;

    rep(i, 0, N) {
        cin >> A[i];
        sum_a += A[i];
        if (A[i] < N) {
            cnt[A[i]]++;
        } else {
            R++;
        }
    }

    // ベースライン: 全てのランプが最大効率でコストを下げた場合の合計
    // Reduction = (0 + 1 + ... + N-1)
    ll base_reduction = (ll)N * (N - 1) / 2;
    ll tmp_cost = sum_a - base_reduction;

    // dp[a][b]
    // a: 位置が決まっていない「コスト i 未満」のランプの数
    // b: 負のコストを 0 に補正するための累積値
    const int L = (N * N) + 1;
    vector dp(N + 1, vector<mint>(L, 0));
    dp[0][0] = 1;

    int processed_lamps = 0;
    rep(i, 0, N) {
        // 1. コスト i の各ランプを処理
        rep(rp, 0, cnt[i]) {
            vector n_dp(N + 1, vector<mint>(L, 0));
            rep(a, 0, N + 1) {
                rep(b, 0, L) {
                    if (dp[a][b].val() == 0) continue;
                    
                    // パターンA: このランプを保留にする（後で使う）
                    if (a + 1 <= N) {
                        n_dp[a + 1][b] += dp[a][b];
                    }
                    
                    // パターンB: 過去の空きスロット（0..i-1）のいずれかに埋める
                    // 空きスロットの数 = 現在の位置 i - (これまでに確定させたランプ数)
                    // 確定させた数 = すでに処理したランプ processed_lamps - 現在保留中の a
                    int empty_slots = i - (processed_lamps - a);
                    if (empty_slots > 0) {
                        n_dp[a][b] += dp[a][b] * empty_slots;
                    }
                }
            }
            processed_lamps++;
            dp = move(n_dp);
        }

        // 2. 位置 i を処理（この位置に何を置くか確定させる）
        vector n_dp(N + 1, vector<mint>(L, 0));
        rep(a, 0, N + 1) {
            rep(b, 0, L) {
                if (dp[a][b].val() == 0) continue;

                // パターンA: 保留中のランプ a 個のうちどれかを位置 i に置く
                // コストが a_L < i なので、補正が発生する
                if (a > 0) {
                    int next_b = b + (a - 1);
                    if (next_b < L) {
                        n_dp[a - 1][next_b] += dp[a][b] * a;
                    }
                }

                // パターンB: この位置 i は空けたまま（コスト i 以上のランプを後で入れる）
                int next_b = b + a;
                if (next_b < L) {
                    n_dp[a][next_b] += dp[a][b];
                }
            }
        }
        dp = move(n_dp);
    }

    mint ans = 0;
    rep(b, 0, L) {
        if (tmp_cost + b <= X) {
            // dp[0][b] は「コスト N 未満」が全て位置確定した状態
            ans += dp[0][b];
        }
    }

    // 最後に「コスト N 以上」のランプ R 個の並べ替えを考慮
    ans *= fact[R];

    cout << ans.val() << endl;

    return 0;
}