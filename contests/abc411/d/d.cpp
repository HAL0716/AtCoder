#include <bits/stdc++.h>
using namespace std;

struct Node {
    vector<shared_ptr<Node>> parts;
    string data;

    Node() {}
    Node(const string& s) : data(s) {}

    void collect(string& out) const {
        for (auto& part : parts) part->collect(out);
        out += data;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<shared_ptr<Node>> PC(N + 1, make_shared<Node>());
    shared_ptr<Node> server = make_shared<Node>();

    for (int i = 0; i < Q; ++i) {
        int mode, p;
        cin >> mode >> p;
        if (mode == 1) {
            PC[p] = server;
        } else if (mode == 2) {
            string s;
            cin >> s;
            auto newNode = make_shared<Node>(s);
            auto combined = make_shared<Node>();
            combined->parts.push_back(PC[p]);
            combined->parts.push_back(newNode);
            PC[p] = combined;
        } else if (mode == 3) {
            server = PC[p];
        }
    }

    string ans;
    server->collect(ans);
    cout << ans << '\n';
}
