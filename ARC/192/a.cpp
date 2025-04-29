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

// bool dp[2][4][10][10];

vector dp(2, vector<vector<vector<bool>>>(4, vector<vector<bool>>(9, vector<bool>(9))));

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int sum = 0;
    rep(i, 0, n) sum += a[i];

    if(n%4 == 0){
        cout << "Yes" << endl;
    }else if(n%4 == 1 || n%4 == 3){
        if(sum) cout << "Yes" << endl;
        else cout << "No" << endl;
    }else{

        int e = 0, o = 0;
        rep(i, 0, n){
            if(a[i] == 0) continue;
            if(i%2 == 1) o++;
            else e++;
        }
        if(min(e, o) >= 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}