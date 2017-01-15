void GAME::moveHead()
{
		switch(hd)
		{
				case 'd': if(inp == 'w' || inp == 's')
							hd=inp;
							mp[hy][hx].d=hd;
							//printf("moveHead r hd = %c\n",hd);
							break;
				case 'a': if(inp == 'w' || inp == 's')
							hd=inp;
							mp[hy][hx].d=hd;
							//printf("moveHead l hd = %c\n",hd);
							break;
				case 'w': if(inp == 'a' || inp == 'd')
							hd=inp;
							mp[hy][hx].d=hd;
							//printf("moveHead u hd = %c\n",hd);
							break;
				case 's': if(inp == 'a' || inp == 'd')
							hd=inp;
							mp[hy][hx].d=hd;
							//printf("moveHead r hd = %c\n",hd);
							break;
				default : printf("break from moveHead\n");
							exit(1);							
		}
		
		switch(hd)
		{
			case 'd':  hx++;
					   break;	   
		    case 'a':  hx--;
					   break;
			case 'w':  hy--;
					   break;
			case 's':  hy++;
					   break;
			default :printf("break from headpos change\n");
					 exit(1);		   						
		}
}

void GAME::moveTail()
{
		switch(mp[ty][tx].d)
		{
				case 'd': /*mp[tx+1][ty].v+=mp[tx][ty].v;
						  mp[tx][ty].v-=1;*/
						  mp[ty][tx].d=NULL;
						  tx++;
						  break;
				case 'a': /*mp[tx-1][ty].v+=mp[tx][ty].v;
						  mp[tx][ty].v-=1;*/
						  mp[ty][tx].d=NULL;
						  tx--;
						  break;
				case 'w': /*mp[tx][ty-1].v+=mp[tx][ty].v;
						  mp[tx][ty].v-=1;*/
						  mp[ty][tx].d=NULL;
						  ty--;
						  break;
				case 's': /*mp[tx][ty+1].v+=mp[tx][ty].v;
						  mp[tx][ty].v-=1;*/
						  mp[ty][tx].d=NULL;
						  ty++;
						  break;	
				default:  printf("break moveTail\n");
							exit(1);	
		}
}

void GAME::moveBody()
{
		for(int y=0;y<SIZE;y++)
		{
				for(int x=0;x<SIZE;x++)
				{
					switch(mp[y][x].d)
					{
							case 'd': mp[y][x].v--;
									  mp[y][x+1].v++;
									  //printf("moveBody r x= %d y =%d\n",x,y);
									  break;
							case 'a': mp[y][x].v--;
									  mp[y][x-1].v++;
									   //printf("moveBody l x= %d y =%d\n",x,y);
									  break;
							case 'w': mp[y][x].v--;
									  mp[y-1][x].v++;
									   //printf("moveBody u x= %d y =%d\n",x,y);
									  break;			  										  	 
							case 's': mp[y][x].v--;
									  mp[y+1][x].v++;
									   //printf("moveBody d x= %d y =%d\n",x,y);
									  break;
							case NULL : break;
							
							default: printf("break from moveBody\n");
										exit(1);
					}
				}	
		}
}

void GAME::move()
{
	
			moveHead();
			moveBody();
			moveTail();
			if(hx == fx && hy == fy)
			{
				mp[hy][hx].v=1;
				addNode();
				genFood();
			}
}
