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
// https://atcoder.jp/contests/abc311/tasks/abc311_a

int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> cnt(3);
    rep(i, 0, n){
        cnt[s[i]-'A']++;
        if(cnt[0] && cnt[1] && cnt[2]){
            cout << i+1 << endl;
            break;
        }
    }
    
    return 0;
}