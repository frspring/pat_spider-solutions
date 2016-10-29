
#include<iostream>
#include<stdio.h>
#include<stdint.h>
#include<algorithm>
using namespace std;
int judge(char alien, char blue)	//ALIEN 0 WIN,1 FLAT,2 DEFEAT
{
	if (alien == blue)
		return 1;
	if (alien == 'C'&&blue == 'J')
		return 0;
	if (alien == 'C'&&blue == 'B')
		return 2;
	if (alien == 'J'&&blue == 'C')
		return 2;
	if (alien == 'J'&&blue == 'B')
		return 0;
	if (alien == 'B'&&blue == 'C')
		return 0;
	if (alien == 'B'&&blue == 'J')
		return 2;
	return 99;
}
int main()//C J B
{
	int n = 0;
	scanf("%d", &n);
	int winDefFlat[2][3] = { 0 };
	int posture[2][3] = { 0 };
	char alien[2], blue[2];
	int condition;
	for (int i = 0; i < n; i++)
	{
		scanf("%1s %1s", alien, blue);
		condition=judge(alien[0], blue[0]);
		winDefFlat[0][condition]++;
		winDefFlat[1][2 - condition]++;
		posture[0][0] += (condition == 0 && alien[0] == 'C');
		posture[0][1] += (condition == 0 && alien[0] == 'J');
		posture[0][2] += (condition == 0 && alien[0] == 'B');
		posture[1][0] += (condition == 2 && blue[0] == 'C');
		posture[1][1] += (condition == 2 && blue[0] == 'J');
		posture[1][2] += (condition == 2 && blue[0] == 'B');
	}
	printf("%d %d %d\n", winDefFlat[0][0], winDefFlat[0][1], winDefFlat[0][2]);
	printf("%d %d %d\n", winDefFlat[1][0], winDefFlat[1][1], winDefFlat[1][2]);
	int m1 = 0, m2 = 0;
	for (int i = 0; i < 2; i++)
	{
		if (posture[i][2] >= posture[i][1] && posture[i][2] >= posture[i][0])
			printf("B");
		else if(posture[i][1] > posture[i][2] && posture[i][1] > posture[i][0])
		{
			printf("J");
		}
		else
		{
			printf("C");
		}
		if(i!=1)
			printf(" ");
	}
}