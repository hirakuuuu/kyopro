#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abl/tasks/abl_d

struct SegmentTree {
    private:
        int n;
        vector<int> node;
    
    public:
        SegmentTree(vector<int> a){
            // 配列のサイズを取得
            int sz = a.size();
            // nはszを超える最小の2のべき乗
            n = 1;
            while(n < sz) n *= 2;
            // ノードの個数は2n-1
            node.resize(2*n-1, 0);

            // 再下段にaの値を格納
            rep(i, 0, sz) node[i+n-1] = a[i];
            // 親を更新
            for(int j = n-2; j >= 0; j--) node[j] = max(node[2*j+1], node[2*j+2]);
        }

        // 更新処理
        void update(int x, int val){
            // 再下段の指定した位置の値を更新
            x += n-1;
            node[x] = max(node[x], val);
            // 親の値を更新しながら上る
            while(x > 0){
                x = (x-1)/2;
                node[x] = max(node[x*2+1], node[x*2+2]);
            }
        }

        // 取得処理
        int get_num(int a, int b, int k=0, int l=0, int r=-1){
            if(r < 0) r = n;
            if(r <= a or b <= l) return 0;
            if(a <= l and r <= b) return node[k];

            int v1 = get_num(a, b, 2*k+1, l, (l+r)/2);
            int v2 = get_num(a, b, 2*k+2, (l+r)/2, r);
            return max(v1, v2);
        }
};


int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n+1);
    rep(i, 1, n+1) cin >> a[i];

    vector<int> dp(300005);
    dp[a[1]] = 1;
    SegmentTree st(dp);
    rep(i, 2, n+1){
        int max_len = st.get_num(a[i]-k, a[i]+k+1);
        st.update(a[i], max_len+1);
    }

    cout << st.get_num(0, 300001) << endl;
    
    return 0;
}