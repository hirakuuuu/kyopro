#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
区間反転をそのままやるのはむずいので、区間に区切って考える
反転するフラグに到達したら、対応する区間について今見ている方向と逆から見るようにする.
実装は再帰でやるのがよい.
*/

int main(){
    string s; cin >> s;
    // かっこ列だけ考えて大文字小文字をそろえる
    int acc = 0;
    reverse(s.begin(), s.end());
    for(auto &ss: s){
        if(ss == '('){
            acc--;
        }else if(ss == ')'){
            acc++;
        }else{
            if(acc%2){
                if(islower(ss)) ss = toupper(ss);
                else ss = tolower(ss);
            }
        }
    }
    reverse(s.begin(), s.end());
    string t;
    vector<int> pos;
    rep(i, 0, s.size()){
        if(s[i] != '(' && s[i] != ')'){
            t += s[i];
        }
    }
    stack<int> l;
    vector<int> rev(s.size()+1), kakko(s.size());
    rep(i, 0, s.size()){
        if(s[i] == '('){
            l.push(i);
        }else if(s[i] == ')'){
            int L = l.top(); l.pop();
            kakko[L] = i;
            kakko[i] = L;
        }
    }
    auto f = [&](auto self, int l, int r, int d) -> void {
        if(d == 0){
            rep(i, l, r){
                if(s[i] == '('){
                    self(self, i+1, kakko[i], 1);
                    i = kakko[i];
                }else if(s[i] != ')'){
                    cout << s[i];
                }
            }
        }else{
            rrep(i, r-1, l){
                if(s[i] == ')'){
                    self(self, kakko[i]+1, i, 0);
                    i = kakko[i];
                }else if(s[i] != '('){
                    cout << s[i];
                }
            }
        }
    };
    f(f, 0, s.size(), 0);
    cout << endl;

    return 0;
}