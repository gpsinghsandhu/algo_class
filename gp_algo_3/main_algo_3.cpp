#include <iostream>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <string>
#include <sstream>
#include <Windows.h>
int count = 4;
int no_edges = 5;

struct vertices{
	int v;
	//int inc;
	//vertices *v1,*v2;
};

struct edges{
	int V1,V2;
	//vertices vertex1,vertex2;
};

void delete_ed(edges *e,int i){
	for(int j=i;j<(no_edges-1);j++){
		e[j].V1 = e[j+1].V1;
		e[j].V2 = e[j+1].V2;
		//e[j].vertex1 = e[j+1].vertex1;
		//e[j].vertex2 = e[j+1].vertex2;
	}
}

int min_cut(edges e[],int avn){//,int vert[],vertices *V[]){
	int index = 0;
	
	int del_count=0;
	while(avn>2){
		del_count=0;
		int del[2000];
		index = (rand())%no_edges;
		edges selected = e[index];
		vertices new_v;
		new_v.v = ++count;
		int v_1 = e[index].V1;
		int v_2 = e[index].V2;
		//*new_v.v1 = e[index].vertex1;
		//*new_v.v2 = e[index].vertex2;
		avn--;
		//vert[avn] = ++count;
		for(int i=0;i<no_edges;i++){
			if((e[i].V1==v_1 && e[i].V2==v_2) || (e[i].V1==v_2 && e[i].V2==v_1) ){
				del[del_count]=i;
				del_count++;
			}
			else{
			if(e[i].V1==v_1 || e[i].V1==v_2){
				e[i].V1 = new_v.v;
				//e[i].vertex1 = new_v;
			}
			if(e[i].V2==v_1 || e[i].V2==v_2){
				e[i].V2 = new_v.v;
				//e[i].vertex2 = new_v;
			}
			if(e[i].V1==e[i].V2){
				del[del_count]=i;
				del_count++;}
			}
		}
		for(int j=del_count-1;j>=0;j--){
			delete_ed(e,del[j]);
			del[j]=INT_MAX;
		
		}
		no_edges-=del_count;
			if(no_edges<(avn))
			int a=0;
		if(no_edges <3)
			int a=0;
	}

	return no_edges;
}

int main(){
	
	int min = INT_MAX;
	no_edges = 0;
	int max_edges;
	int v=0;
	int V[] = {1,2,3};
	edges e[7800],er[7800];
	int avn = 200;
	std::ifstream gp_read("kargerMinCut.txt",std::ios::in);

	int first_elem;
	int num;
	char ch;
	int flag = 1;
	std::string line;
	while(std::getline(gp_read,line)){
		std::istringstream iss(line);
		v++;
		iss>>num;
		while(iss >> num){
                  if(num>v){
			e[no_edges].V1 = v;
			e[no_edges].V2 = num;
			no_edges++;
        }
		}
	}
	avn = v;
	max_edges = no_edges;
	//srand(clock());
	srand(clock()+GetTickCount());
	for(int i=0;i<100;i++){
	count = v;	
	//read file
	
	no_edges = max_edges;
	for(int j=0;j<no_edges;j++){
	
		er[j].V1 = e[j].V1;
		er[j].V2 = e[j].V2;
	}
	int cross = min_cut(er,avn);
	if(cross==0)
		int a=1;
	if(cross<min)
		min = cross;
	std::cout << cross << "\t";
	/*for(int i=0;i<no_edges;i++){
		std::cout<<e[i].V1<<" "<<e[i].V2<<"\n";
	}*/
	}
	std::cout <<"\n"<< min;
	_getch();
	return 0;
}


				
