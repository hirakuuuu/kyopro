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


int main(){

    // いくつか数を選んで、gcd をとった値を g とする
    // g が min(A) 以下ならその値を達成する操作が可能
    // そうじゃない場合は無理？

    int n; cin >> n; 
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = (int)a.size();

    // vector<int> arr = {a[0]};
    map<int, int> t;
    rep(i, 0, n){
        for(int j = 1; j*j <= a[i]; j++){
            if(a[i]%j == 0){
                if(t.find(j) != t.end()) t[j] = gcd(a[i], t[j]);
                else t[j] = a[i];

                int k = a[i]/j;
                if(k != j){
                    if(t.find(k) != t.end()) t[k] = gcd(a[i], t[k]);
                    else t[k] = a[i];
                }
            }
        }
    }

    int ans = 0;
    for(auto [key, val]: t){
        // cout << key << ' ' << val << endl;
        if(key > a[0]) break;
        if(key == val) ans++;
    }
    cout << ans << endl;



    return 0;
}