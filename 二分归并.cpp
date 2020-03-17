#include<stdio.h>
#define max 100
int s1[max], s2[max];
void merge(int low, int mid, int high) {
	int i=low, j=mid+1,k=low;
	while (i <= mid && j <= high) {
		if (s1[i] < s1[j])
			s2[k++] = s1[i++];
		else
			s2[k++] = s1[j++];
	}
	while (i<=mid){
		s2[k++] = s1[i++];
	}
	while (j<=high) {
		s2[k++] = s1[j++];
	}
	for (i = low; i <= high; ++i) {
		s1[i] = s2[i];
	}
}
void mergesort(int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergesort(low, mid);
		mergesort(mid + 1, high);
		merge(low, mid,high);
	}
}
int main() {
	int n,i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &s1[i]);
	}
	mergesort(0, n-1);
	for (i = 0; i < n; ++i) {
		s1[i] = s2[i];
		printf("%d ", s2[i]);
	}
}
