#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main(){
    int q; cin >> q;
    stack<pair<ll, ll>> stc;
    set<pair<ll, ll>> s;
    ll total = 0;
    while(q--){
        int op; cin >> op;
        if(op == 1){
            ll x, c; cin >> x >> c;
            stc.push({x, c});
            total += x;
            s.insert({total, c});
        }else if(op == 2){
            ll x; cin >> x;
            while(x && !stc.empty()){
                pair<ll, ll> t = stc.top(); stc.pop();
                if(x < t.first){
                    t.first -= x;
                    stc.push(t);
                    s.erase(s.find({total, t.second}));
                    total -= x;
                    s.insert({total, t.second});
                    x = 0;
                }else{
                    x -= t.first;
                    s.erase(s.find({total, t.second}));
                    total -= t.first;
                }
            }
        }else{
            ll x; cin >> x;
            auto itr = s.lower_bound({total-x+1, 0});
            cout << (*itr).second << endl;
        }
    }


    return 0;
}