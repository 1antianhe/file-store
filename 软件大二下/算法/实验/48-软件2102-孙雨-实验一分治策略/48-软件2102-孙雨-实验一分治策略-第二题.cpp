#include <stdio.h>
#include <math.h>
//ѭ�����ճ̱����ƣ�
int a[100][100];//�������鳤�� 

//�����ϰ벿�ֵ��Ƶ����ϰ벿�� 
void add(int x,int y,int d){
	int i,j;
	for(i=x;i<=x+d-1;i++){
		for(j=y;j<=y+d-1;j++){
			a[i][j+d]=a[i][j]+d;//���浽������ֵ���Ϸ��鳤�� 
		}
	}
	return;
}

//������������ 
void copy(int x1,int y1,int d,int x2,int y2){
	int i,j;
	for(i=0;i<=d-1;i++){
		for(j=0;j<=d-1;j++){
			//��ȫ���ƣ���ʼλ��ȷ�� 
			a[x2+i][y2+j]=a[x1+i][y1+j];
			 
		}
	}
	return;
}

//��ӡ��ά���� 
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

//������ 
int main(){
	int n,d,i;
	float k;
		
	printf("������ѡ������:\n");
	scanf("%d",&n);
	k=log2(n);//ȡlog��ȡk��ֵ 
	if(k!=(int)k)//�ж�k�Ƿ�Ϊ���� 
		printf("�������������\n");
	else//kΪ���� 
	{
		d=1;//�����ʼ���鳤��Ϊ1 
		a[1][1]=1;//��������ֵΪ1 
		//���η��͸��Ƽ��� 
		for(i=0;i<=k-1;i++){
			add(1,1,d);
			copy(1,1+d,d,1+d,1);//���ϵ�����
			copy(1,1,d,1+d,1+d);//���ϵ����� 
			d=d*2;//�߿��Ϊ֮ǰ���� 
			}
		
		prt(1,1,d);//��ӡ 
	}
	

}
