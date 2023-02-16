#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int mod = 1000000007;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/jsc2019-qual/tasks/jsc2019_qual_c

/*
- s[0]とs[2n-1]はＢじゃないとダメ（1回しか反転できないから）
*/


int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<ll> a(2*n);
    a[0] = 1;
    rep(i, 1, 2*n){
        if(s[i-1] != s[i]){
            a[i] = a[i-1];
        }else{
            a[i] = 1-a[i-1];
        }

    }

    if(s[0] != 'B' or s[2*n-1] != 'B'){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1, dep = 0;
    rep(i, 0, 2*n){
        if(a[i] == 1) dep++;
        else{
            ans *= dep;
            ans %= mod;
            dep--;
        }
        if(dep < 0){
            cout << 0 << endl;
            return 0;
        }
    }

    if(dep != 0){
        cout << 0 << endl;
        return 0;
    }

    rep(i, 1, n+1){
        ans *= (ll)i;
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}