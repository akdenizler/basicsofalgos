#include <queue>
#include <iostream>
#include <functional>
#include <vector>
using namespace std;

int numPer;
int numTicketWin;

priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() { //meown 
    cin >> numPer >> numTicketWin;
    vector<int> secondsSpent(numPer+1);
    for (int i=1; i<numPer; i++) { cin >> secondsSpent[i];}

    for (int i = 0; i<numTicketWin; i++) { pq.push(0);}
    long long answer =0; 
    
    for (int i = 0; i < numPer; i++) {
        long long freeTime = pq.top();
        pq.pop();

        freeTime += secondsSpent[i];

        answer = max(answer, freeTime); 

        pq.push(freeTime);
}
    cout << answer;

}

