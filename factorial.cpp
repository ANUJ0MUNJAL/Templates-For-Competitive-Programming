#include<bits/stdc++.h>
using namespace std;

const unsigned long long int md = 1000000007; 
const unsigned long long int co = 2000020;
unsigned long long int ft[co];
unsigned long long int fact(unsigned long long int n)
{   
    return ft[n];
}
void fct(){
    ft[0]=1;
    for(unsigned long long int i = 1;i<=2000020;i++){
        ft[i]=(i*ft[i-1]) % md;
    }
}
unsigned long long int pow(unsigned long long int x, unsigned long long int n, unsigned long long int mod){
    unsigned long long int result=1; 
    x = x % md;
    while(n>0){
        if(n%2 ==1){
            result = (result*x) % md;
        }
        n= n>>1;
        x= (x*x)% md;   
    }
    return result;
}