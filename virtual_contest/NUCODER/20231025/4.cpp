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
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        vector<int> a(n);
        rep(i, 0, n) cin >> a[i];

        if(n%2 == 1){
            cout << "Second" << endl;
        }else{
            map<int, int> cnt;
            rep(i, 0, n) cnt[a[i]]++;
            bool f = false;
            rep(i, 0, n){
                if(cnt[a[i]]%2 == 1) f = true;
            }
            if(f) cout << "First" << endl;
            else cout << "Second" << endl;
        }
    }
    
    return 0;
}