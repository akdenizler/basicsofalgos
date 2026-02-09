#include <iostream>
#include <queue>
using namespace std;
deque<int> L;
deque<int> R;


void rebalance(deque<int>& L, deque<int>& R) {
    if (L.size() > R.size() + 1) {
        R.push_front(L.back());
        L.pop_back();
    }
    else if (R.size() > L.size()) {
        L.push_back(R.front());
        R.pop_front();
    }
}

int main(){

     int N;
    cin >> N;  //number of stores

    char type;
    while (cin >> type) {  //read event type
        if (type == '#') {
            break; //end of input due to end of worknig day 
        }

        int store;
        cin >> store;//store number

        if (type == '+' || type == '!') {
            int id;
            cin >> id;               
            if (type == '+') {
                L.push_back(id);
                rebalance(L,R);
            }
            else if (type == '!') {
                R.push_back(id);
                rebalance(L,R);
            }
        }
        else if (type == '-') {
            int frontcus = R.front();
            R.pop_front();
            cout << frontcus << '\n';
            rebalance(L,R);
        }

        else if (type == '?') {
            cout << R.size() + L.size() << '\n';
}
    }