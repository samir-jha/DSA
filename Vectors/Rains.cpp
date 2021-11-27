/*
    Given an array whose elements represent heights of a building, find the maximum water that can be trapped between the buildings.
    Best approach: O(n) Space Complexity O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rains(vector<int> arr)
{
    int water = 0, n = arr.size();
    vector<int> left(n, 0), right(n, 0);
    left[0] = (arr[0]);
    right[n - 1] = (arr[n - 1]);
    for (int i = 1; i < n; i++)
    {
        left[i] = (max(left[i - 1], arr[i]));
        right[n - i - 1] = (max(right[n - i], arr[n - i - 1]));
    }

    for (int i = 0; i < n; i++)
    {
        water += (min(left[i], right[i]) - arr[i]);
    }
    return water;
}

int main()
{
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << rains(arr) << endl;
    return 0;
}