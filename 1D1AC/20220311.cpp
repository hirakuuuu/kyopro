#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    string s; cin >> s;
    // この2つはシノニムが起こらない
    if(s == "a" or s == "zzzzzzzzzzzzzzzzzzzz"){
        cout << "NO" << endl;
        return 0;
    }
    // ハッシュ値を求める
    int hash = 0;
    for(auto ss: s){
        hash += ss-'a'+1;
    }
    // 答えは2つ求めれば十分
    string ans1 = "", ans2 = "";
    // 1つめは前からzを埋めて余った分はその数字に対応する文字にしたもの
    int hash1 = hash;
    while(hash1 > 0){
        if(hash1 >= 26){
            ans1.push_back('z');
            hash1 -= 26;
        }else{
            ans1.push_back('a'+hash1-1);
            hash1 = 0;
        }
    }
    // 2つめは1つめを前後入れ替えたもの
    ans2 = ans1;
    reverse(ans2.begin(), ans2.end());
    // 1つめと2つめが一致しなければ、元のパスワードと異なる方を出力
    if(ans1 != ans2){
        if(s != ans1) cout << ans1 << endl;
        else cout << ans2 << endl;
    // 1つめと2つめが一致する場合
    }else{
        // 元のパスワードと異なるならそれでいい
        if(ans1 != s) cout << ans1 << endl;
        // 元のパスワードと同じなら、最後の1文字を1つ前にしてaを追加すれば良い
        else{
            rep(i, 0, ans1.size()-1)cout << 'z';
            char c = ans1[ans1.size()-1]-1;
            cout << c;
            cout << 'a' << endl;
        }
    }
    return 0; 
}