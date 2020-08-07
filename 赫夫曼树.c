#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int weight;
	int parent, lchild, rchild;
}HTNode, *HuffmanCode;
//huffman���Ĵ洢��ʾ 

void huffman(HTNode *w, int num);//Huffman�������� 

int main()
{
	int num, input,i;
	
	
	printf("�������������");
	scanf("%d",&num);
	HTNode *w = (HuffmanCode)malloc((2 * num - 1) * sizeof(HTNode));//��̬�����ڴ������ 
	for(i = 0;i < 2 * num - 1;i++)//��ʼ��˫�ס����Һ���Ϊ-1 
	{
		(w + i)->parent = -1;
		(w + i)->lchild = -1;
		(w + i)->rchild = -1;
	}
	printf("������%d��Ȩֵ��",num);
	for(i=0;i<num;i++)//ֱ�ӽ�Ȩֵ���빹���Huffman���� 
	{
		scanf("%d",&input);
		(w + i)->weight = input;
	}
	huffman(w, num);//��Huffman���ĵ�ַ���� 
	
	return 0; 
}
void huffman(HTNode *w,int num)
{
	int min_1 = 0, min_2 = 0;
	int spi_1, spi_2;
	int Num, j, i;
	Num = num - 1;
	
	for(j = 0;j < Num;j++)//������������ 
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
		printf("��С�±꣺%d",spi_1);
		
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
		printf(" ��С�±꣺%d\n",spi_2);
		
		(w + num)->weight = min_1 + min_2;
		(w + num)->lchild = spi_1;
		(w + num)->rchild = spi_2;
		num++;	
	}
	printf("weight parent lchild rchild\n");
	for(i = 0;i < num;i++)//�������õ�Huffman�� 
		printf("%3d%7d%7d%7d\n",(w + i)->weight, (w +i)->parent,(w + i)->lchild,(w + i)->rchild);
	
}
