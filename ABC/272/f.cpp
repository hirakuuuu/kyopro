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

struct SuffixArray {
    vector<int> sa;
    const string s;

    // ダブリングにより suffix array（接尾辞を辞書順に並べたときの開始位置の配列） を構築する
    // 計算量: O(|S|\log{|S|})
    SuffixArray(const string &str) : s(str) {
        sa.resize(s.size());
        iota(sa.begin(), sa.end(), 0);
        sort(sa.begin(), sa.end(), [&](int a, int b) {
            return s[a] == s[b] ? a > b : s[a] < s[b];
        });
        // 長さ 1, 2, 4, ... に対して, 巡回シフトした文字列の辞書順と同値類の値を |S| 個持つ
        // こうすると 2^k-1 から 2^k が O(|S|) で求まる. 
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
    
    // 文字列と同じような interface がほしい
    int operator[](int k) const {
        return sa[k];
    } 
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
    int n; cin >> n;
    string s, t; cin >> s >> t;
    
    string x;
    rep(_, 0, 2) x += s;
    rep(_, 0, n) x += 'a';
    rep(_, 0, 2) x += t;
    rep(_, 0, n) x += 'z';

    SuffixArray sa(x);
    ll ans = 0, tmp = 0;
    rep(i, 0, 6*n){
        if(inr(0, sa[i], n)){
            // sの文字
            tmp++;
        }else if(inr(3*n, sa[i], 4*n)){
            // tの文字
            ans += tmp;
        }
    }
    cout << ans << endl;

    return 0;
}