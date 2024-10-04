#include <iostream>
#include <cmath>
using namespace std;
#define size 1200000


long long A[size];
int k;
int N;

int make_tree(){ // O(N)
    for(int i=pow(2,k-1); i<(pow(2,k-1)+N); i++){
        cin >> A[i];
    }
    int level=k-1;
    while(level!=0){ 
        for(int i=pow(2,level-1); i<pow(2,level); i++){
            A[i]=(A[2*i]+A[2*i+1]);
        }
        level-=1;
    }
    return 0;
}

int renew_tree(int i, long long v){
    i=pow(2,k-1)+i-1;
    A[i]=v;
    for(int j=k; j>0; j--){ // O(logN)
        i=floor(i/2);
        A[i]=A[2*i]+A[2*i+1];
    }
    return 0;
}

int add_tree(int s, int e){ // O(logN)
    long long sum=0;
    s=pow(2,k-1)+s-1;
    e=pow(2,k-1)+e-1;
    if(s>e){
        int temp;
        temp=s;
        s=e;
        e=s;
    }
    while(s!=e){ 
        if((s%2==0)&&(e%2!=0)){
        s=s/2;
        e=(e-1)/2;
        }
        else if((s%2==0)&&(e%2==0)){
            sum+=A[e];
            s=s/2;
            e=e/2-1;
        }
        else if((s%2!=0)&&(e%2!=0)){
            sum+=A[s];
            s=(s-1)/2+1;
            e=(e-1)/2;
        }
        else if((s%2!=0)&&(e%2==0)){
            if((e-s)==1){
                sum=sum+A[s]+A[e];
                break;
            }
            sum+=A[s];
            sum+=A[e];
            s=(s-1)/2+1;
            e=e/2-1;
        }
    }
    if(s==e){
        sum+=A[s];
    }
    cout << sum << '\n';
    return 0;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    int q;
    cin >> N >> Q;

     for(k=1; k<25; k++){ // O(25)
        if(pow(2,k)>=2*N){
            break;
        }
    }

    make_tree();
    for(long long i=0; i<Q; i++){
        cin >> q;
        if(q==1){
            int i;
            long long v;
            cin >> i >> v;
            renew_tree(i,v);
        }
        if(q==2){
            int s,e;
            cin >> s >> e;
            add_tree(s,e);
        }
    }

}