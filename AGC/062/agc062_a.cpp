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
// https://atcoder.jp/contests/agc062/tasks/agc062_a

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        vector<int> cnt(2);
        rep(i, 0, n) cnt[s[i]-'A']++;

        bool f = false;
        rep(i, 0, n-1){
            if(s[i] == 'B' && s[i+1] == 'A'){
                f = true;
                break;
            }
        }

        if(cnt[0] == 0){
            cout << 'B' << endl;
        }else if(cnt[1] == 0){
            cout << 'A' << endl;
        }else if(f){
            cout << 'A' << endl;
        }else{
            cout << 'B' << endl;
        }
    }
    
    return 0;
}