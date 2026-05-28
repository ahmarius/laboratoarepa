#include <iostream>
using namespace std;
void printSub(int *x, int n) {
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}
void submultimiOpt(int s, int k, int r, int M, int n, int w[], int x[]) {
    if (r<=0)
        return;
    x[k]=1;
    if (s+w[k]==M)
        printSub(x, n);
    else if (s+w[k]+w[k+1] <=M)
        submultimiOpt(s+w[k], k+1, r-w[k], M, n, w, x);
    if (s+r-w[k]>=M && s+w[k+1]<=M) {
        x[k]=0;
        submultimiOpt(s,k+1,r-w[k],M,n,w,x);
    }

}
int main() {
    int n =5;
    int M = 10;
    int w[5]= {1,2,3,4,5};
    int x[5]={0};
    submultimiOpt(0,0,15,M,n,w,x);
    return 0;
}