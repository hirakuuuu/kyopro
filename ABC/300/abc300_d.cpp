#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc300/tasks/abc300_d

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
    init_e();
    ll n; cin >> n;
    vector<ll> p;
    rep(i, 2, 1000005){
        if(erat[i] == 0) p.push_back(i);
    }

    int ans = 0;
    rep(i, 0, p.size()-2){
        ll a = p[i], c = i+2;
        if(a > 1000) continue;

        while(c < p.size() and a < n/(a*a*p[c]*p[c])){
            if(p[c] <= n/(a*a*p[c]*p[c])) ans += lower_bound(p.begin(), p.end(), p[c]) - upper_bound(p.begin(), p.end(), a);
            else ans += upper_bound(p.begin(), p.end(), n/(a*a*p[c]*p[c])) - upper_bound(p.begin(), p.end(), a);
            c++;
        }
    }
    cout << ans << endl;
    
    return 0;
}