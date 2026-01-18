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
    int n; cin >> n;
    set<pair<ll, ll>> pos;
    ll sum = 0;
    {
        ll x; cin >> x;
        pos.insert({0LL, x});
        pos.insert({x, x});
        sum += x;
        sum += x;
    }
    cout << sum << endl;
    rep(i, 1, n){
        ll x; cin >> x;
        auto itr_r = pos.lower_bound({x, 0});
        if(itr_r == pos.begin()){
            auto [pr, dr] = *itr_r;
            if(dr > pr-x){
                sum -= dr;
                pos.erase(pos.find({pr, dr}));
                sum += pr-x;
                pos.insert({pr, pr-x});
            }
            sum += pr-x;
            pos.insert({x, pr-x});
        }else{
            auto itr_l = prev(itr_r);
            if(itr_r == pos.end()){
                auto [pl, dl] = *itr_l;
                if(dl > x-pl){
                    sum -= dl;
                    pos.erase(pos.find({pl, dl}));
                    sum += x-pl;
                    pos.insert({pl, x-pl});
                }
                sum += x-pl;
                pos.insert({x, x-pl});
            }else{
                auto [pr, dr] = *itr_r;
                auto [pl, dl] = *itr_l;
                if(dr > pr-x){
                    sum -= dr;
                    pos.erase(pos.find({pr, dr}));
                    sum += pr-x;
                    pos.insert({pr, pr-x});
                }
                if(dl > x-pl){
                    sum -= dl;
                    pos.erase(pos.find({pl, dl}));
                    sum += x-pl;
                    pos.insert({pl, x-pl});
                }

                ll tmp = min(pr-x, x-pl);
                sum += tmp;
                pos.insert({x, tmp});
            }
        }
        cout << sum << endl;
    }
    
    return 0;
}