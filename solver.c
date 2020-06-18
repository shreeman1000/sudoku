#include <stdio.h>
#include <stdlib.h>
int x,y,num;
int check(int ac[*][*]);
void display(int ad[*][*]);
int fill(int af[*][*]);
void main(){
	int a1[9][9]={  3,0,0,8,0,1,0,0,2,
			2,0,1,0,3,0,6,0,4,
			0,0,0,2,0,4,0,0,0,
			8,0,9,0,0,0,1,0,6,
			0,6,0,0,0,0,0,5,0,
			7,0,2,0,0,0,4,0,9,
			0,0,0,5,0,9,0,0,0,
			9,0,4,0,8,0,7,0,5,
			6,0,0,1,0,7,0,0,3 };
	display(a1);
	getchar();
	fill(a1);
	display(a1);
}
int check(int ac[9][9]){
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
		p*=3;
		q=(y-1)/3;
		q*=3;
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
int fill(int af[9][9]){
	int i,j;
	int l,r=1,c=0;
	int n=0,p,q;
	int a=2;
	for(p=1;p<=9;p++){
		for(q=1;q<=9;q++){
			if(af[p-1][q-1] == 0){
				//printf("%d %d %d\n",p,q,af[p-1][q-1]);
				//getchar();
				goto a;
			}
		}
	}
	a:
	loop:
	//printf("%d %d %d\n",p,q,af[p-1][q-1]);
	//getchar();
	for(;n<9;){
		n++;
		num=n,x=p,y=q;
		r=check(af);
		if(r==1){
			//printf("check pass\n");
			//getchar();
			af[p-1][q-1]=n;
			//display(af);
			//getchar();
			break;
		}
		else{
			//printf("check fail num =%d\n",n);
		}
	}
	if(r==1){
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				if(af[i][j]!=0){
					c++;
				}
			}
		}
		if(c==81)
			return 0;
		else{
			//printf("going to new cell\n");
			a=fill(af);
			//printf("a=%d\n",a);
		}
	}
	if(a==1){
		if(n==9){
			af[p-1][q-1]=0;
			n=0;
			return 1;
		}
		//printf("backtracking :(\n");
		goto loop;
	}
	if(r!=1){
		//printf("r!=1 for position %d %d\n",p,q);
		return 1;
	}
	if(a==0){
		return 0;
	}
}
