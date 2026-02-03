#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    int id;
    long long int score; 
    string nickname;
};

void merge(vector<Student>& x, int l, int m, int r) {
    vector<Student> tmp;
    int i1 = l;
    int i2 = m;

    while (i1 < m || i2 < r) {
        bool pickLeft;

        if (i2 >= r) { //right side is exhausted, must pick from left
            pickLeft = true;
        } else if (i1 < m) {
            if (x[i1].score > x[i2].score) { //higher score comes first (non-increasing)
                pickLeft = true;
            } 
            else if (x[i1].score == x[i2].score && x[i1].id < x[i2].id) {
                pickLeft = true;  //if scores are equal, lower id comes first

            } else {
                pickLeft = false;
            }
        } else {
            pickLeft = false; //left side is exhausted, must pick from right
        }

        if (pickLeft) {
            tmp.push_back(x[i1]);
            i1++;
        } else {
            tmp.push_back(x[i2]);
            i2++;
        }
    }

    //copy temporary vector back to the original
    for (int i = 0; i < tmp.size(); i++) {
        x[l + i] = tmp[i];
    }
}

void merge_sort(vector<Student>& x, int l, int r) {
    if (r - l > 1) {
        int m = (l + r) / 2;
        merge_sort(x, l, m);
        merge_sort(x, m, r);
        merge(x, l, m, r);
    }
}

int main() {

    int N;
    if (!(cin >> N)) return 0;

    vector<Student> students(N);
    for (int i = 0; i < N; i++) {
        cin >> students[i].id >> students[i].score >> students[i].nickname;
    }

    merge_sort(students, 0, N);

    //nicknames of top 3
    for (int i = 0; i < 3; i++) {
        cout << students[i].nickname << "\n";
    }

    //all ids on one line space esepaarted 
    for (int i = 0; i < N; i++) {
        cout << students[i].id << (i == N - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}