#include <iostream>
#include <stack>
#define size 1000000

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    stack<long long> st;
    long long pair_num[size]={0};

    cin >> N;

    for(long long i=0; i<N; i++){
        long long v;
        cin >> v;

        if(st.empty()){
            st.push(v);
        }
        else{
            if(v>=st.top()){
                long long j=i-1;
                while(v>=st.top()){
                    pair_num[i]+=pair_num[j];
                    pair_num[i]+=1;
                    st.pop();
                    j-=(1+pair_num[j]);
                    if(st.empty()){
                        break;
                    }
                }
                st.push(v);
            }
            
            else if(v<st.top()){
                pair_num[i]=0;
                st.push(v);
            }
        }
        
    }
    
    long long sum=0;
    for(long long i=0; i<N; i++){
        sum+=pair_num[i];
    }
    cout << sum << '\n';

    return 0;
}