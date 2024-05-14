#include <stdio.h> 
//两堆数字 
int A[50000],B[50000];

int main()
{
    int n1,n2,mid,Max,Min;
    //获取第一堆数 
    printf("请输入第一堆的数字数量（升序排列）："); 
    scanf("%d",&n1);
    for(int i=0;i<n1;++i)
        scanf("%d",&A[i]);
    //获取第二堆数 
    printf("请输入第二堆的数字数量（降序排列）：");     
    scanf("%d",&n2);
    for(int i=0;i<n2;++i)
        scanf("%d",&B[i]);
    //从头遍历第一堆数 
    for(int i=0;i<n1;++i)
    	//二分排序 
        for(Min=0,Max=n2-1,mid=(Max+Min)/2;Min<=Max;mid=(Max+Min)/2)
        {
        	//找到数字相加和为10000时 
            if(A[i]+B[mid]==10000)
            {
                printf("YES");
                return 0;
            }
            //如果和B堆里中值相加大于10000，应从B堆中选取更小的，那B堆的中值的下一个数就是左边界，即最大数 
            else if(A[i]+B[mid]>10000)
                Min=mid+1;
            //如果和B堆里中值相加小于10000，应从B堆中选取更大的，那B堆的中值的上一个数就是右边界，即最小数 
            else
                Max=mid-1;
        }
    //遍历后没找到说明不存在 
    printf("NO");
    return 0;
}
