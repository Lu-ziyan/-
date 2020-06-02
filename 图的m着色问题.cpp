#include<stdio.h>
#include<string.h>
const int maxn = 100 + 10;

int n, m, match;       //图的顶点数，可用的颜色数量，边的数量
int c[maxn][maxn];  //图的链接矩阵
int col[maxn];          //当前的解
int sum = 0;            //方案数

bool Same(int t) {//判断是否能往下涂色
	for (int i = 1; i <= n; ++i) {
		if (c[t][i] == 1 && col[i] == col[t])
			return false;
	}
	return true;
}

void BackTrack(int t) {
	if (t > n) {
		sum++;
		for (int i = 1; i <= n; ++i)
			printf("%d ", col[i]);
		printf("\n");
	}
	else {
		for (int i = 1; i <= m; ++i) {
			col[t] = i;
			if (Same(t))BackTrack(t + 1);
			col[t] = 0;
		}
	}
}

int main() {
	printf("输入可用的颜色数量:\n");
	scanf("%d", &m);
	printf("输入图的顶点数、边的数量:\n");
	scanf("%d %d",&n, &match);
	printf("输入边:\n");
	for (int i = 1; i <= match; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		c[x][y] = c[y][x] = 1;
	}
	printf("着色的方法为：\n");
	BackTrack(1);
	if (sum == 0)printf("不存在\n");
	else printf("一共有%d种着色方法\n", sum);
}