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
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    // ソートして一致しなければ、そもそも不可能
    vector<int> A = a, B = b;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    if(A != B){
        cout << "No" << endl;
        return 0;
    }

    // すべて奇数なら、操作はできない
    int cnt_odd = 0;
    rep(i, 0, n) cnt_odd += a[i]&1;
    if(cnt_odd == n){
        if(a == b) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }

    // {奇, 奇, 偶} の箇所があるかどうか
    bool ooe_a = false;
    rep(i, 0, n-2){
        int num = (a[i]&1)+(a[i+1]&1)+(a[i+2]&1);
        if(num == 2) ooe_a = true;
    }
    bool ooe_b = false;
    rep(i, 0, n-2){
        int num = (b[i]&1)+(b[i+1]&1)+(b[i+2]&1);
        if(num == 2) ooe_b = true;
    }
    if(!ooe_a){
        // 3つ以上並んだ偶数はソートできる
        bool ok = true;
        rep(i, 0, n){
            if(a[i]&1 && a[i] != b[i]) ok = false;
        }
        if(ok){
            vector<vector<int>> ea, eb;
            for(int i = 0; i < n; i++){
                if(a[i]&1) continue;
                ea.push_back({}), eb.push_back({});
                int j = i;
                while(j < n && !(a[j]&1)){
                    ea.back().push_back(a[j]);
                    eb.back().push_back(b[j]);
                    j++;
                }
                i = j-1;
            }
            for(auto &aa: ea){ if(aa.size() >= 3) sort(aa.begin(), aa.end()); }
            for(auto &bb: eb){ if(bb.size() >= 3) sort(bb.begin(), bb.end()); }
            rep(i, 0, ea.size()){
                if(ea[i] != eb[i]) ok = false;
            }
        }
        if(ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }else if(!ooe_b){
        // 3つ以上並んだ偶数はソートできる
        bool ok = true;
        rep(i, 0, n){
            if(b[i]&1 && a[i] != b[i]) ok = false;
        }
        if(ok){
            vector<vector<int>> ea, eb;
            for(int i = 0; i < n; i++){
                if(b[i]&1) continue;
                ea.push_back({}), eb.push_back({});
                int j = i;
                while(j < n && !(b[j]&1)){
                    ea.back().push_back(a[j]);
                    eb.back().push_back(b[j]);
                    j++;
                }
                i = j-1;
            }
            for(auto &aa: ea){ if(aa.size() >= 3) sort(aa.begin(), aa.end()); }
            for(auto &bb: eb){ if(bb.size() >= 3) sort(bb.begin(), bb.end()); }
            rep(i, 0, ea.size()){
                if(ea[i] != eb[i]) ok = false;
            }
        }
        if(ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }else{
        // 偶数が2つのときは、元の順序を逆転できない
        if(cnt_odd == n-2){
            vector<int> even_a, even_b;
            rep(i, 0, n){
                if(!(a[i]&1)) even_a.push_back(a[i]);
                if(!(b[i]&1)) even_b.push_back(b[i]);
            }
            if(even_a == even_b) cout << "Yes" << endl;
            else cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }
    return 0;
}