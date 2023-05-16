#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define rrep(i, a, n) for(ll i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

vector<ll> Q;

// 0ならば素数, 0でないなら最小の素因数
vector<int> erat(1000005);
void init_e(){
    rep(i, 2, sqrt(1000005)){
        if(erat[i] == 0){
            for(int j = i*i; j <= 1000005; j += i){
                if(erat[j] == 0) erat[j] = i;
            }
        }
    }
}


int main(){
    ll n; cin >> n;
    init_e();
    rep(i, 2, 1000005){
        if(erat[i] == 0) Q.push_back(i);
    }
    ll ans = 0;
    for(auto q: Q){
        ans += lower_bound(Q.begin(), Q.end(), min(q, n/(q*q*q)+1))-Q.begin();
    }
    cout << ans << endl;

    

    
    return 0;
}