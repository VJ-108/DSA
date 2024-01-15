#include <bits/stdc++.h>
using namespace std;
//Selection Sort
void selection(int arr[],int n){
    for(int i=0;i<=n-2;i++){
        int min = i;
        for(int j=i;j<=n-1;j++){
            if (arr[j]<arr[min]) min = j;
        }
        // swap(arr[min],arr[i]);
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
//Recursive Selection Sort
void recselection(int arr[],int start,int n){
    if (start>=n) return;
    int min = start;
    for (int i=start;i<n;i++){
        if (arr[i]<arr[min]) min = i;
    }
    swap(arr[min],arr[start]);
    recselection(arr,start+1,n);
}
//Bubble Sort
void bubble(int arr[],int n){
    for(int i=n-1;i>=0;i--){
        int didswap = 0;
        for(int j=0;j<=i-1;j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                didswap = 1;
            }
        }
        if (didswap == 0) break;
    }
}
//Recursive Bubble Sort
void recbubble(int arr[],int n){
    if (n==0) return;
    for (int i=0;i<n;i++)
    {
        if (arr[i]>arr[i+1]) swap(arr[i],arr[i+1]);
    }
    recbubble(arr,n-1);   
}
//Insertion Sort
void insertion(int arr[],int n){
    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>0 && (arr[j-1]>arr[j])){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}
//Recursive Insertion Sort
void recinsertion(int arr[],int start,int n){
    if (start==n) return;
    int j=start;
    while(j>0 && (arr[j-1]>arr[j])){
        swap(arr[j-1],arr[j]);
        j--;
    }
    recinsertion(arr,start+1,n);
}
//Merge Sort
void ms(int arr[],int low,int mid,int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while (left<=mid && right<=high){
        if (arr[left]<=arr[right]){ 
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for (int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void mergesort(int arr[],int low,int high){
    if (low>=high) return;
    int mid = (low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    ms(arr,low,mid,high);
}
//Quick Sort
int partition(int arr[],int low,int high){
    int pivot = arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1) i++;
        while(arr[j]>pivot && j>=low+1) j--;
        if (i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
};
void quicksort(int arr[],int low,int high){
    if (low<high){
        int pIndex = partition(arr,low,high);
        quicksort(arr,low,pIndex-1);
        quicksort(arr,pIndex+1,high);
    }
}

int main(){
    int n;
    cin>>n;
    int low=0,high=n-1;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    // selection(arr,n);
    // recselection(arr,0,n);
    // bubble(arr,n);
    // recbubble(arr,n);
    // insertion(arr,n);
    // recinsertion(arr,0,n);
    // mergesort(arr,low,high);
    // quicksort(arr,low,high); 
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
return 0;
}