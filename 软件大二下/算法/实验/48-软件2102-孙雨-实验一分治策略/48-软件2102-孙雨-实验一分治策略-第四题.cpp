#include <stdio.h> 
//�������� 
int A[50000],B[50000];

int main()
{
    int n1,n2,mid,Max,Min;
    //��ȡ��һ���� 
    printf("�������һ�ѵ������������������У���"); 
    scanf("%d",&n1);
    for(int i=0;i<n1;++i)
        scanf("%d",&A[i]);
    //��ȡ�ڶ����� 
    printf("������ڶ��ѵ������������������У���");     
    scanf("%d",&n2);
    for(int i=0;i<n2;++i)
        scanf("%d",&B[i]);
    //��ͷ������һ���� 
    for(int i=0;i<n1;++i)
    	//�������� 
        for(Min=0,Max=n2-1,mid=(Max+Min)/2;Min<=Max;mid=(Max+Min)/2)
        {
        	//�ҵ�������Ӻ�Ϊ10000ʱ 
            if(A[i]+B[mid]==10000)
            {
                printf("YES");
                return 0;
            }
            //�����B������ֵ��Ӵ���10000��Ӧ��B����ѡȡ��С�ģ���B�ѵ���ֵ����һ����������߽磬������� 
            else if(A[i]+B[mid]>10000)
                Min=mid+1;
            //�����B������ֵ���С��10000��Ӧ��B����ѡȡ����ģ���B�ѵ���ֵ����һ���������ұ߽磬����С�� 
            else
                Max=mid-1;
        }
    //������û�ҵ�˵�������� 
    printf("NO");
    return 0;
}
