#include<stdio.h>
#define NUM 8 /*定义数组的大小*/
int a[NUM+1];
int main()
{
	int i,k,flag,not_finish=1,count=0;
    i=1; /*正在处理的元素下标，表示前i-1个元素已符合要求，正在处理第i个元素*/
    a[1]=1; /*为数组的第一个元素赋初值*/
    printf("The possible configuration of 8 queens are: ");
    while(not_finish) /*not_finish=1:处理尚未结束*/
	{
		while(not_finish&&i<=NUM) /*处理尚未结束且还没处理到第NUM个元素*/
		{
			for(flag=1,k=1;flag&&k<i;k++) /*判断是否有多个皇后在同一行*/
				if(a[k]==a[i])flag=0;
				for(k=1;flag&&k<i;k++) /*判断是否有多个皇后在同一对角线*/
					if((a[i]==a[k]-(k-i))||(a[i]==a[k]+(k-i))) flag=0;
					if(!flag) /*若存在矛盾不满足要求，需要重新设置第i个元素*/
					{
						if(a[i]==a[i-1]) /*若a[i]的值已经经过一圈追上a[i-1]的值*/
						{
							i--; /*退回一步，重新试探处理前一个元素*/
                            if(i>1&&a[i]==NUM)
								a[i]=1; /*当a[i]为NUM时将a[i]的值置1*/
                            else if(i==1&&a[i]==NUM)
								not_finish=0; /*当第一位的值达到NUM时结束*/
							else a[i]++; /*将a[i]的值取下一个值*/
						}
						else if(a[i]==NUM) 
							a[i]=1;
						else a[i]++; /*将a[i]的值取下一个值*/
					}
					else if(++i<=NUM)
						if(a[i-1]==NUM) a[i]=1; /*若前一个元素的值为NUM则a[i]=1*/
						else a[i]=a[i-1]+1; /*否则元素的值为前一个元素的下一个值*/
		}
		if(not_finish)
		{
			++count;
            printf((count-1)%3?" [%2d]: ":" [%2d]: ",count);
            for(k=1;k<=NUM;k++) /*输出结果*/
				printf(" %d",a[k]);
			if(a[NUM-1]<NUM) a[NUM-1]++; /*修改倒数第二位的值*/
			else a[NUM-1]=1;
			i=NUM-1; /*开始寻找下一个足条件的解*/
		}
	}
}
