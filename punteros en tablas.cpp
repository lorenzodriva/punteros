#include <iostream>
using namespace std;
int main()
{
 int T[3] = {1,2,3};
 int *p;
 p = &T[0]; // p apunta al primer elemento de la tabla T

 p = T; // p = &T[0]
 cout << *p << endl;

 *(p+1); // el segundo elemento despues de donde apunta p
 cout << *(p+1) << endl;

 p[0]; //a donde apunta p
 cout << p[0] << endl;

 p[1]; // *(p+1)
 cout << p[1] << endl;

 return 0;
}
