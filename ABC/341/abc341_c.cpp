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
// https://atcoder.jp/contests/abc341/tasks/abc341_c

int main(){
    int h, w, n; cin >> h >> w >> n;
    string t; cin >> t;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];
    int ans = 0;
    string dir = "ULDR";
    rep(i, 0, h){
        rep(j, 0, w){
            if(s[i][j] == '#') continue;
            bool f = true;
            int x = i, y = j;
            rep(k, 0, n){
                if(!f) break;
                rep(l, 0, 4){
                    if(t[k] == dir[l]){
                        int nx = x+(l-1)%2, ny = y+(l-2)%2;
                        if(s[nx][ny] == '#'){
                            f = false;
                            break;
                        }else{
                            x = nx, y = ny;
                        }
                    }
                }
            }
            if(f) ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}