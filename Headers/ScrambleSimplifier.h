#pragma once
#include "Header.h"

//ScramblerSimplifier Functions
std::string transformator(std::string rot, std::string move)
{
	if (rot == "x")
	{
		if (move == "L")
			return "L";
		if (move == "R")
			return "R";
		if (move == "B")
			return "U";
		if (move == "F")
			return "D";
		if (move == "U")
			return "F";
		if (move == "D")
			return "B";

		if (move == "L'")
			return "L'";
		if (move == "R'")
			return "R'";
		if (move == "B'")
			return "U'";
		if (move == "F'")
			return "D'";
		if (move == "U'")
			return "F'";
		if (move == "D'")
			return "B'";

		if (move == "L2")
			return "L2";
		if (move == "R2")
			return "R2";
		if (move == "B2")
			return "U2";
		if (move == "F2")
			return "D2";
		if (move == "U2")
			return "F2";
		if (move == "D2")
			return "B2";
	}
	if (rot == "y")
	{
		if (move == "B")
			return "L";
		if (move == "F")
			return "R";
		if (move == "U")
			return "U";
		if (move == "D")
			return "D";
		if (move == "L")
			return "F";
		if (move == "R")
			return "B";

		if (move == "B'")
			return "L'";
		if (move == "F'")
			return "R'";
		if (move == "U'")
			return "U'";
		if (move == "D'")
			return "D'";
		if (move == "L'")
			return "F'";
		if (move == "R'")
			return "B'";

		if (move == "B2")
			return "L2";
		if (move == "F2")
			return "R2";
		if (move == "U2")
			return "U2";
		if (move == "D2")
			return "D2";
		if (move == "L2")
			return "F2";
		if (move == "R2")
			return "B2";
	}
	if (rot == "z")
	{
		if (move == "U")
			return "L";
		if (move == "D")
			return "R";
		if (move == "R")
			return "U";
		if (move == "L")
			return "D";
		if (move == "F")
			return "F";
		if (move == "B")
			return "B";

		if (move == "U'")
			return "L'";
		if (move == "D'")
			return "R'";
		if (move == "R'")
			return "U'";
		if (move == "L'")
			return "D'";
		if (move == "F'")
			return "F'";
		if (move == "B'")
			return "B'";

		if (move == "U2")
			return "L2";
		if (move == "D2")
			return "R2";
		if (move == "R2")
			return "U2";
		if (move == "L2")
			return "D2";
		if (move == "F2")
			return "F2";
		if (move == "B2")
			return "B2";
	}
	if (rot == "x'")
	{
		if (move == "L")
			return "L";
		if (move == "R")
			return "R";
		if (move == "F")
			return "U";
		if (move == "B")
			return "D";
		if (move == "D")
			return "F";
		if (move == "U")
			return "B";

		if (move == "L'")
			return "L'";
		if (move == "R'")
			return "R'";
		if (move == "F'")
			return "U'";
		if (move == "B'")
			return "D'";
		if (move == "D'")
			return "F'";
		if (move == "U'")
			return "B'";

		if (move == "L2")
			return "L2";
		if (move == "R2")
			return "R2";
		if (move == "F2")
			return "U2";
		if (move == "B2")
			return "D2";
		if (move == "D2")
			return "F2";
		if (move == "U2")
			return "B2";
	}
	if (rot == "y'")
	{
		if (move == "F")
			return "L";
		if (move == "B")
			return "R";
		if (move == "U")
			return "U";
		if (move == "D")
			return "D";
		if (move == "R")
			return "F";
		if (move == "L")
			return "B";

		if (move == "F'")
			return "L'";
		if (move == "B'")
			return "R'";
		if (move == "U'")
			return "U'";
		if (move == "D'")
			return "D'";
		if (move == "R'")
			return "F'";
		if (move == "L'")
			return "B'";

		if (move == "F2")
			return "L2";
		if (move == "B2")
			return "R2";
		if (move == "U2")
			return "U2";
		if (move == "D2")
			return "D2";
		if (move == "R2")
			return "F2";
		if (move == "L2")
			return "B2";
	}
	if (rot == "z'")
	{
		if (move == "D")
			return "L";
		if (move == "U")
			return "R";
		if (move == "L")
			return "U";
		if (move == "R")
			return "D";
		if (move == "F")
			return "F";
		if (move == "B")
			return "B";

		if (move == "D'")
			return "L'";
		if (move == "U'")
			return "R'";
		if (move == "L'")
			return "U'";
		if (move == "R'")
			return "D'";
		if (move == "F'")
			return "F'";
		if (move == "B'")
			return "B'";

		if (move == "D2")
			return "L2";
		if (move == "U2")
			return "R2";
		if (move == "L2")
			return "U2";
		if (move == "R2")
			return "D2";
		if (move == "F2")
			return "F2";
		if (move == "B2")
			return "B2";
	}
	if (rot == "x2")
	{
		if (move == "L")
			return "L";
		if (move == "R")
			return "R";
		if (move == "D")
			return "U";
		if (move == "U")
			return "D";
		if (move == "B")
			return "F";
		if (move == "F")
			return "B";

		if (move == "L'")
			return "L'";
		if (move == "R'")
			return "R'";
		if (move == "D'")
			return "U'";
		if (move == "U'")
			return "D'";
		if (move == "B'")
			return "F'";
		if (move == "F'")
			return "B'";

		if (move == "L2")
			return "L2";
		if (move == "R2")
			return "R2";
		if (move == "D2")
			return "U2";
		if (move == "U2")
			return "D2";
		if (move == "B2")
			return "F2";
		if (move == "F2")
			return "B2";
	}
	if (rot == "y2")
	{
		if (move == "R")
			return "L";
		if (move == "L")
			return "R";
		if (move == "U")
			return "U";
		if (move == "D")
			return "D";
		if (move == "B")
			return "F";
		if (move == "F")
			return "B";

		if (move == "R'")
			return "L'";
		if (move == "L'")
			return "R'";
		if (move == "U'")
			return "U'";
		if (move == "D'")
			return "D'";
		if (move == "B'")
			return "F'";
		if (move == "F'")
			return "B'";

		if (move == "R2")
			return "L2";
		if (move == "L2")
			return "R2";
		if (move == "U2")
			return "U2";
		if (move == "D2")
			return "D2";
		if (move == "B2")
			return "F2";
		if (move == "F2")
			return "B2";
	}
	if (rot == "z2")
	{
		if (move == "R")
			return "L";
		if (move == "L")
			return "R";
		if (move == "D")
			return "U";
		if (move == "U")
			return "D";
		if (move == "F")
			return "F";
		if (move == "B")
			return "B";

		if (move == "R'")
			return "L'";
		if (move == "L'")
			return "R'";
		if (move == "D'")
			return "U'";
		if (move == "U'")
			return "D'";
		if (move == "F'")
			return "F'";
		if (move == "B'")
			return "B'";

		if (move == "R2")
			return "L2";
		if (move == "L2")
			return "R2";
		if (move == "D2")
			return "U2";
		if (move == "U2")
			return "D2";
		if (move == "F2")
			return "F2";
		if (move == "B2")
			return "B2";
	}
}
bool IsRot(std::string rot)
{
	if (rot == "x")
	{
		return true;
	}
	if (rot == "y")
	{
		return true;
	}
	if (rot == "z")
	{
		return true;
	}
	if (rot == "x'")
	{
		return true;
	}
	if (rot == "y'")
	{
		return true;
	}
	if (rot == "z'")
	{
		return true;
	}
	if (rot == "x2")
	{
		return true;
	}
	if (rot == "y2")
	{
		return true;
	}
	if (rot == "z2")
	{
		return true;
	}
	if (rot == "l")
	{
		return true;
	}
	if (rot == "l'")
	{
		return true;
	}
	if (rot == "l2")
	{
		return true;
	}
	if (rot == "r")
	{
		return true;
	}
	if (rot == "r'")
	{
		return true;
	}
	if (rot == "r2")
	{
		return true;
	}
	if (rot == "u")
	{
		return true;
	}
	if (rot == "u'")
	{
		return true;
	}
	if (rot == "u2")
	{
		return true;
	}
	if (rot == "d")
	{
		return true;
	}
	if (rot == "d'")
	{
		return true;
	}
	if (rot == "d2")
	{
		return true;
	}
	if (rot == "f")
	{
		return true;
	}
	if (rot == "f'")
	{
		return true;
	}
	if (rot == "f2")
	{
		return true;
	}
	if (rot == "b")
	{
		return true;
	}
	if (rot == "b'")
	{
		return true;
	}
	if (rot == "b2")
	{
		return true;
	}
	if (rot == "M")
	{
		return true;
	}
	if (rot == "M'")
	{
		return true;
	}
	if (rot == "M2")
	{
		return true;
	}
	if (rot == "S")
	{
		return true;
	}
	if (rot == "S'")
	{
		return true;
	}
	if (rot == "S2")
	{
		return true;
	}
	if (rot == "E")
	{
		return true;
	}
	if (rot == "E'")
	{
		return true;
	}
	if (rot == "E2")
	{
		return true;
	}
	return false;
}
std::vector <std::string> ScrambleParser(std::string Scramble)
{
	std::vector <std::string> out;
	for (int i = 0; i <= Scramble.length(); i++)
	{
		if (Scramble[i] == 'L' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("L");
		}
		else if (Scramble[i] == 'R' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("R");
		}
		else if (Scramble[i] == 'U' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("U");
		}
		else if (Scramble[i] == 'D' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("D");
		}
		else if (Scramble[i] == 'F' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("F");
		}
		else if (Scramble[i] == 'B' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("B");
		}
		else if (Scramble[i] == 'L' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("L'");
		}
		else if (Scramble[i] == 'R' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("R'");
		}
		else if (Scramble[i] == 'U' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("U'");
		}
		else if (Scramble[i] == 'D' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("D'");
		}
		else if (Scramble[i] == 'F' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("F'");
		}
		else if (Scramble[i] == 'B' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("B'");
		}
		else if (Scramble[i] == 'L' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
		{
			out.push_back("L2");
		}
		else if (Scramble[i] == 'R' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
		{
			out.push_back("R2");
		}
		else if (Scramble[i] == 'U' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
		{
			out.push_back("U2");
		}
		else if (Scramble[i] == 'D' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
		{
			out.push_back("D2");
		}
		else if (Scramble[i] == 'F' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
		{
			out.push_back("F2");
		}
		else if (Scramble[i] == 'B' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
		{
			out.push_back("B2");
		}
		else if (Scramble[i] == 'l' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
		{
			out.push_back("l2");
		}
		else if (Scramble[i] == 'r' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
		{
			out.push_back("r2");
		}
		else if (Scramble[i] == 'u' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
		{
			out.push_back("u2");
		}
		else if (Scramble[i] == 'd' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
		{
			out.push_back("d2");
		}
		else if (Scramble[i] == 'f' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
		{
			out.push_back("f2");
		}
		else if (Scramble[i] == 'b' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
		{
			out.push_back("b2");
		}
		else if (Scramble[i] == 'l' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("l");
		}
		else if (Scramble[i] == 'r' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("r");
		}
		else if (Scramble[i] == 'u' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("u");
		}
		else if (Scramble[i] == 'd' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("d");
		}
		else if (Scramble[i] == 'f' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("f");
		}
		else if (Scramble[i] == 'b' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("b");
		}
		else if (Scramble[i] == 'l' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("l'");
		}
		else if (Scramble[i] == 'r' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("r'");
		}
		else if (Scramble[i] == 'u' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("u'");
		}
		else if (Scramble[i] == 'd' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("d'");
		}
		else if (Scramble[i] == 'f' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("f'");
		}
		else if (Scramble[i] == 'b' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("b'");
		}
		else if (Scramble[i] == 'x' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
		{
			out.push_back("x2");
		}
		else if (Scramble[i] == 'y' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
		{
			out.push_back("y2");
		}
		else if (Scramble[i] == 'z' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
		{
			out.push_back("z2");
		}
		else if (Scramble[i] == 'x' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("x");
		}
		else if (Scramble[i] == 'y' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("y");
		}
		else if (Scramble[i] == 'z' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("z");
		}
		else if (Scramble[i] == 'x' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("x'");
		}
		else if (Scramble[i] == 'y' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("y'");
		}
		else if (Scramble[i] == 'z' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("z'");
		}
		else if (Scramble[i] == 'M' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
		{
			out.push_back("M2");
		}
		else if (Scramble[i] == 'E' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
		{
			out.push_back("E2");
		}
		else if (Scramble[i] == 'S' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
		{
			out.push_back("S2");
		}
		else if (Scramble[i] == 'M' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("M");
		}
		else if (Scramble[i] == 'E' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("E");
		}
		else if (Scramble[i] == 'S' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("S");
		}
		else if (Scramble[i] == 'M' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("M'");

		}
		else if (Scramble[i] == 'E' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("E'");
		}
		else if (Scramble[i] == 'S' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
		{
			out.push_back("S'");
		}
	}
	return out;
}
std::string handler(int a, std::string str)
{
	std::string buff = "";

	if (str.at(0) == 'L')
		buff = "L";
	else if (str.at(0) == 'R')
		buff = "R";
	else if (str.at(0) == 'U')
		buff = "U";
	else if (str.at(0) == 'D')
		buff = "D";
	else if (str.at(0) == 'F')
		buff = "F";
	else if (str.at(0) == 'B')
		buff = "B";

	switch (a)
	{
	case 1://AA
		return buff + "2";
	case 2://AA2
		return buff + "'";
	case 3://A2A
		return buff + "'";
	case 4://A'A'
		return buff + "2";
	case 5://A'A2
		return buff;
	case 6://A2A'
		return buff;
	}
}
std::string ScrambleSimplifier(std::string scr)
{
	if (scr == "")
		return "";
	std::vector <std::string> pars = ScrambleParser(scr);
	std::vector <std::string> sol, que, done;
	std::string buff = "";
	for (int i = 0; i < pars.size(); i++)
	{
		{
			if (pars.at(i) == "x")
			{
				que.push_back("x");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "y")
			{
				que.push_back("y");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "z")
			{
				que.push_back("z");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "x'")
			{
				que.push_back("x'");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "y'")
			{
				que.push_back("y'");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "z'")
			{
				que.push_back("z'");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "x2")
			{
				que.push_back("x2");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "y2")
			{
				que.push_back("y2");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "z2")
			{
				que.push_back("z2");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "l")
			{
				que.push_back("x'");
				//pars.at(i) = "R";
				sol.push_back("R");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "l'")
			{
				que.push_back("x");
				//pars.at(i) = "R'";
				sol.push_back("R'");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "l2")
			{
				que.push_back("x2");
				sol.push_back("R2");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "r")
			{
				que.push_back("x");
				pars.at(i) = "L";
				/*sol.push_back("L");
				if (pars.size() <= i)
					i++;*/
			}
			if (pars.at(i) == "r'")
			{
				que.push_back("x'");
				pars.at(i) = "L'";
				/*sol.push_back("L'");
				if (pars.size() <= i)
					i++;*/
			}
			if (pars.at(i) == "r2")
			{
				que.push_back("x2");
				sol.push_back("L2");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "u")
			{
				que.push_back("y");
				sol.push_back("D");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "u'")
			{
				que.push_back("y'");
				sol.push_back("D'");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "u2")
			{
				que.push_back("y2");
				sol.push_back("D2");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "d")
			{
				que.push_back("y'");
				sol.push_back("U");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "d'")
			{
				que.push_back("y");
				sol.push_back("U'");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "d2")
			{
				que.push_back("y2");
				sol.push_back("D2");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "f")
			{
				que.push_back("z");
				sol.push_back("B");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "f'")
			{
				que.push_back("z'");
				sol.push_back("B'");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "f2")
			{
				que.push_back("z2");
				sol.push_back("B2");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "b")
			{
				que.push_back("z'");
				sol.push_back("F");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "b'")
			{
				que.push_back("z");
				sol.push_back("F'");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "b2")
			{
				que.push_back("z2");
				sol.push_back("F2");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "M")
			{
				que.push_back("x'");
				sol.push_back("L'");
				sol.push_back("R");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "M'")
			{
				que.push_back("x");
				sol.push_back("L");
				sol.push_back("R'");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "M2")
			{
				que.push_back("x2");
				sol.push_back("L2");
				sol.push_back("R2");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "S")
			{
				que.push_back("z");
				sol.push_back("F'");
				sol.push_back("B");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "S'")
			{
				que.push_back("z'");
				sol.push_back("F");
				sol.push_back("B'");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "S2")
			{
				que.push_back("z2");
				sol.push_back("F2");
				sol.push_back("B2");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "E")
			{
				que.push_back("y'");
				sol.push_back("U");
				sol.push_back("D'");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "E'")
			{
				que.push_back("y");
				sol.push_back("U'");
				sol.push_back("D");
				if (pars.size() <= i)
					i++;
			}
			if (pars.at(i) == "E2")
			{
				que.push_back("y2");
				sol.push_back("U2");
				sol.push_back("D2");
				if (pars.size() <= i)
					i++;
			}
		}
		if (que.empty())
		{
			sol.push_back(pars.at(i));
		}
		else if (!IsRot(pars.at(i)))
		{
			for (int j = 0; j < que.size(); j++)
			{
				buff = transformator(que.at(j), pars.at(i));
				pars.at(i) = buff;
			}
			sol.push_back(pars.at(i));
		}
	}

	//Print Unhandled Scramble
	/*buff = sol.at(0);
	for (int j = 1; j < sol.size(); j++)
		buff += sol.at(j);
	std::cout << "Solution: " << buff << '\n';*/

	buff = "";
	done.push_back("");
	done.push_back(sol.at(0));
	int back_element_number = 0;
	int solution_size = sol.size();
	for (int i = 1; i < solution_size; i++)
	{
		back_element_number = done.size() - 1;
		if (back_element_number == 0)
			done.push_back(sol.at(i));
		else if (done.at(back_element_number).at(0) == sol.at(i).at(0))
		{
			//AA
			if (done.at(back_element_number).size() == 1 && sol.at(i).size() == 1)
			{
				done.pop_back();
				done.push_back(handler(1, sol.at(i)));
			}
			else if (done.at(back_element_number).size() == 1 && sol.at(i).size() == 2)
			{
				//AA'
				if (sol.at(i).at(1) == '\'')
					done.pop_back();
				//AA2
				else if (sol.at(i).at(1) == '2')
				{
					done.pop_back();
					done.push_back(handler(2, sol.at(i)));
				}
			}
			else if (done.at(back_element_number).size() == 2 && sol.at(i).size() == 1)
			{
				//A'A
				if (done.at(back_element_number).at(1) == '\'')
					done.pop_back();
				//A2A
				else if (done.at(back_element_number).at(1) == '2')
				{
					done.pop_back();
					done.push_back(handler(3, sol.at(i)));
				}
			}
			else if (done.at(back_element_number).size() == 2 && sol.at(i).size() == 2)
			{
				//A'A'
				if (done.at(back_element_number).at(1) == '\'' && sol.at(i).at(1) == '\'')
				{
					done.pop_back();
					done.push_back(handler(4, sol.at(i)));
				}
				//A2A2
				else if (done.at(back_element_number).at(1) == '2' && sol.at(i).at(1) == '2')
					done.pop_back();
				//A'A2
				else if (done.at(back_element_number).at(1) == '\'' && sol.at(i).at(1) == '2')
				{
					done.pop_back();
					done.push_back(handler(5, sol.at(i)));
				}
				//A2A'
				else if (done.at(back_element_number).at(1) == '2' && sol.at(i).at(1) == '\'')
				{
					done.pop_back();
					done.push_back(handler(6, sol.at(i)));
				}
			}
		}
		else
			done.push_back(sol.at(i));
	}
	buff = done.at(0) + " ";
	for (int j = 1; j < done.size(); j++)
		buff += done.at(j) + " ";
	return buff;
}
std::string SolveCube(Cube cube1, std::string Mode)
{
	//std::string allmoves[19] = { "U'","U","U2","","R","R2","R'","F","F2","F'","L","L2","L'","B","B2","B'","D","D2","D'" };

	std::string rotcases[4] = { "","y2","y","y'" };

	std::string aufcases[4] = { "","U","U2","U'" };

	std::string sexymovecases[21] = { "","RUR'","L'U'L","R'U'R","LUL'","RU2R'","L'U2L","R'U2R","LU2L'","RUR'L'U'L","RUR'R'U'R","RUR'LUL'","L'U'LRUR'","L'U'LLUL'","L'U'LR'U'R","R'U'RRUR'","R'U'RL'U'L","R'U'RLUL'","LUL'RUR'","LUL'L'U'L","LUL'R'U'R" };

	std::string* f2lcases = ReadAlgsFromFiles(1,103);

	std::string* ollcases = ReadAlgsFromFiles(2,57);

	std::string* pllcases = ReadAlgsFromFiles(3,21);

	Cube cur = cube1;
	std::string pre_cube, pre_cross, frist_cross_piece, second_cross_piece, third_cross_piece,
		fourth_cross_piece, first_f2l_pair, second_f2l_pair, third_f2l_pair, fourth_f2l_pair, OLL, PLL, AUF, solution;

	pre_cube = Pre_SolveCube(cur);
	cur.SetScramble(pre_cube);
	if (Mode == "Default")
		std::cout << pre_cube << "  -  pre cube (3 step max)\n";

	pre_cross = Pre_SolveCross1(cur);
	cur.SetScramble(pre_cross);
	if (Mode == "Default")
		std::cout << pre_cross << "  -  pre cross (3 step max)\n";

	frist_cross_piece = Pre_SolveOneCrossPiece(cur);
	cur.SetScramble(frist_cross_piece);
	if (Mode == "Default")
		std::cout << frist_cross_piece << "  -  1st cross piece\n";

	second_cross_piece = Pre_SolveTwoCrossPieces(cur);
	cur.SetScramble(second_cross_piece);
	if (Mode == "Default")
		std::cout << second_cross_piece << "  -  2nd cross piece\n";

	third_cross_piece = Pre_SolveThreeCrossPieces(cur);
	cur.SetScramble(third_cross_piece);
	if (Mode == "Default")
		std::cout << third_cross_piece << "  -  3rd cross piece\n";

	fourth_cross_piece = Pre_SolveFourCrossPieces(cur);
	cur.SetScramble(fourth_cross_piece);
	if (Mode == "Default")
		std::cout << fourth_cross_piece << "  -  4th cross piece\n";

	first_f2l_pair = Pre_SolveOnePair(cur, sexymovecases, rotcases, aufcases, f2lcases);
	cur.SetScramble(first_f2l_pair);

	second_f2l_pair = Pre_SolveTwoPairs(cur, sexymovecases, rotcases, aufcases, f2lcases);
	cur.SetScramble(second_f2l_pair);

	third_f2l_pair = Pre_SolveThreePairs(cur, sexymovecases, rotcases, aufcases, f2lcases);
	cur.SetScramble(third_f2l_pair);

	fourth_f2l_pair = Pre_SolveFourPairs(cur, aufcases, f2lcases);
	cur.SetScramble(fourth_f2l_pair);

	OLL = Pre_OLL(cur, aufcases, ollcases);
	cur.SetScramble(OLL);

	PLL = Pre_PLL(cur, aufcases, pllcases);
	cur.SetScramble(PLL);

	AUF = Pre_AUF(cur, aufcases);
	cur.SetScramble(AUF);

	if (Mode == "Default" || Mode == "CMD" || Mode == "Gen")
	{
		std::cout << pre_cross + frist_cross_piece + second_cross_piece + third_cross_piece + fourth_cross_piece << "  -  cross\n";
		std::cout << first_f2l_pair << "  -  1st f2l pair\n";
		std::cout << second_f2l_pair << "  -  2nd f2l pair\n";
		std::cout << third_f2l_pair << "  -  3rd f2l pair\n";
		std::cout << fourth_f2l_pair << "  -  4th f2l pair\n";
		std::cout << OLL << "  -  oll\n";
		std::cout << PLL << "  -  pll\n";
		std::cout << AUF << "  -  auf\n";
	}

	solution = ScrambleSimplifier(pre_cube + pre_cross + frist_cross_piece + second_cross_piece + third_cross_piece + fourth_cross_piece +
		first_f2l_pair + second_f2l_pair + third_f2l_pair + fourth_f2l_pair + OLL + PLL + AUF);

	return solution;
}