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
    vector<ll> tousa;
    vector<ll> pre;
    rep(i, 1, 100) tousa.push_back(i);
    rep(i, 10, 100) pre.push_back(i);
    rep(_, 3, 19){
        vector<ll> pre_;
        for(auto p: pre){
            string tmp = to_string(p);
            int d = tmp[0]-tmp[1];
            int t = tmp[0]-'0';
            if(inr(1, t+d, 10)){
                tmp = (char)(t+d+'0')+tmp;
                ll nxt = stol(tmp);
                tousa.push_back(nxt);
                pre_.push_back(nxt);
            }
        }
        swap(pre_, pre);
    }
    sort(tousa.begin(), tousa.end());
    ll x; cin >> x;
    cout << *lower_bound(tousa.begin(), tousa.end(), x) << endl;

    return 0;
}