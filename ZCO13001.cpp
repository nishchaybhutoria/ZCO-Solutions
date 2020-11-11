#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    vector <long long> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    long long left = 0, right = 0;
    for (int i = 0; i < n; ++i)
    {
        left += (i*nums[i]);
        right += (nums[i]*(n-i-1));
    }
    cout << (left - right) << '\n';
}
