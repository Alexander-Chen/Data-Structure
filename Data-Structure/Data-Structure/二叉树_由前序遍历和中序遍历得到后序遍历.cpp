/*
��3.4 ����������
ʱ������:1��
�ڴ�����: 32 ��
��������: ��
��Ŀ����:
��������ǰ�����򡢺�������Ķ���:
ǰ�����: ����һ�������ȷ��ʸ���Ȼ�����������������������������;
�������: ����һ�������ȱ�������������Ȼ����ʸ�����������������;
�������: ����һ�������ȱ�������������Ȼ��������������������ʸ���
����һ�ö�������ǰ��������������������������(��ʾ: ����ǰ���
������������ܹ�Ψһȷ���������)��
����:
�����ַ������䳤��n��С�ڵ���26��
��һ��Ϊǰ��������ڶ���Ϊ����������������еĽ�������Դ�д��ĸ��
ʾ: A,B��....���26 ����㡣
���:
�������������ж��飬����ÿ��������������һ�У�Ϊ����������ַ�����
��������:
ABC
BAC
FDXEAG
XDEFAG
�������:
BCA
XEDGAF
��Դ:
2006���廪��ѧ������о�����������
*/
#define _CRT_SECURE_NO_DEPRECATE
/*int a = 0;
scanf("%d", &a);
����������������123456��Ȼ�󰴻س�����������Ӧ����һ������123456������һ�����з���ͨ����"\r\n"��
��ʱ�����ǿ��������ض�ȡ������a��
������Щʱ�򡱣��������е����ݲ���һ����ȷ����ʱ��������Ҫ����scanf�Ķ�ȡ��Χ��ͨ���Ǹ�������������ʼλ�úͻ������ĳ��ȡ��������԰�ȫ�ش���������ݡ�
���漰CRT�������漰scanf��ʱ��û�п��ǵ���ô��Ĳ���ȫ���أ��������˰�ȫ�汾��scanf����scanf_s��s����˼����safe�����ǻῴ���ܶ�_s�汾�ĺ�����sprintf_s��vsnprintf_s�ȵȣ����ǵ����ö���һ���ġ�
��֮����_s�ĺ����ǲ���_s�İ�ȫ�汾�������ڴ�����Ӧ������ʹ�ð�ȫ�汾��

����˵����char a��20�� scanf_s("%s",a,20)������һ������������֪����������볤�����Ϊ20���൱�ڰ��㴦�����쳣��
��VS2005�Լ��Ժ��VC++�У��������ʹ���˲���ȫ�İ汾���������������һ�����棬��������ݾͺ�¥����һ����
'scanf': This function or variable may be unsafe.Consider using scanf_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.c : \users\user\documents\visual studio 2013\projects\test\test.cpp 8 1 Test
'scanf':������� / ���������ǲ���ȫ�ģ�����ʹ��scanf_s���滻�������Ҫ������������棬��ʹ�ú�_CRT_SECURE_NO_WARNINGS��
���⣬���ִ��Ҫʹ�ò���ȫ�İ汾��Ҫ���԰�ȫ�汾����ʹ�ú�_CRT_SECURE_NO_DEPRECATE��
Unlike scanf and wscanf,scanf_s and wscanf_s require the buffer size to be specified for all input parameters of typec, C, s, S, or string control sets that are enclosed in[]. The buffer size in characters is passed as an additional parameter immediately following the pointer to the buffer or variable. For example, if you are reading a string, the buffer size for that string is passed as follows:


<span style="font-size:12px;">{
char s[10];
scanf_s("%9s", s, _countof(s)); // buffer size is 10, width specification is 9
}</span>
The buffer size includes the terminating null. You can use a width specification field to ensure that the token that's read in will fit into the buffer. If no width specification field is used, and the token read in is too big to fit in the buffer, nothing is written to that buffer.


��VS2005֮��İ汾�У�΢������scanf_s��������scanf�������Դ˱���scanf�����߽�����ڴ�й¶��

��ʹ��%c��%s�����ַ����ַ���ʱ��Ӧ�ڵ�ַ�����󸽼�һ���������߽�ֵ��



�����������Ϊ��


#include <stdio.h>
int main()
{
char c1, c2;
scanf_s("%c%c", &c1, sizeof(c1), &c2, sizeof(c2));
printf("%c\n%c\n", c1, c2);
return 0;
}

������ʧ������������

*/
#include<stdio.h>
#include<string.h>
struct Node
{
	Node *lchild;
	Node *rchild;
	char c;
}Tree[50];
int loc;
Node *creat()
{
	Tree[loc].lchild = Tree[loc].rchild = NULL;
	return &Tree[loc++];
}
char str1[30], str2[30];
void postorder(Node *T)
{
	if (T->lchild != NULL)
	{postorder(T->lchild); }
	if(T->rchild!=NULL)
	{
		postorder(T->rchild);
	}
	printf("%c", T->c); 
}
Node *build(int s1, int e1, int s2, int e2)
{
	Node *ret = creat();
	ret->c = str1[s1];
	int rootldx;
	for (int i = s2; i <= e2; i++)
	{
		if (str2[i] == str1[s1])
		{
			rootldx = i;
			break;
		}
	}
	if (rootldx != s2)
	{
		ret->lchild = build(s1 + 1, s1 + (rootldx - s2), s2, rootldx - 1);
	}
	if (rootldx != e2)
	{
		ret->rchild = build(s1 + (rootldx - s2) + 1, e1, rootldx + 1, e2);
	}
	return ret;
}
int main()
{
	while (scanf_s("%s", str1, sizeof(str1)) != EOF)
	{
		scanf("%s",str2,sizeof(str2));
		loc = 0;
		int L1 = strlen(str1);
		int L2 = strlen(str2);
		Node *T = build(0, L1 - 1, 0,L2 - 1);
		postorder(T);
		printf("\n");
	}
	return 0;
}