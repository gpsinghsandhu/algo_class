#include <iostream>
#include <conio.h>

int max_elem;

void unimodal_max(int A[],int n)
{
	if(n == 1)
		max_elem = A[0];
	else
	{
		if(A[n/2-1] > A[n/2])
			unimodal_max(A,n/2);
		else
			unimodal_max(&A[n/2],(n-n/2));
	}
}

void main()
{
	int arr[8] = {1,2,3,6,9,11,8,4};

	unimodal_max(arr,8);

	std::cout << "\nMax element :" << max_elem;
	_getch();
}