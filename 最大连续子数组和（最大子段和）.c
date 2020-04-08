#include <stdio.h>
#include <stdlib.h>

int  Max(int n,int a[])
{
    int i;
	int sum=0;
	int max=0;
	    for(i=0;i<n;i++)
    {
		sum+=a[i];
		if(sum<0)
            sum=0;
        else
        {
            if(max<sum)
                max=sum;
        }
	}
	return max;
}
int main()
{
	int n,a[1000],max=0,i;
	scanf("%d",&n);
	if (n<=0)
        printf("error 请输入n为正数");
    else
	{
	    for(i=0;i<n;i++)
		scanf("%d",&a[i]);
        max=Max(n,a);
	    printf("%d\n",max);
	}
    return 0;
}
