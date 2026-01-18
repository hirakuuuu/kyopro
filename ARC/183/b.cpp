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

/*
- a = b なら Yes
- k = 1 ならそれぞれランレングス圧縮したとき，b が a の部分列になることが必要十分
- k \ge 2 なら，操作を逆に考えると，|i-j|\le k かつ b_i == b_j なる i, j (i\neq j) を選んで，b_i を好きな数字に置き換えると思える．
    - 操作が1回もできなかったら No
    - b の要素で a に含まれないものがあれば No
    - 実はそれ以外ならすべて Yes となる．
        - 操作によって，ワイルドカードが一つでも作れれば，それを経由して swap 操作が行える．
        - 重複を削除して好きに並べることができる
*/

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n);
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) cin >> b[i];
        
        if(a == b){
            cout << "Yes" << endl;
            continue;
        }

        if(k == 1){
            vector<pair<int, int>> rle_a;
            for(int i = 0; i < n; ){
                int j = i;
                while(j < n && a[i] == a[j]){
                    j++;
                }
                rle_a.emplace_back(a[i], j-i);
                i = j;
            }
            vector<pair<int, int>> rle_b;
            for(int i = 0; i < n; ){
                int j = i;
                while(j < n && b[i] == b[j]){
                    j++;
                }
                rle_b.emplace_back(b[i], j-i);
                i = j;
            }

            int l = 0;
            bool ok = true;
            for(auto [v, _]: rle_b){
                while(l < rle_a.size() && rle_a[l].first != v){
                    l++;
                }
                if(l == rle_a.size()) ok = false;
            }
            if(ok) cout << "Yes" << endl;
            else cout << "No" << endl;
        }else{
            bool f1 = true;
            vector<int> cnt_a(n+1);
            rep(i, 0, n) cnt_a[a[i]]++;
            rep(i, 0, n){
                if(cnt_a[b[i]] == 0){
                    f1 = false;
                }
            }
            bool f2 = false;
            vector<int> cnt_b(n+1);
            rep(i, 0, k+1) cnt_b[b[i]]++;
            rep(i, 0, n){
                if(cnt_b[b[i]] >= 2){
                    f2 = true;
                }
                if(i-k >= 0) cnt_b[b[i-k]]--;
                if(i+1+k < n) cnt_b[b[i+1+k]]++;
            }

            if(f1 && f2) cout << "Yes" << endl;
            else cout << "No" << endl;

        }
    }
    
    return 0;
}