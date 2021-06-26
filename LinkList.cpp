#include<iostream>
#include<stdlib.h> 
using namespace std;


/**
  * TODO ���ݽṹ���������ʵ�� 
  * @author �а��Ĵ����� 
  */

//���嵥���� 
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode, *LinkList;
//��ʼ��������
bool InitList(LinkList &L){
	L = (LNode *)malloc(sizeof(LNode));
	if(L == NULL)
		return false;
	L->next = NULL;
	return true;
} 
//��ͷ�巨����������
LinkList List_HeadInsert(LinkList &L){
	int x;
	cin>>x;
	while(x != -1){
		LNode *s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		cin>>x;
	} 
	return L;
} 
//��λ����
int GetElem(LinkList L, int i){
	LNode *s = L;
	int j = 0;
	while(s != NULL && j < i){
		s = s->next;
		j++;
	}
	if(s == NULL)
		return 0;
	return s->data;
} 
//��ֵ����
int LocateElem(LinkList L, int e){
	LNode *s = L->next;
	int j = 1;
	while(s != NULL){
		if(s->data == e)
			return j;
		s = s->next;
		j++;
	}
	return 0;
} 
//������� 
bool ListInsert(LinkList &L, int i, int e){
	if(L == NULL)
		return false;
	LNode *s = L;
	int j = 0;
	while(s != NULL && j < i - 1){
		s = s->next;
		j++;
	}
	if(s == NULL)
		return false;
	LNode *p = (LNode *)malloc(sizeof(LNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
	return true;
}
//ɾ������
bool ListDelete(LinkList &L, int i, int &e){
	if(L == NULL)
		return false;
	LNode *s = L->next;
	int j = 1;
	while(s != NULL && j < i - 1){
		s = s->next;
		j++;
	}
	if(s == NULL)
		return false;
	LNode *p = s->next;
	s->next = p->next;
	e = p->data;
	free(p);
	return true;
} 
//������ 
int ListLength(LinkList L){
	int j = 0;
	if(L == NULL)
		return 0;
	LNode *s = L->next;
	while(s != NULL){
		s = s->next;
		j++;
	}
	return j;	
}
void PrintList(LinkList L){
	LNode *s = L->next;
	while(s != NULL){
		cout<<s->data<<" ";
		s = s->next;
	}
	cout<<endl;
}
int main(){
	LinkList L;
	InitList(L);
	ListInsert(L, 1, 2);
	ListInsert(L, 2, 4);
	ListInsert(L, 6, 1);
	PrintList(L);
	ListInsert(L, 2, 5);
	ListInsert(L, 1, 1);
	PrintList(L);
	cout<<"��ǰ˳����ȣ�"<<ListLength(L)<<endl;
	int e;
	ListDelete(L, 4, e);
	cout<<"ɾ����Ԫ��eΪ��"<<e<<endl;
	cout<<"��ǰ˳����ȣ�"<<ListLength(L)<<endl;
	PrintList(L);
	cout<<"����Ԫ��1��λ��"<<LocateElem(L, 1)<<endl;
	cout<<"����Ԫ��5��λ��"<<LocateElem(L, 5)<<endl;
	List_HeadInsert(L);
	PrintList(L);
	return 0;
}






















