#include <stdio.h>
 #include <stdlib.h>
 #include <sys/time.h>
 #include <time.h>

 void fnGenRandInput(int [], int);
 void fnDispArray( int [], int);
 void fnInsertionSort(int [], int);


int main( int argc, char **argv)
 {
 FILE *fp;
 struct timeval tv;
 double dStart,dEnd;
 int iaArr[500000],iNum,i,iChoice;
 for(;;)
 {
 printf("\n1.Plot the Graph\n2.Insertion Sort\n3.Exit");
 printf("\nEnter your choice\n");
 scanf("%d",&iChoice);
 switch(iChoice)
 {
 case 1:
 fp = fopen("InsertPlot.dat","w");

 for(i=100;i<10000;i+=100)
 {
 fnGenRandInput(iaArr,i);
 gettimeofday(&tv,NULL);
 dStart = tv.tv_sec + (tv.tv_usec/1000000.0);
 fnInsertionSort(iaArr,i);
 gettimeofday(&tv,NULL);
 dEnd = tv.tv_sec + (tv.tv_usec/1000000.0);
 fprintf(fp,"%d\t%lf\n",i,dEnd-dStart);
 }
 fclose(fp);


printf("\nData File generated and stored in file < InsertPlot.dat>.\n Use a plotting utility\n");
 break;

 case 2:
 printf("\nEnter the number of elements to sort\n");
 scanf("%d",&iNum);
 printf("\nUnsorted Array\n");
 fnGenRandInput(iaArr,iNum);
 fnDispArray(iaArr,iNum);
 fnInsertionSort(iaArr,iNum);
 printf("\nSorted Array\n");
 fnDispArray(iaArr,iNum);
 break;

 case 3: exit(0);
 }
 }
 return 0;
 }
void fnInsertionSort(int A[],int n)
 {
 int i, j, iKey;
 for(i=1;i<n;i++)
 {
 iKey = A[i];
 j = i-1;
 while(j>=0 && A[j] > iKey)
 {
 A[j+1] = A[j];
 j--;
 }
 A[j+1] = iKey;
 }
 }

void fnGenRandInput(int X[], int n)
 {
 srand(time(NULL));
 for(int i=0;i<n;i++)
 {
 X[i] = rand()%10000;
 }
 }

void fnDispArray( int X[], int n)
 {
 for(int i=0;i<n;i++)
 printf(" %5d \n",X[i]);

 }
