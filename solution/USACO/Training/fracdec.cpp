/*
    ID: storm59061
    LANG: C++
    TASK: fracdec
*/
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

ofstream out("fracdec.out");

int colcount=0;

int numBeforeRepeat(int n, int d) {
    int c2=0, c5=0;
    if (n == 0) return 1;
    while (d%2==0) { d/=2; c2++; }
    while (d%5==0) { d/=5; c5++; }
    while (n%2==0) { n/=2; c2--; } /* can go negative */
    while (n%5==0) { n/=5; c5--; } /* can go negative */
    if (c2>c5)
        if (c2>0) return c2;
        else return 0;
    else
        if (c5>0) return c5;
        else return 0;
}

void print (char c) {
    if (colcount==76) {
        out<<endl;
        colcount=0;
    }
    out<<c;
    colcount++;
}

void print (int n) {
    if (n>=10) print (n/10);
    print ((char)('0'+(n%10)));
}

int main() {
    int n, d;
    ifstream in("fracdec.in");
    in>>n>>d;
    in.close();

    print (n/d);
    print ('.');
    n=n%d;
    int m=numBeforeRepeat(n,d);
    for(int i=0;i<m;i++) {
        n*=10;
    print (n/d);
        n%=d;
    }
    int r=n;
    if(r!=0) {
    print ('(');
        do {
            n*=10;
        print (n/d);
            n%=d;
        } while (n!=r);
    print (')');
    }
    out<<endl;
    out.close();
    return 0;
}
