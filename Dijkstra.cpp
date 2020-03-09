#include<stdio.h>
#include<stdlib.h>
#define max 1000000
int a[1000][1000];
int d[1000];//d表示源节点到该节点的最小距离
int p[1000];//p标记访问过的节点
int i, j, k;
int m;//m代表边数
int n;//n代表点数
int main()
{
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
		{
			if (i == j) {
				a[i][j] = 0;
			}
			else
				a[i][j] = max;
		}
	}
	int  k;
	int  x, y;
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &x, &y, &k);//输入邻接矩阵
		a[x][y] = k;
	}
	for (i = 1; i <= n; ++i) {//初始化访问数组
		p[i] = 0;
	}
	p[1] = 1;
	for (i = 1; i <= n; i++) //初始化dis数组为a点到各个顶点的距离
	{
		d[i] = a[1][i];
	}

	for (i = 1; i < n; i++) 
	{
		int min = max,temp;
		for (j = 1; j <= n; j++)
		{
			if (!p[j] && d[j] < min) //找到离1号顶点最近的顶点
			{
				min = d[j];
				temp = j;
			}
		}
		p[temp] = 1;
		for (j = 1; j <= n; j++)
		{
			if (a[temp][j] < max) {
				if (a[temp][j] + d[temp] < d[j])
				{
					d[j] = a[temp][j] + d[temp];
				}
			}
		}

	}
	//最终输出从源节点到其他每个节点的最小距离
	for (i = 1; i < n; i++)
		printf("%d->", d[i]);
	printf("%d\n", d[n]);
	return 0;
}

