/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int N;
int boards[100][100];
int main(){
    int NQueens(int);
    int is_attacked(int,int);
	int num,i,j;
	printf("Input number is:");
	scanf("%d", &num); 
	printf("\n");// Reading input from STDIN
	       // Writing output to STDOUT
	
	N=num;
	if(NQueens(num))
	{
	    for(i=0;i<N;i++)
	    {
	        for(j=0;j<N;j++)
	        {
	            printf("%d",boards[i][j]);
	        }
	        printf("\n");
	    }
	}
}
int NQueens(int n){
	if(n==0)
	return 1;
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(!is_attacked(i,j)&&boards[i][j]!=1)
			{
			    boards[i][j]=1;
			    if(NQueens(n-1))
			        return 1;
			    boards[i][j]=0;
			}   
		}
	}
	return 0;
}
int is_attacked(int k,int l)
{
    int p,q;
    for(p=0;p<N;p++)
    {
        if(boards[k][p]==1||boards[p][l]==1)
        {
            return 1;
        }
    }
    for(p=0;p<N;p++)
    {
        for(q=0;q<N;q++)
        {
            if((p+q)==(k+l)||(p-q)==(k-l))
            {
                if(boards[p][q]==1)
                return 1;
            }
        }
    }
    return 0;
}
