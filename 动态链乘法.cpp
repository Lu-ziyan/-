#include<stdio.h>
#define max 10000000
int m[100][100];
int s[100][100];
int recurMatrixChain(int P[], int i, int j) {
	if (i == j) { 
		m[i][j] = 0;
		s[i][j] = i;
		return m[i][j];
	}
	m[i][j] = max;  
	s[i][j] = i;       
	for (int k = i; k <= j - 1; k++) { 
		int q = recurMatrixChain(P, i, k) + recurMatrixChain(P, k + 1, j) + P[i - 1] * P[k] * P[j];
		if (q < m[i][j]) {
			m[i][j] = q;
			s[i][j] = k;
		}
	}
	return m[i][j];
}
void matrixChain(int P[], int n) { //µü´ú
	int i, j, k, t;
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			s[i][j] = i;
		}
	}
	for (int r = 2; r <= n; r++) {   
		for (i = 1; i <= (n - r + 1); i++) { 
			j = i + r - 1;             
			m[i][j] = m[i + 1][j] + P[i - 1] * P[i] * P[j];  
			s[i][j] = i;                                     
			for (k = i + 1; k <= j - 1; k++) {                 
				t = m[i][k] + m[k + 1][j] + P[i - 1] * P[k] * P[j]; 
				if (t < m[i][j]) {
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
}

int main() {
	int P[100];
	int n,i,j;
	printf("ÊäÈën:\n");
	scanf("%d", &n);
	printf("ÊäÈëp:\n");
	for (i = 0; i <= n; ++i) {
		scanf("%d", &P[i]);
	}
	
	matrixChain(P, n);
	printf("%d",m[1][n]);
}
