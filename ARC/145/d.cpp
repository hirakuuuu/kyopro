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

int main(){
    
    ll n, m; cin >> n >> m;
    ll a = (m%n+n)%n;

    vector<ll> d;
    d.push_back(1);
    ll r = 2;
    while(d.size() < n){
        int sz = d.size();
        rep(i, 0, sz-1) d.push_back(d[i]);
        d.push_back(r);
        r = 3LL*r-1;
    }

    ll sum = 0;
    rep(i, 0, n-1){
        sum += (n-1-i)*d[i];
    }

    set<ll> s;
    ll plus = 0;
    rrep(i, n-3, 0){
        ll minus = 0;
        rrep(j, i, 0){
            minus += d[j];
            assert(plus-minus != 0);
            if(plus-minus < 0){
                s.insert(minus-plus);
            }
        }
        plus += d[i];
    }

    // sum%n == a となるようにしたい
    // (a-sum%n+n)%n を足す, n を足す
    sum -= d[n-2];
    ll tmp = (a-sum%n+n)%n;
    while(true){
        if(s.find(tmp) == s.end()){
            d[n-2] = tmp;
            break;
        }
        tmp += n;
    }
    sum += tmp;
    ll b = (m-sum)/n;
    rep(i, 0, n){
        cout << b << ' ';
        if(i < n-1) b += d[i];
    }
    cout << endl;


    return 0;
}