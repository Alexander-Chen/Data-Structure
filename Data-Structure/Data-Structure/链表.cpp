/*¾²Ì¬Á´±í
#include<iostream>
using namespace std;
struct Student
{
	int num;
	float score;
	struct  Student*next;

};
int main()
{
	struct Student a, b, c, *head, *p;
	a.num = 10101; a.score = 89.5;
	b.num = 10103; b.score = 90;
	c.num = 10107; c.score = 85;
	head = &a;
	a.next = &b;
	b.next = &c;
	c.next = NULL;
	p = head;
	do
	{
		cout << p->num <<' '<< p->score<<endl;
		p = p->next;
	} while (p != NULL);
	getchar();
	getchar();
	return 0;
}
*/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#define LEN sizeof(struct Student)
struct  Student
{
	long num;
	float score;
	struct  Student * next;
};
int n;
struct  Student * creat(void)
{
	struct  Student * head;
	struct	Student *p1, *p2;
	n = 0;
	p1 = p2 = (struct Student *)malloc(LEN);
	scanf_s("%ld,%f,&p1->num,p1->score");
	head = NULL;
	while (p1->num!=0)
	{
		n = n + 1;
		if (n == 1)head = p1;
		else
		{
			p2->next = p1;
		}
		p2 = p1;
		p1 = (struct Student *)malloc(LEN);
		scanf_s("%ld,%f,&p1->num,&p1->score");
	}
	p2->next = NULL;
	return(head);
};
int main()
{
	struct Student *pt;
	pt = creat();
	printf("\nnum:%ld\nscore:%5.1f\n", pt->num, pt->score);
	return 0;
	getchar();
}