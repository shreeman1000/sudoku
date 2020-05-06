#include <stdio.h>
int x,y,num;
int check(int ac[*][*]);
void display(int ad[*][*]);
void main()
{
	printf("Default value of each cell is 0 to erase enter value 0\n\n");
	char ovr;
	int a1[9][9];
	int i,j,r;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			printf("(%d,%d)|",i,j);
		}
		printf("\n");
		for(j=1;j<=9;j++)
		{
			printf("_____|");
		}
		printf("\n");
	}
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			a1[i][j]=0;
		}
	}
	for(i=1;i<=81;i++)
	{
		redo:
		printf("Select position to input number- ");
		scanf("%d%d",&x,&y);
		getchar();
		if(num==0)
		{
			a1[x-1][y-1]=0;
		}
		if(x>=1 && x<=9 && y>=1 && y<=9)
		{
			if (a1[x-1][y-1]==0)
			{
				printf("Enter number - ");
				scanf("%d",&num);
				r=check(a1);
				if(r==1)
				{
					a1[x-1][y-1]=num;
				}
				else if(r==0)
				{
					a1[x-1][y-1]==0;
					printf("Number already in row. Redo input.\n");
					goto redo;
				}
				else if(r==2)
				{
					a1[x-1][y-1]==0;
					printf("Number already in column. Redo input.\n");
					goto redo;
				}
				else if(r==3)
				{
					a1[x-1][y-1]==0;
					printf("Number already in box. Redo input.\n");
					goto redo;
				}
			}
			else
			{
				printf("Position filled\n");
				printf("overwrite?\n");
				yn:
				scanf("%c",&ovr);
				if(ovr=='y'|| ovr=='Y')
				{
					printf("Enter number - ");
					scanf("%d",&num);
					r=check(a1);
					if(r==1)
					{
						a1[x-1][y-1]=num;
						display(a1);
						goto redo;
					}
					else if(r==0)
					{
						a1[x-1][y-1]==0;
						printf("Number already in row. Redo input.\n");
						goto redo;
					}
					else if(r==2)
					{
						a1[x-1][y-1]==0;
						printf("Number already in column. Redo input.\n");
						goto redo;
					}
					else if(r==3)
					{
						a1[x-1][y-1]==0;
						printf("Number already in box. Redo input.\n");
						goto redo;
					}
				}
				else if(ovr=='n'|| ovr=='N')
				{
					goto redo;
				}
				else
				{
					printf("Enter y or n.\n");
					getchar();
					goto yn;
				}
			}
		}
		else
		{
			printf("Enter valid position\n");
			goto redo;
		}
		display(a1);
	}
	printf("\n\nCongratulations entered sudoku is correct!!!\n");
}
int check(int ac[9][9])
{
	int i,j,p,q;
	if(num==0)
	{
		return(1);
	}
	else if (num!=0)
	{
		for(i=0;i<9;i++)
		{
			if(num==ac[x-1][i])
			{
				return(0);
			}
			if(num==ac[i][y-1])
			{
				return(2);
			}
		}
		p=(x-1)/3;
		q=(y-1)/3;
		if(p==0 && q==0)
		{
			p=0,q=0;
		}
		else if(p==1 && q==0)
		{
			p=3,q=0;
		}
		else if(p==2 && q==0)
		{
			p=6,q=0;
		}
		else if(p==0 && q==1)
		{
			p=0,q=3;
		}
		else if(p==0 && q==2)
		{
			p=0,q=6;
		}
		else if(p==1 && q==1)
		{
			p=3,q=3;
		}
		else if(p==1 && q==2)
		{
			p=3,q=6;
		}
		else if(p==2 && q==1)
		{
			p=6,q=3;
		}
		else if(p==2 && q==2)
		{
			p=6,q=6;
		}
		for(i=p;i<p+3;i++)
			{
				for(j=q;j<q+3;j++)
				{
					if(num==ac[i][j])
					return(3);
				}
			}
		return(1);
	}
	
}
void display(int ad[9][9])
{
	system("cls");
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{	
			if(ad[i][j]!=0)
			printf("%d |",ad[i][j]);
			else if(ad[i][j]==0)
			printf("  |",ad[i][j]);
		}
		printf("\n");
		for(j=0;j<9;j++)
		{
			printf("__|");
		}
		printf("\n");
	}
}
