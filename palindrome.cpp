#include<iostream>
#include<stdio.h>
#include<cstring>

using namespace std;
/************************************************************************
*Function:get_cent
*Description:gets the users input for the string
*Parameters: s
*Pre-Conditions: s must be a string
*Post-Conditions:s must be a string
*************************************************************************/
void get_cent(char *s)
{
	cout << "Enter your string :";
	cin.get(s, 256, '\n');
}

void get_start(char *);
/*************************************************************************
*Function:determine_palindrome
*Description:checks if the string entered is a palindrome
*Parameters: s
*Pre-Conditions: s must be a string
*Post-Conditions: the function must return a boolean
**************************************************************************/
void determine_palindrome(char *s)
{
	char re[256];
	int c = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		re[i] = s[strlen(s) - i -1];
	}
	for (int x = 0; x < strlen(s); x++)
	{
		if (re[x] != s[x])
		{
			cout << "You have not entered a palindrome!!!" << endl;
			break;
		}
		c += 1;
	}
	if (c == strlen(s)) cout << "You have entered a palindrome!!!" << endl;
}

void get_search_replace_strings(char *);
/************************************************************************************
*Function:replace
*Description: replaces string with a new string
*Parameters: s, s1, x, y
*Pre-Conditions: s and s1 must be strings. x and y must be integers
*Post-Conditions: s2 and s3 must be strings
*************************************************************************************/
void replace(char *s, char *s1, int m, int o)
{
	char s2[256], x[256];
	int j = 0, n, l;
	for (int i = 0; i < strlen(s) + 1; i++)
	{
		s2[i] = s[i];
	}
	cout << "the replacement.";
	cin.get(x, 256);
	for (; j < m; j++)
	{
		s[j] = s2[j];
	}
	n = j + strlen(x);
	l = j;
	for (; j < n; j++)
	{
		s[j] = x[j - l];
	}
	l = j;
	for (; j < strlen(s2) - o + l; j++)
	{
		s[j] = s2[j - strlen(x) + strlen(s1)];
	}
	s[j] = '\0';
	cout << "result: " << s << endl;
}
/************************************************************************************
*Function:search
*Description: searches the current string for the word inputted by user
*Parameters: s and s1
*Pre-Conditions: s and s1 must be strings
*Post-Conditions: s and s1 must be strings and 1 and m must be integers
*************************************************************************************/
void search(char *s, char *s1)
{
	int c = 0, j, m, o;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s1[0] == s[i])
		{
			c = 1;
			m = i;
			for (j = 1; j < strlen(s1); j++)
			{
				if (s1[j] == s[i + j]) c += 1;
			}
			o = i + j;
			if (c == strlen(s1)) break;
		}
	}
	if (c == strlen(s1))
	{
		cout << "found." << endl;
		cin.ignore();
		replace(s, s1, m, o);
	}
	else
	{
		cout << "nothing found." << endl;
		cin.ignore();
		get_search_replace_strings(s);
	}
}
/**********************************************************************************************
*Function:get_search_replace_strings
*Description: gets the user input for string to search for and calls search function
*Parameters: s
*Pre-Conditions: s must be a string
*Post-Conditions: s and s1 must be strings
***********************************************************************************************/
void get_search_replace_strings(char *s)
{
	char s1[256];
	cout << "enter a search string: ";
	cin.get(s1, 256, '\n');
	search(s, s1);
}
/***************************************************************************************************
*Function:get_start
*Description: ask user to pick a choice then runs functions according to the choices they picked
*Parameters: s
*Pre-Conditions: s must be a string
*Post-Conditions: must return a integer
****************************************************************************************************/
void get_start(char *s)
{
	int choice;
	cout << "Determine if palindrome (1), replace string (2), enter new string (3), or quit (0)?";
	cin >> choice;
	cin.ignore();
	if (choice == 1)
	{
		determine_palindrome(s);
		get_start(s);
	}
	else if (choice == 2)
	{
		get_search_replace_strings(s);
		get_start(s);
	}
	else if (choice == 3)
	{
		get_cent(s);
		get_start(s);
	}
	else if (choice == 0)
	{
		cout << "You're done" << endl;
	}
	else
	{
		cout << "1,2,3, or 0. " << endl;
		get_start(s);
	}
}
/************************************************************************************
*Function: main
*Description:calls get_cent and get_start
*Parameters: none
*Pre-Conditions: none
*Post-Conditions:must return integer
*************************************************************************************/
int main()
{
	char *s;
	s = new char[256];
	get_cent(s);
	get_start(s);
	return 0;
}