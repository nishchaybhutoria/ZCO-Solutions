#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long

using namespace __gnu_pbds;
using namespace std;

template <class T> using oset = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

void usaco(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(name.size())
    {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

const int MAXX = 1e5, MAXY = 5e2;

signed main()
{
    usaco();
    int n;
    cin >> n;
    vector <pair <int, int>> v(n);
    vector <int> left(n), right(n);
    for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
    sort(begin(v), end(v));
    // for (int i = 0; i < n; ++i) cout << v[i].x << " " << v[i].y << '\n';
    stack <pair <int, int>> st;
    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && st.top().first > v[i].second)
        {
            right[st.top().second] = v[i].first;
            st.pop();
        }
        st.push(make_pair(v[i].second, i));
    }
    while (!st.empty())
    {
        right[st.top().second] = MAXX;
        st.pop();
    }
    for (int i = n-1; i >= 0; --i)
    {
        while (!st.empty() && st.top().first > v[i].second)
        {
            left[st.top().second] = v[i].first;
            st.pop();
        }
        st.push(make_pair(v[i].second, i));
    }
    while (!st.empty())
    {
        left[st.top().second] = 0LL;
        st.pop();
    }
    int prex = MAXX, ans = 0, miny = MAXY;
    for (int i = n-1; i >= 0; --i)
    {
        ans = max(ans, (prex-v[i].first)*MAXY);
        ans = max(ans, v[i].second*(right[i]-left[i]));
        prex = v[i].first;
    }
    cout << max(ans, MAXY*prex) << '\n';
}
