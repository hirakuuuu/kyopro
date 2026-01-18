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
    int n, s; cin >> n >> s;
    s--;
    
    vector<string> cand;
    int lim = 1;
    rep(i, 0, n) lim *= 3;
    rep(i, 0, lim){
        int tmp = i;
        string t;
        vector<int> cnt(3);
        rep(j, 0, n){
            cnt[tmp%3]++;
            t += (char)('A'+tmp%3);
            tmp /= 3;
        }
        if(cnt[0] && cnt[1] && cnt[2]) cand.push_back(t);
    }
    sort(cand.begin(), cand.end());
    if(cand.size() <= s) cout << -1 << endl;
    else cout << cand[s] << endl; 

    return 0;
}