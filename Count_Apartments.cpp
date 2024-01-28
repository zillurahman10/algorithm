#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
const int N = 1005;
char maze[N][N];
vector<vector<int>> adjList;
vector<vector<bool>> visited;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool validate(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && maze[x][y] != '#' ;
}

void bfs(pair<int, int> src)
{
    queue<pair<int, int>> q;
    q.push(src);
    visited[src.first][src.second] = true;

    while (!q.empty())
    {
        auto parent = q.front();
        q.pop();
        int x = parent.first;
        int y = parent.second;

        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (validate(new_x, new_y))
            {
                q.push({new_x, new_y});
                visited[new_x][new_y] = true;
            }
        }
    }
}

int countApartments()
{
    int count = 0;
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && maze[i][j] != '#')
            {
                bfs({i, j});
                count++;
            }
        }
    }
    return count;
}

int main()
{
    cin >> n >> m;
    adjList.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
        }
    }
    int apartments = countApartments();
    cout << apartments << endl;
    return 0;
}
