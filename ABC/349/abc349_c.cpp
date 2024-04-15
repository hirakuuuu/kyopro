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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){
    string s, t; cin >> s >> t;
    vector<vector<int>> pos(26);
    rep(i, 0, s.size()){
        pos[s[i]-'a'].push_back(i);
    }
    rep(i, 0, 26) rep(j, 0, 26) rep(k, 0, 26){
        string tmp;
        auto itr = lower_bound(pos[i].begin(), pos[i].end(), 0);
        if(itr == pos[i].end()) continue;
        itr = upper_bound(pos[j].begin(), pos[j].end(), *itr);
        if(itr == pos[j].end()) continue;
        tmp += ('A'+i);
        tmp += ('A'+j);
        tmp += 'X';
        if(tmp == t){
            cout << "Yes" << endl;
            return 0;
        }
        itr = upper_bound(pos[k].begin(), pos[k].end(), *itr);
        if(itr == pos[k].end()) continue;
        tmp[2] = ('A'+k);
        if(tmp == t){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
    return 0;
}