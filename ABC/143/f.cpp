#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
ansが固定されていると、ある種類の数は最大ans回しか使えない。
すべての種類の数についてmin(個数,ans)の総和をとったとき、これがK*ans以上であれば、そのKについてansは達成できる。
この性質までたどり着くのが長い。

*/

int main(){
    int n; cin >> n;
    vector<int> a(n), c(n);
    rep(i, 0, n){
        cin >> a[i];
        a[i]--;
        c[a[i]]++;
    }
    sort(c.begin(), c.end());
    vector<ll> acc(n+1);
    rep(i, 0, n) acc[i+1] = acc[i]+c[i];

    rep(k, 1, n+1){
        // k 個選ぶ場合の操作回数の最大値を求める
        ll ok = 0, ng = IINF;
        while(ng-ok > 1){
            ll mid = (ok+ng)/2;
            ll over = c.end()-lower_bound(c.begin(), c.end(), mid);
            ll tmp = acc[n-over]+mid*over;
            if(tmp >= k*mid) ok = mid;
            else ng = mid;
        }
        cout << ok << endl;
    }
    
    return 0;
}