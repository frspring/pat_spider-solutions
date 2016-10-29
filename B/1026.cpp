
#include<iostream>
#include<stdio.h>
#include<stdint.h>
using namespace std;
int main()
{
	int before, after;
	scanf("%d%d", &before, &after);
	int time;
	time = (int)((after - before)/100.0+0.5);
	int h = 0, m = 0, s = 0;
	s = time % 60;
	time /= 60;
	m = time % 60;
	h = time / 60;
	printf("%02d:%02d:%02d", h, m, s);

}