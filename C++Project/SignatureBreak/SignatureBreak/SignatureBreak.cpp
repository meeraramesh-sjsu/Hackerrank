// SignatureBreak.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	char *inputTemp = "Meera are you";
	char *input = "0x48656C6C6F";
	char *tempo = inputTemp;
	bool found = true;
	while (*tempo != '\0')
	{
		found = true;
		for (int i = 2; input[i] != '\0';)
		{
			int val1 = (input[i] - 48) > 9 ? (input[i] - 55) * 16 : (input[i] - 48) * 16;
			int val2 = (input[i + 1] - 48) > 9 ? (input[i + 1] - 55) : (input[i + 1] - 48);
			int val = val1 + val2;
			if (*tempo == '\0' || !(*tempo == val)) {
				found = false; 
				if (*tempo != '\0') tempo++;
				break;
			}
			tempo++;
			i = i + 2;
		}
		if (found) break; 
	}
	cout << found;
	int a[] = {0x48,0x65,0x6C,0x6C,0x6F};
	for (int i = 0; i < 5; i++)
	{
		if (a[i] == input[i])
			cout << "Equal ";
	}
    return 0;
}

