#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<cstdio>
using namespace std;
//typedef struct BiTNode
//{
//	char data;
//	struct BiTNode *lchild;
//	struct BiTNode *rchild;
//
//} BiTNode, *BiTree;
//void CreatBiTree(BiTree *T)
//{
//	char ch;
//	scanf("%c", &ch);
//	if (ch == '#')
//		*T = NULL;
//	else
//	{
//		*T = (BiTree)malloc(sizeof(BiTNode));
//		if(!*T)
//			exit(OVERFLOW);
//		(*T)->data = ch;
//		CreatBiTree(&(*T)->lchild);
//		CreatBiTree(&(*T)->rchild);
//
//		
//	}
//}
//
//void preordertraverse(BiTree T)
//{
//	if (T == NULL)
//		return;
//	printf("%c", T->data);
//	preordertraverse(T->lchild);
//	preordertraverse(T->rchild);
//}
//void inordertraverse(BiTree T)
//{
//	if (T == NULL)
//		return;
//	inordertraverse(T->lchild);
//	printf("%c", T->data);
//	inordertraverse(T->rchild);
//}
//void postordertraverse(BiTree T)
//{
//	if (T == NULL)
//		return;
//	postordertraverse(T->lchild);
//	postordertraverse(T->rchild);
//	printf("%c",T->data);
//}
//int main()
//{
//	BiTree T=NULL;
//	CreatBiTree(&T);
//	cout << "������������ɣ�" << endl;
//	cout << "ǰ�������������" << endl;
//	preordertraverse(T);
//	cout << endl;
//	cout << "���������������" << endl;
//	inordertraverse(T);
//	cout << endl;
//	cout << "���������������" << endl;
//	postordertraverse(T);
//	cout << endl;
//	system("pause");
//	return 0;
//}
//#include<iostream>
//using namespace std;

//����ڵ�
typedef struct node
{
	struct node *lchild;
	struct node *rchild;
	char data;
}BiTreeNode, *BiTree;      /*BiTree����˼�Ǹ� struct node*���˸���������BiTree����BiTreeΪָ��ڵ��ָ�롣*/


						  //����ǰ��˳����������
void createBiTree(BiTreeNode * (&T)) //&����˼�Ǵ������ڵ�ָ������ã������ڵȼ��� BiTreeNode* &T,Ŀ�����ô��ݽ�����ָ�뷢���ı�
{
	char c;
	cin >> c;
	if ('#' == c)             //������#ʱ�������ĸ��ڵ�ΪNULL���Ӷ������÷�֧�ĵݹ�
		T = NULL;
	else
	{
		T = new BiTreeNode;
		T->data = c;
		createBiTree(T->lchild);
		createBiTree(T->rchild);
	}
}

//ǰ���������������ӡ
void preTraverse(BiTree T)
{
	if (T)
	{
		cout << T->data << " ";
		preTraverse(T->lchild);
		preTraverse(T->rchild);
	}
}
//�����������������ӡ
void midTraverse(BiTree T)
{
	if (T)
	{
		midTraverse(T->lchild);
		cout << T->data << " ";
		midTraverse(T->rchild);
	}
}
//������������������ӡ
void postTraverse(BiTree T)
{
	if (T)
	{
		postTraverse(T->lchild);
		postTraverse(T->rchild);
		cout << T->data << " ";
	}
}
int main()
{
	BiTree T;               //����һ��ָ����������ڵ��ָ��               
	createBiTree(T);
	cout << "������������ɣ�" << endl;
	cout << "ǰ�������������" << endl;
	preTraverse(T);
	cout << endl;
	cout << "���������������" << endl;
	midTraverse(T);
	cout << endl;
	cout << "���������������" << endl;
	postTraverse(T);
	system("pause");
	return 0;
}