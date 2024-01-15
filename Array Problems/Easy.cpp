#include <bits/stdc++.h>
using namespace std;
void largest(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    cout << max << endl;
}
void slargest(int arr[], int n)
{
    int max = arr[0];
    int smax = max;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            smax = max;
            max = arr[i];
        }
    }
    cout << smax << endl;
}
void sorted(int arr[], int n)
{
    int t = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            t = 0;
            break;
        }
    }
    if (t == 0)
        cout << "Not Sorted" << endl;
    else
        cout << "Sorted" << endl;
}
void rem_duplicate(int arr[], int n)
{
    int j = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[j])
        {
            arr[j++] = arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void lrotate(int arr[], int n, int d)
{
    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    reverse(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void zero1(int arr[], int n)
{
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[j] != arr[i] && arr[i] == 0)
        {
            arr[i] = arr[j];
            arr[j] = 0;
            i++;
        }
        if (arr[i] != 0)
            i++;
    }
}
void zero2(int arr[], int n)
{
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}
// Union of two sorted array
void uno()
{
    int n1;
    cin >> n1;
    int a[n1];
    for (int i = 0; i < n1; i++)
        cin >> a[i];
    int n2;
    cin >> n2;
    int b[n2];
    for (int i = 0; i < n2; i++)
        cin >> b[i];
    int i = 0, j = 0;
    vector<int> uno;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            if (uno.size() == 0 || uno.back() != a[i])
                uno.push_back(a[i]);
            i++;
        }
        else
        {
            if (uno.size() == 0 || uno.back() != b[j])
                uno.push_back(b[j]);
            j++;
        }
    }
    while (i < n1)
    {
        if (uno.size() == 0 || uno.back() != a[i])
            uno.push_back(a[i]);
        i++;
    }

    while (j < n2)
    {
        if (uno.size() == 0 || uno.back() != b[j])
            uno.push_back(b[j]);
        j++;
    }
    for (auto it : uno)
        cout << it << " ";
}
// Intersection of two sorted array
void ins()
{
    int n1;
    cin >> n1;
    int a[n1];
    for (int i = 0; i < n1; i++)
        cin >> a[i];
    int n2;
    cin >> n2;
    int b[n2];
    for (int i = 0; i < n2; i++)
        cin >> b[i];
    int i = 0, j = 0;
    vector<int> ins;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
            i++;
        else if (b[j] < a[i])
            j++;
        else
        {
            ins.push_back(a[i]);
            i++;
            j++;
        }
    }
    for (auto it : ins)
        cout << it << " ";
}
// Find the missing number in an array
// Sum method
void sum(int arr[], int n)
{
    long int sum2 = 0, sum1 = n * (n + 1) / 2;
    for (int i = 0; i < n; i++)
    {
        sum2 += arr[i];
    }
    cout << sum2 - sum1;
}
// XOR method
void xoro(int arr[], int n)
{
    int xor1 = 0, xor2 = 0; // This method is slightly better than sum method as we do not
    for (int i = 0; i < n - 1; i++)
    { // have to define long int for larger testcases
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i + 1);
    }
    xor1 = xor1 ^ n;
    cout << (xor1 ^ xor2);
}
// Maximum consecutive ones
void one(int arr[], int n)
{
    int maxi = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            cnt++;
            maxi = max(maxi, cnt);
        }
        else
            cnt = 0;
    }
    cout << maxi;
}
// Find the number that appears once, others will appear twice
void appear(int arr[], int n)
{
    int xor1 = 0;
    for (int i = 0; i < n; i++)
    {
        xor1 = xor1 ^ arr[i]; // a^a=0 or b^b = 0 and 0^b=b and a^a^b=b
    }
    cout << xor1;
}
// Longest subarray with sum k
// Brute force approach
void subarrsum1(int arr[],int n){
    int k, length = 0;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = i; j < n; j++)
        {
            s += arr[j];
            if (s == k)
                length = max(length, j - i + 1);
        }
    }
    cout << length;
}
// Better approach (This runs even if array contains positives and negatives)
void subarrsum2(int arr[], int n)
{
    long long k;
    cin >> k;
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        long long rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    cout << maxLen;
}
// Optimal approach (This runs only if array contains only positives or negatives, (T.C: O(2N), S.C: O(1)))
void subarrsum3(int arr[],int n)
{
    long long k;
    cin >> k;
    int left = 0, right = 0;
    int maxLen = 0;
    long long sum = arr[0];
    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == k)
            maxLen = max(maxLen, right - left + 1);
        right++;
        if (right < n)
            sum += arr[right];
    }
    cout << maxLen;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    // largest(arr, 6);
    // slargest(arr, 6);
    // sorted(arr, 6);
    // rem_duplicate(arr, 6);
    // lrotate(arr, 6, 2);
    // zero1(arr, 6);
    // zero2(arr, 6);
    // uno();
    // ins();
    // sum(arr,6);
    // xoro(arr,6);
    // one(arr,6);
    // appear(arr,6);
    // subarrsum1(arr,6);
    // subarrsum2(arr,6);
    // subarrsum3(arr,6);
    return 0;
}