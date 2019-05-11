#include<iostream>
#include<math.h>
#include<cstdlib>
#include<ctime>
using namespace std;
class sudoku
{
	public:
	sudoku()
	{
		cout<<"-----------WELCOME TO SUDOKU GAME---------------------"<<"\n";
		cout<<"INSTRUCTIONS:"<<"\n";
		cout<<"initially enter size of sudoku which you want to play"<<"\n";
		cout<<"while playing the game you have traverse row-wise"<<"\n";
		cout<<"you are not allowed to choose the random positions"<<"\n";
		cout<<"at each and every stage your game status is displayed"<<"\n";
		cout<<"after your every entry you will recieve a message based on your answer"<<"\n";
		cout<<"----------------------------------------------------------"<<"\n";
		cout<<"************START GAME :) ********************************"<<"\n";
		
	}
	void game()
	{
		int n,i,j,m,p1,p2;
		int ans,count=0;
		char s=' ';
		cout<<"enter the size of sudoku";
		cin>>n;
		int arr[n];
		int ran[n];
		m=sqrt(n);
		int a[n][n],b[n][n];
		int ib,in;
		for(i=0;i<n;i++)
		{
			arr[i]=i+1;
		}
		for(j=0;j<n;j++)
		{
			a[0][j]=arr[j];
		}
		for(i=1;i<n;i++)
		{
			ib=a[i-1][0]-1;
			in=0;
			for(j=0;j<n;j++,ib++)
			{
				if(i%m==0)
				{
					in=ib+((n/m)+1);
				}
				else
				{
				in=ib+(n/m);
				}
				while(in>=n)
				{
					in=in-n;
				}
				a[i][j]=arr[in];
			}
		}
		srand(time(NULL));
		for(i=0;i<n;i++)
		{
			ran[i]=rand()%n+1;//max+min
		}
	
		for(i=0;i<n;i++)
		{
			
			for(j=0;j<n;j++)
			{
				if(i==ran[j])
				{
					
					b[i][j]=a[i][j];
					cout<<b[i][j]<<"|";
				}
				else
				{
					
					b[i][j]=s-'0';
					cout<<s<<"|";
					
				}
			}
			cout<<"\n";
			for(int k=0;k<n;k++)
			{
				cout<<"-|";
			}
			cout<<"\n";
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
	
				if(b[i][j]==s-'0')
				{
				
					cout<<"enter your answer";
					cin>>ans;
					if(ans>n||ans<=0)
					{
						cout<<"plzz enter a valid answer"<<"\n";
						count=10;
					}
					p1=i;
					p2=j;
					for(int t=0;t<n;t++)
					{
						if(ans==b[p1][t]||ans==b[t][p2])
						{
							cout<<"wrong entry:("<<"\n";
							count++;
							break;
						}
					}
					if(count==0)               
					{
						int k1,k2,ic,jc,istart,iend,jstart,jend,pi,pj,i1,j1;
						ic=jc=0;
						k1=k2=0;
						while(k1<m&&ic==0)
						{
							pi=m+(k1*m);
							if(p1<pi)
							{
								istart=pi-m;
								iend=pi;
								ic++;
							}
							else
							{
									k1++;
							}
						}
						while(k2<m&&jc==0)
						{
							pj=m+(k2*m);
							if(p2<pj)
							{
								jstart=pj-m;
								jend=pj;
								jc++;
							}
							else
							{
								k2++;
							}
						}
						for(i1=istart;i1<iend;i1++)
						{
							for(j1=jstart;j1<jend;j1++)
							{
								if(ans==b[i1][j1])
								{
											cout<<"with in the matrix once check your answer"<<"\n";
											cout<<"wrong entry--"<<"\n";
											count++;
											break;
								}
							}
						}

					
					
					}
					if(count==0)
					{
						cout<<"right entry move ahead:)"<<"\n";
						b[i][j]=ans;
						for(int i2=0;i2<n;i2++)
						{
							for(int j2=0;j2<n;j2++)
							{
								if(b[i2][j2]!=s-'0')
								{
									cout<<b[i2][j2]<<"|";
								}
								else
								{
								
									cout<<' '<<"|";
								}
							}
							cout<<"\n";
							for(int k=0;k<n;k++)
							for( k=0;k<n;k++)
							{
								cout<<"-|";
							}
							cout<<"\n";
					 
						}
					}
					if(count>=1)
					{
						
						cout<<"try again";
						j--;
						count=0;
					}
				}
			}
		}
		if(i>=n&&j>=n)
		{
			cout<<"--------------------END OF THE GAME :)----------------"<<"\n";
		}
		
	}
};
int main()
{
	sudoku obj;
	obj.game();
}
