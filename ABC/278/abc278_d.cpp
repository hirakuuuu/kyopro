#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc278/tasks/abc278_d

struct LazySegTree {
    private:
        int n;
        vector<int> node, lazy;
    
    public:
        LazySegTree(vector<int> a){
            // 配列のサイズを取得
            int sz = (int) a.size();
            // nはszを超える最小の2のべき乗
            n = 1;
            while(n < sz) n *= 2;
            // ノードの個数は2n-1
            node.resize(2*n-1, 0);
            lazy.resize(2*n-1, 0);

            // 再下段にaの値を格納
            rep(i, 0, sz) node[i+n-1] = a[i];
            // 親を更新
            for(int j = n-2; j >= 0; j--) node[j] = node[2*j+1]+node[2*j+2];
        }

        // k番目のノードについて遅延評価を行う
        void eval(int k) {
            // 遅延配列が空出ない場合、自ノードおよび子ノードへの
            // 値の伝播が起こる
            if(lazy[k] == 0) return;

            // 葉でなければ、子に伝播させる
            if(k < n-1) {
                lazy[2*k+1] = lazy[k];
                lazy[2*k+2] = lazy[k];
            }

            // 伝播が終わったら自ノードの遅延配列を空にする
            node[k] = lazy[k];
            lazy[k] = 0;
            
        }

        // 区間の更新処理
        void update(int a, int b, int val, int k=0, int l=0, int r=-1){
            // 最初に遅延評価を実行しないと前の区間更新の際に入れていた値が消える
            eval(k);
            if(r < 0) r = n;
            // 完全に内側の時
            if(a <= l and r <= b){
                lazy[k] = val;
                eval(k);
            }else if(a < r and l < b){
            // 一部区間がかぶるとき
                update(a, b, val, k*2+1, l, (l+r)/2); // 左の子
                update(a, b, val, k*2+2, (l+r)/2, r); // 右の子
                node[k] = node[k*2+1]+node[k*2+2];
            }
        }


        // 更新処理
        void add_update(int x, int val){
            // 再下段の指定した位置の値を更新
            x += n-1;
            lazy[x] += val;
            // 親の値を更新しながら上る
            while(x > 0){
                x = (x-1)/2;
                node[x] += val;            
                lazy[x] += val;
            }
        }


        // 取得処理
        int get_num(int a, int b, int k=0, int l=0, int r=-1){
            eval(k);
            if(r < 0) r = n;
            // 完全に外側の時
            if(r <= a or b <= l) return 0;
            // 完全に内側の時
            if(a <= l and r <= b) return node[k];

            int v1 = get_num(a, b, 2*k+1, l, (l+r)/2);
            int v2 = get_num(a, b, 2*k+2, (l+r)/2, r);
            return v1+v2;
        }
};

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    LazySegTree lst(a);

    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x; cin >> x;
            lst.update(0, n, x);
        }else if(t == 2){
            int i, x; cin >> i >> x;
            i--;
            lst.add_update(i, x);
        }else{
            int i; cin >> i;
            i--;
            cout << lst.get_num(i, i+1) << endl;

        }

    }
    
    return 0;
}