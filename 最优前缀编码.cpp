#include<stdio.h>
#include<stdlib.h> 
#define MAX 100

typedef struct HuffmanTreeNode {
	int  data;  //哈夫曼树中节点的权值
	struct HuffmanTreeNode* left;
	struct HuffmanTreeNode* right;
}HuffmanTreeNode, *PtrHuffman;


PtrHuffman createHuffmanTree(int arr[],int n) {
	PtrHuffman ptrArr[MAX];
	PtrHuffman ptr, pRoot = NULL;

	for (int i = 0; i < n; i++) {  //初始化结构体指针数组,数组中每一个元素为一个结构体指针类型
		ptr = (PtrHuffman)malloc(sizeof(HuffmanTreeNode));
		ptr->data = arr[i];
		ptr->left = ptr->right = NULL;
		ptrArr[i] = ptr;
	}

	for (int i = 1; i < n; i++) {  //进行 n-1 次循环建立哈夫曼树  
		//k1表示森林中具有最小权值的树根结点的下标,k2为次最小的下标
		int k1 = -1, k2;
		for (int j = 0; j < n; j++) {
			if (ptrArr[j] != NULL && k1 == -1) {
				k1 = j;
				continue;
			}
			if (ptrArr[j] != NULL) {
				k2 = j;
				break;
			}
		}
		//将指针数组中的指针指向的最小值赋值给索引号为k1的,次小值赋值给索引号为k2的
		for (int j = k2; j < n; j++) {
			if (ptrArr[j] != NULL) {
				if (ptrArr[j]->data < ptrArr[k1]->data) {
					k2 = k1;
					k1 = j;
				}
				else if (ptrArr[j]->data < ptrArr[k2]->data) {
					k2 = j;
				}
			}
		}
		//由最小权值树和次最小权值树建立一棵新树,pRoot指向树根结点
		pRoot = (PtrHuffman)malloc(sizeof(HuffmanTreeNode));
		pRoot->data = ptrArr[k1]->data + ptrArr[k2]->data;
		pRoot->left = ptrArr[k1];
		pRoot->right = ptrArr[k2];

		ptrArr[k1] = pRoot; //将指向新树的指针赋给ptrArr指针数组中k1位置
		ptrArr[k2] = NULL; //k2位置为空
	}

	return pRoot;
}
/**
 * 哈夫曼树编码(叶子节点按中序方式依次打印其编码)
 */
void HuffmanCoding(PtrHuffman &ptrTree, int len) {
	static int arr[20];
	if (ptrTree != NULL) {
		if (ptrTree->left == NULL && ptrTree->right == NULL) {
			printf("结点为%d的编码: ", ptrTree->data);
			for (int i = 0; i < len; i++) {
				printf("%d", arr[i]);
			}
			printf("\n");
		}
		else {
			arr[len] = 0;
			HuffmanCoding(ptrTree->left, len + 1);
			arr[len] = 1;
			HuffmanCoding(ptrTree->right, len + 1);
		}
	}
}


int main() {
	int n;
	int arr[] = { 5,5,10,10,10,15,20,25 };
	n = sizeof(arr) / sizeof(arr[0]);
	PtrHuffman pRoot = createHuffmanTree(arr,n);
	printf("==========各节点的哈夫曼树编码==========\n");
	HuffmanCoding(pRoot, 0);
	printf("\n");
	return 0;
}