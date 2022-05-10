#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc223/tasks/abc223_f

struct SegmentTree {
    private:
        int n;
        vector<pii> node;
    
    public:
        SegmentTree(vector<pii> a){
            // 配列のサイズを取得
            int sz = a.size();
            // nはszを超える最小の2のべき乗
            n = 1;
            while(n < sz) n *= 2;
            // ノードの個数は2n-1
            node.resize(2*n-1, {0, 0});

            // 再下段にaの値を格納
            rep(i, 0, sz) node[i+n-1] = a[i];
            // 親を更新
            for(int j = n-2; j >= 0; j--){
                node[j] = {min(node[2*j+1].first, node[2*j+1].second+node[2*j+2].first), node[2*j+1].second+node[2*j+2].second};
            }
        }

        // 更新処理
        void update(int l, int r){
            l += n-1, r += n-1;
            // 再下段の指定した位置の値を更新
            swap(node[l], node[r]);
            // 親の値を更新しながら上る
            while(l > 0){
                l = (l-1)/2;
                node[l] = {min(node[2*l+1].first, node[2*l+1].second+node[2*l+2].first), node[2*l+1].second+node[2*l+2].second};
            }
            while(r > 0){
                r = (r-1)/2;
                node[r] = {min(node[2*r+1].first, node[2*r+1].second+node[2*r+2].first), node[2*r+1].second+node[2*r+2].second};
            }
        }

        // 取得処理
        pii get_num(int a, int b, int k=0, int l=0, int r=-1){
            if(r < 0) r = n;
            if(r <= a or b <= l) return {0, 0};
            if(a <= l and r <= b) return node[k];

            pii v1 = get_num(a, b, 2*k+1, l, (l+r)/2);
            pii v2 = get_num(a, b, 2*k+2, (l+r)/2, r);
            return {min(v1.first, v1.second+v2.first), v1.second+v2.second};
        }
};

int main(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<pii> kakko(n);
    rep(i, 0, n){
        if(s[i] == '(') kakko[i] = {0, 1};
        else kakko[i] = {-1, -1};
    }

    SegmentTree st(kakko);

    while(q--){
        int t, l, r; cin >> t >> l >> r;
        l--, r--;
        if(t == 1){
            st.update(l, r);
        }else{
            if(st.get_num(l, r+1) == make_pair(0, 0)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
    
    return 0;
}