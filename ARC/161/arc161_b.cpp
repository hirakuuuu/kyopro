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
// https://atcoder.jp/contests/arc161/tasks/arc161_b

int main(){
    int T; cin >> T;

    vector<ll> three;
    rep(i, 0, 61){
        rep(j, i+1, 61){
            rep(k, j+1, 61){
                ll tmp = (1LL<<i)+(1LL<<j)+(1LL<<k);
                three.push_back(tmp);
            }
        }
    }

    sort(three.begin(), three.end());
    while(T--){
        ll n; cin >> n;
        auto itr = upper_bound(three.begin(), three.end(), n);
        if(itr == three.begin()){
            cout << -1 << endl;
        }else{
            --itr;
            cout << *itr << endl;
        }

    }
    
    return 0;
}