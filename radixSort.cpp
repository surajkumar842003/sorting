#include <iostream> //Writing wrong vacubalary will lead compiler error.
using namespace std;
#include <string>
#include <vector>

void countSort(vector<int> &arr, vector<string> &mnums)
{

    int max = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (max < arr[i])
        {
            // Start thinking every step from scratch
            max = arr[i];
        }
    }

    vector<int> arr1(max + 1, 0); // misplaced vector can cause eror unqualified-id

    for (int j = 0; j < arr.size(); j++)
    {
        arr1[arr[j]] = 1;
    }

    // frequency calculation
    vector<int> freq(max + 1, 0);

    for (int i = 0; i < freq.size(); i++)
    {
        if (i - 1 < 0)
            freq[i] = arr1[i];
        else
        {
            freq[i] = freq[i - 1] + arr1[i];
        }
    }
    vector<string> mnums1 = mnums; // Copying 2-D array
    vector<int> ans(arr.size(), 0);
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        ans[freq[arr[i]] - 1] = arr[i];
        mnums[freq[arr[i]] - 1] = mnums1[i];
        freq[arr[i]]--;
    }

    cout << endl;
    arr = ans; // Array copying short trick
}

void radixSort(vector<string> &mnums)
{
    for (int i = mnums[0].size() - 1; i >= 0; i--)
    {

        vector<int> arr(mnums.size(), 0); // No initialisation to this vector uff array
        for (int j = 0; j < mnums.size(); j++)
        {
            arr[j] = mnums[j][i] - 48;
        }
        countSort(arr, mnums);
    }
    for (int j = 0; j < mnums.size(); j++)
    {
        cout << mnums[j] << " ";
    }

    cout << endl;
}

int main()
{

    vector<string> nums = {"102", "473", "251", "814", "099"};
    radixSort(nums);
    return 0;
}