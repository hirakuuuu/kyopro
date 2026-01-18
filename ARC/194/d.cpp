#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    string s; cin >> s;

    vector<mint> fact(n+1);
    fact[0] = fact[1] = 1;
    rep(i, 2, n+1) fact[i] = fact[i-1]*i;

    vector<int> par(1, -1);
    {
        int pos = 0;
        rep(i, 0, n){
            if(s[i] == '('){
                int nxt = (int)par.size();
                par.push_back(pos);
                pos = nxt;
            }else{
                pos = par[pos];
            }
        }
    }
    int sz = (int)par.size();
    vector<vector<int>> g(sz);
    rep(i, 1, sz) g[par[i]].push_back(i);

    // 部分木のハッシュ値を取る
    vector<pair<int, int>> hash(sz);
    int b1 = rand()%998244353;
    int b2 = rand()%1000000007;
    auto f1 =[&](auto self, int pos) -> void {
        vector<pair<int, int>> sh;
        for(auto nxt: g[pos]){
            self(self, nxt);
            sh.push_back({hash[nxt].first, hash[nxt].second});
        }
        sort(sh.begin(), sh.end());
        hash[pos].first = b1;
        hash[pos].second = b2;
        for(auto ss: sh){
            hash[pos].first = (hash[pos].first*b1+ss.first)%998244353;
            hash[pos].second = (hash[pos].second*b2+ss.second)%1000000007;
        }
        return;
    };
    f1(f1, 0);


    auto f2 = [&](auto self, int pos) -> mint {
        mint res = fact[g[pos].size()];
        vector<pair<int, int>> vec;
        for(auto nxt: g[pos]){
            res *= self(self, nxt);
            vec.push_back({hash[nxt].first, hash[nxt].second});
        }
        sort(vec.begin(), vec.end());
        for(int i = 0; i < (int)vec.size(); ){
            int j = i;
            while(j < (int)vec.size() && vec[i] == vec[j]){
                j++;
            }
            res /= fact[j-i];
            i = j;
        }
        return res;
    };


    cout << f2(f2, 0).val() << endl;


    
    return 0;
}