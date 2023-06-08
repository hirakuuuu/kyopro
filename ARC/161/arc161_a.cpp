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
// https://atcoder.jp/contests/arc161/tasks/arc161_a

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    sort(a.begin(), a.end());

    int pos_o = 0, pos_e = (n+1)/2;
    rep(i, 0, n-(n+1)/2){
        if(a[pos_o] >= a[pos_e] || a[pos_e] <= a[pos_o+1]){
            cout << "No" << endl;
            return 0;
        }
        pos_o++;
        pos_e++;
    }

    cout << "Yes" << endl;
    
    return 0;
}