#include <iostream>
#include <conio.h>

bool res = false;

void index_eq(int A[],int n,int index_st)
{
	if(n==1)
	{
		if(A[0] == index_st)
			res = true;
		else
			return;
	}

	else
	{
		if(A[n/2] > index_st+n/2)
		{
			index_eq(A,n/2,index_st);
		}
		else
		{
			index_eq(&A[n/2],n/2,index_st+n/2);
		}
	}
}

void main()
{
	int arr[4] = {0,2,3,4};
	index_eq(arr,4,0);
	std::cout << "Index Eq :" << res;
	_getch();
}