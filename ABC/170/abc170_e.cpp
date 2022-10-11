#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc170/tasks/abc170_e

vector<multiset<int>> kg(200005);
vector<int> cnt(200005);

struct SegmentTree {
    private:
        int n;
        vector<ll> node;
    
    public:
        SegmentTree(vector<ll> a){
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
            for(int j = n-2; j >= 0; j--) node[j] = min(node[2*j+1], node[2*j+2]);
        }

        // 更新処理
        void update(int x, ll val){
            // 再下段の指定した位置の値を更新
            x += n-1;
            node[x] = val;
            // 親の値を更新しながら上る
            while(x > 0){
                x = (x-1)/2;
                node[x] = min(node[2*x+1], node[2*x+2]);
            }
        }

        // 取得処理
        ll get_num(int a, int b, int k=0, int l=0, int r=-1){
            if(r < 0) r = n;
            if(r <= a or b <= l) return 1e9;
            if(a <= l and r <= b) return node[k];

            ll v1 = get_num(a, b, 2*k+1, l, (l+r)/2);
            ll v2 = get_num(a, b, 2*k+2, (l+r)/2, r);
            return min(v1, v2);
        }
};


int main(){
    int n, q; cin >> n >> q;
    vector<ll> a(n+1), b(n+1), max_rates(200005, 1LL<<60);
    SegmentTree st(max_rates);
    rep(i, 1, n+1){
        cin >> a[i] >> b[i];
        b[i]--;
        kg[b[i]].insert(a[i]);
        cnt[b[i]]++;
        // 最大レートの更新
        st.update(b[i], *kg[b[i]].rbegin());
    }

    
    while(q--){
        int c, d; cin >> c >> d;
        d--;
        // 削除
        cnt[b[c]]--;
        auto ite = kg[b[c]].find(a[c]);
        kg[b[c]].erase(ite);
        if(cnt[b[c]] == 0) st.update(b[c], 1LL<<60);
        else st.update(b[c], *kg[b[c]].rbegin());
        
        // 挿入
        b[c] = d;
        cnt[d]++;
        kg[d].insert(a[c]);
        st.update(d, *kg[d].rbegin());

        cout << st.get_num(0, 200000) << endl;
    }

    return 0;
}