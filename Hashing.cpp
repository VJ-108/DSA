#include <bits/stdc++.h>
using namespace std;
    // int n;
    // cout<<"Enter size of array: ";
    // cin>>n;
    // int arr[n],s;
    // cout<<"Enter array: "<<endl;
    // for (int i=0;i<n;i++) cin>>arr[i];
    // cout<<"Enter the total no. of elements you want to search: ";
    // cin>>s;
    // int hash[13]={0};
    // //precompute
    // for(int i=0;i<n;i++){
    //     hash[arr[i]]+=1;
    // }
    // while(s>0){
    //     int a;
    //     cout<<"Enter the element: ";
    //     cin>>a;
    //     //fetch
    //     cout<<"Occurence: "<<hash[a]<<endl;
    //     s--;
    // }

    // string s;
    // cout<<"Enter a string: ";
    // cin>>s;
    // int hash[256]={0};
    // for(int i=0;i<s.size();i++){
    //     hash[s[i]]++;
    // }
    // int cha;
    // cout<<"Enter the total no. of character: ";
    // cin>>cha;
    // while(cha--){
    //     char character;
    //     cout<<"Enter the character: ";
    //     cin>>character;
    //     cout<<hash[character]<<endl;
    // }

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n],s;
    unordered_map<int,int> mapp;
    cout<<"Enter array: "<<endl;
    for (int i=0;i<n;i++){ 
        cin>>arr[i];
        mapp[arr[i]]++;
    }
    // cout<<"Enter the total no. of elements you want to search: ";
    // cin>>s;
    // while(s>0){
    //     int a;
    //     cout<<"Enter the element: ";
    //     cin>>a;
    //     //fetch
    //     cout<<"Occurence: "<<mapp[a]<<endl;
    //     s--;
    // }
    //To find highest and lowest frequency
    int min=100,max=-1;
    for(auto it:mapp){
        if (it.second>max) max=it.second;
    }
    for(auto it:mapp){
        if (it.second<min) min=it.second;
    }
    cout<<max<<" "<<min<<endl;
return 0;
}