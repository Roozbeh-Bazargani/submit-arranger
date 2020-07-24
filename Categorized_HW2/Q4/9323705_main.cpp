#include <iostream>

int min(int arr[],size_t n);
int minIndex(int* arr,size_t n);

int main()
{
size_t i{};
int temp{1};
int* arr=NULL;
arr=new int[100];

std::cout<<"Enter your numeric array: "<<std::endl;

while(temp!=0)
{
std::cin>>temp;
arr[i]=temp;
i++;
}
i--;

for (size_t I{};I<i;I++)
std::cout<<arr[I]<<"-";
std::cout<<std::endl;

/////////////////////////////////////////////////main loop
for (size_t j{i-1};j>0;--j)
{

temp=arr[j];

int Index{minIndex(arr,j+1)};
if (arr[Index]!=min(arr,j+1))
std::cout<<" Error in Index"<<std::endl;

arr[j]=min(arr,j+1);

arr[Index]=temp;
std::cout<<"new array= ";
for (size_t I{};I<i ;I++)
std::cout<<arr[I]<<"-";
std::cout<<std::endl;

}

int* oarr=NULL;
oarr=new int[i];



for (size_t I{};I<i ;I++)
oarr[i-I-1]=arr[I];
std::cout<<"final array is= ";
for (size_t I{};I<i ;I++)
std::cout<<oarr[I]<<"-";
std::cout<<std::endl;

}







int min(int* arr,size_t n)//min function
{
int m{arr[0]};
for (size_t i{0};i<n;i++)
{
if (arr[i]<m)
m=arr[i];
}
return m;
}

int minIndex(int* arr,size_t n)//Index of minimum value
{
int m{arr[0]};
size_t I{0};
for (size_t i{0};i<n;i++)
{
    if (arr[i]<m)
    {
    m=arr[i];
    I=i;
    }
}
return I;
}

