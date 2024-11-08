#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N,P,Q;
vector<long long> memo;

// f: 팩토리알 모듈러 메모이제이션
long long f(int n){

    if(memo[n]!=-1){
        return memo[n];
    }
    else if(memo[n]==-1){
        memo[n]= n>=2 ? (f(n-1)*(n%P))%P : 1;
        return memo[n];
    }
    return 0;
}
// 제곱 모듈러
long long moduler_sq(long long div, long long x){
    if(x==1){
        return div%P;
    }
    if(x%2 ==0){
        return (moduler_sq(div, x/2) * moduler_sq(div, x/2)) %P;
    }
    if(x%2!=0){
        return (((moduler_sq(div, (x-1)/2) * moduler_sq(div, (x-1)/2)) %P) *(div%P))%P;
    }
    return 0;
}

int main() {
    int a,b,c,d;

    cin >> N >> P >> Q;

    int n[Q+1];
    int m[Q+1];
    long long k[Q+1];

    memo.resize(N+1,-1);

    cin >> n[1] >> m[1] >> a >> b >> c >> d;

    long long result=0;
   
    for(long long i=1; i<=Q; i++){
        if(i!=1){
            n[i]=(a*n[i-1]+b) % N;
            m[i]=(c*m[i-1]+d)%N;
        }

        if(n[i]>m[i]){
            long long div=(f(n[i]-m[i]) * f(m[i])) %P;
            k[i]=(f(n[i]) * moduler_sq(div, P-2))%P;
        }
        else{
            long long div=(f(m[i]-n[i])%P * f(n[i])%P) %P;
            k[i]=(f(m[i]) * moduler_sq(div, P-2))%P;
            
        }
        result = result^(i*k[i]);
    }
    cout << result;
  return 0;
}