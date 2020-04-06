#include<stdio.h>
#include<string.h>
#define M 100
void Sort(int *arr, int low,int high)
{
	int i, j, tmp;
	for (i = low; i < high; i++) {
		for (j = low; j < high - i  ; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int select(int arr[],int l,int h ,int k){
	int mid[M];
	int size = h - l + 1;
	if (size <= 5) {
		Sort(arr, l, size-1);
		return arr[k - 1];
	}
	else {
		int q = size / 5;
		int r = size - q * 5;
		for (int i = 0; i < q; ++i) {
			Sort(arr, 5 * i, (i + 1) * 5);
			mid[i] = arr[i * 5 + 2];
		}
		if (r > 0) {
			Sort(arr, 5 * q, 5 * q + r-1);
			mid[q] = arr[q * 5 + (r + 1) / 2 - 1];
		}
		int mm = select(mid, 0, q - 1, (q + 1) / 2);
		int S1[M],S2[M];
		int lens1=0, lens2=0;
		for (int i = l; i <= h; ++i) {
			if (arr[i] < mm) {
				S1[lens1++] = arr[i];
			}
			else {
				S2[lens2++] = arr[i];
			}
		}
		int f = 0;
		if ( k == lens1+1) {
			f = mm;
		}
		else if (k<=lens1) {
			f = select(S1, 0, lens1 - 1, k);
		}
		else {
			f = select(S2,0,lens2 - 1,k-lens1);
		}
		return f;
	}
}
int main() {
	int a[M];
	int k,n;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int s=select(a, 0, n-1, k);
	printf("%d", s);
}
