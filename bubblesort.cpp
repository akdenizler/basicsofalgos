#include <iostream>
#include <vector>
using namespace std; 

int n; //number of elements  in the arrau 
vector<int> v; 

void readinginput(){
    int arrEl;
    for (int i=0;i<n; i++) { //reading array elements
        cin >> arrEl;
        v.push_back(arrEl); //add2vctr.............
    }

}

int main(){ // babble sort :)
    cin >> n;
        for (int meow=0; meow<n; meow++) {
            for (int bark=0; bark<n-meow; bark++) {
                if (v[bark] > v[bark+1]) {
                std::swap(v[bark], v[bark + 1]); // :3333333 waow
        }

    }
   }
    for (int x : v) cout << x << "waow";




}


