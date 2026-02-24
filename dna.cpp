#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;
int N;
long long s0 =1, s1 = 0, s2 = 0;
long long t0, t1, t2;

int main(){

    cin >> N;

    for (int i=0; i<N; i++){
        t0 = 3*(s0+s1+s2);
        t1 = s0;
        t2 = s1;

        s0 = t0;
        s1 = t1;
        s2 = t2;
        }
    
    cout << (s0 + s1 + s2);


}