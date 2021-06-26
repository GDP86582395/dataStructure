#include<iostream> 
#include<stdlib.h>

using namespace std;

/**
  * TODO 数据结构，顺序表的实现 
  * @author 有爱的大鹏叔 
  */

//默认初始大小 
#define INITSIZE 5
//定义 顺序表动态分配 
typedef struct{
	int *data;
	int length;
	int MaxSize;
}SqList;

//初始化顺序表 
void InitList(SqList &L){
	L.data = (int *)malloc(sizeof(int)*INITSIZE);
	//初始化为0，可省略 
	for(int i=0;i<INITSIZE;i++){
		L.data[i] = 0;
	}
	L.MaxSize = INITSIZE;
	L.length = 0;
} 
//增加顺序表长度 
void IncreaseSize(SqList &L, int len){
	int *p = L.data;
	L.data = (int *)malloc(sizeof(int)*(L.MaxSize + len));
	for(int i = 0; i < L.length; i++){
		L.data[i] = p[i];
	}
	L.MaxSize = L.MaxSize + len;
	free(p);
} 
//顺序表插入操作 在顺序表L的位序为i的地方 插入元素e  
bool ListInsert(SqList &L, int i, int e){
	if(i < 1 || i > L.length + 1)
		return false;
	if(L.length + 1 > L.MaxSize)
		return false;
	for(int j = L.length; j >= i; j--)
		L.data[j] = L.data[j-1];
	L.data[i-1] = e;
	L.length++;
	return true;
		
}
//顺序表删除操作 
bool ListDelete(SqList &L, int i, int &e){
	if(i < 1 || i > L.length)
		return false;
	e = L.data[i-1];
	for(int j = i - 1; j < L.length - 1; j++)
		L.data[j] = L.data[j+1];
	L.length--;
	return true;
} 
//顺序表按值查找操作 
int LocateElem(SqList L, int e){
	for(int i=0; i < L.length; i++){
		if(L.data[i] == e){
			return i + 1;
		}
	}
	return 0;
}
//顺序表按位查找操作
int GetElem(SqList L, int i){
	if(i < 1 || i > L.length)
		return 0;
	return L.data[i-1];
} 
void PrintList(SqList L){
	for(int i = 0; i < L.length; i++)
		cout<<L.data[i]<<" ";
	cout<<endl;
}

int main(){
	SqList L;
	InitList(L);
	ListInsert(L, 1, 2);
	ListInsert(L, 2, 4);
	ListInsert(L, 6, 1);
	PrintList(L);
	ListInsert(L, 2, 5);
	ListInsert(L, 1, 1);
	PrintList(L);
	cout<<"当前顺序表长度："<<L.length<<endl;
	int e;
	ListDelete(L, 4, e);
	cout<<"删除的元素e为："<<e<<endl;
	cout<<"当前顺序表长度："<<L.length<<endl;
	PrintList(L);
	cout<<"当前顺序表最大长度："<<L.MaxSize<<endl;
	IncreaseSize(L, 2);
	cout<<"当前顺序表最大长度："<<L.MaxSize<<endl;
	cout<<"查找元素1的位置"<<LocateElem(L, 1)<<endl;
	cout<<"查找元素5的位置"<<LocateElem(L, 5)<<endl;
	return 0;
}
  
  
  
  
  
  
  
  
  
  
  
  


