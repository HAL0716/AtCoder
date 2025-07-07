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
./test.sh abc406　d
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // --- コーディング開始 ---

    int H, W, N; cin >> H >> W >> N;

    vector<int> row_cnt(H, 0), col_cnt(W, 0);
    vector<vector<int>> row_pos(H), col_pos(W);
    for (int i = 0; i < N; ++i) {
        int x, y; cin >> x >> y; --x; --y;
        row_cnt[x]++;
        col_cnt[y]++;
        row_pos[x].push_back(y);
        col_pos[y].push_back(x);
    }

    int Q; cin >> Q;
    vector<bool> removed_row(H, false), removed_col(W, false);
    for (int i = 0; i < Q; ++i) {
        int mode, pos; cin >> mode >> pos; --pos;
        if (mode == 1) {
            if (removed_row[pos]) {
                cout << 0 << "\n";
                continue;
            }
            cout << row_cnt[pos] << "\n";
            removed_row[pos] = true;
            for (int y : row_pos[pos]) {
                if (!removed_col[y]) {
                    col_cnt[y]--;
                }
            }
            row_cnt[pos] = 0;
        } else {
            if (removed_col[pos]) {
                cout << 0 << "\n";
                continue;
            }
            cout << col_cnt[pos] << "\n";
            removed_col[pos] = true;
            for (int x : col_pos[pos]) {
                if (!removed_row[x]) {
                    row_cnt[x]--;
                }
            }
            col_cnt[pos] = 0;
        }
    }

    // --- コーディング終了 ---
    
    return 0;
}