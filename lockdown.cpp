/*
given:
- number of cities (allover the world) 
- list of still opened roads connecting these cities

roads are bidirectional

calculate number of cities that are visitable

input 3 numbers in first line
- number of cities
- number of roads
- id of home city of current traveller (userCity)

second line input :
- Vi, Ui idCity, iRoad


*/
#include <bits/stdc++.h>

using namespace std;
int Ui;
int Vi;
int numCities;
int numOpenRoads;
int currentCity;

int bfs(vector<vector<int>> &graph, int start) {
    int N = graph.size(); //i did NOT write this BFS btw just being honest wit u 

    vector<bool> visited(N, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    int count = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : graph[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                count++;
            }
        }
    }

    return count;
}

int main(){

    cin >> numCities >> numOpenRoads >> currentCity;
    vector<vector<int>> graph(numCities +1);
    for (int i =0;i<numOpenRoads; i++){ 
        cin >> Vi >> Ui;
        graph[Ui].push_back(Vi);
        graph[Vi].push_back(Ui);
        }

        cout << bfs(graph, currentCity); 

    
}


