#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

bool canMixAll(int N, const string& S) {
    int total = 1 << N;
    vector<bool> visited(total, false);
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int mask = q.front();
        q.pop();

        // ゴールに到達したら成功
        if (mask == total - 1) return true;

        for (int i = 0; i < N; ++i) {
            if ((mask >> i) & 1) continue; // 既に追加済み

            int next = mask | (1 << i);
            if (S[next - 1] == '1') continue; // 危険状態は無視
            if (visited[next]) continue;

            visited[next] = true;
            q.push(next);
        }
    }

    return false; // ゴールにたどり着けなかった
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        string S;
        cin >> N >> S;

        cout << (canMixAll(N, S) ? "Yes" : "No") << '\n';
    }

    return 0;
}
