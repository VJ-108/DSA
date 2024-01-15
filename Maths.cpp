#include <bits/stdc++.h>
using namespace std;
void count_dig(int n){
    //int c = (int)(log10(n)+1);
    int c=0;
    while(n>0){
        n=n/10;
        c++;
    }
    cout<<"No. of digits: "<<c<<endl;;    
}
void reverse(int n){
    int c=0;
    while(n>0){
        c=c*10+(n%10);
        n=n/10;
    }
    cout<<"Reverse: "<<c<<endl;
}
void palindrome(int n){
    int s=n,c=0;
    while(n>0){
        c=c*10+(n%10);
        n=n/10;
    }
    if (s==c) cout<<"Palindrome";
    else cout<<"Not a palindrome";
    cout<<endl;
}
void armstrong(int n){
    int a,s=n,c=0;
    while(n>0){
        a = n%10;
        c=c+(a*a*a);
        n=n/10;
    }
    if (s==c) cout<<"Armstrong";
    else cout<<"Not a Armstrong";
    cout<<endl;
}
void divisor(int n){
    cout<<"Divisors are:";
    //Time complexity: O(N)
    // for(int i=1;i<=n;i++){
    //     if (n%i==0) cout<<i<<" ";
    // }
    //Time complexity: O(sqrt(N))
    vector <int> ls;
    for(int i=1;i*i<=n;i++){
        if (n%i==0){
            ls.push_back(i);
            if (n/i!=i) ls.push_back(n/i);
        }
    }
    sort(ls.begin(),ls.end()); //T.C: O(no. of factors*log(no. of factors))
    for (auto it: ls) cout<<it<<" "; //T.C: O(no. of factors)
    cout<<endl;

}
void prime(int n){
    int c=0;
    for(int i=1;i*i<=n;i++){
        if (n%i==0){
            c++;
            if (n/i!=i) c++;
        }
    }
    if (c==2) cout<<"Prime";
    else cout<<"Not Prime";
    cout<<endl;
}
//Sieve of eratosthenes(Algorithm to find prime numbers quickly)
int N=1000000;
bool sieve[1000000];
void sieveprime(){
    for (int i=2;i*i<=N;i++) sieve[i] = true;
    for (int i=2;i*i<=N;i++){
        if (sieve[i]==true) {
            for (int j=i*i;j<=N;j+=i) sieve[j]=false;
        }
    }
}
//Euclidean Algorithm
void hcf(int a,int b){
    cout<<"HCF: ";
    while(a>0 && b>0){
        if (a>b) a=a%b;
        else b=b%a;
    }
    if (a==0) cout<<b;
    else cout<<a;
    cout<<endl;
}
int main(){
    int n,a,b;
    cout<<"Enter a number: ";
    cin>>n;
    count_dig(n); //Time complexity = O(log10(n)), log comes whenever there is a divison in loop.
    reverse(n);
    palindrome(n);
    armstrong(n);
    divisor(n);
    prime(n);
    sieveprime();
    if (sieve[n]==true) cout<<"Prime";
    else cout<<"Not Prime";
    cout<<"Enter a and b: ";
    cin>>a>>b;
    hcf(a,b); //Time complexity = O(log@(min(a,b))) here @ is used because it is not constant, it can be a or b.
return 0;
}