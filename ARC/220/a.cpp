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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        bool able = true;
        vector<int> ans;
        if(n%3 == 1){
            vector<int> pre = {1}, nxt;
            while(pre.size()+nxt.size() < n){
                if(pre.empty()){
                    swap(pre, nxt);
                }else{
                    rep(_, 0, 4) nxt.push_back(pre.back()*2);
                    pre.pop_back();
                }
            }
            ans = pre;
            for(auto nn: nxt) ans.push_back(nn);
        }else if(n >= 6 && n%3 == 0){
            vector<int> pre, nxt;
            pre = {6, 3, 3, 2, 2, 2};
            while(pre.size()+nxt.size() < n){
                if(pre.empty()){
                    swap(pre, nxt);
                }else{
                    rep(_, 0, 4) nxt.push_back(pre.back()*2);
                    pre.pop_back();
                }
            }
            ans = pre;
            for(auto nn: nxt) ans.push_back(nn);
        }else if(n >= 8 && n%3 == 2){
            vector<int> pre, nxt;
            pre = {2, 2, 3, 3, 3, 3, 6, 6};
            reverse(pre.begin(), pre.end());
            while(pre.size()+nxt.size() < n){
                if(pre.empty()){
                    swap(pre, nxt);
                }else{
                    rep(_, 0, 4) nxt.push_back(pre.back()*2);
                    pre.pop_back();
                }
            }
            ans = pre;
            for(auto nn: nxt) ans.push_back(nn);
        }else{
            able = false;
        }

        if(!able) cout << "No" << endl;
        else{
            cout << "Yes" << endl;
            assert(ans.size() == n);
            for(auto aa: ans){
                cout << aa << ' ';
            } 
            cout << endl;
        }
    }
    
    return 0;
}