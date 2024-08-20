#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class land {
    void bfs(int a, int b, vector<vector<int>>& vis, vector<vector<char>>& g) {
        vis[a][b] = 1;
        queue<pair<int, int>> q;
        q.push({a, b});
        int m = g.size();
        int n = g[0].size();

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    // Skip the center cell
                    if (i == 0 && j == 0) continue;
                    int x = r + i;
                    int y = c + j;

                    if (x >= 0 && y >= 0 && x < m && y < n && g[x][y] == '1' && !vis[x][y]) {
                        vis[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
        }
    }

public:
    int numis(vector<vector<char>>& g) {
        int n = g.size();
        int m = g[0].size();
        vector<vector<int>> v(n, vector<int>(m, 0));
        int co = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '1' && v[i][j] == 0) {
                    co++;
                    bfs(i, j, v, g);
                }
            }
        }
        return co;
    }
};

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<char>> a(r, vector<char>(c, '0'));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            cin >> a[i][j];
        }
    }
    land s;
    int co = s.numis(a);
    cout << co;
}


	









