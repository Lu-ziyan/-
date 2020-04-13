#include<stdio.h>
int main() {

	int m=5, n=4;//m万元钱，n项投资
	int i, j;//循环辅助变量
	int tmp_m, tmp_F = 0;//tmp_m代表给第i个项目投入的钱数  0<=tmp<=j;tmp_F代表一次循环中的钱数
	int f[5][6] = { {0,0,0,0,0,0},{0,11,12,13,14,15},{0,0,5,10,15,20},{0,2,10,30,32,40},{0,20,21,22,23,24}};
	int F[5][6];//F[i][x]，将x元钱投入到前i个项目上最大的收益


	//给F[0][0-m]赋值
	for (j = 0; j <= m; ++j) {
		F[0][j] = f[0][j];//第一个项目上投入0-m元钱的最大收益等于f[0][0-m]
	}
	for (i = 1; i <= n; ++i) {//项目循环，从1开始,也就是从前2个项目开始算，因为第一个项目已经赋值
		for (j = 1; j <= m; ++j) {//钱数循环 从0开始
			for (tmp_m = 0; tmp_m <= j; ++tmp_m) {
				tmp_F = F[i - 1][j - tmp_m] + f[i][tmp_m];
				if (tmp_F > F[i][j]) {
					F[i][j] = tmp_F;
				}		
			}
		}
	}
	printf("the max profit is :%d\n",F[n][m]);
}
