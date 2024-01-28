#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1005;
char maze[N][N];
int visited[N][N];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool validate(int x, int y)
{
     return !visited[x][y] && maze[x][y] != '#' && x >= 0 && x < n && y >= 0 && y < m;
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
            if(validate(new_x, new_y))
            {
                q.push({new_x, new_y});
                visited[new_x][new_y] = true;
            }
        }   
    }
}

int main()
{
    pair<int, int> src, dst;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'A') // Corrected array index
                src = {i, j};
            if (maze[i][j] == 'B') // Corrected array index
                dst = {i, j};
        }
    }
    bfs(src);

    if(visited[dst.first][dst.second])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
