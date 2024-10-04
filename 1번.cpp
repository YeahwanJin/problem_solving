#include <iostream>
#include <cmath>
using namespace std;
#define size 1000000


long long A[size];
int k;
long long N;

int make_tree(){ // O(N)
    for(long long i=pow(2,k-1); i<(pow(2,k-1)+N); i++){ 
        cin >> A[i];
    }
    int level=k-1;
    while(level!=0){ 
        for(long long i=pow(2,level-1); i<pow(2,level); i++){
            A[i]=(A[2*i]+A[2*i+1]);
        }
        level-=1;
    }
    return 0;
}

int renew_tree(long long i, long long v){
    i=pow(2,k-1)+i-1;
    A[i]=v;
    for(int j=k; j>0; j--){ // O(logN)
        i=floor(i/2);
        A[i]=A[2*i]+A[2*i+1];
    }
    return 0;
}

int add_tree(long long s, long long e){
    long long sum=0;
    s=pow(2,k-1)+s-1;
    e=pow(2,k-1)+e-1;
    if(s>e){
        long long temp;
        temp=s;
        s=e;
        e=s;
    }
    while(s!=e){ // O(logN)
        if((s%2==0)&&(e%2!=0)){
        s=floor(s/2);
        e=floor(e/2);
        }
        else if((s%2==0)&&(e%2==0)){
            sum+=A[e];
            s=floor(s/2);
            e=floor(e/2)-1;
        }
        else if((s%2!=0)&&(e%2!=0)){
            sum+=A[s];
            s=floor(s/2)+1;
            e=floor(e/2);
        }
        else if((s%2!=0)&&(e%2==0)){
            sum+=A[s];
            sum+=A[e];
            s=floor(s/2)+1;
            e=floor(e/2)-1;
        }
    }
    sum+=A[s];
    cout << sum << '\n';
    return 0;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x,y,Q;
    int q;
    cin >> N >> Q;

     for(k=1; k<25; k++){ // O(25)
        if(pow(2,k)>=2*N){
            break;
        }
    }

    make_tree();
    for(long long i=0; i<Q; i++){
        cin >> q >> x >> y;
        if(q==1){
            renew_tree(x,y);
        }
        if(q==2){
            add_tree(x,y);
        }
    }

}