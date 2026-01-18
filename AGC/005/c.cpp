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
    vector<int> a(n);
    vector<int> cnt(n);
    rep(i, 0, n){
        cin >> a[i];
        cnt[a[i]]++;
    }

    if(n == 2){
        cout << "Possible" << endl;
        return 0;
    }

    int d = 0;
    rep(i, 0, n){
        if(cnt[i]) d = i;
    }
    if(d < 2){
        cout << "Impossible" << endl;
        return 0;
    }
    rep(i, 0, (d+1)/2){
        if(cnt[i]){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    if(d%2 == 0 && cnt[d/2] != 1){
        cout << "Impossible" << endl;
        return 0;
    }
    if(d%2 == 1 && cnt[(d+1)/2] != 2){
        cout << "Impossible" << endl;
        return 0;
    }
    rep(i, d/2+1, d+1){
        if(cnt[i] < 2){
            cout << "Impossible" << endl;
            return 0;
        }
    }

    cout << "Possible" << endl;
    return 0;
}