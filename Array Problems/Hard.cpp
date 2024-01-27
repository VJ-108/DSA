#include <bits/stdc++.h>
using namespace std;

// Pascal Triangle
// 1) Given Row and Column number, find the element at that place
void funcncr(int n, int r)
{
    int res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    cout << res;
}
// 2)Print the nth row of Pascal Triangle
void printr(int n)
{
    int res = 1;
    cout << "[ " << res << " ";
    for (int i = 1; i < n - 1; i++)
    {
        res = res * (n - i);
        res = res / i;
        cout << res << " ";
    }
    cout << "]";
}
// 3)Print the whole Pascal Triangle upto N
void pascal(int n)
{
    for (int j = 1; j <= n; j++)
    {
        int res = 1;
        cout << res << " ";
        for (int i = 1; i < j; i++)
        {
            res = res * (j - i);
            res = res / i;
            cout << res << " ";
        }
        cout << endl;
    }
}
// Majority Element (which appear more than n/3 times)
void major(int arr[], int n)
{
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && arr[i] != el2)
        {
            cnt1 = 1;
            el1 = arr[i];
        }
        if (cnt2 == 0 && arr[i] != el1)
        {
            cnt2 = 1;
            el2 = arr[i];
        }
        else if (el1 == arr[i])
            cnt1++;
        else if (el2 == arr[i])
            cnt2++;
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (el1 == arr[i])
            cnt1++;
        if (el2 == arr[i])
            cnt2++;
    }
    int mini = (int)(n / 3) + 1;
    if (cnt1 >= mini)
        cout << el1 << " ";
    if (cnt2 >= mini)
        cout << el2 << " ";
}
// 3-Sum Problem
// Better Approach
void bsum3(int arr[], int n)
{
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(arr[i] + arr[j]);
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
}
// Optimal Approach
void osum3(int arr[], int n)
{
    vector<vector<int>> ans;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
                j++;
            else if (sum > 0)
                k--;
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}
// 4-Sum Problem
void sum4(int arr[], int n)
{
    int target;
    cin >> target;
    vector<vector<int>> ans;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j != i + 1 && arr[j] == arr[j - 1])
                continue;
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];
                if (sum == target)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while (k < l && arr[k] == arr[k - 1])
                        k++;
                    while (k < l && arr[l] == arr[l + 1])
                        l--;
                }
                else if (sum < target)
                    k++;
                else
                    l--;
            }
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}
// No. of Subarray with given xor k
void subarr(int arr[], int n)
{
    int k;
    cin >> k;
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        int x = xr ^ k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    cout << cnt;
}
// Merge Overlapping Sub - intervals
// 1)Brute Force Approach
void merge_interval1()
{
    vector<vector<int>> arr;
    int a;
    for (int i = 0; i < 8; i++)
    {
        vector<int> vec;
        for (int j = 0; j < 2; j++)
        {
            cin >> a;
            vec.push_back(a);
        }
        arr.push_back(vec);
    }
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];
        if (!ans.empty() && end <= ans.back()[1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= end)
                end = max(end, arr[j][1]);
            else
                break;
        }
        ans.push_back({start, end});
    }
    cout << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}
// Optimal Approach
void merge_interval2()
{
    vector<vector<int>> arr;
    int a;
    for (int i = 0; i < 8; i++)
    {
        vector<int> vec;
        for (int j = 0; j < 2; j++)
        {
            cin >> a;
            vec.push_back(a);
        }
        arr.push_back(vec);
    }
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || arr[i][0] > ans.back()[1])
            ans.push_back(arr[i]);
        else
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
    }
    cout << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}
// Merge Two sorted without using any extra space
// 1st Optimal Solution
void merge_sorttwo1()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int left = n - 1;
    int right = 0;
    while (left >= 0 && right < m)
    {
        if (a[left] > b[left])
        {
            swap(a[left], b[right]);
            left--, right++;
        }
        else
            break;
    }
    sort(a, a + n);
    sort(b, b + m);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    for (int i = 0; i < m; i++)
        cout << b[i] << " ";
}
// 2nd Optimal Solution
void swapIfGreater(int a[], int b[], int ind1, int ind2)
{
    if (a[ind1] > b[ind2])
        swap(a[ind1], b[ind2]);
}
void merge_sorttwo2()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int len = (m + n);
    int gap = (len / 2) + (len % 2);
    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while (right < len)
        {
            if (left < n && right >= n)
                swapIfGreater(a, b, left, right - n);
            else if (left >= n)
                swapIfGreater(b, b, left - n, right - n);
            else
                swapIfGreater(a, a, left, right);
            left++, right++;
        }
        if (gap == 1)
            break;
        gap = (gap / 2) + (gap % 2);
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    for (int i = 0; i < m; i++)
        cout << b[i] << " ";
}
// Find missing and repeating numbers
// Sum Method
void find1(int arr[], int n)
{
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S += arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }
    long long val1 = S - SN;   // x - y = ...
    long long val2 = S2 - S2N; // x^2 - y^2 = ...
    val2 = val2 / val1;        // x + y = ...
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    cout << (int)x << " " << (int)y;
}
// XOR Method
void find2(int arr[], int n)
{
    int xr = 0;
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        xr = xr ^ (i + 1);
    }
    int number = xr & ~(xr - 1);
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & (number)) != 0)
            one = one ^ arr[i];
        else
            zero = zero ^ arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if ((i & (number)) != 0)
            one = one ^ i;
        else
            zero = zero ^ i;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == zero)
            cnt++;
    }
    if (cnt == 2)
        cout << zero << " " << one;
    else
        cout << one << " " << zero;
}
// Count Inversion (Number of pairs with i<j and arr[i]>arr[j])
int ms(int arr[], int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int cnt = 0;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    return cnt;
}
int mergesort(int arr[], int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergesort(arr, low, mid);
    cnt += mergesort(arr, mid + 1, high);
    cnt += ms(arr, low, mid, high);
    return cnt;
}
void count_Inversion(int arr[], int n)
{
    cout << mergesort(arr, 0, n - 1);
}
// Reverse Pairs (Number of pairs with i<j and arr[i]>2*arr[j])
void mers(int arr[], int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
int countPairs(int arr[], int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
            right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}
int mergsort(int arr[], int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergsort(arr, low, mid);
    cnt += mergsort(arr, mid + 1, high);
    cnt += countPairs(arr, low, mid, high);
    mers(arr, low, mid, high);
    return cnt;
}
void reverse_pair(int arr[], int n)
{
    cout << mergsort(arr, 0, n - 1);
}
// Maximum Product Sub-array
void Max_product_subarray(int arr[], int n)
{
    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
            pre = 1;
        if (suff == 0)
            suff = 1;
        pre = pre * arr[i];
        suff = suff * arr[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    cout << ans;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // int n,r;
    // cin>>n>>r;
    // funcncr(n-1,r-1);
    // printr(n);
    // pascal(n);
    // major(arr,n);
    // bsum3(arr,n);
    // osum3(arr,n);
    // sum4(arr,n);
    // subarr(arr,n);
    // merge_interval1();
    // merge_interval2();
    // merge_sorttwo1();
    // merge_sorttwo2();
    // find1(arr, n);
    // find2(arr, n);
    // count_Inversion(arr, n);
    // reverse_pair(arr, n);
    // Max_product_subarray(arr,n);
    return 0;
}