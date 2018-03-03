#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECUTR_NO_WARNING
#include<iostream>
using namespace std;
typedef struct lianbiao
{
	int data;
	struct lianbiao * next;
}lianbiao,* lb;
void creatlb(lianbiao * &T)
{
	int ch;
	scanf("%d", &ch);
	if (ch == 0)
		T = NULL;
	else
	{
		T = (lb)malloc(sizeof(lianbiao));
		T->data = ch;
		creatlb(T->next);
	}
}
void bianli(lb T)
{
	if (T == NULL)
		return;
	else cout << T->data<<' ';
	bianli(T->next);
}
int main()
{
	lb T;
	creatlb(T);
	bianli(T);
	system("PAUSE");
  return 0;
}