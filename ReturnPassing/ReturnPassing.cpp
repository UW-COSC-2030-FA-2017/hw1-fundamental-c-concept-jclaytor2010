/* Jacob Claytor
 * COSC 2030
 * September 10, 2017
 */


#include <iostream>
using namespace std;

int passByValue(int x);
int passByReference(int &x);
int passByConstReference(int const &x);

int main()
{
	int x = 1;
	cout << "Value of x has been initialized to " << x << endl << endl;
	passByValue(x);
	cout << "After calling passByValue(), initial value of x remains " << x << endl << endl;
	passByReference(x);
	cout << "After calling passByReference(), the initial value of x has been changed to " << x << endl << endl;
	passByConstReference(x);
	cout << "After calling passByConstReference(), the initial value of x remains " << x << endl;
}

int passByValue(int x)
{
	cout << "The initial value of x is " << x << endl;
	x = x + 1;
	cout << "passByValue() has changed x to " << x << endl;
	return 0;
}
int passByReference(int &x)
{
	cout << "The initial value of x is " << x << endl;
	x = x + 1;
	cout << "passByReference() has changed x to " << x << endl;
	return 0;
}
int passByConstReference(int const &x)
{
	cout << "The initial value of x is " << x << endl;
	int y = x;
	y = x + 1;
	cout << "passByConstReference() has changed x to " << y << endl;
	return 0;
}


