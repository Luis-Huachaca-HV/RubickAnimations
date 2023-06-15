#pragma once
#include "Header.h"
#include <vector>
#include <string>
#include <sstream>
using namespace std;


//Testing Functions
void TestFromFile(int size)
{
	std::string solve;
	int am;
	int avg = 0;
	std::string* scramble = ReadAlgsFromFile(4, size);
	Cube Cube1;
	for (int i = 0; i < size; i++)
	{
		Cube1.SetScramble(scramble[i]);
		solve = SolveCube(Cube1, "File");
		am = Cube1.SetScramble(solve);
		std::cout << i + 1 << " Moves: " << am << '\n';
		//std::cout << "Solution: " << solve << '\n';
		if (!Cube1.IsSolved())
			std::cout << "Cube isn't solved\n";
		//Cube1.PrintBoolIsSolved();
		std::cout << '\n';
		avg += am;
	}
	std::cout << "AVG Moves: " << avg / 1000 << '\n';
}

string testFromCube(string scramblecube){

	std::string solve;
	int am;
	Cube Cube1;
	//std::string scramble;
	std::cout << "Don't use {x, y, z, l, r, u, d, f, b, M, S, E} \n Use only {L, R, U, D, F, B} and (\"'\" , \"2\")\n";
	//while (true)
	//{
		std::cout << "Enter the scramble:\n";
		std::cout << scramblecube << std::endl;
		//std::cin >> scramble;

		Cube1.PrintCube();
		Cube1.SetScramble(scramblecube);
		Cube1.PrintCube();
		solve = SolveCube(Cube1, "CMD");
		am = Cube1.SetScramble(solve);
		std::cout << "Movess: " << am << '\n';
		std::cout << "Solutions: " << solve << '\n';
		//std::vector<std::string> convertedMoves = convertMoves(solve);

		//for (const std::string& move : convertedMoves) {
        //			std::cout << move << " ";
	    //}
    //std::cout << std::endl;
		Cube1.PrintCube();
		Cube1.PrintBoolIsSolved();
		std::cout << '\n';
	//}
	return solve;

}
void TestFromCMD()
{
	std::string solve;
	int am;
	Cube Cube1;
	std::string scramble;
	std::cout << "Don't use {x, y, z, l, r, u, d, f, b, M, S, E} \n Use only {L, R, U, D, F, B} and (\"'\" , \"2\")\n";
	//while (true)
	//{
		std::cout << "Enter the scramblSe:\n";
		//std::cin >> scramble;
		scramble = "LFLFLFLLFFFL";
		Cube1.SetScramble(scramble);
		Cube1.PrintCube();
		solve = SolveCube(Cube1, "CMD");
		am = Cube1.SetScramble(solve);
		std::cout << "Movess: " << am << '\n';
		std::cout << "Solutions: " << solve << '\n';
		//std::vector<std::string> convertedMoves = convertMoves(solve);

		//for (const std::string& move : convertedMoves) {
        //			std::cout << move << " ";
	    //}
    //std::cout << std::endl;
		Cube1.PrintCube();
		Cube1.PrintBoolIsSolved();
		std::cout << '\n';
		
//	}


}
int randomNum()
{
	int a = rand() % 100 + 1;
	return a;
}
std::string TestViaGenerator() {
	std::string setArray[6] = { "U", "F", "B", "D", "R", "L" };
	srand(time(0));
	int i = 0;
	std::string completedMove;
	int totalNum;
	int inputLength = 25;
	std::string scr = "";
	std::string turn;

	while (i++ < inputLength) {
		bool doTwo = false;
		bool addOne = false;
		bool ignore = false;
		int r = randomNum();
		int initFirst = (r % 10);
		int initNon = ((int)(r / 10));
		if ((initNon) > 5) {
			addOne = true;
		}
		if ((((initNon) * 3) % 10) > 3) {
			doTwo = true;
		}
		if (initFirst > 5) {
			initFirst = initFirst / 2;
		}
		turn = setArray[initFirst];
		r /= 10;
		if (turn != completedMove) {
			if (addOne == true && ignore == false) {
				if (doTwo == true) {
					scr += turn + "2 ";
				}
				else {
					scr += turn + "' ";
				}
			}
			else if (addOne != true && ignore == false) {
				if (doTwo == true) {
					scr += turn + "2 ";
				}
				else {
					scr += turn + " ";
				}
			}
		}
		completedMove = turn;
	}
	return scr;
}