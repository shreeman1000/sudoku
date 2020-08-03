#include <stdio.h>
#include <stdlib.h>
int check(int ac[*][*],int,int,int);
void display(int ad[*][*]);
int fill(int af[*][*]);
void main(){
	int a[9][9]={  3,0,0,8,0,1,0,0,2,
					2,0,1,0,3,0,6,0,4,
					0,0,0,2,0,4,0,0,0,
					8,0,9,0,0,0,1,0,6,
					0,6,0,0,0,0,0,5,0,
					7,0,2,0,0,0,4,0,9,
					0,0,0,5,0,9,0,0,0,
					9,0,4,0,8,0,7,0,5,
					6,0,0,1,0,7,0,0,3 };
	display(a);
	getchar();
	fill(a);
	display(a);
}
int check(int ac[9][9],int num,int x,int y){
	int i,j,p,q;
	if(num==0)
	{
		return(1);
	}
	else if (num!=0)
	{
		for(i=0;i<9;i++)
		{
			if(num==ac[x][i] || num==ac[i][y])
			{
				return(0);
			}
		}
		p=((x)/3)*3;
		q=((y)/3)*3;
		for(i=p;i<p+3;i++)
			{
				for(j=q;j<q+3;j++)
				{
					if(num==ac[i][j])
						return(0);
				}
			}
		return(1);
	}
	
}
void display(int ad[9][9]){
	system("cls");
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{	
			if(ad[i][j]!=0)
			printf("%d |",ad[i][j]);
			else if(ad[i][j]==0)
			printf("0 |",ad[i][j]);
		}
		printf("\n");
		for(j=0;j<9;j++)
		{
			printf("__|");
		}
		printf("\n");
	}
}
int fill(int a[9][9]){
	int i,j,k;
	for	(i = 0; i < 9; i++){
		for (j = 0; j < 9; j++){
			if(a[i][j] == 0 ){	
				for (k = 1; k <= 9; k++){
					if(check(a,k,i,j)){
						a[i][j]=k;
						//display(a);
						if(fill(a))
							return 1;
						else//else statement is redundant
							a[i][j]=0;
					}
				}
				return 0;
			}
		}
	}
	return 1;
}
