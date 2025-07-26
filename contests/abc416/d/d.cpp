#include <bits/stdc++.h>
using namespace std;

// 型エイリアス
using str = string;
using ll = long long;

// 定数
const int MOD = 1e9 + 7;            // モジュラ演算の定数
const int MOD2 = 998244353;         // 別のモジュラ演算用定数
const int MODULUS = 1e9 + 9;        // ハッシュ用の素数
const double PI = 3.14159265358979323846;  // 円周率
const double EPS = 1e-9;            // 浮動小数点誤差許容範囲
const int MAXN = 100000;            // 配列の最大サイズ
const int ALPHABET_SIZE = 26;       // アルファベットのサイズ
const int LIMIT = 1000;             // 入力の最大制限
const int INF = 1e9;                // 無限大

// 最大値・最小値の定義
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

// デバッグ用
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << (x) << endl
#else
#define debug(x)
#endif

/*
実行コマンド例
bash test.sh abc416 d
*/

void solver() {
    int N; cin >> N;
    ll M; cin >> M;

    multiset<int> A;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        A.insert(a % M);
    }

    vector<int> B(N);
    for (int i = 0; i < N; ++i) {
        int b; cin >> b;
        B[i] = b % M;
    }
    sort(B.rbegin(), B.rend());

    ll ans = 0;
    for (int b : B){
        int dif = (int)(M - b);

        auto it = A.lower_bound(dif);
        if (it == A.end()) it = A.begin();

        ans += (*it + b) % (int)M;
        A.erase(it);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // --- コーディング開始 ---

    int T; cin >> T;

    for (int i = 0; i < T; ++i)
        solver();
    
    // --- コーディング終了 ---
    
    return 0;
}