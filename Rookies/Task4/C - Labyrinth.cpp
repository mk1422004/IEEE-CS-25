#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// أقصى أبعاد للشبكة
const int MAX_HEIGHT = 1000;  

const int DIRECTIONS_COUNT = 4;  
int directionX[] = {-1, 0, 1, 0};
int directionY[] = {0, 1, 0, -1};

char labyrinth[MAX_HEIGHT][MAX_HEIGHT];

bool visited[MAX_HEIGHT][MAX_HEIGHT];   
char directionFrom[MAX_HEIGHT][MAX_HEIGHT];  


bool isValidMove(int x, int y, int height, int width); 

int main() {
    int height, width;
    cin >> height >> width;

    pair<int, int> startPosition, endPosition;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            cin >> labyrinth[row][col];
            if (labyrinth[row][col] == 'A') {
                startPosition = {row, col};  
            }
            if (labyrinth[row][col] == 'B') {
                endPosition = {row, col};    
            }
        }
    }

    queue<pair<int, int>> searchQueue;
    searchQueue.push(startPosition);
    visited[startPosition.first][startPosition.second] = true;

    while (!searchQueue.empty()) {
        auto [currentRow, currentCol] = searchQueue.front();
        searchQueue.pop();

        for (int i = 0; i < DIRECTIONS_COUNT; i++) {
            int newRow = currentRow + directionX[i];
            int newCol = currentCol + directionY[i];

            if (isValidMove(newRow, newCol, height, width) && !visited[newRow][newCol] && labyrinth[newRow][newCol] != '#') {
                visited[newRow][newCol] = true;
                directionFrom[newRow][newCol] = (i == 0 ? 'U' : (i == 1 ? 'R' : (i == 2 ? 'D' : 'L')));
                searchQueue.push({newRow, newCol});
            }
        }
    }

    if (!visited[endPosition.first][endPosition.second]) {
        cout << "NO" << endl;
        return 0;
    }

    vector<char> path;
    int row = endPosition.first, col = endPosition.second;
    while (row != startPosition.first || col != startPosition.second) {
        path.push_back(directionFrom[row][col]);
        if (directionFrom[row][col] == 'U') row++;
        else if (directionFrom[row][col] == 'R') col--;
        else if (directionFrom[row][col] == 'D') row--;
        else if (directionFrom[row][col] == 'L') col++;
    }

    reverse(path.begin(), path.end());

    cout << "YES" << endl;
    cout << path.size() << endl; 
    for (char dir : path) {
        cout << dir;
    }
    cout << endl;

    return 0;
}

bool isValidMove(int x, int y, int height, int width) {
    return (x >= 0 && x < height && y >= 0 && y < width);
}
