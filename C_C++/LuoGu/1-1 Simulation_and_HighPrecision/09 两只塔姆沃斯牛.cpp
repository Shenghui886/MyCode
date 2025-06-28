//P1518 [USACO2.4] 两只塔姆沃斯牛 The Tamworth Two

#include<iostream>
#include<string.h>
using namespace std;

char map[12][12];

bool Judge[10][10][4][10][10][4];

struct peo
{
	int x;
	int y;
	int z = 1;
	
	//这个move的x、y坐标容易搞混，切记
	void move()
	{
		if(z == 4)
		{
			if(map[x][y - 1] == '.')
				y--;
			else
				z++;
		}
		else if(z == 3)
		{
			if(map[x + 1][y] == '.')
				x++;
			else
				z++;
		}
		else if(z == 2)
		{
			if(map[x][y + 1] == '.')
				y++;
			else
				z++;
		}
		else
		{
			if(map[x - 1][y] == '.')
				x--;
			else
				z++;
		}
		z = (z - 1) % 4 + 1;
	}
};

int count(peo *man, peo *cow)
{
	int time = 0;
	while(1)
	{
		if(Judge[man->x - 1][man->y - 1][man->z][cow->x - 1][cow->y - 1][cow->z])
			return 0;
		else
		{
			Judge[man->x - 1][man->y - 1][man->z][cow->x - 1][cow->y - 1][cow->z] = true;
			time++;
		}
		cow->move();
		man->move();
		if(man->x == cow->x && man->y == cow->y)
			return time;
	}
}

int main() {
	
	peo man,cow;
	
	memset(map, '*', sizeof map);
	
	for(int i = 1; i <= 10; i++)
		for(int j = 1; j <= 10 ; j++)
		{
			cin >> map[i][j];
			if(map[i][j] == 'F')
				man.x = i, man.y = j, map[i][j] = '.';
			if(map[i][j] == 'C')
				cow.x = i, cow.y = j, map[i][j] = '.';
		}
	
	cout << count(&man, &cow) << endl;
	
	return 0;
}
