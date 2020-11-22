#include <iostream>
using namespace std;
 const int MAXSIZE = 10;
 int fnBinomialCoefficient(int n, int k);
int main(void)
 {
 int n, k, iRes;
 cout << "Binomial Coefficients\n";
 cout << "Calculates the value of nCk\n";
cout << "Enter the value of n : ";
 cin >> n;
 cout << "Enter the value of k : ";
 cin >> k;
 if (n<k)
 cout << "\nInvalid Input n should be larger than k!\n";
 else
 {
 iRes = fnBinomialCoefficient(n, k);
 cout << "\nThe value of " << n << "C" << k << " is " << iRes << endl;
 }
 return 0;
 }
 /******************************************************************************
36 *Function: fnBinomialCoefficient
37 *Description: Function to find Binomial Coefficient
38 *Input parameters:
39 * int n - no of elements
40 * int k - no of elements chosen out of n elements
41 *RETURNS: value of nCk
42 ******************************************************************************/
 int fnBinomialCoefficient(int n, int k)
 {
 int c[MAXSIZE][MAXSIZE];
 int i,j;
 for (i=0; i<=n; i++)
 {
 for (j=0; j<=i; j++)
 {
 if(j==0 || i==j)
 {
 c[i][j]=1;
}

else
 {
 c[i][j] = c[i-1][j-1] + c[i-1][j];
 }
 }
 }
 cout << "\nThe Binomial matrix is :" << endl << "\t";
 for (i=0; i<=n; i++)
 cout << i << "\t";
 cout << endl;
 for (i=0; i<=n+1; i++)
 cout<<"========";
 cout << endl;
 for (i=0; i<=n; i++)
 {
 cout << "i=" << i << "\t";
 for (j=0; j<=i; j++)
 {
 cout << c[i][j] << "\t";
 }
 cout << endl;
 }
 cout << endl;
 return c[n][k];
 }
