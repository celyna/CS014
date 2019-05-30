#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>

using namespace std;

const int NUMBER_SIZE = 50000;

//worked with vikhyath avantsa and rohan badiga

int genRandInt(int low, int high) 
{

return (low+rand()%(high-low+1));

}

//function to fill array of random numbers

void fillArray(int arr1[], int arr2[], int arr3[])
{

int i;

for(i=0;i<NUMBER_SIZE; i++) 
{
arr1[i]=genRandInt(0, NUMBER_SIZE);

arr2[i]= arr1[i];

arr3[i]= arr2[i];

}

}

//function to display array elements

void displayOutput(int numbers[NUMBER_SIZE], int NUMBER_SIZE)

{

int i;

cout<<endl<<"Array elements are:"<<endl;

for(i=0;i<NUMBER_SIZE;i++)

{

cout<<" "<<numbers[i];

}

}

//Quicksort_midpoint function

void Quicksort_midpoint(int numbers[NUMBER_SIZE], int i, int k)

{

if(k==i+1)

{

if(numbers[i]>numbers[k])

{

int temp;

temp=numbers[i];

numbers[i]=numbers[k];

numbers[k]=temp;

}

return;

}

if(i>=k)

return;

int pivot=numbers[i+(k-i)/2];

//cout<<endl<<"pivot: "<<pivot<<" i:"<<i<<" k:"<<k;

//getchar();

int l=i-1;

int r=k+1;

while(l<=r)

{

do

{

l++;

}while(numbers[l]<pivot && l<=r );

do

{

r--;

}while(numbers[r]>pivot && l<=r);

if(l<=r)

{

int temp;

temp=numbers[l];

numbers[l]=numbers[r];

numbers[r]=temp;

}

}

//displayOutput(numbers,NUMBER_SIZE);

Quicksort_midpoint(numbers,i,r);

Quicksort_midpoint(numbers,r+1,k);

}

//function Quicksort_medianOfThree

void Quicksort_medianOfThree(int numbers[NUMBER_SIZE], int i, int k)

{

if(k==i+1)

{

if(numbers[i]>numbers[k])

{

int temp;

temp=numbers[i];

numbers[i]=numbers[k];

numbers[k]=temp;

}

return;

}

if(i>=k)

return;

int mid=numbers[i+(k-i)/2];

int pivot;

if(numbers[i]<numbers[mid] && numbers[mid]<numbers[k])

pivot=mid;

else if(numbers[i]<numbers[mid] && numbers[i]>numbers[k])

pivot=i;

else

pivot=k;

//cout<<endl<<"pivot: "<<pivot<<" i:"<<i<<" k:"<<k;

//getchar();

int l=i-1;

int r=k+1;

while(l<=r)

{

do

{

l++;

}while(numbers[l]<pivot && l<=r );

do

{

r--;

}while(numbers[r]>pivot && l<=r);

if(l<=r)

{

int temp;

temp=numbers[l];

numbers[l]=numbers[r];

numbers[r]=temp;

}

}

//displayOutput(numbers,NUMBER_SIZE);

Quicksort_midpoint(numbers,i,r);

Quicksort_midpoint(numbers,r+1,k);

}

//function InsertionSort

void InsertionSort(int numbers[NUMBER_SIZE],int NUMBER_SIZE)

{

int i,j,key,count=0;

for(j=1;j<NUMBER_SIZE;j++)

{

key=numbers[j];

i=j-1;

while(i>=0 && numbers[i]>key)

{

numbers[i+1]=numbers[i];

i--;

count++;

}

numbers[i+1]=key;

}

}

//main driver function

int main()

{

int arr1[NUMBER_SIZE],arr2[NUMBER_SIZE],arr3[NUMBER_SIZE];

fillArray(arr1,arr2,arr3);

const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000;

clock_t Start1 = clock();

Quicksort_midpoint(arr1,0,NUMBER_SIZE-1);

//displayOutput(arr1,NUMBER_SIZE);

clock_t End1 = clock();

int elapsedTime1 = (End1 - Start1)/CLOCKS_PER_MS;

cout<<"Quicksort_midpoint algorithm runtime: "<<elapsedTime1<<endl;

clock_t Start2 = clock();

Quicksort_medianOfThree(arr2,0,NUMBER_SIZE);

//displayOutput(arr2,NUMBER_SIZE);

clock_t End2 = clock();

int elapsedTime2 = (End2 - Start2)/CLOCKS_PER_MS;

cout<<"Quicksort_medianOfThree algorithm runtime: "<<elapsedTime2<<endl;

clock_t Start3 = clock();

InsertionSort(arr3,NUMBER_SIZE);

//displayOutput(arr3,NUMBER_SIZE);

clock_t End3 = clock();

int elapsedTime3 = (End3 - Start3)/CLOCKS_PER_MS;

cout<<"InsertionSort algorithm runtime: "<<elapsedTime3<<endl;

}

