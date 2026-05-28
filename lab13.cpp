#include <iostream>
#include <vector>
using namespace std;
#define plusInf 1000000

bool floydWarshall(vector<vector<int> > L, vector<vector<int> > &P) {
    int n = L.size();
    P.assign(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && L[i][j] != plusInf)
                P[i][j] = i;
            else
                P[i][j] = -1;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (L[i][k] == plusInf || L[k][j] == plusInf)
                    continue;
                int temp = L[i][k] + L[k][j];
                if (temp < L[i][j]) {
                    L[i][j] = temp;
                    P[i][j] = P[k][j];
                }
            }
        }

        for (int i = 0; i < n; i++)
            if (L[i][i] < 0)
                return false;
    }

    return true;
}

int main() {
    vector<vector<int> > L = {
        {0, 4, 1,plusInf},
        {plusInf, 0,plusInf, 1},
        {plusInf, 2, 0, 5},
        {plusInf,plusInf, plusInf, 0}
    };
    vector<vector<int> > P;
    if (!floydWarshall(L, P)) {
        cout << "Ciclu negativ";
        return 1;
    }
    int i = 0;
    int j  = 3;
    if (P[i][j] == -1) {
        cout<<"Nu exista";
    }
    vector<int> drum;
    for (int v=  j; v!=i;v=P[i][v])
        drum.push_back(v);
    drum.push_back(i);
    for (int k = drum.size()-1; k>=0; k--) {
        cout << drum[k]<<",";
    }
        return 0;
}
