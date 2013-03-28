#include <iostream>
#include <conio.h>

int no_comp = 0;

void compare(int B1[],int B2[],int B[],int n)
{
	int i=0;
	int j=0;
	no_comp++;
	if(B1[0] > B2[0])
	{
		for(int k=0; k<n; k++)
			B[k] = B1[k];
		B[n] = B2[0];
	}
	else
	{
		for(int k=0; k<n; k++)
			B[k] = B2[k];
		B[n] = B1[0];
	}

}

int sec_lar(int A[],int n,int B[])
{
	if(n == 2)
	{
		no_comp++;
		if(A[0] > A[1])
		{
			B[0] = A[0];
			B[1] = A[1];
		}
		else
		{
			B[0] = A[1];
			B[1] = A[0];
		}
		return 2;
	}

	else
	{
		int *B1 = (int*) malloc((int((log(float(n))/log(2.0)))+1)*sizeof(int));
		int *B2 = (int*) malloc((int((log(float(n))/log(2.0)))+1)*sizeof(int));
		int *C = (int*) malloc((n/2)*sizeof(int));
		int *D = (int*) malloc((n-n/2)*sizeof(int));

		for(int i=0; i<n/2; i++)
			C[i] = A[i];
		int j=0;
		for(int i=n/2; i<n; i++)
		{
			D[j] = A[i];
			j++;
		}

		int x = sec_lar(C,n/2,B1);
		int y = sec_lar(D,(n-n/2),B2);
		compare(B1,B2,B,x);
		delete B1,B2,C,D;
		return x+1;

	}
}

	void main(int argc,char *argv[])
	{
		int arr[32] = {4,2,3,1,8,5,6,10,9,14,7,15,16,12,11,18,19,22,21,23,25,27,24,26,28,29,31,17,30,13,20,32};
		//int arr[4] = {4,2,1,3};
		//int arr[8] = {7,6,4,3,8,2,1,5};
		int m = sizeof(arr)/sizeof(int);
		int *B = (int*) malloc((int((log(float(m))/log(2.0)))+1)*sizeof(int));

		int n = sec_lar(arr,m,B);
		int sec = B[1];
		for(int i=0;i<n;i++)
		{
			std::cout << "\nB[" << i << "] = " << B[i];
		}
		for(int i=2; i<n; i++)
		{
			no_comp++;
			if(B[i] > sec)
				sec = B[i];
		}
		std::cout << "\nsecond largest no." << sec;
		std::cout << "\nno of comparisons " << no_comp;
		delete B;
		_getch();
	}