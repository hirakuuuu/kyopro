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


// 素数 p に対して 1/p の循環部分を求める関数
string find_reccuring_cycle(int p){
    unordered_map<int, int> remainder_positions;
    int numerator = 1; // 初期の分子
    int position = 0;  // 商の桁の位置

    // 商の記録
    string decimal_part = "";

    while(numerator != 0){
        // 余りがすでに記録されている場合，循環を検出
        if(remainder_positions.count(numerator)){
            int start = remainder_positions[numerator];
            string reccuring_cycle = decimal_part.substr(start);
            return reccuring_cycle;
        }

        // 余りの位置を記録
        remainder_positions[numerator] = position;
        position += 1;

        // 割り算
        numerator *= 10;
        decimal_part += to_string(numerator/p);
        numerator %= p;
    }
    
    // 循環がない場合
    return "";
}

// verify: https://atcoder.jp/contests/agc070/tasks/agc070_a
int main(){
    string s = find_reccuring_cycle(1019);
    string x = s;
    reverse(x.begin(), x.end());
    while(x.back() == '0') x.pop_back();
    reverse(x.begin(), x.end());
    cout << x << endl;
    cout << s << s << endl;
    
    
    return 0;
}