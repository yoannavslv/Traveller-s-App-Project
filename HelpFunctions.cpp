#include<cstring>
#include <iostream>
#include"Vector.h"
#include"HelpFunctions.h"

Vector<char*> split(char* text)
{
	Vector<char*> newSpace;
	while (numberOfSymbols(text, ' '))
	{
		newSpace.push_back(substring(text, 0, index(text, ' ')));
		text = substring(text, index(text, ' ') + 1, strlen(text) + 1);
	}
	newSpace.push_back(text);
	return newSpace;
}

size_t theLastIndex(char* text, char symbol)
{
	int lenght = strlen(text);
	for (int i = lenght; i >= 0; i++)
	{
		if (text[i] == symbol)
		{
			return i;
		}
	}
	return -1;
}

size_t numberOfSymbols(char* text, char symbol)
{
	size_t counter = 0;
	size_t lenght = strlen(text);
	for (size_t i = 0; i < lenght; i++)
	{
		if (text[i] == symbol)
		{
			counter++;
		}
	}
	return counter;
}

char* substring(char* text, int firstPosition, int secondPosition)
{
	size_t lenght = strlen(text);
	char* substring = new char[lenght - firstPosition + 1];
	for (size_t i = 0; i < secondPosition - firstPosition; i++)
	{
		substring[i] = text[i + firstPosition];
	}
	substring[secondPosition - firstPosition] = 0;
	return substring;
}

size_t index(char* text, char symbol)
{
	size_t lenght = strlen(text);
	for (size_t i = 0; i < lenght; i++)
	{
		if (text[i] == symbol)
		{
			return i;
		}
	}
}

