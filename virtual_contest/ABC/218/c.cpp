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
    int n; cin >> n;
    vector<string> s(n), t(n);
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, n) cin >> t[i];

    vector<pair<int, int>> at;
    rep(i, 0, n){
        rep(j, 0, n){
            if(t[i][j] == '#'){
                at.push_back({i, j});
            }
        }
    }
    vector<vector<pair<int, int>>> as(4);
    rep(i, 0, n){
        rep(j, 0, n){
            if(s[i][j] == '#'){
                as[0].push_back({i, j});
                as[1].push_back({j, n-i});
                as[2].push_back({n-i, n-j});
                as[3].push_back({n-j, i});
            }
        }
    }

    rep(i, 0, 4) sort(as[i].begin(), as[i].end());

    rep(i, 0, 4){
        vector<pair<int, int>> rt;
        pair<int, int> ofs = {at[0].first-as[i][0].first, at[0].second-as[i][0].second};
        rep(j, 0, as[i].size()){
            rt.push_back({as[i][j].first+ofs.first, as[i][j].second+ofs.second});
        }
        sort(rt.begin(), rt.end());

        if(rt == at){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
    return 0;
}