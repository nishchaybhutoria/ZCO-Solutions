#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, h;
    cin >> n >> h;
    vector <int> heights;
    heights.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> heights[i];
    }
    vector <int> queries;
    queries.resize(0);
    int q = 1;
    while (q != 0)
    {
        cin >> q;
        queries.push_back(q);
    }
    int current = 0;
    bool hasBox = false;
    for (int i = 0; i < queries.size(); ++i)
    {
        if (queries[i] == 1)
        {
            if (current == 0)
            {
               ; 
            } else {
                current--;
            }
        } else if (queries[i] == 2)
        {
            if (current == (n - 1))
            {
                ;
            } else {
                current++;
            }
        } else if (queries[i] == 3) {
            if (hasBox == true || heights[current] == 0)
            {
                ;
            } else 
            {
                heights[current]--;
                hasBox = true;
            }
        } else if (queries[i] == 4) {
            if (hasBox == false || heights[current] == h)
            {
                ;
            } else 
            {
                heights[current]++;
                hasBox = false;
            }
         } else {
                break;
         }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << heights[i] << " ";
    }
}
