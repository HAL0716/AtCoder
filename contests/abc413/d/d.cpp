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
bash test.sh abc413 d
*/

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

pair<ll, ll> get_ratio(ll a, ll b) {
    if (b == 0 || a == 0) return {0, 0};
    ll g = gcd(abs(a), abs(b));
    a /= g;
    b /= g;
    if (b < 0) {
        a = -a;
        b = -b;
    }
    return {a, b};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // --- コーディング開始 ---

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<ll> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];

        bool ok = true;

        sort(A.begin(), A.end(), [](ll a, ll b) {
            return abs(a) < abs(b);
        });
        
        if (N >= 2) {
            auto r = get_ratio(A[1], A[0]);
            for (int i = 2; i < N; ++i) {
                if (get_ratio(A[i], A[i - 1]) != r) {
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? "Yes" : "No") << '\n';
    }

    auto r1 = get_ratio(729, -2430);
    cout << r1.first << " / " << r1.second << endl;
    auto r2 = get_ratio(-2430, 8100);
    cout << r2.first << " / " << r2.second << endl;

    // --- コーディング終了 ---
    
    return 0;
}