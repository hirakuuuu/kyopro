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
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> a[i][j];
        }
    }

    vector<int> num(1000001, -1);
    rep(i, 0, m){
        int b; cin >> b;
        num[b] = i;
    }

    int ok = m+1, ng = 0;
    while(ok-ng > 1){
        int mid = (ok+ng)/2;
        vector<int> row(n);
        vector<int> col(n);
        int l1 = 0, l2 = 0;
        rep(i, 0, n){
            rep(j, 0, n){
                if(num[a[i][j]] != -1 && num[a[i][j]] < mid){
                    row[i]++;
                    col[j]++;
                    if(i == j) l1++;
                    if(i+j == n-1) l2++;
                }
            }
        }
        
        bool f = ((l1 == n) || (l2 == n));
        rep(i, 0, n){
            if(row[i] == n) f = true;
            if(col[i] == n) f = true;
        }
        if(f) ok = mid;
        else ng = mid;
    }
    if(ok == m+1) ok = -1;
    cout << ok << endl;
    return 0;
}