/*
    Given an array of integers, find the length of the longest band of consecutive integers that can be formed from the array elements.
        Brute Force: O(nlog(n)) Sort and then compare
        Best approach: O(n) with O(n) space complexity
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestBand(vector<int> arr)
{
    unordered_set<int> S;
    int maxLength = 0;
    for (int num : arr)
        S.insert(num);
    for (int element : S)
    {
        int parent = element - 1;
        if (S.find(parent) == S.end())
        {
            int length = 1;
            int next = element + 1;
            while (S.find(next) != S.end())
            {
                next++;
                length++;
            }
            if (length > maxLength)
                maxLength = length;
        }
    }
    return maxLength;
}

int main()
{
    vector<int> arr = {1, 9, 3, 0, 18, 5, 4, 10, 7, 12, 6};
    cout << longestBand(arr) << endl;
}