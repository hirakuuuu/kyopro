#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/arc159/tasks/arc159_b

ll f(ll a, ll b){
    if(b == 0) return 0;
    if(a == b) return 1;
    ll c = a-b;
    ll d = a%c;
    return (b-d)/c+f(c, d);
}

int main(){
    ll a, b; cin >> a >> b;
    if(a == b){
        cout << 1 << endl;
        return 0;
    }
    if(a < b) swap(a, b);

    ll cnt = 0;
    while(b){
        ll g = gcd(a, b);
        a /= g, b /= g;
        ll c = a-b;
        vector<ll> p;
        for(ll i = 2; i*i <= c; i++){
            if(c%i == 0){
                p.push_back(i);
                if(c/i != i) p.push_back(c/i);
            }
        }
        p.push_back(c);
        sort(p.begin(), p.end());

        ll t = 9e18;
        for(auto pp: p){
            if(a%pp <= t) t = a%pp;
        }

        if(t == 0){
            cnt += b;
            break;
        }
        cnt += t;
        a -= t;
        b -= t;
        //cout << cnt <<' ' << a << ' ' <<  b << endl;
    }
    cout << cnt << endl;
    return 0;
}