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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    reverse(s.begin(), s.end());
    vector<int> ans;
    int p = 0;
    while(p < n){
        bool f = true;
        rrep(i, p+m, max(0, p+1)){
            if(s[i] == '0'){
                ans.push_back(i-p);
                p = i;
                f = false;
                break;
            }
        }
        if(f){
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto aa: ans){
        cout << aa << ' ';
    }
    cout << endl;
    return 0;
}