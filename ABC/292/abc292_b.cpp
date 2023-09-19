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
// https://atcoder.jp/contests/abc292/tasks/abc292_b

int main(){
    int n, q; cin >> n >> q;
    vector<int> card(n);
    while(q--){
        int c, x; cin >> c >> x;
        x--;
        if(c == 1){
            card[x]++;
        }else if(c == 2){
            card[x] = 2;
        }else if(c == 3){
            if(card[x] >= 2){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
            
        }
    }
    
    return 0;
}