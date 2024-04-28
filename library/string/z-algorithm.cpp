#include <bits/stdc++.h>
using namespace std;


/*
Z-algorythm 
- 文字列 sと s[i:] の最長共通接頭辞の長さを線形時間 O(n) で求めるアルゴリズム
- 連続部分文字列の一致判定とかが出てきたらこれ使えると早そう
- https://qiita.com/Pro_ktmr/items/16904c9570aa0953bf05
*/

void Z_algorithm(const string &s, vector<int> &a) {
	int sz = (int)s.size();
	a.resize(sz);
	a[0] = sz;
	int i = 1, j = 0;
	while (i < sz) {
		while (i + j < sz&&s[j] == s[i + j])++j;
		a[i] = j;
		if (j == 0) { ++i; continue; }
		int k = 1;
		while (i + k < sz&&k + a[k] < j)a[i + k] = a[k], ++k;
		i += k; j -= k;
	}
}

int main(){
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;
    for(int _ = 0; _ < n; _++){
        vector<int> ar;
        Z_algorithm(s, ar);
        for(int i = 0; i < s.size(); i++){
            ans = max(ans, min(i, ar[i]));
        }
        s.erase(s.begin());
    }
    cout << ans << endl;
    return 0;
}