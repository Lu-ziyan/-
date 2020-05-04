#include<stdio.h>
#define max 100
int A[max];
int count = 1;
void fun(int n,int s[],int f[]){
	A[1] = 1;
	int i,j = 1;
	for (i = 2; i <= n; ++i) {
		if (s[i] >= f[j]) {
			count++;
			A[count] = i;
			j = i;
		}
	}
}
void sort(int n, int *s, int *f)
{
	int tmp = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n - i; j++)
		{
			if (f[j] > f[j + 1])
			{
				tmp = f[j];
				f[j] = f[j + 1];
				f[j + 1] = tmp;
				tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}
			else if (f[j] == f[j + 1]) {
				if (s[j] > s[j + 1])
				{
					tmp = s[j];
					s[j] = s[j + 1];
					s[j + 1] = tmp;
				}
			}
		}
	}
}
int main() {
	int s[max],f[max];
	int n,i;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) {
		scanf("%d %d", &s[i], &f[i]);
	}
	sort(n, s, f);
	fun(n, s, f);
	for (i = 1; i <= count; ++i) {
		printf("%d ", A[i]);
	}
}
