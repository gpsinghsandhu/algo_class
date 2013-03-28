#include <iostream>
#include <conio.h>
#include <fstream>
#include <memory.h>
#include <stdlib.h>


unsigned int count_split_inv(unsigned int D[],unsigned int n,unsigned int B[], unsigned int C[])
{
	unsigned int i=0;
	unsigned int j=0;
	unsigned int n_inv=0;
	unsigned int n_B = n/2;
	unsigned int n_C = n-n/2;
	for(unsigned int k=0;k<n;k++)
	{
		if(i >= n_B)
		{
			D[k] = C[j];
			j++;
		}
		else if(j >= n_C)
		{
			D[k] = B[i];
			i++;
		}
		
		else if(B[i] < C[j])
		{
			D[k] = B[i];
			i++;
		}
		else if(C[j] < B[i])
		{
			D[k] = C[j];
			j++;
			n_inv += n_B-i;
		}
	}
	return n_inv;
}


unsigned int count(unsigned int a[],unsigned int n,unsigned int* D = NULL)
{
	unsigned int x,y,z;

	if(D == NULL)
	{
		D = (unsigned int*) malloc(n*sizeof(unsigned int));
	}


	if(n == 1)
		return 0;
	else
	{
		unsigned int *A;
		A = (unsigned int*) malloc(n*sizeof(unsigned int));
		for(unsigned int i=0;i<n;i++)
			A[i] = a[i];
	
		unsigned int *B = (unsigned int*) malloc((n/2)*sizeof(unsigned int));
		for(unsigned int i=0;i<n/2;i++)
			B[i] = a[i];
		unsigned int *C = (unsigned int*) malloc((n-n/2)*sizeof(unsigned int));
		unsigned int j=0;
		for(unsigned int i=n/2;i<n;i++)
		{
			C[j] = a[i];
			j++;
		}
	
	
		x = count(A,n/2,B);
		y = count(&A[(n/2)],(n-n/2),C);
		z = count_split_inv(D,n,B,C);
		delete A,B,C;
		return (x+y+z);
	}
}

void main()
{
	unsigned int no = 0;
	std::ifstream gp_read;
	gp_read.open("IntegerArray.txt",std::ios::in);
	if(!gp_read)
	{
		exit(0);
	}
	unsigned int num = 100000;
	unsigned int *arr = (unsigned int*) malloc(num*sizeof(unsigned int));
	unsigned int elem;
	unsigned int m=0;
	while(gp_read >> elem)
	{
		arr[m] = elem;
		m++;
	}

	no = count(arr,num);
	std::cout << no;
	delete arr;
	_getch();
}
