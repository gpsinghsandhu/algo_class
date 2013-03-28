#include <iostream>
#include <conio.h>
#include <fstream>

unsigned int comp = 0;

int Partion_around_pivot(unsigned int B[],int left, int right)
{


	int pivot;
	//std::cout << "\n";
	//pivot = B[left];

	//pivot = B[right];
	//B[right] =  B[left];
	//B[left] = pivot;


	//for(int i=left;i<=right;i++)
	//{
	//	std::cout << " " << B[i];
	//}

	int mid = (left + right)/2;
	if(right - left +1 <=2)
	{
		pivot = B[left];
	}
	else if(B[mid] < B[right] && B[mid] >B[left] ||B[mid] > B[right] && B[mid] <B[left])
	{
		pivot = B[mid];
		B[mid] = B[left];
		B[left] = pivot;
	}
	else if(B[left] < B[right] && B[left] >B[mid] || B[left] > B[right] && B[left] <B[mid])
	{
		pivot = B[left];
	}
	else
	{
		pivot = B[right];
		B[right] =  B[left];
		B[left] = pivot;
	}



	//std::cout << "\n" << pivot;
	int i = left+1;
	unsigned int temp;
	int n;

	for(int j=left+1;j<=right;j++)
	{
		if(B[j]<pivot)
		{
			temp = B[j];
			B[j] = B[i];
			B[i] = temp;
			i++;
		}
	}

	temp = B[left];
	B[left] = B[i-1];
	B[i-1] = temp;
	return (i-1);
}

void Quicksort(unsigned int A[],int n)
{
	if(n <= 1)
	{
		return;
	}
	int part;

	part = Partion_around_pivot(A,0,n-1);
	if(part>0 )
		comp += part-1;
	Quicksort(&A[0],part);
	if( n-part-1 >0)
		comp += n-part-2;
	Quicksort(&A[part+1],n-part-1);
}

void main()
{
	std::ifstream gp_read;
	gp_read.open("QuickSort.txt",std::ios::in);
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
	comp += m-1;
	Quicksort(arr,m);
	//for(int i=0; i<m; i++)
		//std::cout << "\n" <<arr[i];

	std::cout << "\nCOMPARISONS :" << comp;
	_getch();
}



