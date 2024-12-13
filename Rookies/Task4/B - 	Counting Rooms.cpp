#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

bool is_valid(int x, int y, int n, int m, const vector<vector<char>>& building_map, vector<vector<bool>>& visited) {
    return x >= 0 && x < n && y >= 0 && y < m && building_map[x][y] == '.' && !visited[x][y];
}

void bfs(int start_x, int start_y, int n, int m, const vector<vector<char>>& building_map, vector<vector<bool>>& visited) {
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (is_valid(new_x, new_y, n, m, building_map, visited)) {
                visited[new_x][new_y] = true;
                q.push({new_x, new_y});
            }
        }
    }
}

int count_rooms(int n, int m, const vector<vector<char>>& building_map) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int room_count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (building_map[i][j] == '.' && !visited[i][j]) {
                bfs(i, j, n, m, building_map, visited);
                room_count++;
            }
        }
    }

    return room_count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> building_map(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> building_map[i][j];
        }
    }

    int result = count_rooms(n, m, building_map);
    cout << result << endl;

    return 0;
}
