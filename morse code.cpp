/******************************************************
** Program: morse.cpp
** Author: Jiawei Mo
** Date: 2/27/2016
** Description: This program will translate 
**				message to morse code 
**				or morse code to message 
**				and print out the result. 
** Input: The message or the code and the choice. 
** Output: The morse code or the message 
**		   according to the input. 
******************************************************/
#include<iostream>

using namespace std;
/****************************************************************************************
** Function: len
** Description: figure out the lenth of the string. 
** Parameters:	the string, the lenth. 
** Pre-Conditions: an array of char passed. 
** Post-Conditions: return the number of the lenth. 
*****************************************************************************************/
int len(char *s)
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
	{

	}
	return i;
}
/****************************************************************************************
** Function: mes_in
** Description: store the input chars into a string and return it to the function 
**				that calls this function.
** Parameters:	the string, the temporary string, 
**				the string to hold one letter, the size num, the last index num. 
** Pre-Conditions: None. 
** Post-Conditions: return the string, delete the temporary string 
**					and the string to hold one letter.
*****************************************************************************************/
char *mes_in()
{
	char *mes = NULL, *temp = NULL, *swp = NULL; int num = 2, tp = 0;
	mes = new char[num]; temp = new char[num]; swp = new char[num];
	cin.get(temp, 2); mes[tp] = temp[0];
	while (*temp != '\0')
	{
		delete[] swp; swp = new char[num];
		for (int i = 0; i < num; i++)
		{
			swp[i] = mes[i];
		}
		delete[]mes; mes = new char[num += 1];
		for (int i = 0; i < num; i++)
		{
			mes[i] = swp[i];
		}
		delete[]temp; temp = new char[2];
		cin.get(temp, 2); mes[tp += 1] = temp[0];
	}
	return mes;
}
/****************************************************************************************
** Function: mo_ch
** Description: print the morse code corresponding each char in the message.
** Parameters:	None. 
** Pre-Conditions: ascii code is int.
** Post-Conditions: None.
*****************************************************************************************/
void mo_ch(int x)
{
	if (x == 32) cout << "       ";
	if (x == 65 || x == 97) cout << ".-   "; if (x == 66 || x == 98) cout << "-...   ";
	if (x == 67 || x == 99) cout << "-.-.   "; if (x == 68 || x == 100) cout << "-..   ";
	if (x == 69 || x == 101) cout << ".   "; if (x == 70 || x == 102) cout << "..-.   ";
	if (x == 71 || x == 103) cout << "--.   "; if (x == 72 || x == 104) cout << "....   ";
	if (x == 73 || x == 105) cout << "..   "; if (x == 74 || x == 106) cout << ".---   ";
	if (x == 75 || x == 107) cout << "-.-   "; if (x == 76 || x == 108) cout << ".-..   ";
	if (x == 77 || x == 109) cout << "--   "; if (x == 78 || x == 110) cout << "-.   ";
	if (x == 79 || x == 111) cout << "---   "; if (x == 80 || x == 112) cout << ".--.   ";
	if (x == 81 || x == 113) cout << "--.-   "; if (x == 82 || x == 114) cout << ".-.   ";
	if (x == 83 || x == 115) cout << "...   "; if (x == 84 || x == 116) cout << "-   ";
	if (x == 85 || x == 117) cout << "..-   "; if (x == 86 || x == 118) cout << "...-   ";
	if (x == 87 || x == 119) cout << ".--   "; if (x == 88 || x == 120) cout << "-..-   ";
	if (x == 89 || x == 121) cout << "-.--   "; if (x == 90 || x == 122) cout << "--..   ";
}
/****************************************************************************************
** Function: tomo
** Description: get the massage from user and pass it.
** Parameters: the message
** Pre-Conditions: None. 
** Post-Conditions: message may change. 
*****************************************************************************************/
void tomo()
{
	char *mess = NULL;
	cout << "your message: ";
	mess = mes_in();
	for (int i = 0; i < len(mess); i++)
	{
		mo_ch(int(mess[i]));
	}
	cout << endl;
}
/****************************************************************************************
** Function: me_ch
** Description: transfer morse code to the char of the message one by one.
** Parameters: first index num of morse code string, 
**			   track num that record how many letters are matched. 
** Pre-Conditions: temporary string are sort of chars.
** Post-Conditions: each letter in the message corresponding the morse code printed.
*****************************************************************************************/
void me_ch(char *temp)
{
	int x = 0, y = 0;
	char morse[26][5] = { { ".-" }, { "-..." }, { "-.-." }, { "-.." }, { "." }, { "..-." }, { "--." },
	{ "...." }, { ".." }, { ".---" }, { "-.-" }, { ".-.." }, { "--" }, { "-." }, { "---" }, { ".--." }, { "--.-" }, 
	{ ".-." }, { "..." }, { "-" }, { "..-" }, { "...-" }, { ".--" }, { "-..-" }, { "-.--" }, { "--.." } };
	for (int i = 0; i < 26; i++)
	{
		if (len(morse[i]) == len(temp))
		{
			for (int j = 0; j < len(morse[i]); j++)
			{
				if (morse[i][j] == temp[j])
				{
					x += 1;
				}
			}
			if (x == len(morse[i]))
			{
				cout << char(i + 97);
				y += 1;
			}
			x = 0;
		}
	}
	if (y == 0) cout << "(nothing matched.) " << endl;
}
/****************************************************************************************
** Function: tome_begin
** Description: begin to transfer morse code to the message.
** Parameters: first index num of morse code string, first index num of temporary string. 
** Pre-Conditions: morse code string and temporary string are sort of chars. 
** Post-Conditions: the message corresponding the morse code printed. 
*****************************************************************************************/
void tome_begin(char *m, char *temp)
{
	int i = 0, j = 0;
	for (; i < len(m); i++)
	{
		if (m[i] != ' ')
		{
			temp[j] = m[i];
			j += 1;
		}
		else
		{
			if (m[i] == ' ' && m[i - 1] != ' ')
			{
				temp[j] = '\0';
				me_ch(temp);
				j = 0;
				delete[] temp; temp = new char[5];
			}
			if (m[i] == ' ' && m[i - 6] == ' ' && m[i - 5] == ' ' && m[i - 4] == ' ' && m[i - 3] == ' ' && m[i - 2] == ' ' && m[i - 1] == ' ') cout << ' ';
		}
	}
}
/****************************************************************************************
** Function: tome
** Description: get the morse code from user and initialize a temporary string 
**				and pass them. 
** Parameters: morse code string
** Pre-Conditions: None. 
** Post-Conditions: morse code string may change. 
*****************************************************************************************/
void tome()
{
	char *mor = NULL, *m, *temp;
	temp = new char[5];
	cout << "your morse code: ";
	mor = mes_in();
	m = new char[len(mor) + 2];
	for (int k = 0; mor[k] != '\0'; k++)
	{
		m[k] = mor[k];
	}
	m[len(mor)] = ' '; 
	m[len(mor) + 1] = '\0';
	tome_begin(m, temp);
}
/****************************************************************************************
** Function: cho
** Description: get the choice from user and shift to the translation. 
** Parameters: the choice. 
** Pre-Conditions: None. 
** Post-Conditions: choice may change. 
*****************************************************************************************/
void cho()
{
	int choice;
	cout << "Do you want to translate text to Morse code (1) or translate Morse code to text (2)? ";
	cin >> choice;
	cin.ignore();
	if (choice == 1)
	{
		tomo(); 
		cout << "thanks for using. ";
	}
	else if (choice == 2)
	{
		tome(); 
		cout << "thanks for using. ";
	}
}

int main()
{
	cho();
	return 0;
}