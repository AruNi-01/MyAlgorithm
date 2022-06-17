#include<iostream>
using namespace std;

long Partition (int a[], long p1, long p2)
{//对a[p1]~a[p2]进行分割，返回分割点的序号
 long i, j;
 int x;
 i =p1;
 j =p2;
 x =a[i];
 while (i<j)
 {
  while ( a[j]>=x &&  i<j ) j-- ;  //右左扫描
  if (i<j)  {a[i]=a[j]; i++;}
  while (a[i]<=x && i<j ) i++; //左右扫描
  if (i<j) {a[j] =a[i]; j--;}
 }
 a[i]=x;
 return i;
}

long SortQuick(int a[], long p1, long p2)
  {// 对a[p1]~a[p2]中元素排序 
   long p; 
   if (p1<p2) 
   {  
     p = Partition(a, p1,p2); 
     SortQuick(a, p1, p-1); 
     SortQuick(a, p+1, p2);  
     return p2-p1+1;
    }
   return 0;
  } 

void ShellSort(int r[], int n)
{
	int d,i,j,k;
	for( d=1;d<=n/2;d=d*2+1 );
	for( ;d>0; )
	{
		for( i=d;i<n;i++ )
		{
			k=r[i];
			for( j=i-d;j>=0 && k<r[j];j-=d  ) 
				r[j+d]=r[j];
			r[j+d]=k;
		}
		d=(d-1)/2;
	}  
}

int main()
{
	static int p1=1,p2=5;
	int a[5]={6,5,8,11,4},b[5]={6,5,8,11,4};
	cout<<"Raw data: "<<endl;
    for(int i=p1-1;i<p2;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	SortQuick(a,p1-1,p2-1);
	cout<<"Quick sort result: "<<endl;
	for(int i=p1-1;i<p2;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	ShellSort(b,p2-p1+1);
	cout<<"Shell sort result: "<<endl;
	for(int i=p1-1;i<p2;i++)
		cout<<b[i]<<" ";
    cout<<endl;
    system("pause");
    return 0;
}
