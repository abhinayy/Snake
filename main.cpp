#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include"global.h"
#include"util.cpp"
#include"move.cpp"
#include"misc.cpp"

using namespace std;
int main()
{
		GAME g;
		g.init();
		int t;
		char x;
		printf("Enter Y to start the game\n");
		x=getchar();
		if(x== 'y')
		{
			while(1)
			{
				g.print_map();
				t=GetTickCount();
				while(GetTickCount() - t <= g.diff)
				{
						if(kbhit())
						{
							g.inp=getch();
							break;
						}
				}
				g.move();
				system("cls");
		
				
			}
		}
		else
		printf("Exiting\n");
}
