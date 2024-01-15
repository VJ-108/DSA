#include <bits/stdc++.h>
using namespace std;
int printname(int i,int n){ // Time complexity: O(N)
    if (i>n) return 0;  // Space complexity: O(N)
    cout<<"Hello"<<endl;
    printname(i+1,n);
}
int printdig(int i,int n){
    if (i>n) return 0;
    cout<<i<<endl;
    printdig(i+1,n);
}
//print 1 to n without using i+1
int printb(int i,int n){ //This method is known as backtrack as the i is printed when
    if (i<1) return 0;   //function base condition are met or when function call starts 
    printb(i-1,n);       //to move out of stack so the last function call runs first
    cout<<i<<endl;       //thats why we get 1,2,3..n otherwise we will get n,n-1,...,1
}
//print n to 1 without using i-1
int printa(int i,int n){ //This method is known as backtrack as the i is printed when
    if (i>n) return 0;   //function base condition are met or when function call starts 
    printa(i+1,n);       //to move out of stack so the last function call runs first
    cout<<i<<endl;       //thats why we get n,n-1,..,1 otherwise we will get 1,2,3...n
}
int sump(int i,int n){
    if (i<1) {cout<<n; return 0;}
    sump(i-1,n+i);
}
int sumf(int n){
    if (n==0) return 0;
    return n + sumf(n-1);
}
int fac(int n){
    if (n==0) return 1;
    return n*fac(n-1);
}
int rev(int i,int arr[],int n){
    if (i>=n/2) return 0;
    swap(arr[i],arr[n-i-1]);
    rev(i+1,arr,n);
}
bool pal(int i,string &s){
    if (i>=s.size()/2) return true;
    if (s[i]!=s[s.size()-i-1]) return false;
    pal(i+1,s);
}
int fibo(int n){//Time complexity: approx 2^n, since approx every function calls 2 function
    if (n<=1) return n;
    return fibo(n-1)+fibo(n-2);
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    printname(1,n);cout<<endl;
    printdig(1,n);cout<<endl;
    printb(n,n);cout<<endl;
    printa(1,n);cout<<endl;
    sump(n,0);cout<<endl;
    cout<<sumf(n)<<endl;
    cout<<fac(n)<<endl;
    int arr[n];
    cout<<"Enter an array: ";
    for (int i=0;i<n;i++) cin>>arr[i];
    rev(0,arr,n);
    for (int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;   
    string s = "MADAM";
    cout<<pal(0,s)<<endl;
    cout<<fibo(n)<<endl;
    return 0;
}