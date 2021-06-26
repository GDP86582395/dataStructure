#include<iostream> 
#include<stdlib.h>

using namespace std;

/**
  * TODO ���ݽṹ��˳����ʵ�� 
  * @author �а��Ĵ����� 
  */

//Ĭ�ϳ�ʼ��С 
#define INITSIZE 5
//���� ˳���̬���� 
typedef struct{
	int *data;
	int length;
	int MaxSize;
}SqList;

//��ʼ��˳��� 
void InitList(SqList &L){
	L.data = (int *)malloc(sizeof(int)*INITSIZE);
	//��ʼ��Ϊ0����ʡ�� 
	for(int i=0;i<INITSIZE;i++){
		L.data[i] = 0;
	}
	L.MaxSize = INITSIZE;
	L.length = 0;
} 
//����˳����� 
void IncreaseSize(SqList &L, int len){
	int *p = L.data;
	L.data = (int *)malloc(sizeof(int)*(L.MaxSize + len));
	for(int i = 0; i < L.length; i++){
		L.data[i] = p[i];
	}
	L.MaxSize = L.MaxSize + len;
	free(p);
} 
//˳��������� ��˳���L��λ��Ϊi�ĵط� ����Ԫ��e  
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
//˳���ɾ������ 
bool ListDelete(SqList &L, int i, int &e){
	if(i < 1 || i > L.length)
		return false;
	e = L.data[i-1];
	for(int j = i - 1; j < L.length - 1; j++)
		L.data[j] = L.data[j+1];
	L.length--;
	return true;
} 
//˳���ֵ���Ҳ��� 
int LocateElem(SqList L, int e){
	for(int i=0; i < L.length; i++){
		if(L.data[i] == e){
			return i + 1;
		}
	}
	return 0;
}
//˳���λ���Ҳ���
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
	cout<<"��ǰ˳����ȣ�"<<L.length<<endl;
	int e;
	ListDelete(L, 4, e);
	cout<<"ɾ����Ԫ��eΪ��"<<e<<endl;
	cout<<"��ǰ˳����ȣ�"<<L.length<<endl;
	PrintList(L);
	cout<<"��ǰ˳�����󳤶ȣ�"<<L.MaxSize<<endl;
	IncreaseSize(L, 2);
	cout<<"��ǰ˳�����󳤶ȣ�"<<L.MaxSize<<endl;
	cout<<"����Ԫ��1��λ��"<<LocateElem(L, 1)<<endl;
	cout<<"����Ԫ��5��λ��"<<LocateElem(L, 5)<<endl;
	return 0;
}
  
  
  
  
  
  
  
  
  
  
  
  


