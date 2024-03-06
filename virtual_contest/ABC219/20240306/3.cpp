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
// 

int main(){
    string x; cin >> x;
    vector<char> rev_x(26);
    rep(i, 0, 26){
        rev_x[x[i]-'a'] = i;
    }
    int n; cin >> n;
    vector<string> s(n), t(n);
    rep(i, 0, n){
        cin >> s[i];
        rep(j, 0, s[i].size()){
            t[i] += (char)rev_x[s[i][j]-'a']+'a';
        }
    }
    sort(t.begin(), t.end());
    rep(i, 0, n){
        rep(j, 0, t[i].size()){
            cout << (char)(x[t[i][j]-'a']);
        }
        cout << endl;
    }

    
    return 0;
}