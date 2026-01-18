#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<int> a(n+1, n);
    vector<int> inv(n+1, 0);
    rep(i, 1, n+1){
        cin >> a[i];
        a[i]--;
        inv[a[i]] = i;
    }

    string ans(n, 'A');
    int tmp = 0;
    rep(i, 0, n){
        int p1 = a[i], p2 = a[i+1];
        bool ok = true;
        while(p1 <= n && p2 <= n){
            if(inv[p1] > inv[p2]){
                cout << i << endl;
                        cout << p1 << ' ' << p2 << endl;
        cout << inv[p1] << ' ' << inv[p2] << endl;
                ok = false;
                break;
            }
            p1++, p2++;
        }
        if(!ok) tmp++;
        if(tmp >= 26){
            cout << -1 << endl; 
            return 0;
        }
        ans[a[i+1]] = (char)('A'+tmp);
    }

    cout << ans << endl;
    return 0;
}