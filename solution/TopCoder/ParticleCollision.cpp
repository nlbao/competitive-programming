#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std ; 

const double pi=3.14159265358979323846;

class ParticleCollision {
    public:
    vector <double> collision(int vx, int vy, int vz, int x0, int y0, int z0) {
    vector <double> res;
    res.clear();
    cout << vz << endl;
    if (vz == 1) {
        if (z0 != 0) return res;
        if (z0 == 0) {
            for (int i=1; i <= 3; ++i) res.push_back(0);
            return res;
        }
    }
    cout << vz << endl;
    double t=z0/(1-vz), x=vx*t+x0, y=vy*t+y0;
    if ((cos(t*pi) == x) && (sin(t*pi) == y)) {
        res.push_back(x);   res.push_back(y);   res.push_back(t);
    }
    return res;    
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; double Arr6[] = { }; vector <double> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(0, Arg6, collision(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 4; int Arg2 = 1; int Arg3 = -1; int Arg4 = -1; int Arg5 = 0; double Arr6[] = {0.0, 1.0, 0.5 }; vector <double> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(1, Arg6, collision(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 2; int Arg3 = 5; int Arg4 = 4; int Arg5 = 0; double Arr6[] = {0.0, 0.0, 0.0 }; vector <double> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(2, Arg6, collision(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 1; int Arg3 = 1; int Arg4 = 0; int Arg5 = 0; double Arr6[] = {0.0, 0.0, 0.0 }; vector <double> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(3, Arg6, collision(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE

};
 
 // BEGIN CUT HERE 
    int main()
        {
        ParticleCollision ___test; 
        ___test.run_test(-1); 
       int X ;
       scanf("%d",&X) ;
        } 
    // END CUT HERE 
