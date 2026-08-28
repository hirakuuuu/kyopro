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
    ll X = 0;
    string res;
    auto double_ = [&]() -> void{
        cout << "double" << endl;
        X <<= 1;
        return;    
    };
    auto plus = [&](){
        cout << "plus" << endl;
        X++;
        return;    
    };
    auto minus = [&](){
        cout << "minus" << endl;
        X--;
        return;
    };
    auto answer = [&](){
        cout << "answer" << endl;
        return;
    };
    auto operation = [&](string s){
        if(s == "double") X <<= 1;
        if(s == "plus") X++;
        if(s == "minus") X--;
        return;
    };
    string player; cin >> player;
    int t; cin >> t;
    if(player == "Alice"){
        while(t--){
            X = 0;
            ll x; cin >> x;
            if(x == 0){
                answer();
                continue;
            }
            string s;
            {
                ll _x = x;
                while(_x){
                    s += (char)('0'+_x&1);
                    _x >>= 1;
                }
                reverse(s.begin(), s.end());
            }

            int ii = 0;
            if((__builtin_popcountll(x)^s.size())%2 || x == (1LL<<60)-1){
                plus();
                ii++;
            }else{
                double_();
            }
            cin >> res;
            operation(res);
            bool f = false;
            for(int i = ii; i < s.size(); ){
                if(X == x){
                    break;
                }
                if(X%2 == s[i]){
                    double_();
                    i++;
                }else{
                    if(X%2 == 1) minus();
                    else plus();
                }
                cin >> res;
                if(res == "answer"){
                    f = true;
                    break;
                }
                operation(res);
                if(res == "double") i++;
            }
            if(!f) answer();
        }
    }
    if(player == "Bob"){
        while(t--){
            X = 0;
            rep(i, 0, 120){
                cin >> res; 
                if(res == "answer") break;
                operation(res);
                if(X == (1LL<<60)-1){
                    answer();
                    break;
                }else if(res == "minus" || X%2 == 1){
                    double_();
                }else{
                    plus();
                }
            }
        }
    }
    
    return 0;
}