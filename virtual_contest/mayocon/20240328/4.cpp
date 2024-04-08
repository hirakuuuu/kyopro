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
    string x; cin >> x;
    vector<ll> ans;
    ll sum = 0, tmp = 0;
    rep(i, 0, x.size()) sum += x[i]-'0';
    int id = 0;
    reverse(x.begin(), x.end());
    while((sum+tmp) > 0){
        ans.push_back((sum+tmp)%10);
        tmp = (sum+tmp)/10;
        if(id < x.size()) sum -= x[id]-'0';
        id++;
    }
    reverse(ans.begin(), ans.end());
    for(auto aa: ans){
        cout << aa;
    }
    cout << endl;
    
    return 0;
}