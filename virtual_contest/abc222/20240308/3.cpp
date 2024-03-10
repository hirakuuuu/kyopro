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
    int n, m; cin >> n >> m;
    vector<pair<int, int>> score(2*n);
    rep(i, 0, 2*n){
        score[i] = {0, -i};
    }
    vector<string> a(2*n);
    rep(i, 0, 2*n) cin >> a[i];

    rep(i, 0, m){
        rep(j, 0, n){
            auto [s1, p1] = score[2*j];
            auto [s2, p2] = score[2*j+1];
            char b = a[-p1][i], c = a[-p2][i];
            if((b == 'G' && c == 'C') || (b == 'C' && c == 'P') || (b == 'P' && c == 'G')) s1++;
            else if((b == 'G' && c == 'P') || (b == 'P' && c == 'C') || (b == 'C' && c == 'G')) s2++;

            score[2*j] = {s1, p1};
            score[2*j+1] = {s2, p2};
        }
        sort(score.begin(), score.end());
    }
    reverse(score.begin(), score.end());
    rep(i, 0, 2*n){
        cout << -score[i].second+1 << endl;
    }
    return 0;
}