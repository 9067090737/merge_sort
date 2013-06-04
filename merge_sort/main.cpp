#include <conio.h>
#include <iostream>
using namespace std;
void input(int*,int);
void output(int*,int);
void MergeSort(int*,int,int);

void MergeSort(int *array,int left, int right)
{
	int middle=(left+right)/2;///@param middle index
	int resulted_size=right-left+1;///@param size of resulted array
	if(resulted_size>2)
	{
		MergeSort(array,left,middle);
		/**@detailed array1: left element - left, right element middle;
		array 2:left element middle+1, right element - right;
		array=array1+array2
		*/
		MergeSort(array,middle+1,right);
		int i = left-left, j = middle+1-left, k = left;
		int *temp=new int[resulted_size];///@brief creation of temporary array
		for (int t = 0, y = left; t < resulted_size; t++, y++)
			temp[t] = array[y];
		for (; (i <= middle-left)&&(j <= (right-left)); k++)
		{
			if (temp[i]<=temp[j])
			{
				array[k] = temp[i];
				i++;
			}
			else
			{
				array[k] = temp[j];
				j++;
			}
		}
		if (i == middle+1)
		{
			for (;(j <= right-left); j++, k++)
				array[k] = temp[j];
		}
		else
		{
			for (; (i <= middle-left); i++, k++)
				array[k] = temp[i];
		}
		delete temp;
	}
	else if (resulted_size== 2)
		{
			if(array[left] > array[right])
			{
				///@brief swap of element if size of array=2
				int temp=array[right];
				array[right]=array[left];
				array[left]=temp;
			}
	}
}
void input(int *array, int size)///@function to input array
{
	int i;
	cout<<"Input array:"<<'\n';
	for (i=0; i<size; i++)
		cin>>array[i];
};
void output(int *array,int size)///@function to print array
{ 
	int i;
	for (i=0; i<size; i++)
		cout<<array[i]<<'\t';
		cout<<endl;
};
int main()
{
	int size; ///@param size размер массива
	cout<<"Input size of array n=";
	cin>>size;
	int *array=new int[size];
	cout<<'\n';
	input(array,size);
	output(array,size);
	cout<<"Sorted array:"<<'\n';
	MergeSort(array,0,size-1);;
	output(array,size);
	getch();
	return 0;
}
