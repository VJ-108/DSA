#include <bits/stdc++.h>
using namespace std;

//2 sum problem
string twosum(int arr[],int n){
    int target;
    cin>>target;
    int left=0,right=n-1;
    sort(arr,arr+n);
    while(left<right){
        int p = arr[left]+arr[right];
        if (p==target) return "YES";
        else if (p<target) left++;
        else right--;
    }
    return "NO";
}
//Sort an array of 0,1 and 2 (Dutch National Flag Algorithm) (T.C: O(N), S.C: O(1))
void DNFA(int arr[],int n){
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if (arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid]==1) mid++;
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
//Find Majority element(appearing more than N/2 times)
//Better Approach
int major1(int arr[],int n){
    map<int,int> mpp;
    for (int i=0;i<n;i++) mpp[arr[i]]++;
    for(auto it: mpp){
        if (it.second > n/2) return it.first;
    }
    return -1;
}
//Optimal Approach (Moore's Voting Algorithm) (T.C: O(2N) if majority element may or)
void major2(int arr[],int n){ // (may not be present but if it is stated there is a majority)
    int ele=arr[0],cnt=0;     // (element then T.C: O(N) as the second loop is not required)
    for (int i=0;i<n;i++){    // (S.C: O(1))
        if (cnt==0){
            cnt = 1;
            ele = arr[i];
        }
        if (arr[i]==ele) cnt++;
        else cnt--;
    }
    int cnt1=0;
    for (int i=0;i<n;i++){
        if (arr[i]==ele) cnt1++;
    }
    if (cnt1>n/2) cout<<ele<<endl;
    else cout<<"-1"<<endl;
}
//Maximum Subarray sum (Kadane's Algorithm) (T.C: O(N), S.C: O(1))
void maxsub(int arr[],int n){
    int sum=0,maxi=INT_MIN;
    int start,st=-1,end=-1;
    for(int i=0;i<n;i++){
        if (sum==0) start=i;
        sum+=arr[i];
        if (sum>maxi){
            maxi = sum;
            st=start;
            end=i;
        }
        if (sum<0) sum=0;
    }
    cout<<maxi<<endl;
    //To print that subarray
    for(int i=st;i<=end;i++) cout<<arr[i]<<" ";
}
//Buy and sell stocks
void buy(int arr[],int n){
    int mini=arr[0];
    int maxprofit=0;
    for (int i=0;i<n;i++){
        int cost = arr[i]-mini;
        maxprofit = max(maxprofit,cost);
        mini = min(mini,arr[i]);
    }
    cout<<maxprofit<<endl;
}
//Rearrange elements by sign containing equal no. of positives and negatives (T.C: O(N+N/2), S.C: O(N))
void rearr1(int arr[],int n){
    int arr1[n];
    int posIndex = 0,negIndex = 1;
    for (int i=0;i<n;i++){
        if (arr[i]<0){
            arr1[negIndex]=arr[i];
            negIndex+=2;
        }
        else{
            arr1[posIndex]=arr[i];
            posIndex+=2;
        }
    }
    for(int i=0;i<n;i++) cout<<arr1[i]<<" ";
}
//Rearrange elements by sign containing unequal no. of positives and negatives (T.C: O(2N), S.C: O(N))
void rearr2(int arr[],int n){
    vector<int> pos,neg;
    for (int i=0;i<n;i++){
        if (arr[i]>0) pos.emplace_back(arr[i]);
        else neg.emplace_back(arr[i]);
    }
    if (pos.size()>neg.size()){
        for (int i=0;i<neg.size();i++){
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }
        int index=neg.size()*2;
        for (int i=neg.size();i<pos.size();i++){
            arr[index]=pos[i];
            index++;
        }
    }
    else{
        for (int i=0;i<pos.size();i++){
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }
        int index=pos.size()*2;
        for (int i=pos.size();i<neg.size();i++){
            arr[index]=neg[i];
            index++;
        }
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
//Next Permutation
//Better Approach as brute will generate a very high order time complexity
void perm1(int arr[],int n){
    next_permutation(arr,arr+n);
    for (int i=0;i<n;i++) cout<<arr[i]<<" ";
}
//But it is not good to use STL during interview
//Optimal Approach (T.C: O(3N), S.C: O(1))
/*
Steps involved: 
1) Longer prefix match ---> when arr[i]<arr[i+1]
2) Find someone > 1, but the smallest one so that you stay close
3) Try to place the remaining in sorted manner
*/
int* perm2(int arr[],int n){
    int ind = -1;
    for (int i=n-2;i>=0;i--){
        if (arr[i]<arr[i+1]){
            ind = i;
            break;
        }
    }
    if (ind==-1){
        reverse(arr,arr+n);
        return arr;
    }
    for (int i=n-1;i>ind;i--){
        if (arr[i]>arr[ind]){
            swap(arr[i],arr[ind]);
            break;
        }
    }
    reverse(arr+ind+1,arr+n);
    return arr;
}
//Leaders(on their right every element is smaller than them) in an array
void leaders(int arr[],int n){
    vector<int> ans;
    int maxi = INT_MIN;
    for (int i=n-1;i>=0;i--){
        if (arr[i]>maxi){
            ans.emplace_back(arr[i]);
            maxi = max(maxi,arr[i]);
        }
    }
    sort(ans.begin(),ans.end());
    for(auto it: ans) cout<<it<<" ";
}
//Longest Consecutive Sequence
//Better Approach
void longest1(int arr[],int n){
    sort(arr,arr+n);
    int last_smaller = INT_MIN;
    int cnt = 0;
    int longest = 1;
    for (int i=0;i<n;i++){
        if (arr[i]-1==last_smaller){
            cnt++;
            last_smaller=arr[i];
        }
        else if (last_smaller!=arr[i]){
            cnt=1;
            last_smaller=arr[i];
        }
        longest = max(longest,cnt);
    }
    cout<<longest;
}
//Optimal Approach (T.C: O(3N), S.C: O(N))
void longest2(int arr[],int n){
    if (n==0) cout<<"0";
    int longest = 1;
    unordered_set <int> st;
    for (int i=0;i<n;i++) st.insert(arr[i]);
    for (auto it: st){
        if (st.find(it-1)==st.end()){
            int cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end()){
                x++;
                cnt++;
            }
            longest = max(longest,cnt);
        }
    }
    cout<<longest;
}
//Set Matrix Zero
//Brute Force Approach
void mat1(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>a[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (a[i][j]==0){
                for(int j=0;j<m;j++){
                    if (a[i][j]!=0) a[i][j]=-1;
                }
                for(int i=0;i<n;i++){
                    if (a[i][j]!=0) a[i][j]=-1;
                }
                
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            if (a[i][j]==-1) a[i][j]=0;
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<a[i][j]<<" "; cout<<endl;
    }
}
//Better Approach
void mat2(){
    int n,m;
    cin>>n>>m;
    int a[n][m],row[n]={0},col[m]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>a[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (a[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (row[i]||col[j]) a[i][j]=0;
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<a[i][j]<<" "; cout<<endl;
    }
}
//Optimal Approach
void mat3(){
    int n,m,col0=1;
    cin>>n>>m;
    int a[n][m],row[n]={0},col[m]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>a[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (a[i][j]==0){
                a[i][0]=0;
                if (j!=0) a[0][j]=0;
                else col0=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (a[i][j]!=0){
                if (a[i][0]==0||a[0][j]==0) a[i][j]=0;
            }
        }
    }
    if (a[0][0]==0){
        for(int j=0;j<m;j++) a[0][j]=0;
    }
    if (col0==0){
        for (int i=0;i<n;i++) a[i][0]=0;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<a[i][j]<<" "; cout<<endl;
    }    
}
//Rotate matrix by 90 degree
void rot(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>a[i][j];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<m;j++) swap(a[i][j],a[j][i]);
    }
    for (int i=0;i<n;i++) reverse(a[i],a[i]+n);
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<a[i][j]<<" "; cout<<endl;
    }
}
//Spiral Traverse of matrix
void spiral(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>a[i][j];
    }
    vector<int> ans;
    int left = 0,right = n-1;
    int top = 0,bottom = n-1;

    while(top<=bottom && left<=right){
        for (int i=left;i<=right;i++) ans.push_back(a[top][i]);
        top++;
        for (int i=top;i<=bottom;i++) ans.push_back(a[i][right]);
        right--;
        if (top<=bottom){
            for (int i=right;i>=left;i--) ans.push_back(a[bottom][i]);
            bottom--;
        }
        if (left<=right){
            for (int i=bottom;i>=top;i--) ans.push_back(a[i][left]);
            left++;
        }
    }
    cout<<endl;
    for (auto it: ans) cout<<it<<" ";
}
//Count Subarray sum equals k
void sub(int arr[],int n){
    int k;
    cin>>k;
    unordered_map<int,int> mpp;
    mpp[0]=1;
    int preSum = 0,cnt =0;
    for (int i=0;i<n;i++){
        preSum+=arr[i];
        int remove = preSum-k;
        cnt += mpp[remove];
        mpp[preSum]+=1;
    }
    cout<<cnt;
}

int main(){
    // int *p;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    // cout<<twosum(arr,n);
    // DNFA(arr,n);
    // cout<<major1(arr,n);
    // major2(arr,n);
    // maxsub(arr,n);
    // buy(arr,n);
    // rearr1(arr,n);
    // rearr2(arr,n);
    // perm1(arr,n);
    // p = perm2(arr,n);
    // leaders(arr,n);
    // longest1(arr,n);
    // longest2(arr,n);
    // mat1();
    // mat2();
    // mat3();
    // rot();
    // spiral();
    // sub(arr,n);
    // for(int i=0;i<n;i++) cout<<*(p+i)<<" ";
    // for(int i=0;i<n;i++) cout<<arr[i]<<" ";
return 0;
}