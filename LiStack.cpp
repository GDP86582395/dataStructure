#include<iostream>
#include<stdlib.h>
using namespace std;


/**
  * TODO 数据结构，链栈的实现（不带头结点） 
  * @author 有爱的大鹏叔 
  */
  
//链栈的定义 
typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}*LiStack;
//链栈的初始化
LiStack InitStack(LiStack &S){
	S = NULL;
	return S;
} 
//进栈 
bool Push(LiStack &S, int e){
	LiStack p = (LiStack)malloc(sizeof(struct LinkNode));
	p->data = e;
	p->next = S;
	S = p; 
	return true;
}
//出栈
bool Pop(LiStack &S, int &e){
	if(S == NULL)
		return false;
	e = S->data;
	LiStack p = S;
	S = S->next;
	free(p);
	return true;
} 
//获取栈顶元素
bool GetTop(LiStack S, int &e){
	if(S == NULL)
		return false;
	e = S->data;
	return true;
} 
//判断栈是否为空 
bool StackEmpty(LiStack S){
	if(S == NULL)
		return true;
	return false; 
}
//销毁栈 
bool DestoryStack(LiStack &S){
	LiStack p, q = S;
	while(p){
		p = q->next;
		cout<<"正在删除元素："<<q->data<<endl;
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
	cout<<"当前栈顶元素为："<<e<<endl;
	int p;
	Pop(S, p);
	cout<<"删除的元素为："<<p<<endl;
	GetTop(S, e);
	cout<<"当前栈顶元素为："<<e<<endl;
	DestoryStack(S);
	return 0;
}






