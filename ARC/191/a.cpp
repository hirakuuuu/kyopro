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
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;

    // t は最後の1文字を残して好きに配置してよい
    vector<set<int>> pos_s(10);
    rep(i, 0, n) pos_s[s[i]-'0'].insert(i);
    vector<int> cnt_t(10);
    rep(i, 0, m-1) cnt_t[t[i]-'0']++;

    rrep(i, 9, t[m-1]-'0'){
        rep(j, 0, cnt_t[i]){
            int mi = IINF, mid = -1;
            rep(l, 1, i){
                if(pos_s[l].empty()) continue;
                if(mi > *pos_s[l].begin()){
                    mi = *pos_s[l].begin();
                    mid = l;
                }
            }
            if(mid == -1) break;
            pos_s[mid].erase(pos_s[mid].begin());
            pos_s[i].insert(mi);
        }
    }

    // 最後の１文字をどこに入れるか
    bool edit_last = false; // １の位にする場合
    {
        int last = t[m-1]-'0';
        int mi = IINF, mid = -1;
        rep(l, 1, last){
            if(pos_s[l].empty()) continue;
            if(mi > *pos_s[l].begin()){
                mi = *pos_s[l].begin();
                mid = l;
            }
        }
        if(mid != -1){
            pos_s[mid].erase(pos_s[mid].begin());
            pos_s[last].insert(mi);
        }else if(pos_s[last].empty()){
            edit_last = true;
        }
    }

    rrep(i, t[m-1]-'0'-1, 1){
        rep(j, 0, cnt_t[i]){
            int mi = IINF, mid = -1;
            rep(l, 1, i){
                if(pos_s[l].empty()) continue;
                if(mi > *pos_s[l].begin()){
                    mi = *pos_s[l].begin();
                    mid = l;
                }
            }
            if(mid == -1) break;
            pos_s[mid].erase(pos_s[mid].begin());
            pos_s[i].insert(mi);
        }
    }


    string ans = string(n, '0');
    rep(i, 1, 10){
        for(auto p: pos_s[i]){
            ans[p] = (char)('0'+i);
        }
    }
    if(edit_last){
        ans[n-1] = t[m-1];
    }

    cout << ans << endl;


    
    return 0;
}