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
// https://atcoder.jp/contests/abc323/tasks/abc323_b

int main(){
    int n; cin >> n;
    vector<string> s(n);
    vector<pair<int, int>> result(n);
    rep(i, 0, n){
        cin >> s[i];
        result[i].second = -i-1;
        rep(j, 0, n){
            if(s[i][j] == 'o') result[i].first++;
        }
    }

    sort(result.begin(), result.end());
    reverse(result.begin(), result.end());

    rep(i, 0, n){
        cout << -result[i].second << ' ';
    }
    cout << endl;


    
    return 0;
}