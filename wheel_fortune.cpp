/******************************************************
** Program: wheel_fortune.cpp
** Author: Jiawei Mo
** Date: 2/13/2016
** Description:	play the wheel fortune game-rules on
**				the website.
** Input: player num, round num, the message.
** Output: the winner who has the most total
**         or no winner(draw).
******************************************************/
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;
/***********************************************************************************************************
Function: message_a_to_z_and_A_to_Z
Description: check the input whether it only contains letter or space.
Parameters: s-new name of the address of teh passed variable.
Return: None.
Pre-Conditions: passed string.
Post-Conditions: the passed variable gets a string that only has letters or space.
************************************************************************************************************/
void message_a_to_z_and_A_to_Z(string &s)
{
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		if (!((s.at(i) >= 'a' && s.at(i) <= 'z') || (s.at(i) >= 'A' && s.at(i) <= 'Z') || (s.at(i) == ' ')))
		{
			cout << "alphabet only: ";
			getline(cin, s);
			i = -1;
		}
	}
}
/***********************************************************************************************************
Function: int_check
Description: check the input whether it is integer and return the integer value.
Parameters: s-input value, a-the int value.
Return: integer value.
Pre-Conditions: None
Post-Conditions: the input will be integer value.
************************************************************************************************************/
int int_check()
{
	string s;
	int a;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s.at(i) < '0' || s.at(i) > '9')
		{
			cout << "integre please: ";
			cin >> s;
			i = -1;
		}
	}
	a = atoi(s.c_str());
	return a;
}
/***********************************************************************************************************
Function: int_one_to_three
Description: check the integer value whether it is on [1, 3] and return it.
Parameters: x-the integer value
Return: integer value on [1, 3].
Pre-Conditions: x is an integer.
Post-Conditions: x is 1 or 2 or 3.
************************************************************************************************************/
int int_one_to_three()
{
	int x = 0;
	while (x < 1 || x > 3)
	{
		cout << "1-3 required: ";
		x = int_check();
	}
	return x;
}
/***********************************************************************************************************
Function: int_over_zero
Description: check the integer value whether it is over 0 and return it.
Parameters: x-the integer value
Return: integer value and greater than 0.
Pre-Conditions: x is an integer.
Post-Conditions: x is an integer and gigger than 0.
************************************************************************************************************/
int int_over_zero()
{
	int x = 0;
	while (x == 0)
	{
		cout << "greater than 0: ";
		x = int_check();
	}
	return x;
}
/***********************************************************************************************************
Function: mes_swap
Description: swap message to hidden mes.
Parameters: swapper string.
Return: None
Pre-Conditions: message-str.
Post-Conditions: hidden mes changes.
************************************************************************************************************/
void mes_swap(string &s)
{
	string swp;
	for (int i = 0; i < s.length(); i++)
	{
		if (s.at(i) != ' ')
		{
			swp += "_";
		}
		else
		{
			swp += " ";
		}
	}
	s = swp;
	cout << s;
}
/***********************************************************************************************************
Function: one_str
Description: check the input whether it has only one char.
Parameters: string for checking.
Return: the string with one char.
Pre-Conditions: None
Post-Conditions: the input string get returned.
************************************************************************************************************/
string one_str()
{
	string l;
	message_a_to_z_and_A_to_Z(l);
	while (l.length() != 1)
	{
		cout << "one letter: ";
		message_a_to_z_and_A_to_Z(l);
	}
	return l;
}
/***********************************************************************************************************
Function: vo
Description: check the input whether it is a vowel.
Parameters: string for checking.
Return: None.
Pre-Conditions: vowel-str.
Post-Conditions: the input string may change.
************************************************************************************************************/
void vo(string &l)
{
	l = one_str();
	for (int i = 0; i < l.length(); i++)
	{
		if (!(l.at(i) == 'a' || l.at(i) == 'e' || l.at(i) == 'i' || l.at(i) == 'o' || l.at(i) == 'u'))
		{
			cout << "need vowel: ";
			l = one_str();
			i = -1;
		}
	}
}
/***********************************************************************************************************
Function: mes_check
Description: find the hidden mes through guessing a letter and replace the hidden char with matched char.
Parameters: None.
Return: None.
Pre-Conditions: guess letter-str, message-str, hidden mes-str, matched letter num-int, random num-int.
Post-Conditions: hidden mes and matched letter num and random num may change.
************************************************************************************************************/
void mes_check(string s, string mes, string &mes_none, int &letter_num, int &x)
{
	for (int i = 0; i < mes.length(); i++)
	{
		if ((s.at(0) == mes.at(i)) || (s.at(0) + 32 == mes.at(i)) || (s.at(0) - 32 == mes.at(i)))
		{
			letter_num += 1;
			mes_none.at(i) = mes.at(i);
		}
	}
	if (letter_num == 0)
	{
		x = 0;
	}
	cout << endl << "find " << letter_num << endl;
}
/***********************************************************************************************************
Function: case_1
Description: spin it.
Parameters: matched letter num, gusee letter, random num.
Return: total.
Pre-Conditions: message-str, hidden mes-str, total-int, random num-int.
Post-Conditions: return each player's total.
************************************************************************************************************/
int case_1(string mes, string &mes_none, int total, int &x)
{
	int letter_num = 0;string letter;srand(time(NULL));x = rand() % 22;
	if (x > 0 && x < 21)
	{
		cout << "landed on " << x << endl;cout << "guess a letter. ";
		letter = one_str();
		mes_check(letter, mes, mes_none, letter_num, x);
		total += x * letter_num;
		cout << "total: $" << total << endl << mes_none << endl;return total;
	}
	else if (x = 0)
	{
		cout << "landed on 0, delete earning, lose turn." << endl;return total = 0;
	}
	else
	{
		cout << "landed on 21, lose turn." << endl;return total;
	}
}
/***********************************************************************************************************
Function: case_2
Description: check guess message whether it is correct.
Parameters: guess message.
Return: None
Pre-Conditions: message-str, random num-int.
Post-Conditions: random num will change.
************************************************************************************************************/
void case_2(string mes, int &x, int &end)
{
	string gue_mes;
	cin.ignore();
	cout << "your message is: ";
	message_a_to_z_and_A_to_Z(gue_mes);
	if (gue_mes == mes)
	{
		cout << "you win!!!!!!!!!!!!!!!!!!" << endl;
		end = 1;
	}
	else
	{
		cout << "not correct!!!!!!!!!!!!!!!!!!" << endl;
	}
	x = 21;
}
/***********************************************************************************************************
Function: vowel_check
Description: check the vowel with each char in the message. if nothing matched, player loses turn.
Parameters: number that how many vowel matched.
Return: None
Pre-Conditions: message-str, hidden mes-str, vowel-str, random num-int.
Post-Conditions: hidden mes and random num may change.
************************************************************************************************************/
void vowel_check(string mes, string &mes_none, string &s, int &x)
{
	int c = 0;
	for (int i = 0; i < mes.length(); i++)
	{
		if ((s.at(0) == mes.at(i)) || (s.at(0) + 32 == mes.at(i)) || (s.at(0) - 32 == mes.at(i)))
		{
			mes_none.at(i) = mes.at(i);
			c += 1;
		}
	}
	if (c == 0)
	{
		cout << "no " << s << endl;
		x = 21;
	}
}
/***********************************************************************************************************
Function: case_3
Description: spend $10 on guessing a vowel.
Parameters: vowel.
Return: total.
Pre-Conditions: message-str, hidden mes-str, total-int, random num-int.
Post-Conditions: return each player's total.
************************************************************************************************************/
int case_3(string mes, string &mes_none, int total, int &x)
{
	string vowel;
	if (total < 10)
	{
		cout << "$10 needed." << endl;
		return total;
	}
	cout << "your vowel. ";
	vo(vowel);
	vowel_check(mes, mes_none, vowel, x);
	total -= 10;
	cout << "total: $" << total << endl << mes_none << endl;
	return total;
}
/***********************************************************************************************************
Function: each_player
Description: check each player's choice and bring them to the part of the game.
Parameters: player's choice.
Return: total.
Pre-Conditions: message-str, hidden mes-str, total-int, random num-int.
Post-Conditions: return each player's total.
************************************************************************************************************/
int each_player(string mes, string &mes_none, int total, int &x, int &end)
{
	cout << "Do you want to spin (1), solve the puzzle (2), or buy a vowel (3). ";
	int choice = int_one_to_three();
	switch (choice)
	{
	case 1:
		total = case_1(mes, mes_none, total, x);
		break;
	case 2:
		case_2(mes, x, end);
		break;
	case 3:
		total = case_3(mes, mes_none, total, x);
		break;
	default:
		break;
	}

	return total;
}
/***********************************************************************************************************
Function: each_player_fate
Description: run each player's turn.
Parameters: random num.
Return: total.
Pre-Conditions: message-str, hidden mes-str, total-int.
Post-Conditions: return each player's total.
************************************************************************************************************/
int each_player_fate(string mes, string &mes_none, int total, int &end)
{
	int x = 1;
	while (x > 0 && x < 21)
	{
		total = each_player(mes, mes_none, total, x, end);
	}
	return total;
}
/***********************************************************************************************************
Function: print_earn
Description: to print out each player's total and reset player's total to 0 expect winner's.
Parameters: player num, winner num, each player's total.
Return: None
Pre-Conditions: player num-int, winner num-int, each player's total-int.
Post-Conditions: some players' total may change.
************************************************************************************************************/
void print_earn(int *earn, int &i, int player)
{
	cout << endl << "result: " << endl;
	for (int x = 0; x < player; x++)
	{
		if (x != i)
		{
			earn[x] = 0;
		}
	}
	for (int x = 0; x < player; x++)
	{
		cout << "player#" << x + 1 << " : $" << earn[x] << endl;
	}
}
/***********************************************************************************************************
Function: run
Description: run the wheel of fortune game.
Parameters: total, hidden mes.
Return: None
Pre-Conditions: message-str, player num-int, round num-int
Post-Conditions: store each player's total.
************************************************************************************************************/
void run(string mes, int player, int round, int *earn)
{
	int total, i, end = 0, end_check = 0;string mes_none = mes;
	cout << endl << "the message is : ";mes_swap(mes_none);
	while (end_check == 0)
	{
		for (i = 0; i < player; i++)
		{
			total = 0;
			cout << endl << "player#" << i + 1 << endl;
			total = each_player_fate(mes, mes_none, total, end);
			cout << endl << "player#" << i + 1 << " earns $" << total << endl;
			earn[i] += total;
			if (end == 1)
			{
				end_check = 1;
				break;
			}
		}
	}
	cout << "winner of this round: player#" << i + 1 << ", earning $" << earn[i] << endl;print_earn(earn, i, player);
}
/***********************************************************************************************************
Function: win2
Description: to find out the winner when there are 2 players.
Parameters: each player's total.
Return: None
Pre-Conditions: each player's total-int.
Post-Conditions: None
************************************************************************************************************/
void win2(int *sum)
{
	int x = sum[0] - sum[1];
	if (x > 0)
	{
		cout << "final winner: player#1, earning $" << sum[0] << endl;
	}
	else if (x == 0)
	{
		cout << "draw" << endl;
	}
	else
	{
		cout << "final winner: player#2, earning $" << sum[1] << endl;
	}
}
/***********************************************************************************************************
Function: win3
Description: to find out the winner when there are 3 players.
Parameters: each player's total.
Return: None
Pre-Conditions: each player's total-int.
Post-Conditions: None
************************************************************************************************************/
void win3(int *sum)
{
	int x = sum[0], y = sum[1], z = sum[2];
	if (x > y && x > z)
	{
		cout << "final winner: player#1, earning $" << sum[0] << endl;
	}
	else if (y > x && y > z)
	{
		cout << "final winner: player#2, earning $" << sum[1] << endl;
	}
	else if (z > x && z > y)
	{
		cout << "final winner: player#3, earning $" << sum[2] << endl;
	}
	else
	{
		cout << "no winner" << endl;
	}
}
/***********************************************************************************************************
Function: winner
Description: to find out the winner.
Parameters: player num, each player's total.
Return: None
Pre-Conditions: player num-int, each player's total-int.
Post-Conditions: None
************************************************************************************************************/
void winner(int *sum, int player)
{
	switch (player)
	{
	case 1:
		cout << endl << "final winner: player#1, earning $" << sum[0] << endl;
		break;
	case 2:
		win2(sum);
		break;
	case 3:
		win3(sum);
		break;
	default:
		break;
	}
}
/***********************************************************************************************************
Function: each_round
Description: running for every single round.
Parameters: message, each player's total.
Return: None
Pre-Conditions: player num-int, round num-int.
Post-Conditions: each player's total, message may change.
************************************************************************************************************/
void each_round(int player, int round)
{
	string mes;int *earn, *sum;earn = new int[player];sum = new int[player];
	for (int b = 0; b < player; b++)
	{
		sum[b] = 0;
	}
	cin.ignore();
	for (int i = 0; i < round; i++)
	{
		for (int a = 0; a < player; a++)
		{
			earn[a] = 0;
		}
		cout << endl << "round: " << i + 1 << endl;cout << "someone enters a message: ";
		message_a_to_z_and_A_to_Z(mes);run(mes, player, round, earn);
		for (int c = 0; c < player; c++)
		{
			sum[c] += earn[c];
		}
	}
	winner(sum, player);
}

int main()
{
	int player, round;
	cout << "how many players. ";
	player = int_one_to_three();
	cout << endl << "how many round. ";
	round = int_over_zero();
	each_round(player, round);
	return 0;
}