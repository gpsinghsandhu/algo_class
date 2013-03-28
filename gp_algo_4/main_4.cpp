#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>

int n=875714;
std::vector<std::vector<int>> adj_list(n+1),adj_list_r(n+1);
std::vector<int> temp_list;
std::vector<int> DFS_stk;
std::vector<int> SCC;
std::vector<int> magic_order;
int t=0;
int s=NULL;
std::vector<int> leader(n+1,0),ln(n+1,0),f(n+1,0);
//int *leader = new int[n+1];
//int *ln = new int[n+1];
//bool *avn = new bool[n+1];
//int *f = new int[n+1];
std::vector<bool> explored(n+1,false),explored_r(n+1,false);
//bool *explored = new bool[n+1];
//bool *explored_r = new bool[n+1];
struct read{
	int g[10];
}*pr;

void DFS(int i){
	int tmp,tmp1;
	bool flag;
	//explored[i] = true;
	//leader[i]=s;
	//temp_list.push_back(i);
	DFS_stk.push_back(i);
	while(!DFS_stk.empty()){
		tmp = DFS_stk.back();
		flag=false;		
		if(explored[tmp]==false){
			leader[tmp]=s;
			ln[s]++;
			explored[tmp]=true;
			for(int k=0;k<adj_list[tmp].size();k++){
				tmp1=adj_list[tmp][k];
				if(explored[tmp1]==false){	
					flag=true;
					//explored[tmp1]=true;
				DFS_stk.push_back(tmp1);
				}
			}
		}
		if(flag==false)
			DFS_stk.pop_back();
	}
}

void DFS_r(int i){
	bool flag=false;
	DFS_stk.clear();
	int tmp,tmp1;
	//explored_r[i] = true;
	//leader[i]= s;
	//temp_list.push_back(i);
	DFS_stk.push_back(i);
	while(!DFS_stk.empty()){
		tmp = DFS_stk.back();
		flag=false;
		if(explored_r[tmp]==false){
			explored_r[tmp]=true;
			for(int k=0;k<adj_list_r[tmp].size();k++){
				tmp1=adj_list_r[tmp][k];
				if(explored_r[tmp1]==false){
					//explored_r[tmp1]=true;
				flag=true;
				DFS_stk.push_back(tmp1);
				}
			}
		}
		if(flag==false){
		DFS_stk.pop_back();
		t++;
		f[tmp] = t;
		magic_order.push_back(tmp);
		}
	}
}

void DFS_Loop(void){
	int j;
	for(int i=magic_order.size()-1;i>-1;i--){
		j=magic_order[i];
		if(explored[j]==false){
			s=j;
			DFS(j);
		}
	}
}

void DFS_Loop_r(void){
	t=0;
	for(int i=n;i>0;i--){
		if(explored_r[i]==false)
			DFS_r(i);
	}
}


int main(int argc,char **argv){
	std::ifstream gp_read("SCC.txt",std::ios::in);
	int p_num = 0,num = 0,num1,min=0;
	//adj_list.resize(n+1);
	//adj_list_r.resize(n+1);
	//for(int i=0;i<=n;i++){
	//	explored[i]=false;
	//	explored_r[i]=false;
	//	ln[i]=0;
	//	//avn[i]=false;
	//	leader[i]=0;
	//	f[i]=0;
	//}
	std::cout<<"Started Reading...\n";
	while(!gp_read.eof()){
		gp_read>>num;
		gp_read>>num1;
		if(num==num1)
			continue;
		adj_list[num].push_back(num1);
		adj_list_r[num1].push_back(num);
	}
	std::cout<<"Reading Complete\nDFS_Lopp_r..\n";
	DFS_Loop_r();
	std::cout<<"DFS_Loop\n";
	DFS_Loop();
	//int o,count;

	std::cout<<"SCC:\n";
	for(int i=0;i<5;i++){
		int max=0;
		int max_id=0;
		for(int g=1;g<n+1;g++){
			if(ln[g]>max){
				max=ln[g];
				max_id=g;
			}
		}
		std::cout<<max<<"\n";
		ln[max_id]=-1;
	}
	_getch();
	return 0;
}



