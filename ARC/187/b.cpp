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

/*

連結成分は区間に対応 → 連結性判定は隣接項だけやれば十分
i と i+1 が非連結な条件: min(a[0], a[1], ... , a[i]) > max(a[i+1], ... , a[n-1]);
これが成り立つ数列では、連結成分が増えるという主客転倒

*/

int main(){
    int n, m; cin >> n >> m;
    vector<int> b(n);
    rep(i, 0, n) cin >> b[i];
    int q = 0;
    rep(i, 0, n) if(b[i] == -1) q++;


    vector<int> mx(n+1, -1);
    rrep(i, n-1, 0){
        mx[i] = mx[i+1];
        chmax(mx[i], b[i]);
    }

    mint ans = mint(m).pow(q);

    int cnt_blank = 0, mi = IINF;
    rep(i, 0, n-1){
        // i と i+1 が非連結となる数列を数える
        if(b[i] == -1) cnt_blank++;
        else chmin(mi, b[i]);

        rep(j, 1, m+1){
            // min(a[0], a[1], ... , a[i]) = j の場合
            if(mi < j) continue;
            if(mi != j && cnt_blank == 0) continue;
            if(mx[i+1] >= j) continue;
            mint tmp = mint(m-j+1).pow(cnt_blank);
            if(mi != j) tmp -= mint(m-j).pow(cnt_blank); // 1つは j がないとダメ
            tmp *= mint(j-1).pow(q-cnt_blank);
            ans += tmp;
        }
        // cout << ans.val() << endl;
    }
    cout << ans.val() << endl;

    
    return 0;
}