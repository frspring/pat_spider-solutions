
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const char item[14] = "0123456789JQK";

int main()
{
	char A[150] = { 0 }, B[150] = { 0 };
	scanf("%s%s", A, B);
	int lA, lB;
	lA = strlen(A);
	lB = strlen(B);
	int length;
	length = lA < lB ? lB : lA;
	reverse(A, A + lA);
	reverse(B, B + lB);
	for (int i = 0; i < length; i++)
	{
		int tempA = A[i] == 0 ? 0 : A[i] - '0';
		int tempB = B[i] == 0 ? 0 : B[i] - '0';
		int ans = 0;
		if (i % 2 == 0)
		{
			A[i] = item[(tempA + tempB ) % 13];
		}
		else
		{
			ans = tempB - tempA;
			if (ans<0)
				ans += 10;
			A[i] = ans + '0';
		}
	}
	reverse(A, A + length);
	printf("%s", A);
	return 0;
}