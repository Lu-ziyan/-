#include<stdio.h>
int	SequenceSearch(int a[], int v, int n) {
	int i;
	for (i = 0; i < n; ++i) {
		if (v == a[i]) {
			return i;
		}
	}
	return 0;
}
int BinarySearch(int a[], int v, int n) {
	int h, l, m;
	l = 0;
	h = n - 1;
	while (l <= h)
	{
		m = (l + h) / 2;
		if (a[m] == v)
			return m;
		if (a[m] > v)
			h = m - 1;
		if (a[m] < v)
			l = m + 1;
	}
	return 0;
}
int main() {
	int a[] = { 0,1,6,7,9,12,16,18,20,25,29 };
	int b = SequenceSearch(a, 2, sizeof(a) / sizeof(a[0]));
	int c = BinarySearch(a, 2, sizeof(a) / sizeof(a[0]));
	printf("%d %d", b,c);
}
