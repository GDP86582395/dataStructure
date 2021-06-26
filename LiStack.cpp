#include<iostream>
#include<stdlib.h>
using namespace std;


/**
  * TODO ���ݽṹ����ջ��ʵ�֣�����ͷ��㣩 
  * @author �а��Ĵ����� 
  */
  
//��ջ�Ķ��� 
typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}*LiStack;
//��ջ�ĳ�ʼ��
LiStack InitStack(LiStack &S){
	S = NULL;
	return S;
} 
//��ջ 
bool Push(LiStack &S, int e){
	LiStack p = (LiStack)malloc(sizeof(struct LinkNode));
	p->data = e;
	p->next = S;
	S = p; 
	return true;
}
//��ջ
bool Pop(LiStack &S, int &e){
	if(S == NULL)
		return false;
	e = S->data;
	LiStack p = S;
	S = S->next;
	free(p);
	return true;
} 
//��ȡջ��Ԫ��
bool GetTop(LiStack S, int &e){
	if(S == NULL)
		return false;
	e = S->data;
	return true;
} 
//�ж�ջ�Ƿ�Ϊ�� 
bool StackEmpty(LiStack S){
	if(S == NULL)
		return true;
	return false; 
}
//����ջ 
bool DestoryStack(LiStack &S){
	LiStack p, q = S;
	while(p){
		p = q->next;
		cout<<"����ɾ��Ԫ�أ�"<<q->data<<endl;
		free(q);
		q = p;
	}
	return true;
}

int main(){
	LiStack S;
	InitStack(S);
	Push(S, 1);
	Push(S, 2);
	Push(S, 2);
	Push(S, 5);
	Push(S, 12);
	int e;
	GetTop(S, e);
	cout<<"��ǰջ��Ԫ��Ϊ��"<<e<<endl;
	int p;
	Pop(S, p);
	cout<<"ɾ����Ԫ��Ϊ��"<<p<<endl;
	GetTop(S, e);
	cout<<"��ǰջ��Ԫ��Ϊ��"<<e<<endl;
	DestoryStack(S);
	return 0;
}






