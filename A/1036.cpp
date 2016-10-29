
#include<iostream>
#include<stdio.h>
#include<stdint.h>
#include<string>
#include<algorithm>
using namespace std;

struct student
{
	char name[15];
	char gender[2];
	char id[15];
	int score;
	void operator=(student b)
	{
		sprintf(name, "%s", b.name);
		sprintf(id, "%s", b.id);
		sprintf(gender, "%s", b.gender);
		score = b.score;
	}
};

int main()
{
	int n;
	student mL,fH,temp;
	scanf("%d", &n);
	mL.gender[0] = 'N';
	mL.score = 101;
	fH.gender[0] = 'N';
	fH.score = -1;
	for (int i = 0; i < n; i++)
	{
		scanf("%s%1s%s%d", &temp.name,&temp.gender,&temp.id,&temp.score);
		if(temp.gender[0]=='M'&&temp.score<mL.score)
			mL = temp;
		if (temp.gender[0] == 'F'&&temp.score > fH.score)
			fH = temp;
	}
	if (fH.gender[0] == 'N')
		printf("Absent\n");
	else
		printf("%s %s\n", fH.name, fH.id);
	if (mL.gender[0] == 'N')
		printf("Absent\n");
	else
		printf("%s %s\n", mL.name, mL.id);
	if (mL.gender[0]=='N' || fH.gender[0]=='N')
		printf("NA");
	else
		printf("%d", fH.score - mL.score);

}