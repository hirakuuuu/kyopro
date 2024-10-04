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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int l = 0;
        while((1<<l+1) <= n) l++;
        if(l >= k-1){
            rep(i, 1<<(k-1), 1<<k){
                cout << i << ' ';
            }
            rep(i, 0, n-(1<<(k-1))){
                cout << 1 << ' ';
            }
            cout << endl;
        }else{
            // 上位 l 桁はばらけさせる
            vector<int> ans;
            rep(i, 1<<l, 1<<(l+1)){
                ans.push_back(i<<(k-l-1));
            }
            vector<int> pre = ans;
            int id = 0;
            while(ans.size() < n){
                ans.push_back(pre[id]+(1<<(k-l-2)));
                id++;
            }
            for(auto aa: ans){
                cout << aa << ' ';
            }
            cout << endl;
            // auto calc_score = [&](vector<int> a) -> int {
            //     set<int> s;
            //     s.insert(0);
            //     s.insert(1);
            //     for(auto aa: a){
            //         int k = 0;
            //         while(aa/(1<<k) > 1){
            //             s.insert(aa/(1<<k));
            //             k++;
            //         }
            //     }
            //     return s.size();
            // };
            // cout << calc_score(ans) << endl;
            // vector<int> sample = {662933,967505, 876482, 840117, 1035841, 651549, 543175, 781219};
            // cout << calc_score(sample) << endl;
        }


    }
    
    return 0;
}