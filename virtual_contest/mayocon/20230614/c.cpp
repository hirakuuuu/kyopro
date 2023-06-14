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
    int n, m, h, k; cin >> n >> m >> h >> k;
    string s; cin >> s;

    map<pii, bool> item;
    rep(i, 0, m){
        int x, y; cin >> x >> y;
        item[{x, y}] = true;
    }

    string dir = "LDRU";
    int px = 0, py = 0;
    rep(i, 0, n){
        rep(j, 0, 4){
            if(s[i] == dir[j]){
                px += (j-1)%2, py += (j-2)%2;
                h--;
                if(h < 0){
                    cout << "No" << endl;
                    return 0;
                }
                if(h < k && item[{px, py}]){
                    item[{px, py}] = false;
                    h = k;
                }
            }
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}