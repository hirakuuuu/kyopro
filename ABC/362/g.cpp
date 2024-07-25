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

/*
Suffix Array: 
    長さ N の文字列 s について, N個の接尾辞 (s[0:n], s[1:n], ..., s[n-1:n]) を辞書順に並べ, その開始位置を配列に並べたもの. 
LCP Array:
    Suffix Array の隣接項について, その最長共通接頭辞（LCP）の長さを格納したもの. 
*/

struct SuffixArray {
    vector<int> sa;
    const string s;

    SuffixArray(const string &str) : s(str) {
        sa.resize(s.size());
        iota(sa.begin(), sa.end(), 0);
        sort(sa.begin(), sa.end(), [&](int a, int b) {
            return s[a] == s[b] ? a > b : s[a] < s[b];
        });
        vector<int> classes(s.size()), c(s.begin(), s.end()), cnt(s.size());
        for(int len = 1; len < (int)s.size(); len <<= 1){
            for(int i = 0;  i < (int)s.size(); i++){
                if(i > 0 && c[sa[i-1]] == c[sa[i]] && sa[i-1]+len < (int)s.size() && c[sa[i-1]+len/2] == c[sa[i]+len/2]){
                    classes[sa[i]] = classes[sa[i-1]];
                }else{
                    classes[sa[i]] = i;
                }
            }
            iota(cnt.begin(), cnt.end(), 0);
            copy(sa.begin(), sa.end(), c.begin());
            for(int i = 0; i < (int)s.size(); i++){
                int s1 = c[i]-len;
                if(s1 >= 0) sa[cnt[classes[s1]]++] = s1;
            }
            swap(classes, c);
        }
    }

    int operator[](int k) const {
        return sa[k];
    }

    // 
    size_t size() const {
        return s.size();
    }

    // s[si:n] と t について, s[si:n] < t かどうかを判定する. 
    // 計算量: O(|s[si:n]|+|t|);
    bool lt_substr(const string &t, int si=0, int ti=0){
        int sn = (int)s.size(), tn = (int)t.size();
        while(si < sn && ti < tn){
            if(s[si] < t[ti]) return true;
            if(s[si] > t[ti]) return false;
            ++si, ++ti;
        }
        return si >= sn && ti < tn;
    }

    // 接尾辞配列で, t が入る位置を探索
    // 計算量: O((|s[si:n|+|t|)log{n});
    int lower_bound(const string &t){
        int low = -1, high = (int)sa.size();
        while(high-low > 1){
            int mid = (low+high)/2;
            if(lt_substr(t, sa[mid])) low = mid;
            else high = mid;
        }
        return high;
    }

    // t が含まれる区間 [l, r) の {l, r} を返す.
    // 計算量: O((|s[si:n|+|t|)log{n});
    pair<int, int> lower_upper_bound(string &t) {
        int idx = lower_bound(t);
        int low = idx-1, high = (int)sa.size();
        t.back()++;
        while(high-low > 1){
            int mid = (low+high)/2;
            if(lt_substr(t, sa[mid])) low = mid;
            else high = mid;
        }
        t.back()--;
        return {idx, high};
    }

    // デバッグ用
    void output() {
        for(int i = 0; i < (int) s.size(); i++) {
        cout << i << ": " << s.substr(sa[i]) << endl;
        }
    }
};

int main(){
    string s; cin >> s;
    SuffixArray sa(s);
    int q; cin >> q;
    while(q--){
        string t; cin >> t;
        auto [l, r] = sa.lower_upper_bound(t);
        cout << r-l << endl;
    }
    
    return 0;
}