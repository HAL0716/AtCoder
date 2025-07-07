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
./test.sh abc405　d
*/

int H, W;

void update(int h, int w, vector<string>& S, queue<pair<int, int>>& q) {
    if (h > 0 && S[h-1][w] == '.') {
        S[h-1][w] = 'v';
        q.emplace(h-1, w);
    }
    if (h+1 < H && S[h+1][w] == '.') {
        S[h+1][w] = '^';
        q.emplace(h+1, w);
    }
    if (w > 0 && S[h][w-1] == '.') {
        S[h][w-1] = '>';
        q.emplace(h, w-1);
    }
    if (w+1 < W && S[h][w+1] == '.') {
        S[h][w+1] = '<';
        q.emplace(h, w+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // --- コーディング開始 ---

    cin >> H >> W;

    vector<string> S(H);
    queue<pair<int, int>> q;
    for (int h = 0; h < H; ++h) {
        cin >> S[h];
        for (int w = 0; w < W; ++w) {
            if (S[h][w] == 'E') {
                q.emplace(h, w);
            }
        }
    }

    while (!q.empty()) {
        auto [h, w] = q.front();
        q.pop();

        update(h, w, S, q);
    }

    for (string s : S) {
        cout << s << endl;
    }
    
    // --- コーディング終了 ---
    
    return 0;
}