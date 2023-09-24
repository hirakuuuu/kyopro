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

int main(){
    string s; cin >> s;
    if(s.size() != 8){
        cout << "No" << endl;
        return 0;
    }

    if(s[0] < 'A' || 'Z' < s[0] || s[7] < 'A' || 'Z' < s[7]){
        cout << "No" << endl;
        return 0;
    }

    bool f = (1 <= s[1]-'0' && s[1]-'0' <= 9);
    rep(i, 2, 7){
        int tmp = s[i]-'0';
        if(tmp < 0 || 9 < tmp) f = false;
    }

    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    
    return 0;
}