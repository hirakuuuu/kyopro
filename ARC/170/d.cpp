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
        int n; cin >> n;
        vector<int> a(n), b(n);
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // b[0] を Bob が選ぶとして勝てる初手の選択肢で、最大のものを選ぶ
        int A = -1, A_id = -1;
        rep(i, 0, n){
            int l = abs(b[0]-a[i]), r = b[0]+a[i];
            // l < a[k] < r を満たす a[k] の存在を調べる
            auto itr_l = upper_bound(a.begin(), a.end(), l);
            auto itr_r = lower_bound(a.begin(), a.end(), r);
            if(itr_r-itr_l >= 2){
                A = a[i];
                A_id = i;
            }else if(itr_r-itr_l == 1){
                if(itr_l-a.begin() != i){
                    A = a[i];
                    A_id = i;
                }
            }
        }
        if(A == -1){ // b[0] を選ぶと Bob が必ず勝てる
            cout << "Bob" << endl;
            continue;
        }
        // cout << A << endl;

        bool f = true;
        rep(i, 0, n){
            int B = b[i];
            int l = abs(B-A), r = B+A;
            // l < a[k] < r を満たす a[k] の存在を調べる
            auto itr_l = upper_bound(a.begin(), a.end(), l);
            auto itr_r = lower_bound(a.begin(), a.end(), r);
            if(itr_r-itr_l <= 0){
                f = false;
            }else if(itr_r-itr_l == 1){
                if(itr_l-a.begin() == A_id) f = false;
            }
        }
        if(f) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
    
    return 0;
}