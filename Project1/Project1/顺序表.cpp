#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define LIST_INIT_SIZE 80

typedef struct {
	int* elem;	//����һ������
	int length; //˳�����
	int listsize;//��ǰ����Ĵ洢����
}Sqlist;

int InitList_Sq(Sqlist &L)	//����һ���յ�˳���
{
	L.elem = (int*)malloc(sizeof(int) * MAXSIZE);	//Ϊ˳������ռ�
	if (!L.elem) exit(OVERFLOW);					//����ʧ��
	L.length = 0;									//�ձ�
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

int ListInserst(Sqlist& L, int i, int e)	//�ڵ�iλ����Ԫ��e
{
	if (i<1 || i>L.length + 1)	return ERROR;//Խ��
	if (L.length >= MAXSIZE)  return ERROR;//����ռ�����,�޷�����
	else if(L.length>=L.listsize)			//���Ӵ���ռ���� 
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

void DestoryList(Sqlist &L)			//�������Ա�
{
	if (L.elem) free(L.elem);
}

void ClearList(Sqlist &L)			//������Ա�
{
	L.length = 0;
}

int GetLength(Sqlist L)				//�õ����Ա���
{
	return(L.length);
}

int IsEmpty(Sqlist L)				//�ж����Ա�ղ���
{
	if (L.length == 0) return 1;
	else return 0;
}

int GetElem(Sqlist L, int i, int &e)	//��ȡ���Ա�ĳһλ��ֵ
{
	if (i<1 || i>L.length) return ERROR;
	e = L.elem[i - 1];
	return OK;
}

int locateElem(Sqlist L, int e)		//�����Ա�L�в���ֵΪe��Ԫ�أ����������
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