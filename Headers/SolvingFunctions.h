#pragma once
#include "Header.h"

//Solving Functions
std::string CreateNeighbors(int i)
{
	switch (i)
	{
	case 0:
		return "R";
		break;
	case 1:
		return "L";
		break;
	case 2:
		return "U";
		break;
	case 3:
		return "D";
		break;
	case 4:
		return "F";
		break;
	case 5:
		return "B";
		break;
	case 6:
		return "R'";
		break;
	case 7:
		return "L'";
		break;
	case 8:
		return "U'";
		break;
	case 9:
		return "D'";
		break;
	case 10:
		return "F'";
		break;
	case 11:
		return "B'";
		break;
	case 12:
		return "R2";
		break;
	case 13:
		return "L2";
		break;
	case 14:
		return "U2";
		break;
	case 15:
		return "D2";
		break;
	case 16:
		return "F2";
		break;
	case 17:
		return "B2";
		break;
	}
}
std::string CreateNeighbors(int i, std::string buff)
{
	char c;
	if (buff.length() == 1)
		c = buff[0];
	else
	{
		char a = buff[buff.length() - 2];
		char b = buff[buff.length() - 1];
		if (b == '2' || b == '\'')
			c = a;
		else
			c = b;
	}
	if (c == 'R')
	{
		switch (i)
		{
		case 0:
			return "B2";
			break;
		case 1:
			return "L";
			break;
		case 2:
			return "U";
			break;
		case 3:
			return "D";
			break;
		case 4:
			return "F";
			break;
		case 5:
			return "B";
			break;
		case 6:
			return "F2";
			break;
		case 7:
			return "L'";
			break;
		case 8:
			return "U'";
			break;
		case 9:
			return "D'";
			break;
		case 10:
			return "F'";
			break;
		case 11:
			return "B'";
			break;
		case 12:
			return "D2";
			break;
		case 13:
			return "L2";
			break;
		case 14:
			return "U2";
			break;
		}
	}
	if (c == 'L')
	{
		switch (i)
		{
		case 0:
			return "R";
			break;
		case 1:
			return "B2";
			break;
		case 2:
			return "U";
			break;
		case 3:
			return "D";
			break;
		case 4:
			return "F";
			break;
		case 5:
			return "B";
			break;
		case 6:
			return "R'";
			break;
		case 7:
			return "F2";
			break;
		case 8:
			return "U'";
			break;
		case 9:
			return "D'";
			break;
		case 10:
			return "F'";
			break;
		case 11:
			return "B'";
			break;
		case 12:
			return "R2";
			break;
		case 13:
			return "D2";
			break;
		case 14:
			return "U2";
			break;
		}

		if (i == 0 && c != 'R')
			return "R";
		if (i == 1 && c != 'L')
			return "L";
		if (i == 2 && c != 'U')
			return "U";
		if (i == 3 && c != 'D')
			return "D";
		if (i == 4 && c != 'F')
			return "F";
		if (i == 5 && c != 'B')
			return "B";
		if (i == 6 && c != 'R')
			return "R'";
		if (i == 7 && c != 'L')
			return "L'";
		if (i == 8 && c != 'U')
			return "U'";
		if (i == 9 && c != 'D')
			return "D'";
		if (i == 10 && c != 'F')
			return "F'";
		if (i == 11 && c != 'B')
			return "B'";
		if (i == 12 && c != 'R')
			return "R2";
		if (i == 13 && c != 'L')
			return "L2";
		if (i == 14 && c != 'U')
			return "U2";
		if (i == 15 && c != 'D')
			return "D2";
		if (i == 16 && c != 'F')
			return "F2";
		if (i == 17 && c != 'B')
			return "B2";
	}
	if (c == 'U')
	{
		switch (i)
		{
		case 0:
			return "R";
			break;
		case 1:
			return "L";
			break;
		case 2:
			return "B2";
			break;
		case 3:
			return "D";
			break;
		case 4:
			return "F";
			break;
		case 5:
			return "B";
			break;
		case 6:
			return "R'";
			break;
		case 7:
			return "L'";
			break;
		case 8:
			return "D2";
			break;
		case 9:
			return "D'";
			break;
		case 10:
			return "F'";
			break;
		case 11:
			return "B'";
			break;
		case 12:
			return "R2";
			break;
		case 13:
			return "L2";
			break;
		case 14:
			return "F2";
			break;
		}
	}
	if (c == 'D')
	{
		switch (i)
		{
		case 0:
			return "R";
			break;
		case 1:
			return "L";
			break;
		case 2:
			return "U";
			break;
		case 3:
			return "B2";
			break;
		case 4:
			return "F";
			break;
		case 5:
			return "B";
			break;
		case 6:
			return "R'";
			break;
		case 7:
			return "L'";
			break;
		case 8:
			return "U'";
			break;
		case 9:
			return "F2";
			break;
		case 10:
			return "F'";
			break;
		case 11:
			return "B'";
			break;
		case 12:
			return "R2";
			break;
		case 13:
			return "L2";
			break;
		case 14:
			return "U2";
			break;
		}
	}
	if (c == 'F')
	{
		switch (i)
		{
		case 0:
			return "R";
			break;
		case 1:
			return "L";
			break;
		case 2:
			return "U";
			break;
		case 3:
			return "D";
			break;
		case 4:
			return "B2";
			break;
		case 5:
			return "B";
			break;
		case 6:
			return "R'";
			break;
		case 7:
			return "L'";
			break;
		case 8:
			return "U'";
			break;
		case 9:
			return "D'";
			break;
		case 10:
			return "D2";
			break;
		case 11:
			return "B'";
			break;
		case 12:
			return "R2";
			break;
		case 13:
			return "L2";
			break;
		case 14:
			return "U2";
			break;
		}
	}
	if (c == 'B')
	{
		switch (i)
		{
		case 0:
			return "R";
			break;
		case 1:
			return "L";
			break;
		case 2:
			return "U";
			break;
		case 3:
			return "D";
			break;
		case 4:
			return "F";
			break;
		case 5:
			return "F2";
			break;
		case 6:
			return "R'";
			break;
		case 7:
			return "L'";
			break;
		case 8:
			return "U'";
			break;
		case 9:
			return "D'";
			break;
		case 10:
			return "F'";
			break;
		case 11:
			return "D2";
			break;
		case 12:
			return "R2";
			break;
		case 13:
			return "L2";
			break;
		case 14:
			return "U2";
			break;
		}
	}
}
std::string Pre_SolveCube(Cube cube1)
{
	int ICS = cube1.IsSolved();
	if (ICS)
	{
		//ColorPrint(ICS);
		//std::cout << "cross is solved\n";
		//CrossColor = ICS;
		return "";
	}
	int am = 0;
	int n = 0;
	std::vector<std::string> ngbrs;
	std::queue<std::string> q;
	Cube cur;
	std::string buff;
	for (int i = 0; i < 18; i++)
	{
		ngbrs.push_back(CreateNeighbors(i));
		q.push(ngbrs[n]);
		n++;
	}
	while (!q.empty())
	{
		cur = cube1;
		buff = q.front();
		am = cur.SetScramble(buff);
		if (am > 3)
			return "";
		q.pop();
		ICS = cur.IsSolved();
		if (ICS)
		{
			//std::cout << buff << "\n";
			//ColorPrint(ICS);
			//std::cout << " cross is solved\n";
			//std::cout << "moves: " << am << "\n";
			//CrossColor = ICS;
			return buff;
		}
		for (int i = 0; i < 15; i++)
		{
			ngbrs.push_back(buff + CreateNeighbors(i, buff));
			q.push(ngbrs[n]);
			n++;
		}
	}
}
std::string Pre_SolveCross1(Cube cube1)
{
	int ICS = cube1.IsCrossSolved(CrossColor);
	if (ICS)
	{
		//ColorPrint(ICS);
		//std::cout << "cross is solved\n";
		//CrossColor = ICS;
		return "";
	}
	int am = 0;
	int n = 0;
	std::vector<std::string> ngbrs;
	std::queue<std::string> q;
	Cube cur;
	std::string buff;
	for (int i = 0; i < 18; i++)
	{
		ngbrs.push_back(CreateNeighbors(i));
		q.push(ngbrs[n]);
		n++;
	}
	while (!q.empty())
	{
		cur = cube1;
		buff = q.front();
		am = cur.SetScramble(buff);
		if (am > 3)
			return "";
		q.pop();
		ICS = cur.IsCrossSolved(CrossColor);
		if (ICS)
		{
			//std::cout << buff << "\n";
			//ColorPrint(ICS);
			//std::cout << " cross is solved\n";
			//std::cout << "moves: " << am << "\n";
			//CrossColor = ICS;
			return buff;
		}
		for (int i = 0; i < 15; i++)
		{
			ngbrs.push_back(buff + CreateNeighbors(i, buff));
			q.push(ngbrs[n]);
			n++;
		}
	}
}
std::string Pre_SolveOneCrossPiece(Cube cube1)
{
	int ICS = cube1.IsOneBottomCrossPieceSolved(CrossColor);
	if (ICS)
	{
		//ColorPrint(ICS);
		//std::cout << "three cross pieces is solved\n";
		//CrossColor = ICS;
		return "";
	}
	int am = 0;
	int n = 0;
	std::vector<std::string> ngbrs;
	std::queue<std::string> q;
	Cube cur;
	std::string buff;
	for (int i = 0; i < 18; i++)
	{
		ngbrs.push_back(CreateNeighbors(i));
		q.push(ngbrs[n]);
		n++;
	}
	while (!q.empty())
	{
		cur = cube1;
		buff = q.front();
		am = cur.SetScramble(buff);
		q.pop();
		ICS = cur.IsOneBottomCrossPieceSolved(CrossColor);
		if (ICS)
		{
			//std::cout << buff << "\n";
			//ColorPrint(ICS);
			//std::cout << " three cross pieces is solved\n";
			//std::cout << "moves: " << am << "\n";
			//CrossColor = ICS;
			return buff;
		}
		for (int i = 0; i < 15; i++)
		{
			ngbrs.push_back(buff + CreateNeighbors(i, buff));
			q.push(ngbrs[n]);
			n++;
		}
	}
}
std::string Pre_SolveTwoCrossPieces(Cube cube1)
{
	int ICS = cube1.AreTwoBottomCrossPiecesSolved(CrossColor);
	if (ICS)
	{
		//ColorPrint(ICS);
		//std::cout << "three cross pieces is solved\n";
		//CrossColor = ICS;
		return "";
	}
	int am = 0;
	int n = 0;
	std::vector<std::string> ngbrs;
	std::queue<std::string> q;
	Cube cur;
	std::string buff;
	for (int i = 0; i < 18; i++)
	{
		ngbrs.push_back(CreateNeighbors(i));
		q.push(ngbrs[n]);
		n++;
	}
	while (!q.empty())
	{
		cur = cube1;
		buff = q.front();
		am = cur.SetScramble(buff);
		q.pop();
		ICS = cur.AreTwoBottomCrossPiecesSolved(CrossColor);
		if (ICS)
		{
			//std::cout << buff << "\n";
			//ColorPrint(ICS);
			//std::cout << " three cross pieces is solved\n";
			//std::cout << "moves: " << am << "\n";
			//CrossColor = ICS;
			return buff;
		}
		for (int i = 0; i < 15; i++)
		{
			ngbrs.push_back(buff + CreateNeighbors(i, buff));
			q.push(ngbrs[n]);
			n++;
		}
	}
}
std::string Pre_SolveThreeCrossPieces(Cube cube1)
{
	int ICS = cube1.AreThreeCrossPiecesSolved(CrossColor);
	if (ICS)
	{
		//ColorPrint(ICS);
		//std::cout << "three cross pieces is solved\n";
		//CrossColor = ICS;
		return "";
	}
	int am = 0;
	int n = 0;
	std::vector<std::string> ngbrs;
	std::queue<std::string> q;
	Cube cur;
	std::string buff;
	for (int i = 0; i < 18; i++)
	{
		ngbrs.push_back(CreateNeighbors(i));
		q.push(ngbrs[n]);
		n++;
	}
	while (!q.empty())
	{
		cur = cube1;
		buff = q.front();
		am = cur.SetScramble(buff);
		//if (am > 3)
		//	return "";
		q.pop();
		ICS = cur.AreThreeCrossPiecesSolved(CrossColor);
		if (ICS)
		{
			//std::cout << buff << "\n";
			//ColorPrint(ICS);
			//std::cout << " three cross pieces is solved\n";
			//std::cout << "moves: " << am << "\n";
			//CrossColor = ICS;
			return buff;
		}
		for (int i = 0; i < 15; i++)
		{
			ngbrs.push_back(buff + CreateNeighbors(i, buff));
			q.push(ngbrs[n]);
			n++;
		}
	}
}
std::string Pre_SolveFourCrossPieces(Cube cube1)
{
	int ICS = cube1.IsCrossSolved(CrossColor);
	if (ICS)
	{
		//ColorPrint(ICS);
		//std::cout << "cross is solved\n";
		return "";
	}
	int am = 0;
	int n = 0;
	std::vector<std::string> ngbrs;
	std::queue<std::string> q;
	Cube cur;
	std::string buff;
	for (int i = 0; i < 18; i++)
	{
		ngbrs.push_back(CreateNeighbors(i));
		q.push(ngbrs[n]);
		n++;
	}
	while (!q.empty())
	{
		cur = cube1;
		buff = q.front();
		am = cur.SetScramble(buff);
		q.pop();
		ICS = cur.IsCrossSolved(CrossColor);
		if (ICS)
		{
			//std::cout << buff << "\n";
			//ColorPrint(ICS);
			//std::cout << " cross is solved\n";
			//std::cout << "moves: " << am << "\n";
			return buff;
		}
		for (int i = 0; i < 15; i++)
		{
			ngbrs.push_back(buff + CreateNeighbors(i, buff));
			q.push(ngbrs[n]);
			n++;
		}
	}
}
std::string Pre_SolveOnePair(Cube cube1, std::string* sexymovecases, std::string* rotcases, std::string* aufcases, std::string* f2lcases)
{
	if (cube1.IsOneBottomPairSolved(CrossColor))
		return "";
	Cube cur, cur2, cur3, cur4;
	for (int l = 0; l < 21; l++)
	{
		cur = cube1;
		cur.SetScramble(sexymovecases[l]);
		cur2 = cur;
		for (int j = 0; j < 4; j++)
		{
			cur2 = cur;
			cur2.SetScramble(rotcases[j]);
			cur3 = cur2;
			for (int i = 0; i < 4; i++)
			{
				cur3 = cur2;
				cur3.SetScramble(aufcases[i]);
				cur4 = cur3;
				for (int n = 0; n < 103; n++)
				{
					cur4 = cur3;
					cur4.SetScramble(f2lcases[n]);
					//std::cout << i << " " << n << " " << aufcases[i] << " " << f2lcases[n] << "\n";
					//cur.PrintCube();
					if (cur4.IsOneBottomPairSolved(CrossColor))
					{
						return sexymovecases[l] + rotcases[j] + aufcases[i] + f2lcases[n];
					}
				}
			}
		}
	}
	std::cout << "error f2l 1st pair\n";
	return "";
}
std::string Pre_SolveTwoPairs(Cube cube1, std::string* sexymovecases, std::string* rotcases, std::string* aufcases, std::string* f2lcases)
{
	if (cube1.AreTwoBottomPairsSolved(CrossColor))
		return "";
	Cube cur, cur2, cur3, cur4;
	for (int l = 0; l < 21; l++)
	{
		cur = cube1;
		cur.SetScramble(sexymovecases[l]);
		cur2 = cur;
		for (int j = 0; j < 4; j++)
		{
			cur2 = cur;
			cur2.SetScramble(rotcases[j]);
			cur3 = cur2;
			for (int i = 0; i < 4; i++)
			{
				cur3 = cur2;
				cur3.SetScramble(aufcases[i]);
				cur4 = cur3;
				for (int n = 0; n < 103; n++)
				{
					cur4 = cur3;
					cur4.SetScramble(f2lcases[n]);
					//std::cout << i << " " << n << " " << aufcases[i] << " " << f2lcases[n] << "\n";
					//cur.PrintCube();
					if (cur4.AreTwoBottomPairsSolved(CrossColor))
					{
						return sexymovecases[l] + rotcases[j] + aufcases[i] + f2lcases[n];
					}
				}
			}
		}
	}
	std::cout << "error f2l 2nd pair\n";
	return "";
}
std::string Pre_SolveThreePairs(Cube cube1, std::string* sexymovecases, std::string* rotcases, std::string* aufcases, std::string* f2lcases)
{
	if (cube1.AreThreeBottomPairsSolved(CrossColor))
		return "";
	Cube cur, cur2, cur3, cur4;
	for (int l = 0; l < 21; l++)
	{
		cur = cube1;
		cur.SetScramble(sexymovecases[l]);
		cur2 = cur;
		for (int j = 0; j < 4; j++)
		{
			cur2 = cur;
			cur2.SetScramble(rotcases[j]);
			cur3 = cur2;
			for (int i = 0; i < 4; i++)
			{
				cur3 = cur2;
				cur3.SetScramble(aufcases[i]);
				cur4 = cur3;
				for (int n = 0; n < 103; n++)
				{
					cur4 = cur3;
					cur4.SetScramble(f2lcases[n]);
					//std::cout << i << " " << n << " " << aufcases[i] << " " << f2lcases[n] << "\n";
					//cur.PrintCube();
					if (cur4.AreThreeBottomPairsSolved(CrossColor))
					{
						return sexymovecases[l] + rotcases[j] + aufcases[i] + f2lcases[n];
					}
				}
			}
		}
	}
	std::cout << "error f2l 3rd pair\n";
	return "";
}
std::string Pre_SolveFourPairs(Cube cube1, std::string* aufcases, std::string* f2lcases)
{
	if (cube1.AreFourBottomPairsSolved(CrossColor))
		return "";
	// 1 - BLD unsolved; 2 - BRD unsolved; 3 - FRD unsolved; 4 - FLD unsolved.
	std::string rot;
	Cube cur = cube1;
	Cube cur2, cur3;
	switch (cube1.AreThreeBottomPairsSolved(CrossColor))
	{
	case 1:
		cur.TurnY2();
		rot = "y2";
		break;
	case 2:
		cur.TurnY();
		rot = "y";
		break;
	case 3:
		rot = "";
		break;
	case 4:
		cur.TurnYprime();
		rot = "y'";
		break;
	}
	std::string rot2;
	for (int i = 0; i < 4; i++)
	{
		cur2 = cur;
		cur2.SetScramble(aufcases[i]);
		cur3 = cur2;
		for (int n = 0; n < 103; n++)
		{
			cur2 = cur3;
			cur2.SetScramble(f2lcases[n]);
			//std::cout << i << " " << n << " " << aufcases[i] << " " << f2lcases[n] << "\n";
			//cur.PrintCube();
			if (cur2.AreFourBottomPairsSolved(CrossColor))
			{
				return rot + aufcases[i] + f2lcases[n];
			}
		}
	}
	std::cout << "error f2l\n";
	return "";
}
std::string Pre_OLL(Cube cube1, std::string* aufcases, std::string* ollcases)
{
	if (cube1.IsLastLayerOriented())
		return "";
	Cube cur, cur2;
	for (int i = 0; i < 4; i++)
	{
		cur = cube1;
		cur.SetScramble(aufcases[i]);
		cur2 = cur;
		for (int n = 0; n < 57; n++)
		{
			cur = cur2;
			cur.SetScramble(ollcases[n]);
			//std::cout << i << " " << n << " " << aufcases[i] << " " << f2lcases[n] << "\n";
			//cur.PrintCube();
			if (cur.IsLastLayerOriented())
			{
				return aufcases[i] + ollcases[n];
			}
		}
	}
	std::cout << "error oll\n";
	return "";
}
std::string Pre_PLL(Cube cube1, std::string* aufcases, std::string* pllcases)
{
	if (cube1.IsLastLayerPermuted())
		return "";
	Cube cur, cur2, cur3;
	for (int i = 0; i < 4; i++)
	{
		cur = cube1;
		cur.SetScramble(aufcases[i]);
		cur2 = cur;
		for (int n = 0; n < 21; n++)
		{
			cur = cur2;
			cur.SetScramble(pllcases[n]);
			//std::cout << i << " " << n << " " << aufcases[i] << " " << f2lcases[n] << "\n";
			//cur.PrintCube();
			for (int j = 0; j < 19; j++)
			{

				if (cur.IsLastLayerPermuted())
				{
					return aufcases[i] + pllcases[n];
				}
			}
		}
	}
	std::cout << "error pll\n";
	return "";
}
std::string Pre_AUF(Cube cube1, std::string* aufcases)
{
	if (cube1.IsSolved())
		return "";
	Cube cur, cur2;
	for (int i = 0; i < 4; i++)
	{
		cur = cube1;
		cur.SetScramble(aufcases[i]);
		if (cur.IsSolved())
		{
			return aufcases[i];
		}
	}
	std::cout << "error auf\n";
	return "";
}
std::string* ReadAlgsFromFiles(int a, int len)
{
	std::string path;
	int size;
	std::string* line = new std::string[len];
	if (a == 1)
	{
		path = "F2L.txt";
		size = 103;
		//std::string* line = new std::string[size];
		line[0] = "URU'R'";
		line[1] = "U'F'UF";
		line[2] = "RUR'";
		line[3] = "F'U'F";
		line[4] = "RU'R'URU'R'";
		line[5] = "F'UFU'F'UF";
		line[6] = "RUR'U'RUR'";
		line[7] = "F'U'FUF'U'F";
		line[8] = "U'RUR'U2RU'R'";
		line[9] = "UF'U'FU2F'UF";
		line[10] = "U'RU2R'U2RU'R'";
		line[11] = "UF'U2FU2F'UF";
		line[12] = "U'RU'R'UF'U'F";
		line[13] = "UF'UFU'RUR'";
		line[14] = "U'RU2R'UF'U'F";
		line[15] = "RU'R'URU'R'U2RU'R'";
		line[16] = "U'RU'R'URUR'";
		line[17] = "UF'UFU'F'U'F";
		line[18] = "R2B'R'BR'U2RU'R'";
		line[19] = "F2LFL'FU2F'UF";
		line[20] = "RU2R'U'RUR'";
		line[21] = "F'U2FUF'U'F";
		line[22] = "URU2R'URU'R'";
		line[23] = "U'F'U2FU'F'UF";
		line[24] = "U2RUR'URU'R'";
		line[25] = "U2F'U'FU'F'UF";
		line[26] = "URU'R'U'RU'R'URU'R'";
		line[27] = "U'F'UFUF'UFU'F'UF";
		line[28] = "R'F'RURU'R'F";
		line[29] = "URU'R'FR'F'R";
		line[30] = "U'R'FRF'RU'R'";
		line[31] = "URU'R'URU'R'URU'R'";
		line[32] = "U'RU'R'U2RU'R'";
		line[33] = "U'RU2R'URUR'";
		line[34] = "U'RUR'UF'U'F";
		line[35] = "UF'U'FU'RUR'";
		line[36] = "RU'R'U'RUR'U2RU'R'";
		line[37] = "F'UFUF'U'FU2F'UF";
		line[38] = "RU'R'U'RU'R'UF'U'F";
		line[39] = "F'UFU2RU'R'U'RUR'";
		line[40] = "RU'R'UF'U2FU2F'UF";
		line[41] = "U'R'UR2U'R'";
		line[42] = "B'RB2U'B'U2R'";
		line[43] = "UFU'F2UF";
		line[44] = "LF'L2ULU2F";
		line[45] = "U2L2DF2D'L2";
		line[46] = "LF'UFL'";
		line[47] = "B'R2BR2";
		line[48] = "FDRD'F'";
		line[49] = "U'L'U'LRU'R'";
		line[50] = "FU2F'RUR'";
		line[51] = "URUR'LUL'";
		line[52] = "U2F'LUL'F";
		line[53] = "UBUB'F'UF";
		line[54] = "R'U2RF'U'F";
		line[55] = "FUF2U'F";
		line[56] = "R'D'F'DR";
		line[57] = "U'RU'R'LU'L'";
		line[58] = "U2RB'U'BR'";
		line[59] = "URU'R'L'UL";
		line[60] = "F'U2FU'FUF'";
		line[61] = "U2RU'R'UL'U'L";
		line[62] = "U'F'U'F2U2F'";
		line[63] = "RL'ULR'";
		line[64] = "URUR'FUF'";
		line[65] = "RU2R'UR'U'R";
		line[66] = "U'F'UFBU'B'";
		line[67] = "U'RU'R'U'R'UR";
		line[68] = "F'BU'B'F";
		line[69] = "URUR2U2R";
		line[70] = "RUR'U2BUB'";
		line[71] = "U'R'FRF'U2LUL'";
		line[72] = "URU'R'B'U2B";
		line[73] = "RU'R'LU2L'";
		line[74] = "R'FRF'LU2L'";
		line[75] = "RU'R'ULUL'";
		line[76] = "F'UFB'U2B";
		line[77] = "R2U'R2UR2";
		line[78] = "B'D'RDB";
		line[79] = "F2UF2U'F2";
		line[80] = "LDF'D'L'";
		line[81] = "R'FR2U'R2F'R";
		line[82] = "B'RBR'F'UF";
		line[83] = "RLU2L'R'";
		line[84] = "L2DF2D'L2";
		line[85] = "R2DB2D'R2";
		line[86] = "R2D'F2DR2";
		line[87] = "RDB'UBD'R'";
		line[88] = "R'FR2U'R'U2F'";
		line[89] = "R'FRF'R'U'R";
		line[90] = "FR'URF'";
		line[91] = "R'FU'F'R";
		line[92] = "R'FUF'R";
		line[93] = "FR'U'RF'";
		line[94] = "UR'U'R2UR2U'R";
		line[95] = "U'RUR2U'R2UR'";
		line[96] = "F'RUR'U'R'FR";
		line[97] = "R'F'RURU'R'F";
		line[98] = "R2U'R2UR2";
		line[99] = "R2UR2U'R2";
		line[100] = "FRU'R'U'F'";
		line[101] = "LF'R'FRFL'";
		line[102] = "U'RUR2U'R";}
	if(a ==2){

	
	
		path = "OLL.txt";
		size = 57;
		//std::string* line = new std::string[57];
		line[0] = "RU'U'R2FRF'U2R'FRF'";
		line[1] = "FRUR'U'F'BULU'L'B'";
		line[2] = "L'RB'LU2L'B'RB'R2L";
		line[3] = "L'R2BR'BLU2L'BR'L";
		line[4] = "RUR'UR'FRF'U2R'FRF'";
		line[5] = "LFR'FRF'F'L2B'RB'R'BBL";
		line[6] = "L'B2RBR'BL2F2R'F'RF'L'";
		line[7] = "L'RBRBR'B'L2R2FRF'L'";
		line[8] = "RU'U'R2U'RU'R'U2FRF'";
		line[9] = "FRUR'U'RF'LFR'F'L'";
		line[10] = "FURU'R'URU'R'F'";
		line[11] = "R'U'RU'R'UF'UFR";
		line[12] = "LF2R'F'RFR'F'RF'L'";
		line[13] = "L'B2RBR'B'RBR'BL";
		line[14] = "RB'R2FR2BR2F'R";
		line[15] = "R'FR2B'R2F'R2BR'";
		line[16] = "FRUR'U'RUR'U'F'";
		line[17] = "B'R'U'RUR'U'RUB";
		line[18] = "LFR'FRF'F'L'";
		line[19] = "L'B'RB'R'BBL";
		line[20] = "LR2F'RF'R'FFRF'RL'";
		line[21] = "L'R2BR'BRB'B'R'BR'L";
		line[22] = "R'U'RFR'F'UFRF'";
		line[23] = "U2RUR'UR'FRF'RU2R'";
		line[24] = "L'B2RBR'BL";
		line[25] = "LF2R'F'RF'L'";
		line[26] = "FURU'U'R'U'RUR'F'";
		line[27] = "R'FRUR'F'RFU'F'";
		line[28] = "LFL'RUR'U'LF'L'";
		line[29] = "R'F'RL'U'LUR'FR";
		line[30] = "RUR'URU'U'R'FRUR'U'F'";
		line[31] = "R'U'RUFRUR'U'R'URU'F'";
		line[32] = "R2UR'B'RU'R2URBR'";
		line[33] = "RUR'U'RU'R'F'U'FRUR'";
		line[34] = "RUB'U'R'URBR'";
		line[35] = "R'U'FURU'R'F'R";
		line[36] = "FRU'R'U'RUR'F'";
		line[37] = "FURU'R'F'";
		line[38] = "B'U'R'URB";
		line[39] = "RU'U'R2FRF'RU'U'R'";
		line[40] = "FRUR'U'F'";
		line[41] = "RUR'U'R'FRF'";
		line[42] = "RB'R'U'RUBU'R'";
		line[43] = "R'FRUR'U'F'UR";
		line[44] = "RUR2U'R'FRURU'F'";
		line[45] = "R'U'R'FRF'UR";
		line[46] = "RUR'URU'R'U'R'FRF'";
		line[47] = "R'U'RU'R'URURB'R'B";
		line[48] = "RU2R'U'RUR'U'RU'R'";
		line[49] = "RU2R2U'R2U'R2U2R";
		line[50] = "R'U2RFU'R'U'RUF'";
		line[51] = "LFR'F'L'FRF'";
		line[52] = "F'LFR'F'L'FR";
		line[53] = "RU2R'U'RU'R'";
		line[54] = "RUR'URU2R'";
		line[55] = "LFR'F'L'RURU'R'";
		line[56] = "RUR'U'LR'FRF'L'";
		}
		if(a==3){

	
	
		path = "PLL.txt";
		size = 21;
		//std::string* line = new std::string[21];
		line[0] = "R'FR'B2RF'R'B2R2";
		line[1] = "R2B2RFR'B2RF'R";
		line[2] = "R'U'R'D'RU'R'DRUR'D'RUR'DR2";
		line[3] = "R'UR'U'R'U'R'URUR2";
		line[4] = "R2U'R'U'RURURU'R";
		line[5] = "R'U'RU'RURU'R'URUR2U'R'";
		line[6] = "R2U2R'U2R2U2R2U2R'U2R2";
		line[7] = "RUR'F'RUR'U'R'FR2U'R'";
		line[8] = "L'R'U2RUR'U2LU'R";
		line[9] = "R'U2RU2R'FRUR'U'R'F'R2";
		line[10] = "RU2R'U2RB'R'U'RURBR2";
		line[11] = "RUR'U'R'FR2U'R'U'RUR'F'";
		line[12] = "R'U'F'RUR'U'R'FR2U'R'U'RUR'U R";
		line[13] = "L'URU'LUL'UR'U'LU2RU2R'";
		line[14] = "FRU'R'U'RUR'F'RUR'U'R'FRF'";
		line[15] = "R'URU'R'F'U'FRUR'FR'F'RU'R";
		line[16] = "RU'R'URBUB'R'U'RB'RBR'UR'";
		line[17] = "RUR'F2D'LU'L'UL'DF2";
		line[18] = "R2D'FU'FUF'DR2BU'B'";
		line[19] = "F'U'FR2DB'UBU'BD'R2";
		line[20] = "R2DB'UB'U'BD'R2F'UF";
		
			}
			
	if(a==4){

		path = "Scrambles.txt";
		//size = len;
	
	}
	

	/*
	if (line == NULL)
		return NULL;
	int i = 0;
	std::ifstream fin;
	fin.open(path);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			getline(fin, line[i]);
			//std::cout << line[i] << std::endl;
			i++;
		}
	}else{
		std::cout << "couldnt read" << std::endl;
	}
	fin.close();
	*/
	return line;
}
std::string* ReadAlgsFromFile(int a, int len)
{
	std::string path;
	int size;
	std::string* line = new std::string[len];

	if (a == 1)
	{
		path = "F2L.txt";
		size = 103;
		//std::string* line = new std::string[size];
		line[0] = "URU'R'";
		line[1] = "U'F'UF";
		line[2] = "RUR'";
		line[3] = "F'U'F";
		line[4] = "RU'R'URU'R'";
		line[5] = "F'UFU'F'UF";
		line[6] = "RUR'U'RUR'";
		line[7] = "F'U'FUF'U'F";
		line[8] = "U'RUR'U2RU'R'";
		line[9] = "UF'U'FU2F'UF";
		line[10] = "U'RU2R'U2RU'R'";
		line[11] = "UF'U2FU2F'UF";
		line[12] = "U'RU'R'UF'U'F";
		line[13] = "UF'UFU'RUR'";
		line[14] = "U'RU2R'UF'U'F";
		line[15] = "RU'R'URU'R'U2RU'R'";
		line[16] = "U'RU'R'URUR'";
		line[17] = "UF'UFU'F'U'F";
		line[18] = "R2B'R'BR'U2RU'R'";
		line[19] = "F2LFL'FU2F'UF";
		line[20] = "RU2R'U'RUR'";
		line[21] = "F'U2FUF'U'F";
		line[22] = "URU2R'URU'R'";
		line[23] = "U'F'U2FU'F'UF";
		line[24] = "U2RUR'URU'R'";
		line[25] = "U2F'U'FU'F'UF";
		line[26] = "URU'R'U'RU'R'URU'R'";
		line[27] = "U'F'UFUF'UFU'F'UF";
		line[28] = "R'F'RURU'R'F";
		line[29] = "URU'R'FR'F'R";
		line[30] = "U'R'FRF'RU'R'";
		line[31] = "URU'R'URU'R'URU'R'";
		line[32] = "U'RU'R'U2RU'R'";
		line[33] = "U'RU2R'URUR'";
		line[34] = "U'RUR'UF'U'F";
		line[35] = "UF'U'FU'RUR'";
		line[36] = "RU'R'U'RUR'U2RU'R'";
		line[37] = "F'UFUF'U'FU2F'UF";
		line[38] = "RU'R'U'RU'R'UF'U'F";
		line[39] = "F'UFU2RU'R'U'RUR'";
		line[40] = "RU'R'UF'U2FU2F'UF";
		line[41] = "U'R'UR2U'R'";
		line[42] = "B'RB2U'B'U2R'";
		line[43] = "UFU'F2UF";
		line[44] = "LF'L2ULU2F";
		line[45] = "U2L2DF2D'L2";
		line[46] = "LF'UFL'";
		line[47] = "B'R2BR2";
		line[48] = "FDRD'F'";
		line[49] = "U'L'U'LRU'R'";
		line[50] = "FU2F'RUR'";
		line[51] = "URUR'LUL'";
		line[52] = "U2F'LUL'F";
		line[53] = "UBUB'F'UF";
		line[54] = "R'U2RF'U'F";
		line[55] = "FUF2U'F";
		line[56] = "R'D'F'DR";
		line[57] = "U'RU'R'LU'L'";
		line[58] = "U2RB'U'BR'";
		line[59] = "URU'R'L'UL";
		line[60] = "F'U2FU'FUF'";
		line[61] = "U2RU'R'UL'U'L";
		line[62] = "U'F'U'F2U2F'";
		line[63] = "RL'ULR'";
		line[64] = "URUR'FUF'";
		line[65] = "RU2R'UR'U'R";
		line[66] = "U'F'UFBU'B'";
		line[67] = "U'RU'R'U'R'UR";
		line[68] = "F'BU'B'F";
		line[69] = "URUR2U2R";
		line[70] = "RUR'U2BUB'";
		line[71] = "U'R'FRF'U2LUL'";
		line[72] = "URU'R'B'U2B";
		line[73] = "RU'R'LU2L'";
		line[74] = "R'FRF'LU2L'";
		line[75] = "RU'R'ULUL'";
		line[76] = "F'UFB'U2B";
		line[77] = "R2U'R2UR2";
		line[78] = "B'D'RDB";
		line[79] = "F2UF2U'F2";
		line[80] = "LDF'D'L'";
		line[81] = "R'FR2U'R2F'R";
		line[82] = "B'RBR'F'UF";
		line[83] = "RLU2L'R'";
		line[84] = "L2DF2D'L2";
		line[85] = "R2DB2D'R2";
		line[86] = "R2D'F2DR2";
		line[87] = "RDB'UBD'R'";
		line[88] = "R'FR2U'R'U2F'";
		line[89] = "R'FRF'R'U'R";
		line[90] = "FR'URF'";
		line[91] = "R'FU'F'R";
		line[92] = "R'FUF'R";
		line[93] = "FR'U'RF'";
		line[94] = "UR'U'R2UR2U'R";
		line[95] = "U'RUR2U'R2UR'";
		line[96] = "F'RUR'U'R'FR";
		line[97] = "R'F'RURU'R'F";
		line[98] = "R2U'R2UR2";
		line[99] = "R2UR2U'R2";
		line[100] = "FRU'R'U'F'";
		line[101] = "LF'R'FRFL'";
		line[102] = "U'RUR2U'R";}
	if(a ==2){

	
	
		path = "OLL.txt";
		size = 57;
		//std::string* line = new std::string[57];
		line[0] = "RU'U'R2FRF'U2R'FRF'";
		line[1] = "FRUR'U'F'BULU'L'B'";
		line[2] = "L'RB'LU2L'B'RB'R2L";
		line[3] = "L'R2BR'BLU2L'BR'L";
		line[4] = "RUR'UR'FRF'U2R'FRF'";
		line[5] = "LFR'FRF'F'L2B'RB'R'BBL";
		line[6] = "L'B2RBR'BL2F2R'F'RF'L'";
		line[7] = "L'RBRBR'B'L2R2FRF'L'";
		line[8] = "RU'U'R2U'RU'R'U2FRF'";
		line[9] = "FRUR'U'RF'LFR'F'L'";
		line[10] = "FURU'R'URU'R'F'";
		line[11] = "R'U'RU'R'UF'UFR";
		line[12] = "LF2R'F'RFR'F'RF'L'";
		line[13] = "L'B2RBR'B'RBR'BL";
		line[14] = "RB'R2FR2BR2F'R";
		line[15] = "R'FR2B'R2F'R2BR'";
		line[16] = "FRUR'U'RUR'U'F'";
		line[17] = "B'R'U'RUR'U'RUB";
		line[18] = "LFR'FRF'F'L'";
		line[19] = "L'B'RB'R'BBL";
		line[20] = "LR2F'RF'R'FFRF'RL'";
		line[21] = "L'R2BR'BRB'B'R'BR'L";
		line[22] = "R'U'RFR'F'UFRF'";
		line[23] = "U2RUR'UR'FRF'RU2R'";
		line[24] = "L'B2RBR'BL";
		line[25] = "LF2R'F'RF'L'";
		line[26] = "FURU'U'R'U'RUR'F'";
		line[27] = "R'FRUR'F'RFU'F'";
		line[28] = "LFL'RUR'U'LF'L'";
		line[29] = "R'F'RL'U'LUR'FR";
		line[30] = "RUR'URU'U'R'FRUR'U'F'";
		line[31] = "R'U'RUFRUR'U'R'URU'F'";
		line[32] = "R2UR'B'RU'R2URBR'";
		line[33] = "RUR'U'RU'R'F'U'FRUR'";
		line[34] = "RUB'U'R'URBR'";
		line[35] = "R'U'FURU'R'F'R";
		line[36] = "FRU'R'U'RUR'F'";
		line[37] = "FURU'R'F'";
		line[38] = "B'U'R'URB";
		line[39] = "RU'U'R2FRF'RU'U'R'";
		line[40] = "FRUR'U'F'";
		line[41] = "RUR'U'R'FRF'";
		line[42] = "RB'R'U'RUBU'R'";
		line[43] = "R'FRUR'U'F'UR";
		line[44] = "RUR2U'R'FRURU'F'";
		line[45] = "R'U'R'FRF'UR";
		line[46] = "RUR'URU'R'U'R'FRF'";
		line[47] = "R'U'RU'R'URURB'R'B";
		line[48] = "RU2R'U'RUR'U'RU'R'";
		line[49] = "RU2R2U'R2U'R2U2R";
		line[50] = "R'U2RFU'R'U'RUF'";
		line[51] = "LFR'F'L'FRF'";
		line[52] = "F'LFR'F'L'FR";
		line[53] = "RU2R'U'RU'R'";
		line[54] = "RUR'URU2R'";
		line[55] = "LFR'F'L'RURU'R'";
		line[56] = "RUR'U'LR'FRF'L'";
		}
		if(a==3){

	
	
		path = "PLL.txt";
		size = 21;
		//std::string* line = new std::string[21];
		line[0] = "R'FR'B2RF'R'B2R2";
		line[1] = "R2B2RFR'B2RF'R";
		line[2] = "R'U'R'D'RU'R'DRUR'D'RUR'DR2";
		line[3] = "R'UR'U'R'U'R'URUR2";
		line[4] = "R2U'R'U'RURURU'R";
		line[5] = "R'U'RU'RURU'R'URUR2U'R'";
		line[6] = "R2U2R'U2R2U2R2U2R'U2R2";
		line[7] = "RUR'F'RUR'U'R'FR2U'R'";
		line[8] = "L'R'U2RUR'U2LU'R";
		line[9] = "R'U2RU2R'FRUR'U'R'F'R2";
		line[10] = "RU2R'U2RB'R'U'RURBR2";
		line[11] = "RUR'U'R'FR2U'R'U'RUR'F'";
		line[12] = "R'U'F'RUR'U'R'FR2U'R'U'RUR'U R";
		line[13] = "L'URU'LUL'UR'U'LU2RU2R'";
		line[14] = "FRU'R'U'RUR'F'RUR'U'R'FRF'";
		line[15] = "R'URU'R'F'U'FRUR'FR'F'RU'R";
		line[16] = "RU'R'URBUB'R'U'RB'RBR'UR'";
		line[17] = "RUR'F2D'LU'L'UL'DF2";
		line[18] = "R2D'FU'FUF'DR2BU'B'";
		line[19] = "F'U'FR2DB'UBU'BD'R2";
		line[20] = "R2DB'UB'U'BD'R2F'UF";
		
			}
			
	if(a==4){

		path = "Scrambles.txt";
		//size = len;
	
	}
	/*if (line == NULL)
		return NULL;
	int i = 0;
	std::ifstream fin;
	fin.open(path);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			getline(fin, line[i]);
			//std::cout << line[i] << std::endl;
			i++;
		}
	}else{
		std::cout << "couldnt read" << std::endl;
	}
	fin.close();*/
	return line;
}
