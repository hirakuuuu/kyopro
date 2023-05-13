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
// https://atcoder.jp/contests/abc301/tasks/abc301_b

int main(){
    int n; cin >>n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n-1){
        if(a[i] > a[i+1]){
            rep(j, 0, a[i]-a[i+1]){
                cout << a[i]-j << ' ';
            }
        }else{
            rep(j, 0, a[i+1]-a[i]){
                cout << a[i]+j << ' ';
            }   
        }
    }
    cout << a[n-1] << endl;
    
    return 0;
}