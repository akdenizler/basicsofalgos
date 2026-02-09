#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> scores(numSt); 
int numSt;
int numReq;
int lj; //left bound
int rj; //right bound 

int main(){
    cin >> numSt >> numReq; //number of students, number of requests

    for (int i=0; i<numSt; i++) {
        cin >> scores[i];
    }
    sort(scores.begin(), scores.end());

    
    for (int meow=0; meow<numReq; meow++) {
        cin >> lj >> rj;
        auto L = lower_bound(scores.begin(), scores.end(),lj);
        auto R = upper_bound(scores.begin(), scores.end(), rj);
        cout << (R - L) << "\n";

    }
    }
}