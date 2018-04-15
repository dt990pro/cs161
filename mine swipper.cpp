/******************************************************
** Program: mines.cpp
** Author: Jiawei Mo
** Date: 3/06/2016
** Description: classic game--mine sweeper
** Input: row, column, mine number, flag
** Output: real time mine map.
******************************************************/
#include<iostream>
#include<ctime>
#include<stdlib.h>

using namespace std;
/**************************************************************************************************************************
** Function: print_map
** Description: to print the present map
** Parameters: None
** Pre-Conditions: 2D-array of map, row, column are int
** Post-Conditions: None
**************************************************************************************************************************/
void print_map(char **map, int r, int c)
{
	for (int i = 0; i < r + 2; i++)
	{
		for (int j = 0; j < c + 2; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
/**************************************************************************************************************************
** Function: go_to_delete
** Description: to delete map and map_backup
** Parameters: None
** Pre-Conditions: 2D-array of map, row int
** Post-Conditions: map and map_backup are deleted
**************************************************************************************************************************/
void go_to_delete(char **x, int r)
{
	for (int i = 0; i < r + 2; i++)
	{
		delete[] x[i];
	}
	delete[] x;
}
/**************************************************************************************************************************
** Function: xy_store_delete
** Description: to delete xy_store
** Parameters: None
** Pre-Conditions: 2D-array of xy_store, row int
** Post-Conditions: xy_store is deleted
**************************************************************************************************************************/
void xy_store_delete(int **x, int r)
{
	for (int i = 0; i < r + 2; i++)
	{
		delete[] x[i];
	}
	delete[] x;
}
/**************************************************************************************************************************
** Function: generate_x_y_storage
** Description: to generate 1D-array according to r or c and store 0 inside
** Parameters: None
** Pre-Conditions: 2D-array of row or column, row and column number is int
** Post-Conditions: array generated
**************************************************************************************************************************/
void generate_x_y_storage(int **z_store, int x, int y)
{
	for (int i = 0; i < x + 2; i++)
	{
		for (int j = 0; j < y + 2; j++)
		{
			z_store[i][j] = 0;
		}
	}
}
/**************************************************************************************************************************
** Function: x_y_repeated
** Description: to check if the position has been opened
** Parameters: None
** Pre-Conditions: 2D-array of row and column, address of row and column number, address of track number k
** Post-Conditions: new open row and colunm number stored
**************************************************************************************************************************/
void x_y_repeated(int **xy_store, int &x, int &y, int &k)
{
	if (k > 1)
	{
		while (xy_store[x][y] != 0)
		{
			cout << "you already opened this position." << endl;
			cout << "(r, c)" << endl;
			cout << "r: ";
			cin >> x;
			cout << "c: ";
			cin >> y;
		}
		xy_store[x][y] = 1;
	}
}
/**************************************************************************************************************************
** Function: x_y_storage
** Description: to store 0 in each row and column 1D-array
** Parameters: None
** Pre-Conditions: 2D-array of row and column, address of row and column number, address of track number k, 
**					row and column num are int
** Post-Conditions: new open row and colunm number stored
**************************************************************************************************************************/
void x_y_storage(int **xy_store, int &x, int &y, int r, int c, int &k)
{
	while (!((x >= 1 && x <= r) && (y >= 1 && y <= c)))
	{
		cout << "outside map." << endl;
		cout << "(r, c)" << endl;
		cout << "r: ";
		cin >> x;
		cout << "c: ";
		cin >> y;
	}
	if (k == 0)
	{
		generate_x_y_storage(xy_store, r, c);
		xy_store[x][y] = 1;
	}
	k = k + 1;
	x_y_repeated(xy_store, x, y, k);
}
/**************************************************************************************************************************
** Function: howman_mines
** Description: to count how many mines around the position
** Parameters: None
** Pre-Conditions: 2D-array of map's backup, open row and column num and count num are int
** Post-Conditions: count num may change
**************************************************************************************************************************/
int howman_mines(char **map_backup, int x, int y, int count)
{
	if (map_backup[x - 1][y - 1] == '*') count += 1;
	if (map_backup[x - 1][y] == '*') count += 1;
	if (map_backup[x - 1][y + 1] == '*') count += 1;
	if (map_backup[x][y - 1] == '*') count += 1;
	if (map_backup[x][y + 1] == '*') count += 1;
	if (map_backup[x + 1][y - 1] == '*') count += 1;
	if (map_backup[x + 1][y] == '*') count += 1;
	if (map_backup[x + 1][y + 1] == '*') count += 1;

	return count;
}
/**************************************************************************************************************************
** Function: open_auto
** Description: to open 8 spots around the position if there is no mine.
** Parameters: count num of mine is int
** Pre-Conditions: 2D-array of map, 2D-array of map's backup, open row and column num are int, row and column are int, 
** Post-Conditions: some points of 8 spots around the position may opened
**************************************************************************************************************************/
void open_auto(char **map, char **map_backup, int x, int y, int r, int c)
{
	int count = 0;
	if (x == 0 || x == r + 1 || y == 0 || y == c + 1)
	{
		return;
	}

	count = howman_mines(map_backup, x, y, count);

	if (count != 0)
	{
		map[x][y] = char(count + 48);
		map_backup[x][y] = 'o';
		return;
	}
	if (count == 0)
	{
		map[x][y] = char(48);
		map_backup[x][y] = 'o';
	}

	if (map_backup[x - 1][y - 1] == ' ') open_auto(map, map_backup, x - 1, y - 1, r, c);
	if (map_backup[x - 1][y] == ' ') open_auto(map, map_backup, x - 1, y, r, c);
	if (map_backup[x - 1][y + 1] == ' ') open_auto(map, map_backup, x - 1, y + 1, r, c);
	if (map_backup[x][y - 1] == ' ') open_auto(map, map_backup, x, y - 1, r, c);
	if (map_backup[x][y + 1] == ' ') open_auto(map, map_backup, x, y + 1, r, c);
	if (map_backup[x + 1][y - 1] == ' ') open_auto(map, map_backup, x + 1, y - 1, r, c);
	if (map_backup[x + 1][y] == ' ') open_auto(map, map_backup, x + 1, y, r, c);
	if (map_backup[x + 1][y + 1] == ' ') open_auto(map, map_backup, x + 1, y + 1, r, c);
}

void get_ready(char **, char **, int, int, int &, int **, int);
/**************************************************************************************************************************
** Function: mine_check
** Description: to check if the position is mine
** Parameters: bomb track number
** Pre-Conditions: 2D-array of map, 2D-array of map's backup, open row and column num are int, 
**					row, column, mine number are int, 
**					k to evaluate how many times run, 2D-array to store x, y, mine num is int
** Post-Conditions: print bomb if it is
**************************************************************************************************************************/
void mine_check(char **map, char **map_backup, int x, int y, int r, int c, int &k, int **xy_store, int m)
{
	int bomb = 0;

	if (map_backup[x][y] == '*')
	{
		bomb = 1;
		cout << "bbbbbbbbbbbbbbbbbbbbbbbbbbomb!" << endl;
		print_map(map_backup, r, c);
		go_to_delete(map, r);
		go_to_delete(map_backup, r);
		xy_store_delete(xy_store, r);
		return;
	}
	else
	{
		open_auto(map, map_backup, x, y, r, c);
		print_map(map, r, c);
	}

	if (bomb == 0) get_ready(map, map_backup, r, c, k, xy_store, m);
}
/**************************************************************************************************************************
** Function: winner_check
** Description: to check if user wins
** Parameters: int of flag num
** Pre-Conditions: 2D-array of map, 2D-array of map's backup, row, column, mine num, winner num are int,
**					2D-array to store x, y
** Post-Conditions: may print out winning
**************************************************************************************************************************/
void winner_check(char **map, char **map_backup, int r, int c, int m, int &win, int **xy_store)
{
	int F_count = 0;
	print_map(map, r, c);
	for (int i = 0; i < r + 2; i++)
	{
		for (int j = 0; j < c + 2; j++)
		{
			if (map[i][j] == 'F') F_count += 1;
		}
	}

	if (F_count == m)
	{
		cout << "you win!!!" << endl;
		print_map(map_backup, r, c);
		win = 1;
		go_to_delete(map, r);
		go_to_delete(map_backup, r);
		xy_store_delete(xy_store, r);
		return;
	}
}
/**************************************************************************************************************************
** Function: flag
** Description: to insert flag on the position
** Parameters: int of whether user wins
** Pre-Conditions: 2D-array of map, 2D-array of map's backup, open row and column num are int,
**					row, column, mine number are int,
**					k to evaluate how many times run, 2D-array to store x, y, mine num is int
** Post-Conditions: int of whether user wins may change
**************************************************************************************************************************/
void flag(char **map, char **map_backup, int x, int y, int r, int c, int k, int **xy_store, int m)
{
	int win = 0;
	map[x][y] = 'F';
	winner_check(map, map_backup, r, c, m, win, xy_store);
	if (win == 0) get_ready(map, map_backup, r, c, k, xy_store, m);
}
/**************************************************************************************************************************
** Function: get_ready
** Description: ask user flag or open
** Parameters: choice
** Pre-Conditions: 2D-array of map, 2D-array of map's backup, row, column are int,
**					k to evaluate how many times run, 2D-array to store x, y, mine num is int
** Post-Conditions: x, y stored
**************************************************************************************************************************/
void get_ready(char **map, char **map_backup, int r, int c, int &k, int **xy_store, int m)
{
	int choice, x, y;
	cout << "Flag (1) or Open (2): ";
	cin >> choice;
	cout << "(r, c)" << endl;
	cout << "r: ";
	cin >> x;
	cout << "c: ";
	cin >> y;
	x_y_storage(xy_store, x, y, r, c, k);
	if (choice == 1) flag(map, map_backup, x, y, r, c, k, xy_store, m);
	if (choice == 2) mine_check(map, map_backup, x, y, r, c, k, xy_store, m);
}
/**************************************************************************************************************************
** Function: mine_generate
** Description: to generate mine's position
** Parameters: 1D-array of spreaded mine's position
** Pre-Conditions: 2D-array of map, 2D-array of map's backup, row, column, mine number are int
** Post-Conditions: map's backup changed
**************************************************************************************************************************/
void mine_generate(char **map, char **map_backup, int r, int c, int m)
{
	int *mine_line = NULL, mine_spot, mine_spot_backup, track, k = 0, **xy_store = NULL;
	xy_store = new int*[r + 2];

	for (int i = 0; i < r + 2; i++)
	{
		for (int j = 0; j < c + 2; j++)
		{
			xy_store[i] = new int[c + 2];
		}
	}
	mine_line = new int[r * c];
	for (int l = 0; l < r * c; l++)
	{
		mine_line[l] = l;
	}

	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		mine_spot = rand() % (r * c);
		if (i == 0) mine_line[mine_spot] = 999;
		else if (i > 0)
		{
			while (mine_line[mine_spot] == 999)
			{
				mine_spot = rand() % (r * c);
			}
			mine_line[mine_spot] = 999;
		}
		mine_spot_backup = mine_spot % r;
		track = (mine_spot - mine_spot_backup) / r;

		map_backup[mine_spot_backup + 1][track + 1] = '*';
	}
	//delete after finish  
	//print_map(map_backup, r, c);
	get_ready(map, map_backup, r, c, k, xy_store, m);
}
/**************************************************************************************************************************
** Function: map_backup_generate
** Description: generete the map_backup which is same as map
** Parameters: None
** Pre-Conditions: 2D-array of map, 2D-array of map's backup, row and column are int
** Post-Conditions: map_backup generated
**************************************************************************************************************************/
void map_backup_generate(char **map, char **map_backup, int r, int c)
{
	for (int i = 0; i < r + 2; i++)
	{
		map_backup[i] = new char[c + 2];
	}

	for (int i = 0; i < r + 2; i++)
	{
		for (int j = 0; j < c + 2; j++)
		{
			map_backup[i][j] = map[i][j];
		}
	}
}
/**************************************************************************************************************************
** Function: map_generate
** Description: generete the map
** Parameters: None
** Pre-Conditions: 2D-array of map, row and column are int
** Post-Conditions: map generated
**************************************************************************************************************************/
void map_generate(char **map, int r, int c)
{
	for (int i = 0; i < r + 2; i++)
	{
		map[i] = new char[c + 2];
	}

	for (int i = 0; i < r + 2; i++)
	{
		for (int j = 0; j < c + 2; j++)
		{
			if ((i == 0 && j == 0) || (i == r + 1 && j == c + 1))
			{
				map[i][j] = '\\';
			}
			else if ((i == 0 && j == c + 1) || (i == r + 1 && j == 0))
			{
				map[i][j] = '/';
			}
			else if ((i == 0 && (j != 0 && j != c + 1)) || (i == r + 1 && (j != 0 && j != c + 1)))
			{
				map[i][j] = char(j + 48);
			}
			else if (((i != 0 && i != r + 1) && j == 0) || ((i != 0 && i != r + 1) && j == c + 1))
			{
				map[i][j] = char(i + 48);
			}
			else
			{
				map[i][j] = ' ';
			}
		}
	}
}
/**************************************************************************************************************************
** Function: generate
** Description: generete map and map_backup
** Parameters: 2D-array of map, 2D-array of map's backup
** Pre-Conditions: row, column and mine num are int
** Post-Conditions: map and map_backup generated
**************************************************************************************************************************/
void generate(int r, int c, int m)
{
	char **map = NULL, **map_backup = NULL;

	map = new char*[r + 2];
	map_backup = new char*[r + 2];

	map_generate(map, r, c);
	map_backup_generate(map, map_backup, r, c);
	print_map(map, r, c);
	mine_generate(map, map_backup, r, c, m);
}
/**************************************************************************************************************************
** Function: rcm_int_check
** Description: check the row, column, mine num in the command are int
** Parameters: None
** Pre-Conditions: 2D-array of argv, index num of the row or column or mine is int
** Post-Conditions: if it is int, return 1, otherwise return 0
**************************************************************************************************************************/
int rcm_int_check(char **argv, int i)
{
	for (int x = 0; argv[i][x] != '\0'; x++)
	{
		if (!(argv[i][x] >= '0' && argv[i][x] <= '9')) return 0;
	}
	return 1;
}
/**************************************************************************************************************************
** Function: arg_check
** Description: check the command-line satisfies the format
** Parameters: None
** Pre-Conditions: 2D-array of argv, the row num and column num and mine num are int
** Post-Conditions: if it satisfies, return 1, otherwise return 0. and print out each argument in the command-line
**************************************************************************************************************************/
int arg_check(int argc, char **argv, int &r, int &c, int &m)
{
	cout << argc << " arguments." << endl;
	for (int i = 0; i < argc; i++)
	{
		cout << i + 1 << ": " << argv[i] << endl;
	}
	cout << endl;

	if (argc != 7) return 0;

	for (int i = 1; i < argc; i += 2)
	{
		if (argv[i][0] == '-' && argv[i][1] == 'r')
		{
			if (rcm_int_check(argv, i + 1) == 0) return 0;
			if (rcm_int_check(argv, i + 1) == 1) r = atoi(argv[i + 1]);
		}
		else if (argv[i][0] == '-' && argv[i][1] == 'c')
		{
			if (rcm_int_check(argv, i + 1) == 0) return 0;
			if (rcm_int_check(argv, i + 1) == 1) c = atoi(argv[i + 1]);
		}
		else if (argv[i][0] == '-' && argv[i][1] == 'm')
		{
			if (rcm_int_check(argv, i + 1) == 0) return 0;
			if (rcm_int_check(argv, i + 1) == 1) m = atoi(argv[i + 1]);
		}
		else
			return 0;
	}

	if (r == 0 || c == 0 || m == 0 || m > r * c) return 0;
}
/**************************************************************************************************************************
** Function: reset
** Description: input new row num and column num and mine num
** Parameters: the row num and column num and mine num are int
** Pre-Conditions: None
** Post-Conditions: go to generate new game with the new row num and column num and mine num
**************************************************************************************************************************/
void reset()
{
	int r = 0, c = 0, m = 0;

	while (r == 0 || c == 0 || m == 0 || m > r * c)
	{
		cout << "row: ";
		cin >> r;
		cout << "column: ";
		cin >> c;
		cout << "mines: ";
		cin >> m;
		if (r == 0 || c == 0 || m == 0 || m > r * c) cout << "error!!!" << endl;
	}

	generate(r, c, m);
}

int main(int argc, char **argv)
{
	int r = 0, c = 0, m = 0, again, arg;
	arg = arg_check(argc, argv, r, c, m);
	if (arg == 0)
	{
		cout << "invalid command. try again. " << endl;
		return 0;
	}

	generate(r, c, m);
	
	cout << endl << "play again? (1-yes, 2-no) ";
	cin >> again;

	while (again == 1)
	{
		reset();
		cout << endl << "play again? (1-yes, 2-no) ";
		cin >> again;
	}

	if (again == 2) cout << "thanks." << endl;

	return 0;
}
