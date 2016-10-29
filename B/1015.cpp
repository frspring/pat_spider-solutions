
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int high = 80;
int low = 60;
struct person
{
	int id;
	int virtue;
	int talent;
	bool operator<(const person &b) const
	{
		if (virtue + talent == b.virtue + b.talent)
		{
			if (virtue == b.virtue)
				return id < b.id;
			return virtue > b.virtue;
		}
		return virtue + talent > b.virtue + b.talent;
	}
};
bool cmp(const person &a,const person &b)
{
	if (a.virtue + a.talent == b.virtue + b.talent)
	{
		if (a.virtue == b.virtue)
			return a.id < b.id;
		return a.virtue > b.virtue;
	}
	return a.virtue + a.talent > b.virtue + b.talent;
}

person people[4][100002];

int main()
{
	int n;
	scanf("%d%d%d", &n, &low, &high);
	person temp;
	int cnt[4] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &temp.id, &temp.virtue, &temp.talent);
		if (temp.virtue >= high&&temp.talent >= high)
			people[0][cnt[0]++] = temp;
		else if (temp.virtue >= high&&temp.talent >= low)
			people[1][cnt[1]++] = temp;
		else if (temp.virtue >= temp.talent&&temp.talent >= low)
			people[2][cnt[2]++] = temp;
		else if (temp.virtue >= low&&temp.talent >= low)
			people[3][cnt[3]++] = temp;
	}
	sort(people[0], people[0] + cnt[0], cmp);
	sort(people[1], people[1] + cnt[1], cmp);
	sort(people[2], people[2] + cnt[2],cmp);
	sort(people[3], people[3] + cnt[3], cmp);

	printf("%d\n", cnt[0] + cnt[1] + cnt[2] + cnt[3]);
	for (size_t i = 0; i < 4; i++)
	{
		for (int j = 0; j < cnt[i]; j++)
		{
			printf("%d %d %d\n", people[i][j].id, people[i][j].virtue, people[i][j].talent);
		}
	}
}