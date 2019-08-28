#include <iostream>
using namespace std;

int GCD(int n, int m){
    if(m<=n && (n%m==0))
        return m;
    else if(n < m)
        return GCD(m, n);
    else
        return GCD(m, n%m);
}
