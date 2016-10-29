
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int high = 80;
int low = 60;
char str[4][2] = { "C","M","E","A" };

struct person
{
	int id;
	int cs;
	int math;
	int eng;
	int arv;
	int cr;
	int mr;
	int er;
	int agr;
};
bool cmpm(person a, person b)
{
	return a.math > b.math;
}
bool cmps(person a, person b)
{
	return a.cs > b.cs;
}
bool cmpe(person a, person b)
{
	return a.eng > b.eng;
}
bool cmpa(person a, person b)
{
	return a.arv > b.arv;
}
person student[2100];
person *ptr[1000000] = { 0 };
int main()
{
	int n, m;
	scanf("%d%d",&n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &student[i].id, &student[i].cs, &student[i].math, &student[i].eng);
		student[i].arv = (student[i].cs + student[i].math + student[i].eng)/3;
		
	}
	sort(student, student + n, cmps);
	int acc =1 ;
	for (int i = 1,j=1; i < n+1; i++)
	{
		student[i - 1].cr = j;
		if(i<n)
			if(student[i - 1].cs!=student[i].cs)
			{
				j+=acc;
				acc=1;
			}
			else
			{
				acc++;
			}
	}
	acc=1;
	sort(student, student + n, cmpm);
	for (int i = 1,j=1; i < n + 1; i++)
	{
		student[i - 1].mr = j;
		if(i<n)
		{
			if(student[i - 1].math!=student[i].math)
			{
				j+=acc;
				acc=1;
			}
			else
			{
				acc++;
			}
		}
	}
	acc=1;
	sort(student, student + n, cmpe);
	for (int i = 1,j=1; i < n + 1; i++)
	{
		
		student[i - 1].er = j;
		if(i<n)
			if(student[i - 1].eng!=student[i].eng)
						{
				j+=acc;
				acc=1;
			}
			else
			{
				acc++;
			}
	}
	acc=1;
	sort(student, student + n, cmpa);
	for (int i = 1,j=1; i < n + 1; i++)
	{
		student[i - 1].agr = j;
		if(i<n)
		{
			if(student[i - 1].arv!=student[i].arv)
			{
				j+=acc;
				acc=1;
			}
			else
			{
				acc++;
			}
		}
	}
	for(int i=0,j=1;i<n;i++)
	{
		ptr[student[i].id] = &student[i];
	}
	int snum;
	for(int i=0;i<m;i++)
	{
		scanf("%d",&snum);
		person* p;
		if(ptr[snum] == 0)
			printf("N/A\n");
		else
		{
			p=ptr[snum];
			if(p->agr<=p->cr&&p->agr<=p->er&&p->agr<=p->mr)
			{
				printf("%d A\n",p->agr);
			}
			else if(p->cr<p->agr&&p->cr<=p->mr&&p->cr<=p->er)
			{
				printf("%d C\n",p->cr);
			}
			else if(p->mr<p->agr&&p->mr<p->cr&&p->mr<=p->er)
			{
				printf("%d M\n",p->mr);
			}
			else
			{
				printf("%d E\n",p->er);
			}
		}
	}
	return 0;
}