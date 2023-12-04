#include <stdio.h>

void merge(int a[],int l,int r,int mid,int n){//归并的"治"的过程，将两个有序序列合并为1个有序序列
//l->最左边的元素下标,r->最右边的元素下标,mid->中间元素下标,temp[]是临时数组,n是a[]长度 
	int temp[n];
	int i=l;//左序列指针 
	int j=mid+1;//右序列指针 
	int k=0;//临时数组指针 
	while(i<=mid&&j<=r){
		if(a[i]<=a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	while(i<=mid){//将左边剩余元素填充进temp中 
		temp[k++]=a[i++];
	}
	while(j<=r){//将右边剩余元素填充进temp中
		temp[k++]=a[j++];
	}
	k=0;
	//将temp中的元素全部拷贝到原数组中
	while(l<=r)
		a[l++]=temp[k++];
}

void merge_sort(int a[],int l,int r){//归并排序，“分而治之”的过程，递归实现
	if(l>=r)//保证l是左边，r是右边 n是a[]长度 
	return ;
	
	int mid=(l+r)/2;
	//将序列分为两个序列，分别排序 
	merge_sort(a,l,mid);//左边归并排序，使左子序列有序 
	merge_sort(a,mid+1,r);//右边归并排序，使右子序列有序 
	merge(a,l,r,mid,r-l+1);//将两个有序子序列合并 
}
int main(){
	int a[105],n,i;
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	merge_sort(a,0,n-1);
	
	for(i=0;i<n;i++)
	printf("%d",a[i]);
	
	return 0;
}
