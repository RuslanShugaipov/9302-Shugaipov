#include "LinkedList.h"
#include <iostream>

using namespace std;

int main()
{
	LinkedList a,b;
	for (int i = -1; i <= 20; i++)
		a.push_back(i);
	for (int i = -3; i <= 20; i++)
		b.push_back(i);
	a.print_to_console();
	cout << endl;
	b.print_to_console();
	cout << endl;
	cout << "The number of the first occurrence of one list in another: " << a.find_first(b, a) << "\n\n";
	a.set(5, 78);
	cout << endl;
	a.print_to_console();
	a.clear();
	b.clear();
	return 0;
}