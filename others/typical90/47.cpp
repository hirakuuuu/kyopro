#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_au

string rgb = "RGB";
int want_c(int a, int b){
    if(a == b) return a;
    else return ((a+b)+(a+b)%3)%3;
}

ll hashs[1000005], hasht[1000005];
ll hashws[3][1000005], hashwt[3][1000005];

ll binpower(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b%2) res = (res*a)%mod;
        a = (a*a)%mod;
        b /= 2;
    }
    return res;
}

int main(){
    int n; cin >> n;
    string s, t; cin >> s >> t;
    vector<string> ws(3), wt(3);
    map<char, int> m;
    m['R'] = 0, m['G'] = 1, m['B'] = 2;
    rep(i, 0, 3){
        rep(j, 0, n) ws[i] += rgb[want_c(i, m[s[j]])];
        rep(j, 0, n) wt[i] += rgb[want_c(i, m[t[j]])];
    }
    ll bs = 1, bt = 1;
    rep(i, 1, n+1){
        hashs[i] = (hashs[i-1]+bs*m[s[i-1]])%mod;
        hasht[i] = (hasht[i-1]+bt*m[t[i-1]])%mod;
        bs *= 3; bs %= mod;
        bt *= 3; bt %= mod;
    }
    rep(i, 0, 3){
        bs = 1, bt = 1;
        rep(j, 1, n+1){
            hashws[i][j] = (hashws[i][j-1]+bs*m[ws[i][j-1]])%mod;
            hashwt[i][j] = (hashwt[i][j-1]+bt*m[wt[i][j-1]])%mod;
            bs *= 3; bs %= mod;
            bt *= 3; bt %= mod;
        }
    }


    int ans = 0;
    rep(i, 0, n){
        int fs = 0, ft = 0;
        rep(j, 0, 3){
            if((hashs[n]-hashs[i]+mod)%mod == (hashwt[j][n-i]*binpower(3, i))%mod) fs = 1;
            if((hasht[n]-hasht[i]+mod)%mod == (hashws[j][n-i]*binpower(3, i))%mod) ft = 1;
        }
        if(i == 0) ans += fs|ft;
        else ans += fs+ft;
    }
    cout << ans << endl;
    return 0;
}