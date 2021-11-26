/*
    Given an array and a Target sum, find all distinct integer triplets that add up to form target sum.
    The numbers in each triplet should be ordered in ascending order and triplets should be ordered too.
        Brute Force: O(n3)
        Better approach: O(n2) , Space Complexity O(n)    Sort the array, take each element and appply PairSum logic on the rest
        Best approach: O(n2) Space Complexity O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> Triplets(vector<int> arr, int Target)
{
    vector<vector<int>> result;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == Target)
            {
                result.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
            }
            else if (sum < Target)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> arr = {3, 2, 4, 7, 1, 6, 8, 5, 9};
    int Target = 9;
    auto result = Triplets(arr, Target);
    if (result.size() == 0)
    {
        cout << "No such Triplets present" << endl;
    }
    else
    {
        for (auto row : result)
        {
            for (auto num : row)
            {
                cout << num << ", ";
            }
            cout << endl;
        }
    }
    return 0;
}