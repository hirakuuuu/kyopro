#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(ll i = a; i < n; i++)
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
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());

    vector<ll> sum(n+1);
    vector<set<ll>> s(n+1);
    rep(i, 0, n){
        sum[i+1] = sum[i]+a[i];
    }

    rep(i, 0, n){
        if(sum[i] < a[i]){
            if(k <= s[i].size()+a[i]-(sum[i]+1)){
                for(auto ss: s[i]){
                    s[i+1].insert(ss);
                }
                rep(j, sum[i]+1, sum[i]+k+1){
                    s[i+1].insert(j);
                }
                while(k--){
                    cout << *s[i+1].begin() << ' ';
                    s[i+1].erase(s[i+1].begin());
                }
                cout << endl;
                return 0;
            }

            for(auto ss: s[i]){
                s[i+1].insert(ss);
                s[i+1].insert(ss+a[i]);
            }
            rep(j, sum[i]+1, a[i]){
                s[i+1].insert(j);
            }
        }else{
            for(auto ss: s[i]){
                if(ss < a[i]) s[i+1].insert(ss);
            }
            if(s[i+1].size() >= k){
                while(k--){
                    cout << *s[i+1].begin() << ' ';
                    s[i+1].erase(s[i+1].begin());
                }
                cout << endl;
                return 0;
            }

            for(auto ss: s[i]){
                if(a[i] <= ss && ss <= sum[i] && s[i].count(ss-a[i])){
                    s[i+1].insert(ss);
                }
                if(sum[i] < ss+a[i]){
                    s[i+1].insert(ss+a[i]);
                }
            }
        }
        // cout << i << ' ' << a[i] << ' ' << sum[i+1] << endl;
        // for(auto ss: s[i+1]){
        //     cout << ss << ' ';
        // }
        // cout << endl;
    }

    rep(i, sum[n]+1, sum[n]+k+1){
        s[n].insert(i);
    }

    while(k--){
        cout << *s[n].begin() << ' ';
        s[n].erase(s[n].begin());
    }
    cout << endl;
    
    
    return 0;
}