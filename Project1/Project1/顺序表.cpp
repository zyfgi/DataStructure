#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define LIST_INIT_SIZE 80

typedef struct {
	int* elem;	//创建一个数组
	int length; //顺序表长度
	int listsize;//当前分配的存储容量
}Sqlist;

int InitList_Sq(Sqlist &L)	//构造一个空的顺序表
{
	L.elem = (int*)malloc(sizeof(int) * MAXSIZE);	//为顺序表分配空间
	if (!L.elem) exit(OVERFLOW);					//分配失败
	L.length = 0;									//空表
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

int ListInserst(Sqlist& L, int i, int e)	//在第i位插入元素e
{
	if (i<1 || i>L.length + 1)	return ERROR;//越界
	if (L.length >= MAXSIZE)  return ERROR;//储存空间已满,无法插入
	else if(L.length>=L.listsize)			//增加储存空间分配 
	{                  
		int* newbase = (int*)realloc(L.elem, (static_cast<unsigned long long>(L.listsize) + (MAXSIZE - LIST_INIT_SIZE)) * sizeof(int));
		if (!newbase) exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += (MAXSIZE - LIST_INIT_SIZE);
	}
	for (int j=(L.length-1);j>=i;j--)
	{
		L.elem[j+1] = L.elem[j];
	}
	L.elem[i - 1] = e;
	L.length++;
	return OK;
}

void DestoryList(Sqlist &L)			//销毁线性表
{
	if (L.elem) free(L.elem);
}

void ClearList(Sqlist &L)			//清空线性表
{
	L.length = 0;
}

int GetLength(Sqlist L)				//得到线性表长度
{
	return(L.length);
}

int IsEmpty(Sqlist L)				//判断线性表空不空
{
	if (L.length == 0) return 1;
	else return 0;
}

int GetElem(Sqlist L, int i, int &e)	//获取线性表某一位的值
{
	if (i<1 || i>L.length) return ERROR;
	e = L.elem[i - 1];
	return OK;
}

int locateElem(Sqlist L, int e)		//在线性表L中查找值为e的元素，返回其序号
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e) return i + 1;
	}
	return 0;
}

 
int main()
{
	Sqlist L;
	InitList_Sq(L);
	ListInserst(L, 1, 1);
	ListInserst(L, 2, 1);
	ListInserst(L, 1, 3);
	std::cout << L.elem[0] << std::endl;
	std::cout << L.elem[1] << std::endl;
	std::cout << L.elem[2] << std::endl;
	std::cout << L.length << std::endl;
	std::cout << L.listsize<< std::endl;
	return 0;
}