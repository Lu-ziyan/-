#include <stdio.h>
#include <stdlib.h>
#define Max 50

typedef struct road *Road; //储存图的结构
typedef struct road
{
	int a, b;
	int w;
}road;

typedef struct graph *Graph;
typedef struct graph
{
	int e, n;
	Road data;
}graph;

Graph initGraph(int m, int n)
{
	Graph g = (Graph)malloc(sizeof(graph));
	g->n = m;
	g->e = n;
	g->data = (Road)malloc(sizeof(road) * (g->e));
	return g;
}

void create(Graph g)
{
	int i;
	for (i = 1; i <= g->e; i++)
	{
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		if (x < y)
		{
			g->data[i].a = x;
			g->data[i].b = y;
		}
		else
		{
			g->data[i].a = y;
			g->data[i].b = x;
		}
		g->data[i].w = w;
	}
}

int getRoot(int v[], int x)
{
	while (v[x] != x)
	{
		x = v[x];
	}
	return x;
}

void sort(Road data, int n)
{
	int i, j;
	for (i = 1; i <= n - 1; i++)
	{
		for (j = 1; j <= n - i; j++)
		{
			if (data[j].w > data[j + 1].w)
			{
				road t = data[j];
				data[j] = data[j + 1];
				data[j + 1] = t;
			}
		}
	}
}

void Kruskal(Graph g)
{
	int sum = 0;
	int v[Max];
	int i;
	for (i = 1; i <= g->n; i++)
	{
		v[i] = i;
	}
	sort(g->data, g->e);
	for (i = 1; i <= g->e; i++)
	{
		int a, b;
		a = getRoot(v, g->data[i].a);
		b = getRoot(v, g->data[i].b);
		if (a != b)
		{
			v[a] = b;
			sum += g->data[i].w;
			printf("%d--->%d权值为：%d\n", a, b, g->data[i].w);
		}
	}
	printf("最小权值为：%d\n", sum);
}

int main()
{
	int m, n, id = 1;
	scanf("%d %d", &m, &n);
	int i;
	Graph g = initGraph(m, n);
	create(g);
	Kruskal(g);
	free(g);
	return 0;
}
