#include <iostream>
#include <cmath>
#include <set>
#define size 100000
using namespace std;

int N;
long long A[size+1];

void print_mascot(long long a, long long b){
    long long sum=0;
    set <long long> s;
    for(int i=a; i<=b; i++){
        /*int value=A[i];
        sum+=pow(-1,s.count(A[i]))*value;*/ // 값이 홀수개 있으면 -, 짝수개 있으면 +
        if(s.count(A[i])==0){
            s.insert(A[i]);
        }
        else{
            s.erase(A[i]);
        }
    }
    auto m=s.begin(); //시도2

    cout << *m << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q, t, a, b;

    cin >> N >> Q;
    for(int i=1; i<=N; i++){
        cin >> A[i];
    }

    for(int i=0; i<Q; i++){
        cin >> t >> a >> b;
        if(t==1){
            A[a]=b;
        }
        if(t==2){
            print_mascot(a,b);
        }
    }
    
    
  return 0;
}