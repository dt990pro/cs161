/***********************************************************************************************************
** Program Filename: rover guider.
** Author: Jiawei Mo
** Date: 1/17/2016
** Description: this program will print the path of the rover in a pattern of 4x4 grid.
** Input: s_x, s_y, e_x, e_y, str_1.
** Output: the path from starting position to ending position in a 4x4 grid.
************************************************************************************************************/
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
/***********************************************************************************************************
Function: int_check_0_to_3
Description: a function that can check whether the input is an integer which is in [0, 3].
Parameters: str_1, change
Return: change
Pre-Conditions: none
Post-Conditions: return the inputed integer which is in [0, 3].
************************************************************************************************************/
int int_check_0_to_3()
{
	string str_1;
	int change = 999;

	while (!(change >= 0 && change < 4)) // a loop to ensure that the interval of the input is [0, 3].
	{
		cout << "0-3, integer: ";
		cin >> str_1;
		for (int i = 0; i < str_1.length(); i++) // a loop to ensure that the input is positive integer.
		{
			if (str_1.at(i) < '0' || str_1.at(i) > '9')
			{
				cout << endl << "\aerror! input positive int: ";
				cin >> str_1;
				i = -1;
			}
		}
		cout << endl;
		change = atoi(str_1.c_str());
	}
	return change;
}
/***********************************************************************************************************
Function: x0
Description: to print the location which is (x, 0). x is aninteger in [0. 3].
Parameters: none
Return: none
Pre-Conditions: none
Post-Conditions: none
************************************************************************************************************/
void x0()
{
	cout << "XOOO" << endl;
	return;
}
/***********************************************************************************************************
Function: x1
Description: to print the location which is (x, 1). x is aninteger in [0. 3].
Parameters: none
Return: none
Pre-Conditions: none
Post-Conditions: none
************************************************************************************************************/
void x1()
{
	cout << "OXOO" << endl;
	return;
}
/***********************************************************************************************************
Function: x2
Description: to print the location which is (x, 2). x is aninteger in [0. 3].
Parameters: none
Return: none
Pre-Conditions: none
Post-Conditions: none
************************************************************************************************************/
void x2()
{
	cout << "OOXO" << endl;
	return;
}
/***********************************************************************************************************
Function: x3
Description: to print the location which is (x, 3). x is aninteger in [0. 3].
Parameters: none
Return: none
Pre-Conditions: none
Post-Conditions: none
************************************************************************************************************/
void x3()
{
	cout << "OOOX" << endl;
	return;
}
/***********************************************************************************************************
Function: no
Description: to print horizental line where the rover does not locate.
Parameters: none
Return: none
Pre-Conditions: none
Post-Conditions: none
************************************************************************************************************/
void no()
{
	cout << "OOOO" << endl;
	return;
}
/***********************************************************************************************************
Function: move
Description: to print present position out.
Parameters: s_x, s_y.
Return: none
Pre-Conditions: all parameters are valid integers in [0, 3].
Post-Conditions: no parameters' change and the function will print present position.
************************************************************************************************************/
void move(int s_x, int s_y)
{
	if (s_x == 0 && s_y == 0)
	{
		no();
		no();
		no();
		x0();
		cout << endl;
	}
	else if (s_x == 1 && s_y == 0)
	{
		no();
		no();
		no();
		x1();
		cout << endl;
	}
	else if (s_x == 2 && s_y == 0)
	{
		no();
		no();
		no();
		x2();
		cout << endl;
	}
	else if (s_x == 3 && s_y == 0)
	{
		no();
		no();
		no();
		x3();
		cout << endl;
	}
	else if (s_x == 0 && s_y == 1)
	{
		no();
		no();
		x0();
		no();
		cout << endl;
	}
	else if (s_x == 1 && s_y == 1)
	{
		no();
		no();
		x1();
		no();
		cout << endl;
	}
	else if (s_x == 2 && s_y == 1)
	{
		no();
		no();
		x2();
		no();
		cout << endl;
	}
	else if (s_x == 3 && s_y == 1)
	{
		no();
		no();
		x3();
		no();
		cout << endl;
	}
	else if (s_x == 0 && s_y == 2)
	{
		no();
		x0();
		no();
		no();
		cout << endl;
	}
	else if (s_x == 1 && s_y == 2)
	{
		no();
		x1();
		no();
		no();
		cout << endl;
	}
	else if (s_x == 2 && s_y == 2)
	{
		no();
		x2();
		no();
		no();
		cout << endl;
	}
	else if (s_x == 3 && s_y == 2)
	{
		no();
		x3();
		no();
		no();
		cout << endl;
	}
	else if (s_x == 0 && s_y == 3)
	{
		x0();
		no();
		no();
		no();
		cout << endl;
	}
	else if (s_x == 1 && s_y == 3)
	{
		x1();
		no();
		no();
		no();
		cout << endl;
	}
	else if (s_x == 2 && s_y == 3)
	{
		x2();
		no();
		no();
		no();
		cout << endl;
	}
	else if (s_x == 3 && s_y == 3)
	{
		x3();
		no();
		no();
		no();
		cout << endl;
	}
	
	return;
}
/***********************************************************************************************************
Function: find_path_sub
Description: a function that evaluate the movement vertically.
Parameters: s_x, s_y, e_x, e_y, n.
Return: none
Pre-Conditions: all parameters are valid integers in [0, 3].
Post-Conditions: parameter s_y may change and it will call function move.
************************************************************************************************************/
void find_path_sub(int s_x, int s_y, int e_x, int e_y)
{
	int n;
	if (s_y > e_y)
	{
		n = 1;
	}
	else if (s_y == e_y)
	{
		n = 2;
	}
	else
	{
		n = 3;
	}
	
	switch (n)
	{
	case 1: 
		for (s_y; s_y >= e_y; s_y--)
		{
			move(e_x, s_y);
		}
		break;

	case 2:
		move(e_x, s_y);
		break;

	case 3:
		for (s_y; s_y <= e_y; s_y++)
		{
			move(e_x, s_y);
		}
		break;

	default:
		;
	}
	return;
}
/***********************************************************************************************************
Function: find_path_main
Description: a function that evaluate the movement horizentally.
Parameters: s_x, s_y, e_x, e_y, m.
Return: none
Pre-Conditions: all parameters are valid integers in [0, 3].
Post-Conditions: parameter s_x may change and it will call function move.
************************************************************************************************************/
void find_path_main(int s_x, int s_y, int e_x, int e_y)
{
	int m;
	if (s_x > e_x)
	{
		m = 1;
	}
	else if (s_x == e_x)
	{
		m = 2;
	}
	else
	{
		m = 3;
	}
	
	switch (m)
	{
	case 1: 
		for (s_x; s_x > e_x; s_x--)
		{
			move(s_x, s_y);
		}
		find_path_sub(s_x, s_y, e_x, e_y);
		break;

	case 2:
		find_path_sub(s_x, s_y, e_x, e_y);
		break;

	case 3:
		for (s_x; s_x < e_x; s_x++)
		{
			move(s_x, s_y);
		}
		find_path_sub(s_x, s_y, e_x, e_y);
		break;

	default:
		;
	}
	return;
}
/***********************************************************************************************************
Function: int_check_0_or_3
Description: a function that can check whether the input is an integer which is in [0, 1].
Parameters: str_1, change
Return: change
Pre-Conditions: none
Post-Conditions: return the inputed integer which is in [0, 1].
************************************************************************************************************/
int int_check_0_or_1()
{
	string str_1;
	int change = 999;

	while (!(change == 0 || change == 1)) // a loop to ensure that the interval of the input is 0 or 1.
	{
		cout << "input, 1 or 0: ";
		cin >> str_1;
		for (int i = 0; i < str_1.length(); i++) // a loop to ensure that the input is positive integer.
		{
			if (str_1.at(i) < '0' || str_1.at(i) > '9')
			{
				cout << endl << "\aerror! input positive int: ";
				cin >> str_1;
				i = -1;
			}
		}
		cout << endl;
		change = atoi(str_1.c_str());
	}
	return change;
}

int main()
{
	int s_x, s_y, e_x, e_y, again = 1;

	cout << "rover guider." << endl << endl;

	while (again == 1)
	{
		cout << "input starting x coord" << endl;
		s_x = int_check_0_to_3();
		cout << "input starting y coord" << endl;
		s_y = int_check_0_to_3();
		cout << "input ending x coord" << endl;
		e_x = int_check_0_to_3();
		cout << "input ending y coord" << endl;
		e_y = int_check_0_to_3();
		cout << endl << "comfirm." << endl;
		cout << "starting coord is: (" << s_x << ", " << s_y << ')' << endl;
		cout << "ending coord is: (" << e_x << ", " << e_y << ')' << endl;

		find_path_main(s_x, s_y, e_x, e_y);

		cout << "would you like to run another guider?" << endl;
		again = int_check_0_or_1();
	}
	cout << "thanks for using" << endl;
	return 0;
}