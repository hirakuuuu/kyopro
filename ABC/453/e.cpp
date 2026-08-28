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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

const int vmax = 250005; // ここは問題ごとに考慮が必要
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

int main(){
    initfact();
    int n; cin >> n;
    vector<int> l(n), r(n);
    vector<vector<int>> gl(n), gr(n);
    rep(i, 0, n){
        cin >> l[i] >> r[i];
        gl[l[i]].push_back(i);
        gr[r[i]].push_back(i);
    }

    set<int> s;
    vector<int> cnt(n);
    int cnt2 = 0;
    int cnt_l = 0, cnt_r = 0;
    mint ans = 0;
    rep(i, 1, n){
        // A: i, B: n-i
        for(auto nn: gl[i]){
            if(cnt[nn] == 0) s.insert(nn);
            cnt[nn]++;
            cnt_l++;
            if(cnt[nn] == 2) cnt2++;
        }
        for(auto nn: gr[n-i]){
            if(cnt[nn] == 0) s.insert(nn);
            cnt[nn]++;
            cnt_r++;
            if(cnt[nn] == 2) cnt2++;
        }

        // cout << i << ' ' << s.size() << ' ' << cnt_l << ' ' << cnt_r << ' ' << cnt2 << endl;

        if(s.size() == n && cnt_l >= i && cnt_r >= n-i){
            ans += choose(cnt2, i-(cnt_l-cnt2));
        }

        for(auto nn: gr[i]){
            if(cnt[nn] == 1) s.erase(nn);
            cnt[nn]--;
            cnt_l--;
            if(cnt[nn] == 1) cnt2--;
        }
        for(auto nn: gl[n-i]){
            if(cnt[nn] == 1) s.erase(nn);
            cnt[nn]--;
            cnt_r--;
            if(cnt[nn] == 1) cnt2--;
        }
    }
    cout << ans.val() << endl;
    return 0;
}