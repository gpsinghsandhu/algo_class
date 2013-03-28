//#include <iostream>
//#include <fstream>
//#include <conio.h>
//#include <vector>
//#include <algorithm>
//
//int n=100000;
//std::vector<int> int_arr;
//int main(int argc,char** argv)
//{
//	std::ifstream gp_read("HashInt.txt",std::ios::in);
//	int num,num1;
//	int count=0;
//	while(!gp_read.eof())
//	{
//		gp_read>>num;
//		if(num<4000)
//		{
//			count++;
//			int_arr.push_back(num);
//		}
//	}
//
//	std::sort(int_arr.begin(),int_arr.end());
//	count=0;
//	for(int j=2500;j<4001;j++)
//	{
//	for(int i=0;i<int_arr.size();i++)
//	{
//		num=int_arr[i];
//		num1=j-num;
//		if(num==num1 || num>j)
//			continue;
//		if(std::binary_search(int_arr.begin(),int_arr.end(),num1)==1)
//		{
//			count++;
//			break;
//		}
//
//	}
//	}
//	std::cout<<"Count:"<<count;
//	getch();
//}