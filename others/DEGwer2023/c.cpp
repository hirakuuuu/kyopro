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
// https://atcoder.jp/contests/DEGwer2023/tasks/c

int main(){
    rep(w, 1, 5){
        int ans = 0;
        rep(i, 0, 1<<w){
            rep(j, i, 1<<w){
                rep(l, j, 1<<w){
              
                vector<int> b(w);
                rep(k, 0, w){
                    if((i&(1<<k))) b[w-k-1] += 4;
                    if((j&(1<<k))) b[w-k-1] += 2;
                    if((l&(1<<k))) b[w-k-1] += 1;
                }
                vector<int> c = b;
                sort(c.begin(), c.end());
                if(b == c){
                    // rep(k, 0, w){
                    //     if((i&(1<<k))) cout << 1;
                    //     else cout <<0;
                    // }
                    // cout << endl;
                    // rep(k, 0, w){
                    //     if((j&(1<<k))) cout << 1;
                    //     else cout << 0;
                    // }
                    // cout << endl << endl;;
                    ans++;
                }
  
                }
            }
        }
        cout << ans << endl;
    
    }
    
    return 0;
}