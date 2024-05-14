#include <stdio.h>
#include <math.h>
//循环赛日程表的设计：
int a[100][100];//定义数组长度 

//把左上半部分的移到右上半部分 
void add(int x,int y,int d){
	int i,j;
	for(i=x;i<=x+d-1;i++){
		for(j=y;j<=y+d-1;j++){
			a[i][j+d]=a[i][j]+d;//左面到右面数值加上方块长度 
		}
	}
	return;
}

//复制整个方块 
void copy(int x1,int y1,int d,int x2,int y2){
	int i,j;
	for(i=0;i<=d-1;i++){
		for(j=0;j<=d-1;j++){
			//完全复制，起始位置确定 
			a[x2+i][y2+j]=a[x1+i][y1+j];
			 
		}
	}
	return;
}

//打印二维数组 
void prt(int x,int y,int d){
	int i,j;
	for(i=0;i<=d-1;i++){
		for(j=0;j<=d-1;j++){
			printf("%3d",a[x+i][y+j]);
		}
		printf("\n");
	}
	return;
}

//主函数 
int main(){
	int n,d,i;
	float k;
		
	printf("请输入选手数量:\n");
	scanf("%d",&n);
	k=log2(n);//取log获取k的值 
	if(k!=(int)k)//判断k是否为整数 
		printf("请输入合理数量\n");
	else//k为整数 
	{
		d=1;//定义初始方块长度为1 
		a[1][1]=1;//定义数组值为1 
		//几次方就复制几遍 
		for(i=0;i<=k-1;i++){
			add(1,1,d);
			copy(1,1+d,d,1+d,1);//右上到左下
			copy(1,1,d,1+d,1+d);//左上到右下 
			d=d*2;//边框变为之前两倍 
			}
		
		prt(1,1,d);//打印 
	}
	

}
