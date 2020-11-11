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

bool type(int n) {return (n > 2);}
bool close(int n) {return ((n & 1) ? 0 : 1);}

signed main()
{
    usaco();
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int s1 = 0, s2 = 0, s3 = 0, s4 = 0, ans = 1;
    stack <int> bra, dep;
    for (int i = 0; i < n; ++i)
    {
        if (bra.empty())
        {
            bra.push(a[i]);
            dep.push(1);
        } else {
            if (a[i] & 1)
            {
                if (a[i] == bra.top()) dep.push(dep.top());
                else dep.push(dep.top()+1);
                bra.push(a[i]);
            } else {
                ans = max(ans, dep.top());
                dep.pop();
                bra.pop();
            }
        }
    }
    int c1 = 0, c2 = 0, t1 = 0, t2 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 1) ++s1;
        if (a[i] == 2) ++s2;
        if (a[i] == 3) ++s3;
        if (a[i] == 4) ++s4;
        c1 += (s1 != 0);
        if (s1 == s2)
        {
            t1 = max(t1, c1);
            c1 = 0;
            s1 = s2 = s3 = s4 = 0;
        }
    }
    s1 = s2 = s3 = s4 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 1) ++s1;
        if (a[i] == 2) ++s2;
        if (a[i] == 3) ++s3;
        if (a[i] == 4) ++s4;
        c2 += (s3 != 0);
        if (s3 == s4)
        {
            t2 = max(t2, c2);
            c2 = 0;
            s1 = s2 = s3 = s4 = 0;
        }
    }
    cout << ans << " " << t1 << " " << t2 << '\n';
}

/*
22
1 3 4 1 1 3 3 4 1 1 3 1 2 4 1 2 2 2 4 2 2 2
5 22 14
*/
