#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
#include <conio.h>

int main(int argc,char** argv)
{
	std::priority_queue<int> left_heap;
	std::greater<int> min_heap_comp;
	std::priority_queue<int,std::vector<int>,std::greater<int>> right_heap;

	std::ifstream gp_read("Median.txt",std::ios::in);

	int n=10000,num,sum_m=0,arr_size=0;
	for(int i=0;i<n;i++)
	{
		gp_read>>num;
		
		if(left_heap.empty())
		{
			arr_size++;
			left_heap.push(num);
		}
		else
		{
			arr_size++;
			if(arr_size%2==0)
				if(num<left_heap.top())
				{
					left_heap.push(num);
					right_heap.push(left_heap.top());
					left_heap.pop();
				}
				else
					right_heap.push(num);
			else
			{
				if(num<left_heap.top())
				{
					left_heap.push(num);
				}
				else
				{
					right_heap.push(num);
					left_heap.push(right_heap.top());
					right_heap.pop();
				}
			}
		}
		//std::cout<<"\n"<<left_heap.top();
		sum_m+=left_heap.top();
	}
	if(sum_m>1000000000)
		std::cout<<"warning";
	std::cout<<"\nans: "<<sum_m%10000;
	getch();
	return 0;
}