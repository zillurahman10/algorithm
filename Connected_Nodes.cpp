#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int>> v(n);

    while (e--)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x;
        cin >> x;

        sort(v[x].begin(), v[x].end(), greater<int>());

        if (v[x].size() > 0)
        {
            for (auto val : v[x])
            {
                cout << val << " ";
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
            
    }

    return 0;
}
