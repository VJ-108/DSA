#include <bits/stdc++.h>
using namespace std;

// T.C: O(logN)
// Overflow case: happens when both low and high is INT_MAX and mid being an integer
// cannot store 2*INT_MAX so either use long long or use mid = low + (high-low)/2
// Iterative Binary Search
int BS_Iter(int arr[], int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
// Recursive Binary Search
int BS_Rec(int arr[], int low, int high, int target)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return BS_Rec(arr, mid + 1, high, target);
    else
        return BS_Rec(arr, low, mid - 1, target);
}
// Lower Bound: Smallest Index such that arr[index]>=target
int Lower_Bound(int arr[], int n, int target)
{
    int low = 0, high = n - 1, ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
// Upper Bound: Smallest Index such that arr[index]>target
int Upper_Bound(int arr[], int n, int target)
{
    int low = 0, high = n - 1, ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
// Floor(largest no.<=target) and Ceil(smallest no.>=target) in a sorted array
int Floor(int arr[], int n, int target)
{
    int low = 0, high = n - 1, ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] <= target)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}
int Ceil(int arr[], int n, int target)
{
    int low = 0, high = n - 1, ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
// Find the first and the last occurence of target
// 1)Lower and upper bound method
vector<int> First_Last(int arr[], int n, int target)
{
    int lb = Lower_Bound(arr, n, target);
    if (lb == n || arr[lb] != target)
        return {-1, -1};
    return {lb, Upper_Bound(arr, n, target) - 1};
}
// 2)Binary Search Method
int first_Occurence(int arr[], int n, int target)
{
    int low = 0, high = n - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return first;
}
int last_Occurence(int arr[], int n, int target)
{
    int low = 0, high = n - 1;
    int last = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return last;
}
// Search in a rotated sorted array containing unique elements
// Note: Identify the sorted half
int search_rotated_array1(int arr[], int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= target && target <= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (arr[mid] <= target && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
// Search in a rotated sorted array containing duplicate elements
void search_rotated_array2(int arr[], int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            cout << "True";
            break;
        }
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++, high--;
            continue;
        }
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= target && target <= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (arr[mid] <= target && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
}
// Minimum in rotated sorted array
int min_rotated_array(int arr[], int n)
{
    int low = 0, high = n - 1, ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[high])
        {
            ans = min(ans, arr[low]);
            break;
        }
        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else
        {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}
// Find how many times array is rotated
int times_rotated(int arr[], int n)
{
    int low = 0, high = n - 1, ans = INT_MAX, index = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[high])
        {
            if (ans > arr[low])
            {
                ans = arr[low];
                index = low;
            }
            break;
        }
        if (arr[low] <= arr[mid])
        {
            if (ans > arr[low])
            {
                ans = arr[low];
                index = low;
            }
            low = mid + 1;
        }
        else
        {
            if (ans > arr[mid])
            {
                ans = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}
// Find the element which appears once
int appear__once(int arr[], int n)
{
    int low = 1, high = n - 2;
    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
            return arr[mid];
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) or (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
            low = mid + 1; // Eliminated the left half
        else
            high = mid - 1; // Eliminated the right half
    }
    return -1;
}
// Find Peak element (arr[i-1]<arr[i]>arr[i+1])
int peak_element(int arr[], int n)
{
    int low = 1, high = n - 2;
    if (arr[0] > arr[1])
        return arr[0];
    if (arr[n - 1] > arr[n - 2])
        return arr[n - 1];
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return arr[mid];
        else if (arr[mid] > arr[mid - 1])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
// Find Sqrt of a number
int sqrt_number(int n)
{
    int low = 1, high = n;
    int ans = INT_MIN;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if ((mid * mid) <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}
// Find Nth Sqrt of a number
int func_sqrt(int mid, int n, int m)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}
int Nth_sqrt(int m)
{
    int n;
    cin >> n;
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (func_sqrt(mid, n, m) == 1)
            return mid;
        else if (func_sqrt(mid, n, m) == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
// Koko Eating Banana
int func_koko(int arr[], int n, int hour)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += ceil((double)arr[i] / (double)hour);
    }
    return ans;
}
int Koko(int arr[], int n, int hour)
{
    int ans, low = 1, high = *max_element(arr, arr + n);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midN = func_koko(arr, n, mid);
        if (midN <= hour)
            high = mid - 1;
        else
            low = mid + 1;
        ans = low;
    }
    return ans;
}
// Minimum days to make m bouqet by taking k adjacent flowers
int bouqet_possible(int arr[], int n, int day, int m, int k)
{
    int cnt = 0, no_of_bouqet = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= day)
            cnt++;
        else
        {
            no_of_bouqet += (cnt / k);
            cnt = 0;
        }
    }
    no_of_bouqet += (cnt / k);
    if (no_of_bouqet >= m)
        return 1;
    return 0;
}
int min_bouqet(int arr[], int n, int m)
{
    int k;
    cin >> k;
    if ((m * k) > n)
        return -1;
    int low = *min_element(arr, arr + n), high = *max_element(arr, arr + n);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (bouqet_possible(arr, n, mid, m, k) == 1)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
// Find the smallest divisor given a threshold
int divisor_possible(int arr[], int n, int mid, int threshold)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += ceil((double)arr[i] / (double)mid);
    }
    if (sum <= threshold)
        return 1;
    return 0;
}
int smallest_divisor(int arr[], int n, int threshold)
{
    int low = 1, high = *max_element(arr, arr + n);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midN = divisor_possible(arr, n, mid, threshold);
        if (midN == 1)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
// Least Capacity to ship packages within D days
int Capacity_possible(int arr[], int n, int mid, int tot)
{
    int day = 1, load = 0;
    for (int i = 0; i < n; i++)
    {
        if (load + arr[i] > mid)
        {
            day = day + 1;
            load = arr[i];
        }
        else
            load += arr[i];
    }
    if (day <= tot)
        return 1;
    return 0;
}
int least_Capacity(int arr[], int n, int day)
{
    int low = *max_element(arr, arr + n), high = accumulate(arr, arr + n, 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midN = Capacity_possible(arr, n, mid, day);
        if (midN == 1)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
// Find the Kth missing Number
int missing_number(int arr[], int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return (high + 1 + target); // return low+target
}
// Aggressive Cows (min. distance b/w them is max.)
bool can_we_place(int arr[], int n, int dist, int cow)
{
    int cnt = 1, last = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - last >= dist)
        {
            cnt++;
            last = arr[i];
        }
    }
    if (cnt >= cow)
        return true;
    return false;
}
int aggressive_cow(int arr[], int n, int target)
{
    sort(arr, arr + n);
    int low = 1, high = arr[n - 1] - arr[0];
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midN = can_we_place(arr, n, mid, target);
        if (midN == true)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}
// Allocate Books (max. no. of pages assigned to a student is min.)
int count_student(int arr[], int n, int mid, int target)
{
    int cnt = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] > mid)
        {
            cnt++;
            sum = arr[i];
        }
        else
            sum += arr[i];
    }
    if (cnt > target)
        return 1;
    return 0;
}
int allocate_books(int arr[], int n, int target)
{
    if (n < target)
        return -1;
    int low = *max_element(arr, arr + n), high = accumulate(arr, arr + n, 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midN = count_student(arr, n, mid, target);
        if (midN == 1)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
// Minimise Maximum distance between gas station
int gas_possible(int arr[], int n, long double mid)
{
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        int No_in_between = ((arr[i] - arr[i - 1]) / mid);
        if ((arr[i] - arr[i - 1]) / mid == No_in_between * mid)
            No_in_between--;
        cnt += No_in_between;
    }
    return cnt;
}
long double gas_station(int arr[], int n, int target)
{
    long double low = 0, high = 0;
    for (int i = 0; i < n - 1; i++)
        high = max(high, (long double)arr[i + 1] - arr[i]);
    long double diff = 1e-6;
    while (high - low > diff)
    {
        long double mid = (low + high) / (2.0);
        int cnt = gas_possible(arr, n, mid);
        if (cnt > target)
            low = mid;
        else
            high = mid;
    }
    return high;
}
// Median of two sorted array
double median(int arr1[], int arr2[], int n1, int n2)
{
    if (n1 > n2)
        return median(arr2, arr1, n2, n1);
    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2;
    int n = n1 + n2;
    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1)
            r1 = arr1[mid1];
        if (mid2 < n2)
            r2 = arr2[mid2];
        if (mid1 - 1 >= 0)
            l1 = arr1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = arr2[mid2 - 1];
        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
                return (double)max(l1, l2);
            return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0;
}
int K_element(int arr1[], int arr2[], int n1, int n2, int k)
{
    if (n1 > n2)
        return K_element(arr2, arr1, n2, n1, k);
    int low = max(0, k - n2), high = min(k, n1);
    int left = k;
    int n = n1 + n2;
    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1)
            r1 = arr1[mid1];
        if (mid2 < n2)
            r2 = arr2[mid2];
        if (mid1 - 1 >= 0)
            l1 = arr1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = arr2[mid2 - 1];
        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
                return (double)max(l1, l2);
        }
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0;
}
// Row with max number of 1s
int Max_1(vector<vector<int>> &mat, int n, int m)
{
    int cnt = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        int curr = count(mat[i].begin(), mat[i].end(), 1);

        if (curr > cnt)
        {
            cnt = curr;
            index = i;
        }
    }
    return index;
}
// Search in a sorted Matrix - 1
bool Search_Mat_1(vector<vector<int>> &mat, int n, int m, int target)
{
    int low = 0, high = n * m - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;
        if (mat[row][col] == target)
            return true;
        else if (mat[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}
// Search in a sorted Matrix - 2
bool Search_Mat_2(vector<vector<int>> &mat, int n, int m, int target)
{
    int row = 0, col = m - 1;
    while (row < n && col >= 0)
    {
        if (mat[row][col] == target)
            return true;
        else if (mat[row][col] < target)
            row++;
        else
            col--;
    }
    return false;
}
// Peak element in Matrix
int findMax(vector<vector<int>> &mat, int n, int m, int col)
{
    int maxValue = -1;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (mat[i][col] > maxValue)
        {
            maxValue = mat[i][col];
            index = i;
        }
    }
    return index;
}
int Peak_Mat(vector<vector<int>> &mat, int n, int m)
{
    int low = 0, high = m - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = findMax(mat, n, m, mid);
        int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
        int right = mid + 1 < m ? mat[row][mid + 1] : -1;
        if (mat[row][mid] > left && mat[row][mid] > right)
            return mat[row][mid];
        else if (mat[row][mid] < left)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
// Median of row-wise sorted matrix
int count_smaller(vector<vector<int>> &mat, int n, int m, int x)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += upper_bound(mat[i].begin(), mat[i].end(), x) - mat[i].begin();
    }
    return cnt;
}
int median_mat(vector<vector<int>> &mat, int n, int m)
{
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][m - 1]);
    }

    int req = (n * m + 1) / 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int smaller = count_smaller(mat, n, m, mid);
        if (smaller <= req)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main()
{
    int n, m, k;
    cin >> n >> m;
    // int arr[n], arr1[m];
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];
    // for (int i = 0; i < m; i++)
    //     cin >> arr1[i];
    // int target;
    // cin >> target;
    // cout<<BS_Iter(arr,n,target);
    // cout<<BS_Rec(arr,0,n-1,target);
    // cout<<Lower_Bound(arr,n,target);
    // OR we can use built in function
    // cout<<lower_bound(arr,arr+n,target)-arr;
    // cout<<Upper_Bound(arr,n,target);
    // OR we can use built in function
    // cout<<upper_bound(arr,arr+n,target)-arr;
    // cout<<Floor(arr,n,target);
    // cout<<Ceil(arr,n,target);
    // cout<<First_Last(arr,n,target)[0]<<" "<<First_Last(arr,n,target)[1];
    // cout<<first_Occurence(arr,n,target)<<" "<<last_Occurence(arr,n,target);
    // cout<<search_rotated_array1(arr,n,target);
    // search_rotated_array2(arr,n,target);
    // cout<<min_rotated_array(arr,n);
    // cout<<times_rotated(arr,n);
    // cout<<appear__once(arr,n);
    // cout<<peak_element(arr,n);
    // cout<<sqrt_number(n);
    // cout<<Nth_sqrt(n);
    // cout<<Koko(arr,n,target);
    // cout<<min_bouqet(arr,n,target);
    // cout<<smallest_divisor(arr,n,target);
    // cout<<least_Capacity(arr,n,target);
    // cout<<missing_number(arr,n,target);
    // cout<<aggressive_cow(arr,n,target);
    // cout<<allocate_books(arr,n,target);
    // cout<<gas_station(arr,n,target);
    // cout << median(arr, arr1, n, m) << endl;
    // cout << K_element(arr, arr1, n, m,k) << endl;
    // cout << Max_1(mat, n, m);
    // cout << Search_Mat_1(mat, n, m, k);
    // cout << Search_Mat_2(mat, n, m, k);
    // cout << Peak_Mat(mat, n, m);
    cout << median_mat(mat, n, m);
    return 0;
}