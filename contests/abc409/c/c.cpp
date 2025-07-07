#include <bits/stdc++.h>
using namespace std;

// 型エイリアス
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
bash test.sh abc409 c
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // --- コーディング開始 ---

    int N, L;
    cin >> N >> L;

    vector<int> D(N - 1);
    for (int i = 0; i < N - 1; ++i) cin >> D[i];

    if (L % 3 != 0) {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> cntPos(L, 0);
    int pos = 0;
    cntPos[pos]++;
    for (int d : D) {
        pos = (pos + d) % L;
        cntPos[pos]++;
    }

    ll ans = 0;
    int edge = L / 3;
    for (int i = 0; i < edge; ++i) {
        ans += ll(cntPos[i]) * cntPos[i + edge] * cntPos[i + 2 * edge];
    }

    cout << ans << "\n";
    
    // --- コーディング終了 ---
    
    return 0;
}