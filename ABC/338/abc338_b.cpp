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
// https://atcoder.jp/contests/abc338/tasks/abc338_b

int main(){
    string s; cin >> s;
    vector<int> cnt(26);
    rep(i, 0, s.size()){
        cnt[s[i]-'a']++;
    }

    int mx = 0;
    rep(i, 0, 26){
        chmax(mx, cnt[i]);
    }

    rep(i, 0, 26){
        if(cnt[i] == mx){
            cout << (char)('a'+i) << endl;
            break;
        }
    }
    
    return 0;
}