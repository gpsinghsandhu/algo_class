#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>
#include <vector>

int n=200;

std::vector<std::vector<int>> adj_list(n+1);
std::vector<bool> X_st(n+1);
std::vector<int> A(n+1,1000000);
std::vector<int> X;

void Dijkstra_shortest_path(int s){
	int min,v,w,v_str,w_str,tmp,flag;
	A[s]=0;
	X.push_back(s);
	X_st[s]=true;
	for(int i=1;i<n;i++){
		min=INT_MAX;
		flag=0;
		for(int k=0;k<X.size();k++){
			v=X[k];
			for(int h=0;h<adj_list[v].size();h+=2){
				w=adj_list[v][h];
				if(X_st[w]==true)
					continue;
			tmp=A[v]+adj_list[v][h+1];
			if(min>tmp){
				flag=1;
				min=tmp;
				v_str=v;
				w_str=w;
			}
			}
		}
		if(flag==1){
		X.push_back(w_str);
		X_st[w_str]=true;
		A[w_str]=min;
		}
	}

}

int main(int argc,char **argv){
	std::ifstream gp_read("dijkstraData.txt",std::ios::in);
	FILE *gp1; 
	fopen_s(&gp1,"dijkstraData.txt","r");
	//gp1 = fopen("test3.txt","r");


	for(int i=0;i<n+1;i++){
		X_st[i]=false;
	}
	int v,w,le,a;
	while(1){
		a = fscanf_s(gp1,"%d,%d",&w,&le);
		if(a==1)
			v=w;
		else if(a<1)
			break;
		else{
			adj_list[v].push_back(w);
			adj_list[v].push_back(le);
		}
	}
	fclose(gp1);

	Dijkstra_shortest_path(1);
	std::cout<<A[7]<<"\n";
	std::cout<<A[37]<<"\n";
	std::cout<<A[59]<<"\n";
	std::cout<<A[82]<<"\n";
	std::cout<<A[99]<<"\n";
	std::cout<<A[115]<<"\n";
	std::cout<<A[133]<<"\n";
	std::cout<<A[165]<<"\n";
	std::cout<<A[188]<<"\n";
	std::cout<<A[197]<<"\n";
	//for(int i=1;i<n+1;i++)
		//std::cout<<A[i]<<"\n";

	_getch();
	return 0;
}
