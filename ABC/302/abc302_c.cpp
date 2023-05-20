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
// https://atcoder.jp/contests/abc302/tasks/abc302_c

int main(){
    int n, m; cin >> n >> m;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    vector<int> jun(n);
    iota(jun.begin(), jun.end(), 0);

    do{
        bool f = true;
        rep(i, 0, n-1){
            int cnt = 0;
            rep(j, 0, m){
                cnt += (s[jun[i]][j] != s[jun[i+1]][j]);
            }
            if(cnt != 1) f = false;
        }
        if(f){
            cout << "Yes" << endl;
            return 0;
        }
    }while(next_permutation(jun.begin(), jun.end()));
    cout << "No" << endl;
    
    return 0;
}