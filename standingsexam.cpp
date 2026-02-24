/*Now you are asked to generate standings table

Your problem should generate standings table
according to the information from logs.

Each line should contain:
- student login 
- number of problems solved by this student.

Students should:
- be sorted in descending order of the number of solved problems

If two students have the same number of solveed problems, 
- Print alphabetically

*/


#include <bits/stdc++.h>
using namespace std;

struct student {
    string login;
    int solved;
};

int nLines; //n lines in log file

bool compare(const student&a, const student &b) {
    if (a.solved != b.solved)
        return a.solved > b.solved;
    return a.login < b.login;
}

int main(){

    cin >> nLines;
    vector<student> meow(nLines);

    unordered_map<string, int> solved;

    for (int i = 0; i < nLines; i++) {
        string name;
        cin >> name;
        solved[name]++;}

    for (auto &p:solved) {
        student s;
        s.login = p.first;
        s.solved = p.second;
        meow.push_back(s);
    }
    sort(meow.begin(), meow.end(), compare);

    for (auto &s : meow) {
        cout << s.login << s.solved << "\n";
    }
}
