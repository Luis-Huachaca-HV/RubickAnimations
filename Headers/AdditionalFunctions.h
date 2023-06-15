#pragma once
#include "Header.h"

#define W 1
#define O 2
#define Y 3
#define R 4
#define G 5
#define B 6

int CrossColor = 3; //Global Variable

//Additional Functions
void PrintTemplateSolvedState()
{
	std::cout << "      " << "W" << " " << "W" << " " << "W" << std::endl;
	std::cout << "      " << "W" << " " << "W" << " " << "W" << std::endl;
	std::cout << "      " << "W" << " " << "W" << " " << "W" << std::endl;
	std::cout << "O" << " " << "O" << " " << "O" << " " << "G" << " " << "G" << " " << "G" << " " << "R" << " " << "R" << " " << "R" << " " << "B" << " " << "B" << " " << "B" << "\n";
	std::cout << "O" << " " << "O" << " " << "O" << " " << "G" << " " << "G" << " " << "G" << " " << "R" << " " << "R" << " " << "R" << " " << "B" << " " << "B" << " " << "B" << "\n";
	std::cout << "O" << " " << "O" << " " << "O" << " " << "G" << " " << "G" << " " << "G" << " " << "R" << " " << "R" << " " << "R" << " " << "B" << " " << "B" << " " << "B" << "\n";
	std::cout << "      " << "Y" << " " << "Y" << " " << "Y" << std::endl;
	std::cout << "      " << "Y" << " " << "Y" << " " << "Y" << std::endl;
	std::cout << "      " << "Y" << " " << "Y" << " " << "Y";
	std::cout << "\n";
}
void ColorPrint(int Color)
{
	switch (Color)
	{
	case 1:
		std::cout << "W";
		break;
	case 2:
		std::cout << "O";
		break;
	case 3:
		std::cout << "Y";
		break;
	case 4:
		std::cout << "R";
		break;
	case 5:
		std::cout << "G";
		break;
	case 6:
		std::cout << "B";
		break;
	}
}
void PrintSixSpaces()
{
	std::cout << "      ";
}
void PrintSpace()
{
	std::cout << " ";
}
void PrintNewLine()
{
	std::cout << "\n";
}
void PrintTest()
{
	std::cout << "test\n";
}
void BoolCheck(bool a)
{
	if (a)
		std::cout << "True" << "\n";
	else
		std::cout << "False" << "\n";
}
bool AreValuesEqual(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
	if (a == b)
	{
		if (a == c)
		{
			if (a == d)
			{
				if (a == e)
				{
					if (a == f)
					{
						if (a == g)
						{
							if (a == h)
							{
								if (a == i)
								{
									return true;
								}
								else
									return false;
							}
							else
								return false;
						}
						else
							return false;
					}
					else
						return false;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}
bool AreValuesEqual(int a, int b, int c, int d, int e, int f, int g, int h)
{
	if (a == b)
	{
		if (a == c)
		{
			if (a == d)
			{
				if (a == e)
				{
					if (a == f)
					{
						if (a == g)
						{
							if (a == h)
							{
								return true;
							}
							else
								return false;
						}
						else
							return false;
					}
					else
						return false;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}
bool AreValuesEqual(int a, int b, int c, int d, int e, int f, int g)
{
	if (a == b)
	{
		if (a == c)
		{
			if (a == d)
			{
				if (a == e)
				{
					if (a == f)
					{
						if (a == g)
						{
							return true;
						}
						else
							return false;
					}
					else
						return false;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}
bool AreValuesEqual(int a, int b, int c, int d, int e, int f)
{
	if (a == b)
	{
		if (a == c)
		{
			if (a == d)
			{
				if (a == e)
				{
					if (a == f)
					{
						return true;
					}
					else
						return false;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}
bool AreValuesEqual(int a, int b, int c, int d, int e)
{
	if (a == b)
	{
		if (a == c)
		{
			if (a == d)
			{
				if (a == e)
				{
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}
bool AreValuesEqual(int a, int b, int c, int d)
{
	if (a == b)
	{
		if (a == c)
		{
			if (a == d)
			{
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}
bool AreValuesEqual(int a, int b, int c)
{
	if (a == b)
	{
		if (a == c)
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}