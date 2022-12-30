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
// https://atcoder.jp/contests/agc056/tasks/agc056_a

int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i, 0, n){
        rep(j, 0, n){
            s[i] += '.';
        }
    }
    rep(i, 0, n){
        s[i][(3*i)%n] = s[i][(3*i+1)%n] = s[i][(3*i+2)%n] = '#';
    }
    //     rep(i, 0, n){
    //     cout << s[i] << endl;
    // }

    if(n%3 != 0) swap(s[n/3], s[n-n/3-1]);

    rep(i, 0, n){
        cout << s[i] << endl;
    }
    
    
    return 0;
}