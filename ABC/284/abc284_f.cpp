#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc284/tasks/abc284_f

const ll b = 26;
vector<ll> b_n(1000005);
void init_b(){
    b_n[0] = 1;
    rep(i, 1, 1000005){
        b_n[i] = b_n[i-1]*b;
        b_n[i] %= MOD;
    }
}

int main(){
    int n; cin >> n;
    string s; cin >> s;
    init_b();
    vector<int> t(2*n);
    rep(i, 0, 2*n) t[i] = s[i]-'a';

    vector<ll> s_hash(n+1);
    rep(i, 0, n){
        s_hash[n] *= b;
        s_hash[n] += t[2*n-i-1];
        s_hash[n] %= MOD;
    }

    rep(i, 0, n){
        ll s_hash_l = (s_hash[n-i]-(t[2*n-i-1]*b_n[n-1])%MOD+MOD)%MOD;
        s_hash[n-1-i] = (s_hash_l*b+t[n-i-1])%MOD;
    }

    vector<ll> l_hash(n+1), r_hash(n+1);
    rep(i, 0, n){
        l_hash[n-i-1] = l_hash[n-i]+t[i]*b_n[n-i-1];
        l_hash[n-i-1] %= MOD;

        r_hash[i+1] = r_hash[i]+t[2*n-i-1]*b_n[i];
        r_hash[i+1] %= MOD;
    }

    rep(i, 0, n+1){
        cout << s_hash[n-i] << ' ' << l_hash[i] << ' ' << r_hash[i] << endl;
        if(s_hash[n-i] == (l_hash[i]+r_hash[i])%MOD){
            string ans = s.substr(n-i, n);
            reverse(ans.begin(), ans.end());
            cout << ans << endl;
            cout << n-i << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    
    
    return 0;
}