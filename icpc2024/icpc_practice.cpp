#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int left_sum, right_sum;

int count(int diff){
    int a1=diff/100;
    diff = diff-100*a1;
    int a2=diff/50;
    diff = diff-50*a2;
    int a3=diff/20;
    diff = diff-20*a3;
    int a4=diff/10;
    diff = diff-10*a4;
    int a5=diff/5;
    diff = diff-5*a5;
    int a6=diff/2;
    diff = diff-2*a6;
    int a7=diff;
    int sum=a1+a2+a3+a4+a5+a6+a7;
    cout << (sum);
    return 0;
}

int main(void){
    int m, diff, n, first, second;
    cin >> n;
    cin >> first >> second;
    left_sum=first;
    right_sum=second;

    for(int i=3; i<=n; i++){
        cin >> m;
        if(left_sum>right_sum){
            right_sum+=m;
        }
        else if(left_sum<=right_sum){
            left_sum+=m;
        }
    }
    if(left_sum==right_sum){
        cout << 0;
        return 0;
    }
    else{
        diff=abs(left_sum-right_sum);
        count(diff);
    }
}