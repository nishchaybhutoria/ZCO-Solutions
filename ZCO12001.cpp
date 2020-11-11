#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int s1 = 0, s2 = 0, nd = 0, ndpos = 0, en = 0, enpos = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 1) ++s1;
        else ++s2;
        if (s1-s2 > nd)
        {
            nd = (s1-s2);
            ndpos = (i+1);
        }
        if (s1 == s2)
        {
            if (s1+s2 > en)
            {
                en = (s1+s2);
                enpos = i-en+2;
            }
            s1 = s2 = 0;
        }
    }
    cout << nd << " " << ndpos << " " << en << " " << enpos << '\n';
}
