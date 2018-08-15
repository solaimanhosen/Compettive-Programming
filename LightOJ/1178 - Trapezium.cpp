#include <iostream>
#include <iomanip>
#include <math.h>
 
 
using namespace std;
 
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    int t;
    double a, b, c, d;
    cin >> t;
    for (int testCase = 1; testCase <= t; testCase++){
        cin >> a >> b >> c >> d;
        if (c > a){
            swap(c, a);
        }
        double temp = (a - c);
        double x = (d*d - b*b + temp*temp) / (2 * temp);
        double h = sqrt(d*d - x*x);
        double area = (0.5*(a + c)*h);
        cout << "Case " << testCase << ": ";
        cout << fixed << setprecision(7) << area << endl;
    }
 
 
 
    return 0;
}