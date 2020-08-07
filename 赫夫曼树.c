#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int weight;
	int parent, lchild, rchild;
}HTNode, *HuffmanCode;
//huffman树的存储表示 

void huffman(HTNode *w, int num);//Huffman树的排序 

int main()
{
	int num, input,i;
	
	
	printf("请输入结点个数：");
	scanf("%d",&num);
	HTNode *w = (HuffmanCode)malloc((2 * num - 1) * sizeof(HTNode));//动态分配内存给数组 
	for(i = 0;i < 2 * num - 1;i++)//初始化双亲、左右孩子为-1 
	{
		(w + i)->parent = -1;
		(w + i)->lchild = -1;
		(w + i)->rchild = -1;
	}
	printf("请输入%d个权值：",num);
	for(i=0;i<num;i++)//直接将权值放入构造的Huffman树中 
	{
		scanf("%d",&input);
		(w + i)->weight = input;
	}
	huffman(w, num);//将Huffman树的地址传入 
	
	return 0; 
}
void huffman(HTNode *w,int num)
{
	int min_1 = 0, min_2 = 0;
	int spi_1, spi_2;
	int Num, j, i;
	Num = num - 1;
	
	for(j = 0;j < Num;j++)//进行排序整理 
	{
		min_1 = 100; 
		for(i = 0;i < num;i++)
		{
			if((w + i)->parent == -1)
				if(min_1 >= (w + i)->weight)
				{
					spi_1 = i;
					min_1 = (w + i)->weight;
				}
		}
		(w + spi_1) ->parent = num;
		printf("最小下标：%d",spi_1);
		
		min_2 = 100;
		for(i = 0;i < num;i++)
		{
			if((w + i)->parent == -1)			
				if(min_2 >= (w + i)->weight)
				{
					spi_2 = i;
					min_2 = (w + i)->weight;
				}
		}
		(w + spi_2) ->parent = num;
		printf(" 次小下标：%d\n",spi_2);
		
		(w + num)->weight = min_1 + min_2;
		(w + num)->lchild = spi_1;
		(w + num)->rchild = spi_2;
		num++;	
	}
	printf("weight parent lchild rchild\n");
	for(i = 0;i < num;i++)//输出排序好的Huffman树 
		printf("%3d%7d%7d%7d\n",(w + i)->weight, (w +i)->parent,(w + i)->lchild,(w + i)->rchild);
	
}
