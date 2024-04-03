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
// https://atcoder.jp/contests/agc012/tasks/agc012_b

int main(){
    string s; cin >> s;
    int k; cin >> k;
    int n = (int)s.size();
    vector<int> acc(n+1);
    rep(i, 0, n) acc[i+1] = acc[i]+(s[i]=='.');
    int ok = 0, ng = n+1; 
    while(ng-ok > 1){
        int mid = (ok+ng)/2;
        bool f = false;
        rep(l, 0, n-mid+1){
            int r = l+mid;
            if(acc[r]-acc[l] <= k) f = true;
        }
        if(f) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    
    return 0;
}