void GAME::addNode()
{
		if(mp[ty+1][tx].v == 0)
		{
		//	printf("Adding down\n");
			ty++;
			l++;
			if(l%SP == 0)
			diff/=2;
			mp[ty][tx].v=1;
			mp[ty][tx].d='w';
		}
		else if(mp[ty-1][tx].v == 0)
		{
			//	printf("Adding up\n");
				l++;
				if(l%SP == 0)
				diff/=2;
				ty--;
				mp[ty][tx].v=1;
				mp[ty][tx].d='s';
		}
		else if(mp[ty][tx+1].v == 0)
		{
			//	printf("Adding right\n");
				l++;
				tx++;
				if(l%SP == 0)
				diff/=2;
				mp[ty][tx].v=1;
				mp[ty][tx].d='a';
		}
		else if(mp[ty][tx-1].v == 0)
		{
			//	printf("Adding left\n");
				tx--;
				l++;
				if(l%SP == 0)
				diff/=2;
				mp[ty][tx].v=1;
				mp[ty][tx].d='d';
		}
}

void GAME::genFood()
{
		fx=rand()%SIZE;
		fy=rand()%SIZE;
		
		while(mp[fy][fx].v != 0)
		{
			fx=rand()%SIZE;
			fy=rand()%SIZE;
		}
		mp[fy][fx].v=5;
}
