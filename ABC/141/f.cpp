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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
部分集合の xor が最大になるようにする問題に帰着できる
それは掃き出し法して，全部の xor をとればよい
（掃き出し法しても作れる xor の集合が変化せず，最大なのは明らかに全部使う場合なので）
*/

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    ll tmp = 0;

    rep(i, 0, 60){
        int cnt = 0;
        rep(j, 0, n){
            if((a[j]>>i)&1) cnt++;
        }
        if(cnt&1){
            tmp += (1LL<<i);
            rep(j, 0, n){
                if((a[j]>>i)&1) a[j] -= (1LL<<i);
            }
        }
    }
    // rep(i, 0, n){
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    
    sort(a.rbegin(), a.rend());
    int l = 0;
    rrep(i, 60, 0){
        if(l == n) break;
        int k = -1;
        rep(j, l, n){
            if((a[j]>>i)&1){
                k = j;
                break;
            }
        }
        if(k == -1) continue;
        swap(a[k], a[l]);
        rep(j, 0, n){
            if(j == l) continue;
            if(a[j]>>i&1) a[j] ^= a[l];
        }
        l++;
        // rep(j, 0, n) cout << a[j] << ' ';
        // cout << endl;
    }

    ll ans = 0;
    rep(i, 0, n) ans ^= a[i];
    cout << (ans*2)+tmp << endl;
    return 0;
}