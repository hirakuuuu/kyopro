#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc237/tasks/abc237_d

int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n+1);
    int l = 0, r = n;
    rep(i, 0, n){
        if(s[i] == 'L'){
            a[r] = i;
            r--;
        }else{
            a[l] = i;
            l++;
        }
    }
    a[r] = n;
    rep(i, 0, n+1){
        cout << a[i] << ' ';
    }
    cout << endl;
    
    return 0;
}