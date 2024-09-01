/* Find triplets whose sum is 0 in an array */
#include<stdio.h>
int main(){
	int a[100],i,j,k,n,flag;
	printf("Enter size of array: ");
	scanf("%d",&n);
	printf("Enter elements of array: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	flag=0;
	for(i=0;i<n-2;i++)
		for(j=i+1;j<n-1;j++)
			for(k=j+1;k<n;k++)
				if(a[i]+a[j]+a[k]==0){
					flag=1;
					printf("%d %d %d\n",a[i],a[j],a[k]);
				}
	if(flag==0)
		printf("There is no such triplet");
	return 0;
}

