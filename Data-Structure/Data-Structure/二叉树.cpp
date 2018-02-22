/*
例3.4 二叉树遍历
时间限制:1秒
内存限制: 32 兆
特殊判题: 否
题目描述:
二叉树的前序、中序、后序遍历的定义:
前序遍历: 对任一子树，先访问跟，然后遍历其左子树，最后遍历其右子树;
中序遍历: 对任一子树，先遍历其左子树，然后访问根，最后遍历其右子树;
后序遍历: 对任一子树，先遍历其左子树，然后遍历其右子树，最后访问根。
给定一棵二叉树的前序遍历和中序遍历，求其后序遍历(提示: 给定前序遍
历与中序遍历能够唯一确定后序遍历)。
输入:
两个字符串，其长度n均小于等于26。
第一行为前序遍历，第二行为中序遍历。二叉树中的结点名称以大写字母表
示: A,B，....最多26 个结点。
输出:
输入样例可能有多组，对于每组测试样例，输出一行，为后序遍历的字符串。
样例输入:
ABC
BAC
FDXEAG
XDEFAG
样例输出:
BCA
XEDGAF
来源:
2006年清华大学计算机研究生机试真题
*/
#define _CRT_SECURE_NO_DEPRECATE
/*int a = 0;
scanf("%d", &a);
假设我们输入数字123456，然后按回车。缓冲区中应该是一个数组123456，加上一个换行符，通常是"\r\n"。
这时候我们可以正常地读取到数字a。
但“有些时候”，缓冲区中的数据并不一定正确，这时候我们需要限制scanf的读取范围，通常是给定缓冲区的起始位置和缓冲区的长度。这样可以安全地处理错误数据。
但涉及CRT的人在涉及scanf的时候没有考虑到这么多的不安全因素，所以有了安全版本的scanf，级scanf_s，s的意思就是safe，我们会看到很多_s版本的函数，sprintf_s，vsnprintf_s等等，它们的作用都是一样的。
总之，带_s的函数是不带_s的安全版本，我们在代码中应当尽量使用安全版本。

比如说输入char a［20］ scanf_s("%s",a,20)；这样一来，编译器就知道了这个输入长度最多为20，相当于帮你处理了异常。
在VS2005以及以后的VC++中，如果我们使用了不安全的版本，编译器会给我们一条警告，警告的内容就和楼主的一样。
'scanf': This function or variable may be unsafe.Consider using scanf_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.c : \users\user\documents\visual studio 2013\projects\test\test.cpp 8 1 Test
'scanf':这个函数 / 变量可能是不安全的，考虑使用scanf_s来替换它。如果要想忽略这样警告，请使用宏_CRT_SECURE_NO_WARNINGS。
另外，如果执意要使用不安全的版本而要忽略安全版本，请使用宏_CRT_SECURE_NO_DEPRECATE。
Unlike scanf and wscanf,scanf_s and wscanf_s require the buffer size to be specified for all input parameters of typec, C, s, S, or string control sets that are enclosed in[]. The buffer size in characters is passed as an additional parameter immediately following the pointer to the buffer or variable. For example, if you are reading a string, the buffer size for that string is passed as follows:


<span style="font-size:12px;">{
char s[10];
scanf_s("%9s", s, _countof(s)); // buffer size is 10, width specification is 9
}</span>
The buffer size includes the terminating null. You can use a width specification field to ensure that the token that's read in will fit into the buffer. If no width specification field is used, and the token read in is too big to fit in the buffer, nothing is written to that buffer.


在VS2005之后的版本中，微软定义了scanf_s用来代替scanf函数，以此避免scanf不检查边界造成内存泄露。

在使用%c和%s读入字符或字符串时，应在地址参数后附加一个缓冲区边界值。



将上述代码改为：


#include <stdio.h>
int main()
{
char c1, c2;
scanf_s("%c%c", &c1, sizeof(c1), &c2, sizeof(c2));
printf("%c\n%c\n", c1, c2);
return 0;
}

警告消失，调试正常。

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