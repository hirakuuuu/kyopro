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

int main(){
    ll n; cin >> n;
    vector<int> cnt(60);
    rep(i, 0, 60){
        if((n&(1LL<<i)) > 0){
            cnt[i]++;
        }
    }

    set<ll> s;
    s.insert(0);
    rep(i, 0, 60){
        if(cnt[i]){
            set<ll> t = s;
            for(auto ss: t){
                s.insert(ss+(1LL<<i));
            }
        }
    }
    
    for(auto ss: s){
        cout << ss << '\n';
    }



    
    return 0;
}