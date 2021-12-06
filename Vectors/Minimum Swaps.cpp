/*
    Given an array, find the minimum number of swaps required to make the array sorted.
        T.C - O(nlogn) S.C - O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MinSwaps(vector<int> arr)
{
    int swaps = 0;
    int n = arr.size();
    pair<int, int> ap[n];
    for (int i = 0; i < n; i++)
    {
        ap[i].first = arr[i];
        ap[i].second = i;
    }
    sort(ap, ap + n);
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] or ap[i].first == arr[i])
        {
            continue;
        }
        int node = i;
        while (!visited[node])
        {
            visited[node] = true;
            node = ap[i].second;
            swaps++;
        }
        swaps--;
    }
    return swaps;
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    cout << MinSwaps(arr) << endl;
    return 0;
}