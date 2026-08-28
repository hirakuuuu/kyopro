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
    string s; cin >> s;
    vector<vector<int>> p(3);
    rep(i, 0, s.size()){
        p[s[i]-'A'].push_back(i);
    }

    int ok = 0, ng = p[0].size()+1;
    while(ng-ok > 1){
        int mid = (ok+ng)/2;
        bool f = true;
        vector<int> nb;
        int l = 0;
        rep(i, 0, mid){
            while(l < p[1].size() && p[0][i] > p[1][l]) l++;
            if(l == p[1].size()){
                f = false; break;
            }else nb.push_back(p[1][l]), l++;
        }
        if(!f){
            ng = mid;
            continue;
        }

        vector<int> nc;
        l = 0;
        rep(i, 0, mid){
            while(l < p[2].size() && nb[i] > p[2][l]) l++;
            if(l == p[2].size()){
                f = false; break;
            }else nc.push_back(p[2][l]), l++;
        }
        if(!f){
            ng = mid;
        }else{
            ok = mid;
        }
    }

   
    cout << ok << endl;

    return 0;
}