#include <cstdio>
#include <iostream>
#include <ostream>
#include <queue>
#include <vector>
using namespace std;

bool sortareTopologicaBFS(vector<vector<int> > D, vector<int> &L) {
    queue<int> q;
    vector<int> np(D.size(), 0);
    for (int u = 0; u < D.size(); u++)
        for (int v: D[u])
            np[v]++;

    for (int u = 0; u < D.size(); u++)
        if (np[u] == 0)
            q.push(u);

    for (int k = 0; k < D.size(); k++) {
        if (q.empty())
            return false;

        int u = q.front();
        q.pop();

        L.push_back(u);

        for (int v: D[u]) {
            np[v]--;
            if (np[v] == 0)
                q.push(v);
        }
    }
    return true;
}
int main() {

    vector<vector<int>> D = {
        {1, 3},
        {3},
        {},
        {2}
    };

    vector<int> L;
    if (sortareTopologicaBFS(D, L)) {
        for (int x:L)
            cout<<x<<endl;
    }
    else {
        perror("Error");
    }
}