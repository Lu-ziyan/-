#include<stdio.h>
#define max 100
#define inf 1000000
int main() {
	int D[max][max] = { {inf,2,6,4},{inf,inf,3,inf},{7,inf,inf,1},{5,inf,12,inf} };  //表示图中各个节点之间的路径，如D[i][j]，就为Vi——>Vj权值为D[i][j]
	int S[max][max];  //表示图中节点的后继矩阵,如S[i][j]，则Vi——>Vj的最短路径的存在V S[i][j].
	int i, j, k, V,count;
	printf("输入节点个数：");
	scanf("%d", &V);
	for (i = 0; i < V; ++i) { //对S进行初始化
		count = 0;
		for (j = 0; j < V; ++j) {
			if(i != j){
				S[i][j] = count;
			}
			else 
				S[i][j] = -1;
			++count;
		}
	}
	for (k = 0; k < V; ++k) //V表示节点的数量
		for (i = 0; i < V; ++i)
			for (j = 0; j < V; ++j)
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
					S[i][j] = S[i][k];
				}
	printf("各顶点最小距离矩阵为：\n");
	for (i = 0; i < V; ++i) {//输出最短距离矩阵。
		for (j = 0; j < V; ++j) {
			if (i==j) {
				printf("-1 ");
			}
			else
				printf("%2d ", D[i][j]);
		}
		printf("\n");
	}

}

