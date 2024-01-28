#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1005;
char maze[N][N];
vector<vector<bool>> visited;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool validate(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && maze[x][y] != '#' ;
}

int bfs(pair<int, int> src)
{
    queue<pair<int, int>> q;
    q.push(src);
    visited[src.first][src.second] = true;
    int roomCount = 0;

    while (!q.empty())
    {
        auto parent = q.front();
        q.pop();
        int x = parent.first;
        int y = parent.second;
        roomCount++;

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
    return roomCount;
}

int countApartments(vector<int>& counts)
{
    int count = 0;
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && maze[i][j] != '#')
            {
                int roomsInApartment = bfs({i, j});
                counts.push_back(roomsInApartment);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    cin >> n >> m;
    vector<int> counts;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
        }
    }
    int apartments = countApartments(counts);
    sort(counts.begin(), counts.end());
    
    if (apartments == 0) {
        cout << 0 << endl;
    } else {
        for (int val : counts)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
