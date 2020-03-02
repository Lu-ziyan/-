#include<stdio.h>    
#define MAX 100  
#define MAXCOST 10000000

int graph[MAX][MAX];

void prim(int graph[][MAX], int n)
{
	int Vnew[MAX];     //表示对应Dist的起点
	int Dist[MAX];     //储存已选点和未选点之间的相邻边
	int i, j, min, minid, sum = 0;
	for (i = 2; i <= n; ++i) { //对几个数组进行初始化，因为默认从下标1开始，所以i=2
		Vnew[i] = 1;
		Dist[i] = graph[1][i]; //将顶点1的邻接边读入
	}
	Vnew[1] = 0;
	for (i = 2; i <= n; i++) {
		min = MAXCOST;
		minid = 0;
		for (j = 2; j <= n; j++) {
			if (min > Dist[j] && Dist[j] != 0) { //找出最小边和最小边对应的下标
				min = Dist[j];       
				minid = j;
			}
		}
		printf("%d--->%d : 权值为：%d\n", Vnew[minid], minid, min);
		sum += min;
		Dist[minid] = 0; //minid对应的最路路径为0
		for (j = 2; j <= n; j++)
		{
			if (graph[minid][j] < Dist[j])  //对这一点直达的顶点进行路径更新 
			{
				Dist[j] = graph[minid][j];
				Vnew[j] = minid; 
			}
		}
	}
	printf("最小权值和为:%d", sum);
}
int main()
{
	int i, j, k, m, n;
	int cost;
	scanf("%d%d", &m, &n);//m=顶点的个数，n=边的个数  

	for (i = 1; i <= m; i++)//初始化图 
	{
		for (j = 1; j <= m; j++)
		{
			graph[i][j] = MAXCOST;
		}
	}
	for (k = 1; k <= n; k++)
	{
		scanf("%d%d%d", &i, &j, &cost);
		graph[i][j] = cost;
		graph[j][i] = cost;
	}
	prim(graph, m);
	return 0;
}

