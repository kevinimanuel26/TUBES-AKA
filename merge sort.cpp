#include <iostream>

using namespace std;

int a[50];

void merge(int,int,int);
void merge_sort(int low,int high)
{
 int mid;
 if(low<high)
 {
  mid=(low+high)/2;
  merge_sort(low,mid);
  merge_sort(mid+1,high);
  merge(low,mid,high);
 }
}
void merge(int low,int mid,int high)
{
 int h,i,j,b[50],k;
 h=low;
 i=low;
 j=mid+1;
 while((h<=mid)&&(j<=high))
 {
  if(a[h]<=a[j])
  {
   b[i]=a[h]; h++;
  }
  else
  {
   b[i]=a[j]; j++;
  } i++;
 }
 if(h>mid)
 {
  for(k=j;k<=high;k++)
  {
   b[i]=a[k]; i++;
  }
 }
 else
 {
  for(k=h;k<=mid;k++)
  {
   b[i]=a[k]; i++;
  }
 }
 for(k=low;k<=high;k++)
  a[k]=b[k];
}
main()
{
 int num,i;
 cout<<"Masukkan Banyak Bilangan: ";cin>>num;
 cout<<endl;
 cout<<"Sekarang masukkan "<< num <<" Bilangan yang ingin Diurutkan :"<<endl;
 for(i=1;i<=num;i++)
 {
  cout<<"Bilangan ke- "<<i<<" ";cin>>a[i] ;
 }
 merge_sort(1,num);
 cout<<endl;
 cout<<"Hasil akhir pengurutan :"<<endl;
 cout<<endl;
 for(i=1;i<=num;i++)
  cout<<a[i]<<" ";
 cout<<endl<<endl<<endl<<endl;
 }
