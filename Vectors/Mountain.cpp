/*
    Given an array, find the tallest mountain and print its height.
    A mountain is defined as adjascent integers that are strictly increasing  until they reach a peak,after which they become strictly decrasing
    At least 3 numbers are required to form a mountain.
    The height of a mountain is the number of elements required to build that mountain.
*/

#include <iostream>
#include <vector>
using namespace std;

int Mountain(vector<int> arr)
{
    int n = arr.size();
    int maxHeight = 0;
    for (int i = 1; i < n - 1;)
    {
        if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1])
        { //peak
            int height = 3;
            int j = i - 1;
            while (j > 0 and arr[j] > arr[j - 1])
            {
                height++;
                j--;
            }
            j = i + 1;
            while (j < n - 1 and arr[j] > arr[j + 1])
            {
                height++;
                j++;
            }
            maxHeight = max(height, maxHeight);
        }
        i++;
    }
    return maxHeight;
}

int main()
{
    vector<int> arr = {5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
    cout << Mountain(arr) << endl;
    return 0;
}