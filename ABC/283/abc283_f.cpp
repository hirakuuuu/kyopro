#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc283/tasks/abc283_f

const int inf = 1001001001;
struct SegmentTree {
    private:
        int n;
        vector<int> node;
    
    public:
        SegmentTree(vector<int> a){
            // 配列のサイズを取得
            int sz = (int) a.size();
            // nはszを超える最小の2のべき乗
            n = 1;
            while(n < sz) n *= 2;
            // ノードの個数は2n-1
            node.resize(2*n-1, -inf);

            // 再下段にaの値を格納
            rep(i, 0, sz) node[i+n-1] = a[i];
            // 親を更新
            for(int j = n-2; j >= 0; j--) node[j] = max(node[2*j+1], node[2*j+2]);
        }

        // 更新処理
        void update(int x, int val){
            // 再下段の指定した位置の値を更新
            x += n-1;
            chmax(node[x], val);
            // 親の値を更新しながら上る
            while(x > 0){
                x = (x-1)/2;
                chmax(node[x], val);
            }
        }

        // 取得処理
        int get_num(int a, int b, int k=0, int l=0, int r=-1){
            if(r < 0) r = n;
            if(r <= a or b <= l) return -inf;
            if(a <= l and r <= b) return node[k];

            int v1 = get_num(a, b, 2*k+1, l, (l+r)/2);
            int v2 = get_num(a, b, 2*k+2, (l+r)/2, r);
            return max(v1, v2);
        }
};

int main(){
    int n; cin >> n;
    vector<int> p(n), ans(n, inf), q(n, -inf);
    rep(i, 0, n){
        cin >> p[i];
        p[i]--;
    }

    rep(ri, 0, 2){
        rep(rj, 0, 2){
            SegmentTree st(q);
            rep(i, 0, n){
                int x = i+p[i];
                chmin(ans[i], x-st.get_num(0, p[i]));
                st.update(p[i], x);
            }
            rep(i, 0, n) p[i] = n-1-p[i];
        }
        reverse(p.begin(), p.end());
        reverse(ans.begin(), ans.end());
    }

    rep(i, 0, n) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}