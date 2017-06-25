#include <iostream>

#include "quickSort.h"
#include "bubbleSort.h"

using namespace std;

int main()
{	int n, din;
	cin >> n;
	int a[n];
	cin >> din;
	agregar(a, n);
	quick_Sort(a, 0, n-1);
	capacidad(a, n, din);

	bubble_Sort();

	return 0;        
}