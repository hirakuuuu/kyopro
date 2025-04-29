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
    vector<vector<int>> yakusu(n+1);
    rep(i, 2, n+1){
        for(int j = 2; j*j <= i; j++){
            if(i%j == 0){
                yakusu[i].push_back(j);
                if(i/j != j) yakusu[i].push_back(i/j);
            }
        }
    }
    vector<string> ans(2005);
    vector<bool> need_kakko(2005);
    ans[1] = "1";
    ans[11] = "11";
    ans[111] = "111";
    ans[1111] = "1111";
    rep(i, 1, n+1){
        if(!ans[i].empty()) continue;
        // +
        string tmp = "1+"+ans[i-1];
        rep(j, 2, i){
            string tmp2 = ans[j]+"+"+ans[i-j];
            if(tmp.size() > tmp2.size()) swap(tmp, tmp2);
        }

        // *
        for(auto y: yakusu[i]){
            if(y == 1 || y == i) continue;

            string tmp2;
            if(!need_kakko[y]) tmp2 += ans[y];
            else tmp2 += "("+ans[y]+")";
            tmp2 += "*";
            if(!need_kakko[i/y]) tmp2 += ans[i/y];
            else tmp2 += "("+ans[i/y]+")";

            if(tmp.size() > tmp2.size()) swap(tmp, tmp2);
        }

        ans[i] = tmp;
        int cnt = 0;
        for(auto c: ans[i]){
            if(c == '('){
                cnt++;
            }else if(c == ')'){
                cnt--;
            }else if(c == '+' && cnt == 0){
                need_kakko[i] = true;
            }
        }
    }
    // rep(i, 1, n+1){
    //     cout << i << ": " << ans[i] << endl;
    // }
    cout << ans[n] << endl;

    return 0;
}