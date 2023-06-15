#pragma once
#include "Header.h"

//Cube Representation
class Corner
{
	//Clockwise Reading
	//Corner_ColorN
private:
	int C_C1;
	int C_C2;
	int C_C3;

public:
	int GetC_C1()
	{
		return C_C1;
	}
	int GetC_C2()
	{
		return C_C2;
	}
	int GetC_C3()
	{
		return C_C3;
	}
	void SetC_C1(int C_Value)
	{
		C_C1 = C_Value;
	}
	void SetC_C2(int C_Value)
	{
		C_C2 = C_Value;
	}
	void SetC_C3(int C_Value)
	{
		C_C3 = C_Value;
	}
	void PrintC_C1()
	{
		ColorPrint(C_C1);
	}
	void PrintC_C2()
	{
		ColorPrint(C_C2);
	}
	void PrintC_C3()
	{
		ColorPrint(C_C3);
	}
	void SetCorner(int C_Value1, int C_Value2, int C_Value3)
	{
		C_C1 = C_Value1;
		C_C2 = C_Value2;
		C_C3 = C_Value3;
	}
	void PrintCorner()
	{
		ColorPrint(C_C1);
		ColorPrint(C_C2);
		ColorPrint(C_C3);
	}
	bool IsEqualTo(Corner a)
	{
		if (GetC_C1() == a.GetC_C1() && GetC_C2() == a.GetC_C2() && GetC_C3() == a.GetC_C3())
			return true;
		else
			return false;
	}
};
class Edge
{
	//Clockwise Reading
	//Edge_ColorN
private:
	int E_C1;
	int E_C2;
public:
	int GetE_C1()
	{
		return E_C1;
	}
	int GetE_C2()
	{
		return E_C2;
	}
	void SetE_C1(int E_Value)
	{
		E_C1 = E_Value;
	}
	void SetE_C2(int E_Value)
	{
		E_C2 = E_Value;
	}
	void PrintE_C1()
	{
		ColorPrint(E_C1);
	}
	void PrintE_C2()
	{
		ColorPrint(E_C2);
	}
	void SetEdge(int E_Value1, int E_Value2)
	{
		E_C1 = E_Value1;
		E_C2 = E_Value2;
	}
	void PrintE_CN()
	{
		ColorPrint(E_C1);
		ColorPrint(E_C2);
	}
	bool IsEqualTo(Edge a)
	{
		if (GetE_C1() == a.GetE_C1() && GetE_C2() == a.GetE_C2())
			return true;
		else
			return false;
	}
};
class Center
{
private:
	int Cen_C;
public:
	int GetCenter()
	{
		return Cen_C;
	}
	void PrintCenter()
	{
		ColorPrint(Cen_C);
	}
	void SetCenter(int Cen_Value)
	{
		Cen_C = Cen_Value;
	}
	bool IsEqualTo(Center a)
	{
		if (GetCenter() == a.GetCenter())
			return true;
		else
			return false;
	}
};
class Cube
{
private:
	Corner FRU, FLU, FRD, FLD, BRU, BLU, BRD, BLD;
	Edge FU, FD, FL, FR, BU, BD, BL, BR, RU, RD, LU, LD;
	Center FRONT, UP, BACK, DOWN, RIGHT, LEFT;
	int Cross = 0;

public:
	void SetCrossColor(int a)
	{
		Cross = a;
	}
	int GetCrossColor()
	{
		if (Cross != 0)
			return Cross;
		else
		{
			std::cout << "cross color isn't set\n";
			return 0;
		}
	}
	void SetSolveState()
	{
		FRU.SetCorner(W, R, G);
		FLU.SetCorner(W, G, O);
		FRD.SetCorner(Y, G, R);
		FLD.SetCorner(Y, O, G);
		BRU.SetCorner(W, B, R);
		BLU.SetCorner(W, O, B);
		BRD.SetCorner(Y, R, B);
		BLD.SetCorner(Y, B, O);
		FU.SetEdge(W, G);
		FD.SetEdge(G, Y);
		FL.SetEdge(O, G);
		FR.SetEdge(G, R);
		BU.SetEdge(W, B);
		BD.SetEdge(B, Y);
		BL.SetEdge(O, B);
		BR.SetEdge(R, B);
		RU.SetEdge(W, R);
		RD.SetEdge(R, Y);
		LU.SetEdge(O, W);
		LD.SetEdge(Y, O);
		FRONT.SetCenter(G);
		UP.SetCenter(W);
		BACK.SetCenter(B);
		DOWN.SetCenter(Y);
		RIGHT.SetCenter(R);
		LEFT.SetCenter(O);
	};
	bool IsSolved()
	{
		if (AreValuesEqual(BLU.GetC_C1(), BU.GetE_C1(), BRU.GetC_C1(), LU.GetE_C2(), UP.GetCenter(), RU.GetE_C1(), FLU.GetC_C1(), FU.GetE_C1(), FRU.GetC_C1()))
		{
			if (AreValuesEqual(BLU.GetC_C2(), LU.GetE_C1(), FLU.GetC_C3(), BL.GetE_C1(), LEFT.GetCenter(), FL.GetE_C1(), BLD.GetC_C3(), LD.GetE_C2(), FLD.GetC_C2()))
			{
				if (AreValuesEqual(FLU.GetC_C2(), FU.GetE_C2(), FRU.GetC_C3(), FL.GetE_C2(), FRONT.GetCenter(), FR.GetE_C1(), FLD.GetC_C3(), FD.GetE_C1(), FRD.GetC_C2()))
				{
					if (AreValuesEqual(FRU.GetC_C2(), RU.GetE_C2(), BRU.GetC_C3(), FR.GetE_C2(), RIGHT.GetCenter(), BR.GetE_C1(), FRD.GetC_C3(), RD.GetE_C1(), BRD.GetC_C2()))
					{
						if (AreValuesEqual(BRU.GetC_C2(), BU.GetE_C2(), BLU.GetC_C3(), BR.GetE_C2(), BACK.GetCenter(), BL.GetE_C2(), BRD.GetC_C3(), BD.GetE_C1(), BLD.GetC_C2()))
						{
							if (AreValuesEqual(FLD.GetC_C1(), FD.GetE_C2(), FRD.GetC_C1(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BLD.GetC_C1(), BD.GetE_C2(), BRD.GetC_C1()))
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
	void PrintBoolIsSolved()
	{
		if (IsSolved())
			std::cout << "Cube is solved" << "\n";
		else
			std::cout << "Cube isn't solved" << "\n";
	}
	bool AreAllCrossesSolved()
	{
		if (AreValuesEqual(BU.GetE_C1(), LU.GetE_C2(), UP.GetCenter(), RU.GetE_C1(), FU.GetE_C1()) && (BU.GetE_C2() == BACK.GetCenter()) && (LU.GetE_C1() == LEFT.GetCenter()) && (RU.GetE_C2() == RIGHT.GetCenter()) && (FU.GetE_C2() == FRONT.GetCenter()))
		{
			if (AreValuesEqual(LU.GetE_C1(), BL.GetE_C1(), LEFT.GetCenter(), FL.GetE_C1(), LD.GetE_C2()) && (LU.GetE_C2() == UP.GetCenter()) && (BL.GetE_C2() == BACK.GetCenter()) && (FL.GetE_C2() == FRONT.GetCenter()) && (LD.GetE_C1() == DOWN.GetCenter()))
			{
				if (AreValuesEqual(FU.GetE_C2(), FL.GetE_C2(), FRONT.GetCenter(), FR.GetE_C1(), FD.GetE_C1()) && (FU.GetE_C1() == UP.GetCenter()) && (FL.GetE_C1() == LEFT.GetCenter()) && (FR.GetE_C2() == RIGHT.GetCenter()) && (FD.GetE_C2() == DOWN.GetCenter()))
				{
					if (AreValuesEqual(RU.GetE_C2(), FR.GetE_C2(), RIGHT.GetCenter(), BR.GetE_C1(), RD.GetE_C1()) && (RU.GetE_C1() == UP.GetCenter()) && (FR.GetE_C1() == FRONT.GetCenter()) && (BR.GetE_C2() == BACK.GetCenter()) && (RD.GetE_C2() == DOWN.GetCenter()))
					{
						if (AreValuesEqual(BU.GetE_C2(), BR.GetE_C2(), BACK.GetCenter(), BL.GetE_C2(), BD.GetE_C1()) && (BU.GetE_C1() == UP.GetCenter()) && (BR.GetE_C1() == RIGHT.GetCenter()) && (BL.GetE_C1() == LEFT.GetCenter()) && (BD.GetE_C2() == DOWN.GetCenter()))
						{
							if (AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2()) && (FD.GetE_C1() == FRONT.GetCenter()) && (RD.GetE_C1() == RIGHT.GetCenter()) && (BD.GetE_C1() == BACK.GetCenter()) && (LD.GetE_C2() == LEFT.GetCenter()))
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
	int IsCrossSolved()
	{
		if (AreValuesEqual(BU.GetE_C1(), LU.GetE_C2(), UP.GetCenter(), RU.GetE_C1(), FU.GetE_C1()) && (BU.GetE_C2() == BACK.GetCenter()) && (LU.GetE_C1() == LEFT.GetCenter()) && (RU.GetE_C2() == RIGHT.GetCenter()) && (FU.GetE_C2() == FRONT.GetCenter()))
		{
			return UP.GetCenter();
		}
		else if (AreValuesEqual(LU.GetE_C1(), BL.GetE_C1(), LEFT.GetCenter(), FL.GetE_C1(), LD.GetE_C2()) && (LU.GetE_C2() == UP.GetCenter()) && (BL.GetE_C2() == BACK.GetCenter()) && (FL.GetE_C2() == FRONT.GetCenter()) && (LD.GetE_C1() == DOWN.GetCenter()))
		{
			return LEFT.GetCenter();
		}
		else if (AreValuesEqual(FU.GetE_C2(), FL.GetE_C2(), FRONT.GetCenter(), FR.GetE_C1(), FD.GetE_C1()) && (FU.GetE_C1() == UP.GetCenter()) && (FL.GetE_C1() == LEFT.GetCenter()) && (FR.GetE_C2() == RIGHT.GetCenter()) && (FD.GetE_C2() == DOWN.GetCenter()))
		{
			return FRONT.GetCenter();
		}
		else if (AreValuesEqual(RU.GetE_C2(), FR.GetE_C2(), RIGHT.GetCenter(), BR.GetE_C1(), RD.GetE_C1()) && (RU.GetE_C1() == UP.GetCenter()) && (FR.GetE_C1() == FRONT.GetCenter()) && (BR.GetE_C2() == BACK.GetCenter()) && (RD.GetE_C2() == DOWN.GetCenter()))
		{
			return RIGHT.GetCenter();
		}
		else if (AreValuesEqual(BU.GetE_C2(), BR.GetE_C2(), BACK.GetCenter(), BL.GetE_C2(), BD.GetE_C1()) && (BU.GetE_C1() == UP.GetCenter()) && (BR.GetE_C1() == RIGHT.GetCenter()) && (BL.GetE_C1() == LEFT.GetCenter()) && (BD.GetE_C2() == DOWN.GetCenter()))
		{
			return BACK.GetCenter();
		}
		else if (AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2()) && (FD.GetE_C1() == FRONT.GetCenter()) && (RD.GetE_C1() == RIGHT.GetCenter()) && (BD.GetE_C1() == BACK.GetCenter()) && (LD.GetE_C2() == LEFT.GetCenter()))
		{
			return DOWN.GetCenter();
		}
		else
			return 0;
	}
	int IsCrossSolved(int a)
	{
		if ((AreValuesEqual(BU.GetE_C1(), LU.GetE_C2(), UP.GetCenter(), RU.GetE_C1(), FU.GetE_C1()) && (BU.GetE_C2() == BACK.GetCenter()) && (LU.GetE_C1() == LEFT.GetCenter()) && (RU.GetE_C2() == RIGHT.GetCenter()) && (FU.GetE_C2() == FRONT.GetCenter())) && (UP.GetCenter() == a))
		{
			return UP.GetCenter();
		}
		else if ((AreValuesEqual(LU.GetE_C1(), BL.GetE_C1(), LEFT.GetCenter(), FL.GetE_C1(), LD.GetE_C2()) && (LU.GetE_C2() == UP.GetCenter()) && (BL.GetE_C2() == BACK.GetCenter()) && (FL.GetE_C2() == FRONT.GetCenter()) && (LD.GetE_C1() == DOWN.GetCenter())) && (LEFT.GetCenter() == a))
		{
			return LEFT.GetCenter();
		}
		else if ((AreValuesEqual(FU.GetE_C2(), FL.GetE_C2(), FRONT.GetCenter(), FR.GetE_C1(), FD.GetE_C1()) && (FU.GetE_C1() == UP.GetCenter()) && (FL.GetE_C1() == LEFT.GetCenter()) && (FR.GetE_C2() == RIGHT.GetCenter()) && (FD.GetE_C2() == DOWN.GetCenter())) && (FRONT.GetCenter() == a))
		{
			return FRONT.GetCenter();
		}
		else if ((AreValuesEqual(RU.GetE_C2(), FR.GetE_C2(), RIGHT.GetCenter(), BR.GetE_C1(), RD.GetE_C1()) && (RU.GetE_C1() == UP.GetCenter()) && (FR.GetE_C1() == FRONT.GetCenter()) && (BR.GetE_C2() == BACK.GetCenter()) && (RD.GetE_C2() == DOWN.GetCenter())) && (RIGHT.GetCenter() == a))
		{
			return RIGHT.GetCenter();
		}
		else if ((AreValuesEqual(BU.GetE_C2(), BR.GetE_C2(), BACK.GetCenter(), BL.GetE_C2(), BD.GetE_C1()) && (BU.GetE_C1() == UP.GetCenter()) && (BR.GetE_C1() == RIGHT.GetCenter()) && (BL.GetE_C1() == LEFT.GetCenter()) && (BD.GetE_C2() == DOWN.GetCenter())) && (BACK.GetCenter() == a))
		{
			return BACK.GetCenter();
		}
		else if ((AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2()) && (FD.GetE_C1() == FRONT.GetCenter()) && (RD.GetE_C1() == RIGHT.GetCenter()) && (BD.GetE_C1() == BACK.GetCenter()) && (LD.GetE_C2() == LEFT.GetCenter())) && (DOWN.GetCenter() == a))
		{
			return DOWN.GetCenter();
		}
		else
			return 0;
	}
	int IsOneBottomCornerSolved(int a)
	{
		if ((AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2(), FRD.GetC_C1())
			&& (FD.GetE_C1() == FRONT.GetCenter())
			&& (RD.GetE_C1() == RIGHT.GetCenter())
			&& (FRD.GetC_C2() == FRONT.GetCenter())
			&& (FRD.GetC_C3() == RIGHT.GetCenter())
			&& (BD.GetE_C1() == BACK.GetCenter())
			&& (LD.GetE_C2() == LEFT.GetCenter()))
			&& (DOWN.GetCenter() == a))
		{
			return DOWN.GetCenter();
		}
		else if ((AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2(), FLD.GetC_C1())
			&& (FD.GetE_C1() == FRONT.GetCenter())
			&& (RD.GetE_C1() == RIGHT.GetCenter())
			&& (FLD.GetC_C2() == LEFT.GetCenter())
			&& (FLD.GetC_C3() == FRONT.GetCenter())
			&& (BD.GetE_C1() == BACK.GetCenter())
			&& (LD.GetE_C2() == LEFT.GetCenter()))
			&& (DOWN.GetCenter() == a))
		{
			return DOWN.GetCenter();
		}
		else if ((AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2(), BRD.GetC_C1())
			&& (FD.GetE_C1() == FRONT.GetCenter())
			&& (RD.GetE_C1() == RIGHT.GetCenter())
			&& (BRD.GetC_C2() == RIGHT.GetCenter())
			&& (BRD.GetC_C3() == BACK.GetCenter())
			&& (BD.GetE_C1() == BACK.GetCenter())
			&& (LD.GetE_C2() == LEFT.GetCenter()))
			&& (DOWN.GetCenter() == a))
		{
			return DOWN.GetCenter();
		}
		else if ((AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2(), BLD.GetC_C1())
			&& (FD.GetE_C1() == FRONT.GetCenter())
			&& (RD.GetE_C1() == RIGHT.GetCenter())
			&& (BLD.GetC_C2() == BACK.GetCenter())
			&& (BLD.GetC_C3() == LEFT.GetCenter())
			&& (BD.GetE_C1() == BACK.GetCenter())
			&& (LD.GetE_C2() == LEFT.GetCenter()))
			&& (DOWN.GetCenter() == a))
		{
			return DOWN.GetCenter();
		}
		else
			return 0;
	}
	int IsOneBottomPairSolved(int a)
	{
		if ((AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2(), FRD.GetC_C1())
			&& (FD.GetE_C1() == FRONT.GetCenter())
			&& (RD.GetE_C1() == RIGHT.GetCenter())
			&& (FRD.GetC_C2() == FRONT.GetCenter())
			&& (FRD.GetC_C3() == RIGHT.GetCenter())
			&& (BD.GetE_C1() == BACK.GetCenter())
			&& (LD.GetE_C2() == LEFT.GetCenter()))
			&& (FR.GetE_C1() == FRONT.GetCenter())
			&& (FR.GetE_C2() == RIGHT.GetCenter())
			&& (DOWN.GetCenter() == a))
		{
			return DOWN.GetCenter();
		}
		else if ((AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2(), FLD.GetC_C1())
			&& (FD.GetE_C1() == FRONT.GetCenter())
			&& (RD.GetE_C1() == RIGHT.GetCenter())
			&& (FLD.GetC_C2() == LEFT.GetCenter())
			&& (FLD.GetC_C3() == FRONT.GetCenter())
			&& (BD.GetE_C1() == BACK.GetCenter())
			&& (LD.GetE_C2() == LEFT.GetCenter()))
			&& (FL.GetE_C1() == LEFT.GetCenter())
			&& (FL.GetE_C2() == FRONT.GetCenter())
			&& (DOWN.GetCenter() == a))
		{
			return DOWN.GetCenter();
		}
		else if ((AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2(), BRD.GetC_C1())
			&& (FD.GetE_C1() == FRONT.GetCenter())
			&& (RD.GetE_C1() == RIGHT.GetCenter())
			&& (BRD.GetC_C2() == RIGHT.GetCenter())
			&& (BRD.GetC_C3() == BACK.GetCenter())
			&& (BD.GetE_C1() == BACK.GetCenter())
			&& (LD.GetE_C2() == LEFT.GetCenter()))
			&& (BR.GetE_C1() == RIGHT.GetCenter())
			&& (BR.GetE_C2() == BACK.GetCenter())
			&& (DOWN.GetCenter() == a))
		{
			return DOWN.GetCenter();
		}
		else if ((AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2(), BLD.GetC_C1())
			&& (FD.GetE_C1() == FRONT.GetCenter())
			&& (RD.GetE_C1() == RIGHT.GetCenter())
			&& (BLD.GetC_C2() == BACK.GetCenter())
			&& (BLD.GetC_C3() == LEFT.GetCenter())
			&& (BD.GetE_C1() == BACK.GetCenter())
			&& (LD.GetE_C2() == LEFT.GetCenter()))
			&& (BL.GetE_C2() == BACK.GetCenter())
			&& (BL.GetE_C1() == LEFT.GetCenter())
			&& (DOWN.GetCenter() == a))
		{
			return DOWN.GetCenter();
		}
		else
			return 0;
	}
	int AreTwoBottomPairsSolved(int a)
	{
		if ((AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2(), FRD.GetC_C1(), FLD.GetC_C1())
			&& (FD.GetE_C1() == FRONT.GetCenter())
			&& (RD.GetE_C1() == RIGHT.GetCenter())
			&& (FRD.GetC_C2() == FRONT.GetCenter())
			&& (FRD.GetC_C3() == RIGHT.GetCenter())
			&& (FLD.GetC_C2() == LEFT.GetCenter())
			&& (FLD.GetC_C3() == FRONT.GetCenter())
			&& (BD.GetE_C1() == BACK.GetCenter())
			&& (LD.GetE_C2() == LEFT.GetCenter()))
			&& (FR.GetE_C1() == FRONT.GetCenter())
			&& (FR.GetE_C2() == RIGHT.GetCenter())
			&& (FL.GetE_C1() == LEFT.GetCenter())
			&& (FL.GetE_C2() == FRONT.GetCenter())
			&& (DOWN.GetCenter() == a))
		{
			return DOWN.GetCenter();
		}
		else if ((AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2(), FLD.GetC_C1(), BLD.GetC_C1())
			&& (FD.GetE_C1() == FRONT.GetCenter())
			&& (RD.GetE_C1() == RIGHT.GetCenter())
			&& (FLD.GetC_C2() == LEFT.GetCenter())
			&& (FLD.GetC_C3() == FRONT.GetCenter())
			&& (BLD.GetC_C2() == BACK.GetCenter())
			&& (BLD.GetC_C3() == LEFT.GetCenter())
			&& (BD.GetE_C1() == BACK.GetCenter())
			&& (LD.GetE_C2() == LEFT.GetCenter()))
			&& (FL.GetE_C1() == LEFT.GetCenter())
			&& (FL.GetE_C2() == FRONT.GetCenter())
			&& (BL.GetE_C2() == BACK.GetCenter())
			&& (BL.GetE_C1() == LEFT.GetCenter())
			&& (DOWN.GetCenter() == a))
		{
			return DOWN.GetCenter();
		}
		else if ((AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2(), BRD.GetC_C1(), BLD.GetC_C1())
			&& (FD.GetE_C1() == FRONT.GetCenter())
			&& (RD.GetE_C1() == RIGHT.GetCenter())
			&& (BRD.GetC_C2() == RIGHT.GetCenter())
			&& (BRD.GetC_C3() == BACK.GetCenter())
			&& (BLD.GetC_C2() == BACK.GetCenter())
			&& (BLD.GetC_C3() == LEFT.GetCenter())
			&& (BD.GetE_C1() == BACK.GetCenter())
			&& (LD.GetE_C2() == LEFT.GetCenter()))
			&& (BR.GetE_C1() == RIGHT.GetCenter())
			&& (BR.GetE_C2() == BACK.GetCenter())
			&& (BL.GetE_C2() == BACK.GetCenter())
			&& (BL.GetE_C1() == LEFT.GetCenter())
			&& (DOWN.GetCenter() == a))
		{
			return DOWN.GetCenter();
		}
		else if ((AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2(), FRD.GetC_C1(), BRD.GetC_C1())
			&& (FD.GetE_C1() == FRONT.GetCenter())
			&& (RD.GetE_C1() == RIGHT.GetCenter())
			&& (BRD.GetC_C2() == RIGHT.GetCenter())
			&& (BRD.GetC_C3() == BACK.GetCenter())
			&& (FRD.GetC_C2() == FRONT.GetCenter())
			&& (FRD.GetC_C3() == RIGHT.GetCenter())
			&& (BD.GetE_C1() == BACK.GetCenter())
			&& (LD.GetE_C2() == LEFT.GetCenter()))
			&& (BR.GetE_C1() == RIGHT.GetCenter())
			&& (BR.GetE_C2() == BACK.GetCenter())
			&& (FR.GetE_C1() == FRONT.GetCenter())
			&& (FR.GetE_C2() == RIGHT.GetCenter())
			&& (DOWN.GetCenter() == a))
		{
			return DOWN.GetCenter();
		}
		else if ((AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2(), BRD.GetC_C1(), FLD.GetC_C1())
			&& (FD.GetE_C1() == FRONT.GetCenter())
			&& (RD.GetE_C1() == RIGHT.GetCenter())
			&& (BRD.GetC_C2() == RIGHT.GetCenter())
			&& (BRD.GetC_C3() == BACK.GetCenter())
			&& (FLD.GetC_C2() == LEFT.GetCenter())
			&& (FLD.GetC_C3() == FRONT.GetCenter())
			&& (BD.GetE_C1() == BACK.GetCenter())
			&& (LD.GetE_C2() == LEFT.GetCenter()))
			&& (BR.GetE_C1() == RIGHT.GetCenter())
			&& (BR.GetE_C2() == BACK.GetCenter())
			&& (FL.GetE_C1() == LEFT.GetCenter())
			&& (FL.GetE_C2() == FRONT.GetCenter())
			&& (DOWN.GetCenter() == a))
		{
			return DOWN.GetCenter();
		}
		else if ((AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2(), BLD.GetC_C1(), FRD.GetC_C1())
			&& (FD.GetE_C1() == FRONT.GetCenter())
			&& (RD.GetE_C1() == RIGHT.GetCenter())
			&& (BLD.GetC_C2() == BACK.GetCenter())
			&& (BLD.GetC_C3() == LEFT.GetCenter())
			&& (FRD.GetC_C2() == FRONT.GetCenter())
			&& (FRD.GetC_C3() == RIGHT.GetCenter())
			&& (BD.GetE_C1() == BACK.GetCenter())
			&& (LD.GetE_C2() == LEFT.GetCenter()))
			&& (BL.GetE_C2() == BACK.GetCenter())
			&& (BL.GetE_C1() == LEFT.GetCenter())
			&& (FR.GetE_C1() == FRONT.GetCenter())
			&& (FR.GetE_C2() == RIGHT.GetCenter())
			&& (DOWN.GetCenter() == a))
		{
			return DOWN.GetCenter();
		}
		else
			return 0;
	}
	int AreThreeBottomPairsSolved(int a)
	{
		// 1 - BLD unsolved; 2 - BRD unsolved; 3 - FRD unsolved; 4 - FLD unsolved.
		if ((AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2(), FRD.GetC_C1(), FLD.GetC_C1(), BRD.GetC_C1())
			&& (FD.GetE_C1() == FRONT.GetCenter())
			&& (RD.GetE_C1() == RIGHT.GetCenter())
			&& (FRD.GetC_C2() == FRONT.GetCenter())
			&& (FRD.GetC_C3() == RIGHT.GetCenter())
			&& (FLD.GetC_C2() == LEFT.GetCenter())
			&& (FLD.GetC_C3() == FRONT.GetCenter())
			&& (BRD.GetC_C2() == RIGHT.GetCenter())
			&& (BRD.GetC_C3() == BACK.GetCenter())
			&& (BD.GetE_C1() == BACK.GetCenter())
			&& (LD.GetE_C2() == LEFT.GetCenter()))
			&& (FR.GetE_C1() == FRONT.GetCenter())
			&& (FR.GetE_C2() == RIGHT.GetCenter())
			&& (FL.GetE_C1() == LEFT.GetCenter())
			&& (FL.GetE_C2() == FRONT.GetCenter())
			&& (BR.GetE_C1() == RIGHT.GetCenter())
			&& (BR.GetE_C2() == BACK.GetCenter())
			&& (DOWN.GetCenter() == a))
		{
			return 1;
		}
		else if ((AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2(), FLD.GetC_C1(), BLD.GetC_C1(), FRD.GetC_C1())
			&& (FD.GetE_C1() == FRONT.GetCenter())
			&& (RD.GetE_C1() == RIGHT.GetCenter())
			&& (FLD.GetC_C2() == LEFT.GetCenter())
			&& (FLD.GetC_C3() == FRONT.GetCenter())
			&& (BLD.GetC_C2() == BACK.GetCenter())
			&& (BLD.GetC_C3() == LEFT.GetCenter())
			&& (FRD.GetC_C2() == FRONT.GetCenter())
			&& (FRD.GetC_C3() == RIGHT.GetCenter())
			&& (BD.GetE_C1() == BACK.GetCenter())
			&& (LD.GetE_C2() == LEFT.GetCenter()))
			&& (FL.GetE_C1() == LEFT.GetCenter())
			&& (FL.GetE_C2() == FRONT.GetCenter())
			&& (BL.GetE_C2() == BACK.GetCenter())
			&& (BL.GetE_C1() == LEFT.GetCenter())
			&& (FR.GetE_C1() == FRONT.GetCenter())
			&& (FR.GetE_C2() == RIGHT.GetCenter())
			&& (DOWN.GetCenter() == a))
		{
			return 2;
		}
		else if ((AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2(), BRD.GetC_C1(), BLD.GetC_C1(), FLD.GetC_C1())
			&& (FD.GetE_C1() == FRONT.GetCenter())
			&& (RD.GetE_C1() == RIGHT.GetCenter())
			&& (BRD.GetC_C2() == RIGHT.GetCenter())
			&& (BRD.GetC_C3() == BACK.GetCenter())
			&& (BLD.GetC_C2() == BACK.GetCenter())
			&& (BLD.GetC_C3() == LEFT.GetCenter())
			&& (FLD.GetC_C2() == LEFT.GetCenter())
			&& (FLD.GetC_C3() == FRONT.GetCenter())
			&& (BD.GetE_C1() == BACK.GetCenter())
			&& (LD.GetE_C2() == LEFT.GetCenter()))
			&& (BR.GetE_C1() == RIGHT.GetCenter())
			&& (BR.GetE_C2() == BACK.GetCenter())
			&& (BL.GetE_C2() == BACK.GetCenter())
			&& (BL.GetE_C1() == LEFT.GetCenter())
			&& (FL.GetE_C1() == LEFT.GetCenter())
			&& (FL.GetE_C2() == FRONT.GetCenter())
			&& (DOWN.GetCenter() == a))
		{
			return 3;
		}
		else if ((AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2(), FRD.GetC_C1(), BRD.GetC_C1(), BLD.GetC_C1())
			&& (FD.GetE_C1() == FRONT.GetCenter())
			&& (RD.GetE_C1() == RIGHT.GetCenter())
			&& (BLD.GetC_C2() == BACK.GetCenter())
			&& (BLD.GetC_C3() == LEFT.GetCenter())
			&& (FRD.GetC_C2() == FRONT.GetCenter())
			&& (FRD.GetC_C3() == RIGHT.GetCenter())
			&& (BRD.GetC_C2() == RIGHT.GetCenter())
			&& (BRD.GetC_C3() == BACK.GetCenter())
			&& (BD.GetE_C1() == BACK.GetCenter())
			&& (LD.GetE_C2() == LEFT.GetCenter()))
			&& (BR.GetE_C1() == RIGHT.GetCenter())
			&& (BR.GetE_C2() == BACK.GetCenter())
			&& (FR.GetE_C1() == FRONT.GetCenter())
			&& (FR.GetE_C2() == RIGHT.GetCenter())
			&& (BL.GetE_C2() == BACK.GetCenter())
			&& (BL.GetE_C1() == LEFT.GetCenter())
			&& (DOWN.GetCenter() == a))
		{
			return 4;
		}
		else
			return 0;
	}
	int AreFourBottomPairsSolved(int a)
	{
		if ((AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2(), FRD.GetC_C1(), FLD.GetC_C1(), BRD.GetC_C1(), BLD.GetC_C1())
			&& (FD.GetE_C1() == FRONT.GetCenter())
			&& (RD.GetE_C1() == RIGHT.GetCenter())
			&& (FRD.GetC_C2() == FRONT.GetCenter())
			&& (FRD.GetC_C3() == RIGHT.GetCenter())
			&& (BD.GetE_C1() == BACK.GetCenter())
			&& (LD.GetE_C2() == LEFT.GetCenter()))
			&& (FR.GetE_C1() == FRONT.GetCenter())
			&& (FR.GetE_C2() == RIGHT.GetCenter())
			&& (FL.GetE_C1() == LEFT.GetCenter())
			&& (FL.GetE_C2() == FRONT.GetCenter())
			&& (BR.GetE_C1() == RIGHT.GetCenter())
			&& (BR.GetE_C2() == BACK.GetCenter())
			&& (BL.GetE_C2() == BACK.GetCenter())
			&& (BL.GetE_C1() == LEFT.GetCenter())
			&& (DOWN.GetCenter() == a))
		{
			return DOWN.GetCenter();
		}
		else
			return 0;
	}
	int IsOneBottomCrossPieceSolved(int a)
	{
		if (DOWN.GetCenter() == RD.GetE_C2() && (RD.GetE_C1() == RIGHT.GetCenter()) && (DOWN.GetCenter() == a))
			return DOWN.GetCenter();
		else if (FD.GetE_C2() == DOWN.GetCenter() && (FD.GetE_C1() == FRONT.GetCenter()) && (DOWN.GetCenter() == a))
			return DOWN.GetCenter();
		else if (LD.GetE_C1() == DOWN.GetCenter() && (LD.GetE_C2() == LEFT.GetCenter()) && (DOWN.GetCenter() == a))
			return DOWN.GetCenter();
		else if (DOWN.GetCenter() == BD.GetE_C2() && (BD.GetE_C1() == BACK.GetCenter()) && (DOWN.GetCenter() == a))
			return DOWN.GetCenter();
		else
			return 0;
	}
	int AreTwoBottomCrossPiecesSolved(int a)
	{
		if (AreValuesEqual(DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2()) && (RD.GetE_C1() == RIGHT.GetCenter()) && (BD.GetE_C1() == BACK.GetCenter()) && (DOWN.GetCenter() == a))
			return DOWN.GetCenter();
		else if (AreValuesEqual(FD.GetE_C2(), DOWN.GetCenter(), RD.GetE_C2()) && (FD.GetE_C1() == FRONT.GetCenter()) && (RD.GetE_C1() == RIGHT.GetCenter()) && (DOWN.GetCenter() == a))
			return DOWN.GetCenter();
		else if (AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter()) && (FD.GetE_C1() == FRONT.GetCenter()) && (LD.GetE_C2() == LEFT.GetCenter()) && (DOWN.GetCenter() == a))
			return DOWN.GetCenter();
		else if (AreValuesEqual(LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2()) && (RD.GetE_C1() == RIGHT.GetCenter()) && (LD.GetE_C2() == LEFT.GetCenter()) && (DOWN.GetCenter() == a))
			return DOWN.GetCenter();
		else if (AreValuesEqual(FD.GetE_C2(), BD.GetE_C1(), DOWN.GetCenter()) && (FD.GetE_C1() == FRONT.GetCenter()) && (BD.GetE_C1() == BACK.GetCenter()) && (DOWN.GetCenter() == a))
			return DOWN.GetCenter();
		else if (AreValuesEqual(BD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter()) && (BD.GetE_C1() == BACK.GetCenter()) && (LD.GetE_C2() == LEFT.GetCenter()) && (DOWN.GetCenter() == a))
			return DOWN.GetCenter();
		else
			return 0;
	}
	int AreThreeCrossPiecesSolved()
	{
		if (AreValuesEqual(LU.GetE_C2(), UP.GetCenter(), RU.GetE_C1(), FU.GetE_C1()) && (LU.GetE_C1() == LEFT.GetCenter()) && (RU.GetE_C2() == RIGHT.GetCenter()) && (FU.GetE_C2() == FRONT.GetCenter()))
			return UP.GetCenter();
		else if (AreValuesEqual(BU.GetE_C1(), UP.GetCenter(), RU.GetE_C1(), FU.GetE_C1()) && (BU.GetE_C2() == BACK.GetCenter()) && (RU.GetE_C2() == RIGHT.GetCenter()) && (FU.GetE_C2() == FRONT.GetCenter()))
			return UP.GetCenter();
		else if (AreValuesEqual(BU.GetE_C1(), LU.GetE_C2(), UP.GetCenter(), FU.GetE_C1()) && (BU.GetE_C2() == BACK.GetCenter()) && (LU.GetE_C1() == LEFT.GetCenter()) && (FU.GetE_C2() == FRONT.GetCenter()))
			return UP.GetCenter();
		else if (AreValuesEqual(BU.GetE_C1(), LU.GetE_C2(), UP.GetCenter(), RU.GetE_C1()) && (BU.GetE_C2() == BACK.GetCenter()) && (LU.GetE_C1() == LEFT.GetCenter()) && (RU.GetE_C2() == RIGHT.GetCenter()))
			return UP.GetCenter();

		else if (AreValuesEqual(BL.GetE_C1(), LEFT.GetCenter(), FL.GetE_C1(), LD.GetE_C2()) && (BL.GetE_C2() == BACK.GetCenter()) && (FL.GetE_C2() == FRONT.GetCenter()) && (LD.GetE_C1() == DOWN.GetCenter()))
			return LEFT.GetCenter();
		else if (AreValuesEqual(LU.GetE_C1(), LEFT.GetCenter(), FL.GetE_C1(), LD.GetE_C2()) && (LU.GetE_C2() == UP.GetCenter()) && (FL.GetE_C2() == FRONT.GetCenter()) && (LD.GetE_C1() == DOWN.GetCenter()))
			return LEFT.GetCenter();
		else if (AreValuesEqual(LU.GetE_C1(), BL.GetE_C1(), LEFT.GetCenter(), LD.GetE_C2()) && (LU.GetE_C2() == UP.GetCenter()) && (BL.GetE_C2() == BACK.GetCenter()) && (LD.GetE_C1() == DOWN.GetCenter()))
			return LEFT.GetCenter();
		else if (AreValuesEqual(LU.GetE_C1(), BL.GetE_C1(), LEFT.GetCenter(), FL.GetE_C1()) && (LU.GetE_C2() == UP.GetCenter()) && (BL.GetE_C2() == BACK.GetCenter()) && (FL.GetE_C2() == FRONT.GetCenter()))
			return LEFT.GetCenter();

		else if (AreValuesEqual(FL.GetE_C2(), FRONT.GetCenter(), FR.GetE_C1(), FD.GetE_C1()) && (FL.GetE_C1() == LEFT.GetCenter()) && (FR.GetE_C2() == RIGHT.GetCenter()) && (FD.GetE_C2() == DOWN.GetCenter()))
			return FRONT.GetCenter();
		else if (AreValuesEqual(FU.GetE_C2(), FRONT.GetCenter(), FR.GetE_C1(), FD.GetE_C1()) && (FU.GetE_C1() == UP.GetCenter()) && (FR.GetE_C2() == RIGHT.GetCenter()) && (FD.GetE_C2() == DOWN.GetCenter()))
			return FRONT.GetCenter();
		else if (AreValuesEqual(FU.GetE_C2(), FL.GetE_C2(), FRONT.GetCenter(), FD.GetE_C1()) && (FU.GetE_C1() == UP.GetCenter()) && (FL.GetE_C1() == LEFT.GetCenter()) && (FD.GetE_C2() == DOWN.GetCenter()))
			return FRONT.GetCenter();
		else if (AreValuesEqual(FU.GetE_C2(), FL.GetE_C2(), FRONT.GetCenter(), FR.GetE_C1()) && (FU.GetE_C1() == UP.GetCenter()) && (FL.GetE_C1() == LEFT.GetCenter()) && (FR.GetE_C2() == RIGHT.GetCenter()))
			return FRONT.GetCenter();

		else if (AreValuesEqual(FR.GetE_C2(), RIGHT.GetCenter(), BR.GetE_C1(), RD.GetE_C1()) && (FR.GetE_C1() == FRONT.GetCenter()) && (BR.GetE_C2() == BACK.GetCenter()) && (RD.GetE_C2() == DOWN.GetCenter()))
			return RIGHT.GetCenter();
		else if (AreValuesEqual(RU.GetE_C2(), RIGHT.GetCenter(), BR.GetE_C1(), RD.GetE_C1()) && (RU.GetE_C1() == UP.GetCenter()) && (BR.GetE_C2() == BACK.GetCenter()) && (RD.GetE_C2() == DOWN.GetCenter()))
			return RIGHT.GetCenter();
		else if (AreValuesEqual(RU.GetE_C2(), FR.GetE_C2(), RIGHT.GetCenter(), RD.GetE_C1()) && (RU.GetE_C1() == UP.GetCenter()) && (FR.GetE_C1() == FRONT.GetCenter()) && (RD.GetE_C2() == DOWN.GetCenter()))
			return RIGHT.GetCenter();
		else if (AreValuesEqual(RU.GetE_C2(), FR.GetE_C2(), RIGHT.GetCenter(), BR.GetE_C1()) && (RU.GetE_C1() == UP.GetCenter()) && (FR.GetE_C1() == FRONT.GetCenter()) && (BR.GetE_C2() == BACK.GetCenter()))
			return RIGHT.GetCenter();

		else if (AreValuesEqual(BR.GetE_C2(), BACK.GetCenter(), BL.GetE_C2(), BD.GetE_C1()) && (BR.GetE_C1() == RIGHT.GetCenter()) && (BL.GetE_C1() == LEFT.GetCenter()) && (BD.GetE_C2() == DOWN.GetCenter()))
			return BACK.GetCenter();
		else if (AreValuesEqual(BU.GetE_C2(), BACK.GetCenter(), BL.GetE_C2(), BD.GetE_C1()) && (BU.GetE_C1() == UP.GetCenter()) && (BL.GetE_C1() == LEFT.GetCenter()) && (BD.GetE_C2() == DOWN.GetCenter()))
			return BACK.GetCenter();
		else if (AreValuesEqual(BU.GetE_C2(), BR.GetE_C2(), BACK.GetCenter(), BD.GetE_C1()) && (BU.GetE_C1() == UP.GetCenter()) && (BR.GetE_C1() == RIGHT.GetCenter()) && (BD.GetE_C2() == DOWN.GetCenter()))
			return BACK.GetCenter();
		else if (AreValuesEqual(BU.GetE_C2(), BR.GetE_C2(), BACK.GetCenter(), BL.GetE_C2()) && (BU.GetE_C1() == UP.GetCenter()) && (BR.GetE_C1() == RIGHT.GetCenter()) && (BL.GetE_C1() == LEFT.GetCenter()))
			return BACK.GetCenter();

		else if (AreValuesEqual(LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2()) && (RD.GetE_C1() == RIGHT.GetCenter()) && (BD.GetE_C1() == BACK.GetCenter()) && (LD.GetE_C2() == LEFT.GetCenter()))
			return DOWN.GetCenter();
		else if (AreValuesEqual(FD.GetE_C2(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2()) && (FD.GetE_C1() == FRONT.GetCenter()) && (RD.GetE_C1() == RIGHT.GetCenter()) && (BD.GetE_C1() == BACK.GetCenter()))
			return DOWN.GetCenter();
		else if (AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), BD.GetE_C2()) && (FD.GetE_C1() == FRONT.GetCenter()) && (BD.GetE_C1() == BACK.GetCenter()) && (LD.GetE_C2() == LEFT.GetCenter()))
			return DOWN.GetCenter();
		else if (AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2()) && (FD.GetE_C1() == FRONT.GetCenter()) && (RD.GetE_C1() == RIGHT.GetCenter()) && (LD.GetE_C2() == LEFT.GetCenter()))
			return DOWN.GetCenter();
		else
			return 0;
	}
	int AreThreeCrossPiecesSolved(int a)
	{
		if (AreValuesEqual(LU.GetE_C2(), UP.GetCenter(), RU.GetE_C1(), FU.GetE_C1()) && (LU.GetE_C1() == LEFT.GetCenter()) && (RU.GetE_C2() == RIGHT.GetCenter()) && (FU.GetE_C2() == FRONT.GetCenter()) && (UP.GetCenter() == a))
			return UP.GetCenter();
		else if (AreValuesEqual(BU.GetE_C1(), UP.GetCenter(), RU.GetE_C1(), FU.GetE_C1()) && (BU.GetE_C2() == BACK.GetCenter()) && (RU.GetE_C2() == RIGHT.GetCenter()) && (FU.GetE_C2() == FRONT.GetCenter()) && (UP.GetCenter() == a))
			return UP.GetCenter();
		else if (AreValuesEqual(BU.GetE_C1(), LU.GetE_C2(), UP.GetCenter(), FU.GetE_C1()) && (BU.GetE_C2() == BACK.GetCenter()) && (LU.GetE_C1() == LEFT.GetCenter()) && (FU.GetE_C2() == FRONT.GetCenter()) && (UP.GetCenter() == a))
			return UP.GetCenter();
		else if (AreValuesEqual(BU.GetE_C1(), LU.GetE_C2(), UP.GetCenter(), RU.GetE_C1()) && (BU.GetE_C2() == BACK.GetCenter()) && (LU.GetE_C1() == LEFT.GetCenter()) && (RU.GetE_C2() == RIGHT.GetCenter()) && (UP.GetCenter() == a))
			return UP.GetCenter();

		else if (AreValuesEqual(BL.GetE_C1(), LEFT.GetCenter(), FL.GetE_C1(), LD.GetE_C2()) && (BL.GetE_C2() == BACK.GetCenter()) && (FL.GetE_C2() == FRONT.GetCenter()) && (LD.GetE_C1() == DOWN.GetCenter()) && (LEFT.GetCenter() == a))
			return LEFT.GetCenter();
		else if (AreValuesEqual(LU.GetE_C1(), LEFT.GetCenter(), FL.GetE_C1(), LD.GetE_C2()) && (LU.GetE_C2() == UP.GetCenter()) && (FL.GetE_C2() == FRONT.GetCenter()) && (LD.GetE_C1() == DOWN.GetCenter()) && (LEFT.GetCenter() == a))
			return LEFT.GetCenter();
		else if (AreValuesEqual(LU.GetE_C1(), BL.GetE_C1(), LEFT.GetCenter(), LD.GetE_C2()) && (LU.GetE_C2() == UP.GetCenter()) && (BL.GetE_C2() == BACK.GetCenter()) && (LD.GetE_C1() == DOWN.GetCenter()) && (LEFT.GetCenter() == a))
			return LEFT.GetCenter();
		else if (AreValuesEqual(LU.GetE_C1(), BL.GetE_C1(), LEFT.GetCenter(), FL.GetE_C1()) && (LU.GetE_C2() == UP.GetCenter()) && (BL.GetE_C2() == BACK.GetCenter()) && (FL.GetE_C2() == FRONT.GetCenter()) && (LEFT.GetCenter() == a))
			return LEFT.GetCenter();

		else if (AreValuesEqual(FL.GetE_C2(), FRONT.GetCenter(), FR.GetE_C1(), FD.GetE_C1()) && (FL.GetE_C1() == LEFT.GetCenter()) && (FR.GetE_C2() == RIGHT.GetCenter()) && (FD.GetE_C2() == DOWN.GetCenter()) && (FRONT.GetCenter() == a))
			return FRONT.GetCenter();
		else if (AreValuesEqual(FU.GetE_C2(), FRONT.GetCenter(), FR.GetE_C1(), FD.GetE_C1()) && (FU.GetE_C1() == UP.GetCenter()) && (FR.GetE_C2() == RIGHT.GetCenter()) && (FD.GetE_C2() == DOWN.GetCenter()) && (FRONT.GetCenter() == a))
			return FRONT.GetCenter();
		else if (AreValuesEqual(FU.GetE_C2(), FL.GetE_C2(), FRONT.GetCenter(), FD.GetE_C1()) && (FU.GetE_C1() == UP.GetCenter()) && (FL.GetE_C1() == LEFT.GetCenter()) && (FD.GetE_C2() == DOWN.GetCenter()) && (FRONT.GetCenter() == a))
			return FRONT.GetCenter();
		else if (AreValuesEqual(FU.GetE_C2(), FL.GetE_C2(), FRONT.GetCenter(), FR.GetE_C1()) && (FU.GetE_C1() == UP.GetCenter()) && (FL.GetE_C1() == LEFT.GetCenter()) && (FR.GetE_C2() == RIGHT.GetCenter()) && (FRONT.GetCenter() == a))
			return FRONT.GetCenter();

		else if (AreValuesEqual(FR.GetE_C2(), RIGHT.GetCenter(), BR.GetE_C1(), RD.GetE_C1()) && (FR.GetE_C1() == FRONT.GetCenter()) && (BR.GetE_C2() == BACK.GetCenter()) && (RD.GetE_C2() == DOWN.GetCenter()) && (RIGHT.GetCenter() == a))
			return RIGHT.GetCenter();
		else if (AreValuesEqual(RU.GetE_C2(), RIGHT.GetCenter(), BR.GetE_C1(), RD.GetE_C1()) && (RU.GetE_C1() == UP.GetCenter()) && (BR.GetE_C2() == BACK.GetCenter()) && (RD.GetE_C2() == DOWN.GetCenter()) && (RIGHT.GetCenter() == a))
			return RIGHT.GetCenter();
		else if (AreValuesEqual(RU.GetE_C2(), FR.GetE_C2(), RIGHT.GetCenter(), RD.GetE_C1()) && (RU.GetE_C1() == UP.GetCenter()) && (FR.GetE_C1() == FRONT.GetCenter()) && (RD.GetE_C2() == DOWN.GetCenter()) && (RIGHT.GetCenter() == a))
			return RIGHT.GetCenter();
		else if (AreValuesEqual(RU.GetE_C2(), FR.GetE_C2(), RIGHT.GetCenter(), BR.GetE_C1()) && (RU.GetE_C1() == UP.GetCenter()) && (FR.GetE_C1() == FRONT.GetCenter()) && (BR.GetE_C2() == BACK.GetCenter()) && (RIGHT.GetCenter() == a))
			return RIGHT.GetCenter();

		else if (AreValuesEqual(BR.GetE_C2(), BACK.GetCenter(), BL.GetE_C2(), BD.GetE_C1()) && (BR.GetE_C1() == RIGHT.GetCenter()) && (BL.GetE_C1() == LEFT.GetCenter()) && (BD.GetE_C2() == DOWN.GetCenter()) && (BACK.GetCenter() == a))
			return BACK.GetCenter();
		else if (AreValuesEqual(BU.GetE_C2(), BACK.GetCenter(), BL.GetE_C2(), BD.GetE_C1()) && (BU.GetE_C1() == UP.GetCenter()) && (BL.GetE_C1() == LEFT.GetCenter()) && (BD.GetE_C2() == DOWN.GetCenter()) && (BACK.GetCenter() == a))
			return BACK.GetCenter();
		else if (AreValuesEqual(BU.GetE_C2(), BR.GetE_C2(), BACK.GetCenter(), BD.GetE_C1()) && (BU.GetE_C1() == UP.GetCenter()) && (BR.GetE_C1() == RIGHT.GetCenter()) && (BD.GetE_C2() == DOWN.GetCenter()) && (BACK.GetCenter() == a))
			return BACK.GetCenter();
		else if (AreValuesEqual(BU.GetE_C2(), BR.GetE_C2(), BACK.GetCenter(), BL.GetE_C2()) && (BU.GetE_C1() == UP.GetCenter()) && (BR.GetE_C1() == RIGHT.GetCenter()) && (BL.GetE_C1() == LEFT.GetCenter()) && (BACK.GetCenter() == a))
			return BACK.GetCenter();

		else if (AreValuesEqual(LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2()) && (RD.GetE_C1() == RIGHT.GetCenter()) && (BD.GetE_C1() == BACK.GetCenter()) && (LD.GetE_C2() == LEFT.GetCenter()) && (DOWN.GetCenter() == a))
			return DOWN.GetCenter();
		else if (AreValuesEqual(FD.GetE_C2(), DOWN.GetCenter(), RD.GetE_C2(), BD.GetE_C2()) && (FD.GetE_C1() == FRONT.GetCenter()) && (RD.GetE_C1() == RIGHT.GetCenter()) && (BD.GetE_C1() == BACK.GetCenter()) && (DOWN.GetCenter() == a))
			return DOWN.GetCenter();
		else if (AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), BD.GetE_C2()) && (FD.GetE_C1() == FRONT.GetCenter()) && (BD.GetE_C1() == BACK.GetCenter()) && (LD.GetE_C2() == LEFT.GetCenter()) && (DOWN.GetCenter() == a))
			return DOWN.GetCenter();
		else if (AreValuesEqual(FD.GetE_C2(), LD.GetE_C1(), DOWN.GetCenter(), RD.GetE_C2()) && (FD.GetE_C1() == FRONT.GetCenter()) && (RD.GetE_C1() == RIGHT.GetCenter()) && (LD.GetE_C2() == LEFT.GetCenter()) && (DOWN.GetCenter() == a))
			return DOWN.GetCenter();
		else
			return 0;
	}
	int IsLastLayerOriented()
	{
		if (AreValuesEqual(FRU.GetC_C1(), FLU.GetC_C1(), BRU.GetC_C1(), BLU.GetC_C1(), FU.GetE_C1(), RU.GetE_C1(), LU.GetE_C2(), BU.GetE_C1(), UP.GetCenter()))
		{
			return UP.GetCenter();
		}
		else
			return 0;
	}
	int IsLastLayerPermuted()
	{
		if (AreValuesEqual(FRU.GetC_C1(), FLU.GetC_C1(), BRU.GetC_C1(), BLU.GetC_C1(), FU.GetE_C1(), RU.GetE_C1(), LU.GetE_C2(), BU.GetE_C1(), UP.GetCenter())
			&& AreValuesEqual(FU.GetE_C2(), FRU.GetC_C3(), FLU.GetC_C2())
			&& AreValuesEqual(RU.GetE_C2(), FRU.GetC_C2(), BRU.GetC_C3())
			&& AreValuesEqual(BU.GetE_C2(), BRU.GetC_C2(), BLU.GetC_C3())
			&& AreValuesEqual(LU.GetE_C1(), FLU.GetC_C3(), BLU.GetC_C2()))
		{
			return UP.GetCenter();
		}
		else
			return 0;
	}
	void PrintBoolIsCrossSolved()
	{
		int a = IsCrossSolved();
		if (a)
		{
			ColorPrint(a);
			std::cout << " Cross is solved" << "\n";
		}
		else
			std::cout << "Cross isn't solved" << "\n";
	}
	void PrintSide(int a)
	{
		if (UP.GetCenter() == a)
		{
			BLU.PrintC_C1();
			PrintSpace();
			BU.PrintE_C1();
			PrintSpace();
			BRU.PrintC_C1();
			PrintNewLine();
			LU.PrintE_C2();
			PrintSpace();
			UP.PrintCenter();
			PrintSpace();
			RU.PrintE_C1();
			PrintNewLine();
			FLU.PrintC_C1();
			PrintSpace();
			FU.PrintE_C1();
			PrintSpace();
			FRU.PrintC_C1();
			PrintNewLine();
		}
		else if (LEFT.GetCenter() == a)
		{
			BLU.PrintC_C2();
			PrintSpace();
			LU.PrintE_C1();
			PrintSpace();
			FLU.PrintC_C3();
			PrintSpace();
			PrintNewLine();
			BL.PrintE_C1();
			PrintSpace();
			LEFT.PrintCenter();
			PrintSpace();
			FL.PrintE_C1();
			PrintSpace();
			PrintNewLine();
			BLD.PrintC_C3();
			PrintSpace();
			LD.PrintE_C2();
			PrintSpace();
			FLD.PrintC_C2();
			PrintSpace();
			PrintNewLine();
		}
		else if (FRONT.GetCenter() == a)
		{
			FLU.PrintC_C2();
			PrintSpace();
			FU.PrintE_C2();
			PrintSpace();
			FRU.PrintC_C3();
			PrintSpace();
			PrintNewLine();
			FL.PrintE_C2();
			PrintSpace();
			FRONT.PrintCenter();
			PrintSpace();
			FR.PrintE_C1();
			PrintSpace();
			PrintNewLine();
			FLD.PrintC_C3();
			PrintSpace();
			FD.PrintE_C1();
			PrintSpace();
			FRD.PrintC_C2();
			PrintSpace();
			PrintNewLine();
		}
		else if (RIGHT.GetCenter() == a)
		{
			FRU.PrintC_C2();
			PrintSpace();
			RU.PrintE_C2();
			PrintSpace();
			BRU.PrintC_C3();
			PrintSpace();
			PrintNewLine();
			FR.PrintE_C2();
			PrintSpace();
			RIGHT.PrintCenter();
			PrintSpace();
			BR.PrintE_C1();
			PrintSpace();
			PrintNewLine();
			FRD.PrintC_C3();
			PrintSpace();
			RD.PrintE_C1();
			PrintSpace();
			BRD.PrintC_C2();
			PrintSpace();
			PrintNewLine();
		}
		else if (BACK.GetCenter() == a)
		{
			BRU.PrintC_C2();
			PrintSpace();
			BU.PrintE_C2();
			PrintSpace();
			BLU.PrintC_C3();
			PrintNewLine();
			BR.PrintE_C2();
			PrintSpace();
			BACK.PrintCenter();
			PrintSpace();
			BL.PrintE_C2();
			PrintSpace();
			PrintNewLine();
			BRD.PrintC_C3();
			PrintSpace();
			BD.PrintE_C1();
			PrintSpace();
			BLD.PrintC_C2();
			PrintNewLine();
		}
		else if (DOWN.GetCenter() == a)
		{
			FLD.PrintC_C1();
			PrintSpace();
			FD.PrintE_C2();
			PrintSpace();
			FRD.PrintC_C1();
			PrintNewLine();
			LD.PrintE_C1();
			PrintSpace();
			DOWN.PrintCenter();
			PrintSpace();
			RD.PrintE_C2();
			PrintNewLine();
			BLD.PrintC_C1();
			PrintSpace();
			BD.PrintE_C2();
			PrintSpace();
			BRD.PrintC_C1();
			PrintNewLine();
		}
	}
	void PrintCube()
	{
		// WWW
		//1st WWW BLU1 BU1 BRU1
		PrintSixSpaces();
		BLU.PrintC_C1();
		PrintSpace();
		BU.PrintE_C1();
		PrintSpace();
		BRU.PrintC_C1();
		PrintNewLine();
		//2nd WWW LU2 UP RU1
		PrintSixSpaces();
		LU.PrintE_C2();
		PrintSpace();
		UP.PrintCenter();
		PrintSpace();
		RU.PrintE_C1();
		PrintNewLine();
		//3rd WWW FLU1 FU1 FRU1
		PrintSixSpaces();
		FLU.PrintC_C1();
		PrintSpace();
		FU.PrintE_C1();
		PrintSpace();
		FRU.PrintC_C1();
		PrintNewLine();

		//1st OOO GGG RRR BBB
		//1st OOO BLU2 LU1 FLU3
		BLU.PrintC_C2();
		PrintSpace();
		LU.PrintE_C1();
		PrintSpace();
		FLU.PrintC_C3();
		PrintSpace();
		//1st GGG FLU2 FU2 FRU3
		FLU.PrintC_C2();
		PrintSpace();
		FU.PrintE_C2();
		PrintSpace();
		FRU.PrintC_C3();
		PrintSpace();
		//1st RRR FRU2 RU2 BRU3
		FRU.PrintC_C2();
		PrintSpace();
		RU.PrintE_C2();
		PrintSpace();
		BRU.PrintC_C3();
		PrintSpace();
		//1st BBB BRU2 BU2 BLU3
		BRU.PrintC_C2();
		PrintSpace();
		BU.PrintE_C2();
		PrintSpace();
		BLU.PrintC_C3();
		PrintNewLine();

		//2nd OOO GGG RRR BBB
		//2nd OOO BL1 LEFT FL1
		BL.PrintE_C1();
		PrintSpace();
		LEFT.PrintCenter();
		PrintSpace();
		FL.PrintE_C1();
		PrintSpace();
		//2nd GGG FL2 FRONT FR1
		FL.PrintE_C2();
		PrintSpace();
		FRONT.PrintCenter();
		PrintSpace();
		FR.PrintE_C1();
		PrintSpace();
		//2nd RRR FR2 RIGHT BR1
		FR.PrintE_C2();
		PrintSpace();
		RIGHT.PrintCenter();
		PrintSpace();
		BR.PrintE_C1();
		PrintSpace();
		//2nd BBB BR2 BACK BL2
		BR.PrintE_C2();
		PrintSpace();
		BACK.PrintCenter();
		PrintSpace();
		BL.PrintE_C2();
		PrintSpace();
		PrintNewLine();

		//3rd OOO GGG RRR BBB
		//3rd OOO BLD3 LD2 FLD2
		BLD.PrintC_C3();
		PrintSpace();
		LD.PrintE_C2();
		PrintSpace();
		FLD.PrintC_C2();
		PrintSpace();
		//3rd GGG FLD3 FD1 FRD2
		FLD.PrintC_C3();
		PrintSpace();
		FD.PrintE_C1();
		PrintSpace();
		FRD.PrintC_C2();
		PrintSpace();
		//3rd RRR FRD3 RD1 BRD2
		FRD.PrintC_C3();
		PrintSpace();
		RD.PrintE_C1();
		PrintSpace();
		BRD.PrintC_C2();
		PrintSpace();
		//3rd BBB BRD3 BD1 BLD2
		BRD.PrintC_C3();
		PrintSpace();
		BD.PrintE_C1();
		PrintSpace();
		BLD.PrintC_C2();
		PrintNewLine();

		// YYY
		//1st YYY FLD1 FD2 FRD1
		PrintSixSpaces();
		FLD.PrintC_C1();
		PrintSpace();
		FD.PrintE_C2();
		PrintSpace();
		FRD.PrintC_C1();
		PrintNewLine();
		//2nd YYY LD1 DOWN RD2
		PrintSixSpaces();
		LD.PrintE_C1();
		PrintSpace();
		DOWN.PrintCenter();
		PrintSpace();
		RD.PrintE_C2();
		PrintNewLine();
		//3rd YYY BLD1 BD2 BRD1
		PrintSixSpaces();
		BLD.PrintC_C1();
		PrintSpace();
		BD.PrintE_C2();
		PrintSpace();
		BRD.PrintC_C1();
		PrintNewLine();
	}
	void TurnR()
	{
		//Corners: FRU -> BRU -> BRD -> FRD -> FRU; Edges: FR -> RU -> BR -> RD -> FR.
		Corner C_BUFF1, C_BUFF2, C_BUFF3;
		Edge E_BUFF1, E_BUFF2, E_BUFF3;
		C_BUFF1.SetCorner(FRU.GetC_C1(), FRU.GetC_C2(), FRU.GetC_C3());
		C_BUFF2.SetCorner(BRU.GetC_C1(), BRU.GetC_C2(), BRU.GetC_C3());
		C_BUFF3.SetCorner(BRD.GetC_C1(), BRD.GetC_C2(), BRD.GetC_C3());
		E_BUFF1.SetEdge(RU.GetE_C1(), RU.GetE_C2());
		E_BUFF2.SetEdge(BR.GetE_C1(), BR.GetE_C2());
		E_BUFF3.SetEdge(RD.GetE_C1(), RD.GetE_C2());
		FRU.SetCorner(FRD.GetC_C2(), FRD.GetC_C3(), FRD.GetC_C1());
		RU.SetEdge(FR.GetE_C1(), FR.GetE_C2());
		BRU.SetCorner(C_BUFF1.GetC_C3(), C_BUFF1.GetC_C1(), C_BUFF1.GetC_C2());
		BR.SetEdge(E_BUFF1.GetE_C2(), E_BUFF1.GetE_C1());
		BRD.SetCorner(C_BUFF2.GetC_C2(), C_BUFF2.GetC_C3(), C_BUFF2.GetC_C1());
		RD.SetEdge(E_BUFF2.GetE_C1(), E_BUFF2.GetE_C2());
		FRD.SetCorner(C_BUFF3.GetC_C3(), C_BUFF3.GetC_C1(), C_BUFF3.GetC_C2());
		FR.SetEdge(E_BUFF3.GetE_C2(), E_BUFF3.GetE_C1());
	}
	void TurnRprime()
	{
		//Corners: FRU -> FRD -> BRD -> BRU -> FRU; Edges: FR -> RD -> BR -> RU -> FR.
		Corner C_BUFF1, C_BUFF2, C_BUFF3;
		Edge E_BUFF1, E_BUFF2, E_BUFF3;
		C_BUFF1.SetCorner(FRU.GetC_C1(), FRU.GetC_C2(), FRU.GetC_C3());
		C_BUFF2.SetCorner(FRD.GetC_C1(), FRD.GetC_C2(), FRD.GetC_C3());
		C_BUFF3.SetCorner(BRD.GetC_C1(), BRD.GetC_C2(), BRD.GetC_C3());
		E_BUFF1.SetEdge(RD.GetE_C1(), RD.GetE_C2());
		E_BUFF2.SetEdge(FR.GetE_C1(), FR.GetE_C2());
		E_BUFF3.SetEdge(RU.GetE_C1(), RU.GetE_C2());
		FRU.SetCorner(BRU.GetC_C2(), BRU.GetC_C3(), BRU.GetC_C1());
		RU.SetEdge(BR.GetE_C2(), BR.GetE_C1());
		BRU.SetCorner(C_BUFF3.GetC_C3(), C_BUFF3.GetC_C1(), C_BUFF3.GetC_C2());
		BR.SetEdge(E_BUFF1.GetE_C1(), E_BUFF1.GetE_C2());
		BRD.SetCorner(C_BUFF2.GetC_C2(), C_BUFF2.GetC_C3(), C_BUFF2.GetC_C1());
		RD.SetEdge(E_BUFF2.GetE_C2(), E_BUFF2.GetE_C1());
		FRD.SetCorner(C_BUFF1.GetC_C3(), C_BUFF1.GetC_C1(), C_BUFF1.GetC_C2());
		FR.SetEdge(E_BUFF3.GetE_C1(), E_BUFF3.GetE_C2());
	}
	void TurnL()
	{
		//Corners: FLU -> FLD -> BLD -> BLU -> FLU; Edges: LU -> FL -> LD -> BL -> LU.
		Corner C_BUFF1, C_BUFF2, C_BUFF3;
		Edge E_BUFF1, E_BUFF2, E_BUFF3;
		C_BUFF1.SetCorner(FLU.GetC_C1(), FLU.GetC_C2(), FLU.GetC_C3());
		C_BUFF2.SetCorner(FLD.GetC_C1(), FLD.GetC_C2(), FLD.GetC_C3());
		C_BUFF3.SetCorner(BLD.GetC_C1(), BLD.GetC_C2(), BLD.GetC_C3());
		E_BUFF1.SetEdge(LD.GetE_C1(), LD.GetE_C2());
		E_BUFF2.SetEdge(FL.GetE_C1(), FL.GetE_C2());
		E_BUFF3.SetEdge(LU.GetE_C1(), LU.GetE_C2());
		FLU.SetCorner(BLU.GetC_C3(), BLU.GetC_C1(), BLU.GetC_C2());
		LU.SetEdge(BL.GetE_C1(), BL.GetE_C2());
		BLU.SetCorner(C_BUFF3.GetC_C2(), C_BUFF3.GetC_C3(), C_BUFF3.GetC_C1());
		BL.SetEdge(E_BUFF1.GetE_C2(), E_BUFF1.GetE_C1());
		BLD.SetCorner(C_BUFF2.GetC_C3(), C_BUFF2.GetC_C1(), C_BUFF2.GetC_C2());
		LD.SetEdge(E_BUFF2.GetE_C2(), E_BUFF2.GetE_C1());
		FLD.SetCorner(C_BUFF1.GetC_C2(), C_BUFF1.GetC_C3(), C_BUFF1.GetC_C1());
		FL.SetEdge(E_BUFF3.GetE_C1(), E_BUFF3.GetE_C2());
	}
	void TurnLprime()
	{
		//Corners: FLU -> BLU -> BLD -> FLD -> FLU; Edges: LU -> BL -> LD -> FL -> LU.
		Corner C_BUFF1, C_BUFF2, C_BUFF3;
		Edge E_BUFF1, E_BUFF2, E_BUFF3;
		C_BUFF1.SetCorner(FLU.GetC_C1(), FLU.GetC_C2(), FLU.GetC_C3());
		C_BUFF2.SetCorner(BLU.GetC_C1(), BLU.GetC_C2(), BLU.GetC_C3());
		C_BUFF3.SetCorner(BLD.GetC_C1(), BLD.GetC_C2(), BLD.GetC_C3());
		E_BUFF1.SetEdge(LD.GetE_C1(), LD.GetE_C2());
		E_BUFF2.SetEdge(BL.GetE_C1(), BL.GetE_C2());
		E_BUFF3.SetEdge(LU.GetE_C1(), LU.GetE_C2());
		FLU.SetCorner(FLD.GetC_C3(), FLD.GetC_C1(), FLD.GetC_C2());
		LU.SetEdge(FL.GetE_C1(), FL.GetE_C2());
		BLU.SetCorner(C_BUFF1.GetC_C2(), C_BUFF1.GetC_C3(), C_BUFF1.GetC_C1());
		BL.SetEdge(E_BUFF3.GetE_C1(), E_BUFF3.GetE_C2());
		BLD.SetCorner(C_BUFF2.GetC_C3(), C_BUFF2.GetC_C1(), C_BUFF2.GetC_C2());
		LD.SetEdge(E_BUFF2.GetE_C2(), E_BUFF2.GetE_C1());
		FLD.SetCorner(C_BUFF3.GetC_C2(), C_BUFF3.GetC_C3(), C_BUFF3.GetC_C1());
		FL.SetEdge(E_BUFF1.GetE_C2(), E_BUFF1.GetE_C1());
	}
	void TurnU()
	{
		//Corners: FRU -> FLU -> BLU -> BRU -> FRU; Edges: FU -> LU -> BU -> RU -> FU.
		Corner C_BUFF1, C_BUFF2, C_BUFF3;
		Edge E_BUFF1, E_BUFF2, E_BUFF3;
		C_BUFF1.SetCorner(FRU.GetC_C1(), FRU.GetC_C2(), FRU.GetC_C3());
		C_BUFF2.SetCorner(FLU.GetC_C1(), FLU.GetC_C2(), FLU.GetC_C3());
		C_BUFF3.SetCorner(BLU.GetC_C1(), BLU.GetC_C2(), BLU.GetC_C3());
		E_BUFF1.SetEdge(FU.GetE_C1(), FU.GetE_C2());
		E_BUFF2.SetEdge(LU.GetE_C1(), LU.GetE_C2());
		E_BUFF3.SetEdge(BU.GetE_C1(), BU.GetE_C2());
		FRU.SetCorner(BRU.GetC_C1(), BRU.GetC_C2(), BRU.GetC_C3());
		FU.SetEdge(RU.GetE_C1(), RU.GetE_C2());
		FLU.SetCorner(C_BUFF1.GetC_C1(), C_BUFF1.GetC_C2(), C_BUFF1.GetC_C3());
		LU.SetEdge(E_BUFF1.GetE_C2(), E_BUFF1.GetE_C1());
		BLU.SetCorner(C_BUFF2.GetC_C1(), C_BUFF2.GetC_C2(), C_BUFF2.GetC_C3());
		BU.SetEdge(E_BUFF2.GetE_C2(), E_BUFF2.GetE_C1());
		BRU.SetCorner(C_BUFF3.GetC_C1(), C_BUFF3.GetC_C2(), C_BUFF3.GetC_C3());
		RU.SetEdge(E_BUFF3.GetE_C1(), E_BUFF3.GetE_C2());
	}
	void TurnUprime()
	{
		//Corners: FRU -> BRU -> BLU -> FLU -> FRU; Edges: FU -> RU -> BU -> LU -> FU.
		Corner C_BUFF1, C_BUFF2, C_BUFF3;
		Edge E_BUFF1, E_BUFF2, E_BUFF3;
		C_BUFF1.SetCorner(BLU.GetC_C1(), BLU.GetC_C2(), BLU.GetC_C3());
		C_BUFF2.SetCorner(BRU.GetC_C1(), BRU.GetC_C2(), BRU.GetC_C3());
		C_BUFF3.SetCorner(FRU.GetC_C1(), FRU.GetC_C2(), FRU.GetC_C3());
		E_BUFF1.SetEdge(BU.GetE_C1(), BU.GetE_C2());
		E_BUFF2.SetEdge(RU.GetE_C1(), RU.GetE_C2());
		E_BUFF3.SetEdge(FU.GetE_C1(), FU.GetE_C2());
		FRU.SetCorner(FLU.GetC_C1(), FLU.GetC_C2(), FLU.GetC_C3());
		FU.SetEdge(LU.GetE_C2(), LU.GetE_C1());
		FLU.SetCorner(C_BUFF1.GetC_C1(), C_BUFF1.GetC_C2(), C_BUFF1.GetC_C3());
		LU.SetEdge(E_BUFF1.GetE_C2(), E_BUFF1.GetE_C1());
		BLU.SetCorner(C_BUFF2.GetC_C1(), C_BUFF2.GetC_C2(), C_BUFF2.GetC_C3());
		BU.SetEdge(E_BUFF2.GetE_C1(), E_BUFF2.GetE_C2());
		BRU.SetCorner(C_BUFF3.GetC_C1(), C_BUFF3.GetC_C2(), C_BUFF3.GetC_C3());
		RU.SetEdge(E_BUFF3.GetE_C1(), E_BUFF3.GetE_C2());
	}
	void TurnD()
	{
		//Corners: FRD -> FLD -> BLD -> BRD -> FRD; Egdes: FD -> LD -> BD -> RD -> FD.
		Corner C_BUFF1, C_BUFF2, C_BUFF3;
		Edge E_BUFF1, E_BUFF2, E_BUFF3;
		C_BUFF1.SetCorner(BLD.GetC_C1(), BLD.GetC_C2(), BLD.GetC_C3());
		C_BUFF2.SetCorner(BRD.GetC_C1(), BRD.GetC_C2(), BRD.GetC_C3());
		C_BUFF3.SetCorner(FRD.GetC_C1(), FRD.GetC_C2(), FRD.GetC_C3());
		E_BUFF1.SetEdge(BD.GetE_C1(), BD.GetE_C2());
		E_BUFF2.SetEdge(RD.GetE_C1(), RD.GetE_C2());
		E_BUFF3.SetEdge(FD.GetE_C1(), FD.GetE_C2());
		FRD.SetCorner(FLD.GetC_C1(), FLD.GetC_C2(), FLD.GetC_C3());
		FD.SetEdge(LD.GetE_C2(), LD.GetE_C1());
		FLD.SetCorner(C_BUFF1.GetC_C1(), C_BUFF1.GetC_C2(), C_BUFF1.GetC_C3());
		LD.SetEdge(E_BUFF1.GetE_C2(), E_BUFF1.GetE_C1());
		BLD.SetCorner(C_BUFF2.GetC_C1(), C_BUFF2.GetC_C2(), C_BUFF2.GetC_C3());
		BD.SetEdge(E_BUFF2.GetE_C1(), E_BUFF2.GetE_C2());
		BRD.SetCorner(C_BUFF3.GetC_C1(), C_BUFF3.GetC_C2(), C_BUFF3.GetC_C3());
		RD.SetEdge(E_BUFF3.GetE_C1(), E_BUFF3.GetE_C2());
	}
	void TurnDprime()
	{
		//Corners: FRD -> BRD -> BLD -> FLD -> FRD; Edges: FD -> RD -> BD -> LD -> FD.
		Corner C_BUFF1, C_BUFF2, C_BUFF3;
		Edge E_BUFF1, E_BUFF2, E_BUFF3;
		C_BUFF1.SetCorner(FRD.GetC_C1(), FRD.GetC_C2(), FRD.GetC_C3());
		C_BUFF2.SetCorner(FLD.GetC_C1(), FLD.GetC_C2(), FLD.GetC_C3());
		C_BUFF3.SetCorner(BLD.GetC_C1(), BLD.GetC_C2(), BLD.GetC_C3());
		E_BUFF1.SetEdge(FD.GetE_C1(), FD.GetE_C2());
		E_BUFF2.SetEdge(LD.GetE_C1(), LD.GetE_C2());
		E_BUFF3.SetEdge(BD.GetE_C1(), BD.GetE_C2());
		FRD.SetCorner(BRD.GetC_C1(), BRD.GetC_C2(), BRD.GetC_C3());
		FD.SetEdge(RD.GetE_C1(), RD.GetE_C2());
		FLD.SetCorner(C_BUFF1.GetC_C1(), C_BUFF1.GetC_C2(), C_BUFF1.GetC_C3());
		LD.SetEdge(E_BUFF1.GetE_C2(), E_BUFF1.GetE_C1());
		BLD.SetCorner(C_BUFF2.GetC_C1(), C_BUFF2.GetC_C2(), C_BUFF2.GetC_C3());
		BD.SetEdge(E_BUFF2.GetE_C2(), E_BUFF2.GetE_C1());
		BRD.SetCorner(C_BUFF3.GetC_C1(), C_BUFF3.GetC_C2(), C_BUFF3.GetC_C3());
		RD.SetEdge(E_BUFF3.GetE_C1(), E_BUFF3.GetE_C2());
	}
	void TurnF()
	{
		//Corners: FRU -> FRD -> FLD -> FLU -> FRU; Edges: FU -> FR -> FD -> FL -> FU.
		Corner C_BUFF1, C_BUFF2, C_BUFF3;
		Edge E_BUFF1, E_BUFF2, E_BUFF3;
		C_BUFF1.SetCorner(FRU.GetC_C1(), FRU.GetC_C2(), FRU.GetC_C3());
		C_BUFF2.SetCorner(FRD.GetC_C1(), FRD.GetC_C2(), FRD.GetC_C3());
		C_BUFF3.SetCorner(FLD.GetC_C1(), FLD.GetC_C2(), FLD.GetC_C3());
		E_BUFF1.SetEdge(FU.GetE_C1(), FU.GetE_C2());
		E_BUFF2.SetEdge(FR.GetE_C1(), FR.GetE_C2());
		E_BUFF3.SetEdge(FD.GetE_C1(), FD.GetE_C2());
		FRU.SetCorner(FLU.GetC_C3(), FLU.GetC_C1(), FLU.GetC_C2());
		FU.SetEdge(FL.GetE_C1(), FL.GetE_C2());
		FRD.SetCorner(C_BUFF1.GetC_C2(), C_BUFF1.GetC_C3(), C_BUFF1.GetC_C1());
		FR.SetEdge(E_BUFF1.GetE_C2(), E_BUFF1.GetE_C1());
		FLD.SetCorner(C_BUFF2.GetC_C3(), C_BUFF2.GetC_C1(), C_BUFF2.GetC_C2());
		FD.SetEdge(E_BUFF2.GetE_C1(), E_BUFF2.GetE_C2());
		FLU.SetCorner(C_BUFF3.GetC_C2(), C_BUFF3.GetC_C3(), C_BUFF3.GetC_C1());
		FL.SetEdge(E_BUFF3.GetE_C2(), E_BUFF3.GetE_C1());
	}
	void TurnFprime()
	{
		//Corners: FRU -> FLU -> FLD -> FRD -> FRU; Edges: FU -> FL -> FD -> FR -> FU.
		Corner C_BUFF1, C_BUFF2, C_BUFF3;
		Edge E_BUFF1, E_BUFF2, E_BUFF3;
		C_BUFF1.SetCorner(FLD.GetC_C1(), FLD.GetC_C2(), FLD.GetC_C3());
		C_BUFF2.SetCorner(FLU.GetC_C1(), FLU.GetC_C2(), FLU.GetC_C3());
		C_BUFF3.SetCorner(FRU.GetC_C1(), FRU.GetC_C2(), FRU.GetC_C3());
		E_BUFF1.SetEdge(FD.GetE_C1(), FD.GetE_C2());
		E_BUFF2.SetEdge(FL.GetE_C1(), FL.GetE_C2());
		E_BUFF3.SetEdge(FU.GetE_C1(), FU.GetE_C2());
		FRU.SetCorner(FRD.GetC_C3(), FRD.GetC_C1(), FRD.GetC_C2());
		FU.SetEdge(FR.GetE_C2(), FR.GetE_C1());
		FRD.SetCorner(C_BUFF1.GetC_C2(), C_BUFF1.GetC_C3(), C_BUFF1.GetC_C1());
		FR.SetEdge(E_BUFF1.GetE_C1(), E_BUFF1.GetE_C2());
		FLD.SetCorner(C_BUFF2.GetC_C3(), C_BUFF2.GetC_C1(), C_BUFF2.GetC_C2());
		FD.SetEdge(E_BUFF2.GetE_C2(), E_BUFF2.GetE_C1());
		FLU.SetCorner(C_BUFF3.GetC_C2(), C_BUFF3.GetC_C3(), C_BUFF3.GetC_C1());
		FL.SetEdge(E_BUFF3.GetE_C1(), E_BUFF3.GetE_C2());
	}
	void TurnB()
	{
		//Corners: BRU -> BLU -> BLD -> BRD -> BRU; Edges: BU -> BL -> BD -> BR -> BU.
		Corner C_BUFF1, C_BUFF2, C_BUFF3;
		Edge E_BUFF1, E_BUFF2, E_BUFF3;
		C_BUFF1.SetCorner(BLD.GetC_C1(), BLD.GetC_C2(), BLD.GetC_C3());
		C_BUFF2.SetCorner(BLU.GetC_C1(), BLU.GetC_C2(), BLU.GetC_C3());
		C_BUFF3.SetCorner(BRU.GetC_C1(), BRU.GetC_C2(), BRU.GetC_C3());
		E_BUFF1.SetEdge(BD.GetE_C1(), BD.GetE_C2());
		E_BUFF2.SetEdge(BL.GetE_C1(), BL.GetE_C2());
		E_BUFF3.SetEdge(BU.GetE_C1(), BU.GetE_C2());
		BRU.SetCorner(BRD.GetC_C2(), BRD.GetC_C3(), BRD.GetC_C1());
		BU.SetEdge(BR.GetE_C1(), BR.GetE_C2());
		BRD.SetCorner(C_BUFF1.GetC_C3(), C_BUFF1.GetC_C1(), C_BUFF1.GetC_C2());
		BR.SetEdge(E_BUFF1.GetE_C2(), E_BUFF1.GetE_C1());
		BLD.SetCorner(C_BUFF2.GetC_C2(), C_BUFF2.GetC_C3(), C_BUFF2.GetC_C1());
		BD.SetEdge(E_BUFF2.GetE_C2(), E_BUFF2.GetE_C1());
		BLU.SetCorner(C_BUFF3.GetC_C3(), C_BUFF3.GetC_C1(), C_BUFF3.GetC_C2());
		BL.SetEdge(E_BUFF3.GetE_C1(), E_BUFF3.GetE_C2());
	}
	void TurnBprime()
	{
		//Corners: BRU -> BRD -> BLD -> BLU -> BRU; Edges: BU -> BR -> BD -> BL -> BU.
		Corner C_BUFF1, C_BUFF2, C_BUFF3;
		Edge E_BUFF1, E_BUFF2, E_BUFF3;
		C_BUFF1.SetCorner(BRU.GetC_C1(), BRU.GetC_C2(), BRU.GetC_C3());
		C_BUFF2.SetCorner(BRD.GetC_C1(), BRD.GetC_C2(), BRD.GetC_C3());
		C_BUFF3.SetCorner(BLD.GetC_C1(), BLD.GetC_C2(), BLD.GetC_C3());
		E_BUFF1.SetEdge(BU.GetE_C1(), BU.GetE_C2());
		E_BUFF2.SetEdge(BR.GetE_C1(), BR.GetE_C2());
		E_BUFF3.SetEdge(BD.GetE_C1(), BD.GetE_C2());
		BRU.SetCorner(BLU.GetC_C2(), BLU.GetC_C3(), BLU.GetC_C1());
		BU.SetEdge(BL.GetE_C1(), BL.GetE_C2());
		BRD.SetCorner(C_BUFF1.GetC_C3(), C_BUFF1.GetC_C1(), C_BUFF1.GetC_C2());
		BR.SetEdge(E_BUFF1.GetE_C1(), E_BUFF1.GetE_C2());
		BLD.SetCorner(C_BUFF2.GetC_C2(), C_BUFF2.GetC_C3(), C_BUFF2.GetC_C1());
		BD.SetEdge(E_BUFF2.GetE_C2(), E_BUFF2.GetE_C1());
		BLU.SetCorner(C_BUFF3.GetC_C3(), C_BUFF3.GetC_C1(), C_BUFF3.GetC_C2());
		BL.SetEdge(E_BUFF3.GetE_C2(), E_BUFF3.GetE_C1());
	}
	void TurnM()
	{
		//Centers: UP -> FRONT -> DOWN -> BACK -> UP; Edges: FU -> FD -> BD -> BU -> FU.
		Center Cen_BUFF1, Cen_BUFF2, Cen_BUFF3;
		Edge E_BUFF1, E_BUFF2, E_BUFF3;
		Cen_BUFF1.SetCenter(DOWN.GetCenter());
		Cen_BUFF2.SetCenter(FRONT.GetCenter());
		Cen_BUFF3.SetCenter(UP.GetCenter());
		E_BUFF1.SetEdge(BD.GetE_C1(), BD.GetE_C2());
		E_BUFF2.SetEdge(FD.GetE_C1(), FD.GetE_C2());
		E_BUFF3.SetEdge(FU.GetE_C1(), FU.GetE_C2());
		UP.SetCenter(BACK.GetCenter());
		BACK.SetCenter(Cen_BUFF1.GetCenter());
		DOWN.SetCenter(Cen_BUFF2.GetCenter());
		FRONT.SetCenter(Cen_BUFF3.GetCenter());
		FU.SetEdge(BU.GetE_C2(), BU.GetE_C1());
		BU.SetEdge(E_BUFF1.GetE_C1(), E_BUFF1.GetE_C2());
		BD.SetEdge(E_BUFF2.GetE_C2(), E_BUFF2.GetE_C1());
		FD.SetEdge(E_BUFF3.GetE_C1(), E_BUFF3.GetE_C2());
	}
	void TurnMprime()
	{
		//Centers: UP -> BACK -> DOWN -> FRONT -> UP; Edges: FU -> BU -> BD -> FD -> FU.
		Center Cen_BUFF1, Cen_BUFF2, Cen_BUFF3;
		Edge E_BUFF1, E_BUFF2, E_BUFF3;
		Cen_BUFF1.SetCenter(UP.GetCenter());
		Cen_BUFF2.SetCenter(BACK.GetCenter());
		Cen_BUFF3.SetCenter(DOWN.GetCenter());
		E_BUFF1.SetEdge(FU.GetE_C1(), FU.GetE_C2());
		E_BUFF2.SetEdge(BU.GetE_C1(), BU.GetE_C2());
		E_BUFF3.SetEdge(BD.GetE_C1(), BD.GetE_C2());
		UP.SetCenter(FRONT.GetCenter());
		BACK.SetCenter(Cen_BUFF1.GetCenter());
		DOWN.SetCenter(Cen_BUFF2.GetCenter());
		FRONT.SetCenter(Cen_BUFF3.GetCenter());
		FU.SetEdge(FD.GetE_C1(), FD.GetE_C2());
		BU.SetEdge(E_BUFF1.GetE_C2(), E_BUFF1.GetE_C1());
		BD.SetEdge(E_BUFF2.GetE_C1(), E_BUFF2.GetE_C2());
		FD.SetEdge(E_BUFF3.GetE_C2(), E_BUFF3.GetE_C1());
	}
	void TurnE()
	{
		//Centers: FRONT -> RIGHT -> BACK -> LEFT -> FRONT; Edges: FR -> BR -> BL -> FL -> FR.
		Center Cen_BUFF1, Cen_BUFF2, Cen_BUFF3;
		Edge E_BUFF1, E_BUFF2, E_BUFF3;
		Cen_BUFF1.SetCenter(FRONT.GetCenter());
		Cen_BUFF2.SetCenter(RIGHT.GetCenter());
		Cen_BUFF3.SetCenter(BACK.GetCenter());
		E_BUFF1.SetEdge(FR.GetE_C1(), FR.GetE_C2());
		E_BUFF2.SetEdge(BR.GetE_C1(), BR.GetE_C2());
		E_BUFF3.SetEdge(BL.GetE_C1(), BL.GetE_C2());
		FRONT.SetCenter(LEFT.GetCenter());
		RIGHT.SetCenter(Cen_BUFF1.GetCenter());
		BACK.SetCenter(Cen_BUFF2.GetCenter());
		LEFT.SetCenter(Cen_BUFF3.GetCenter());
		FR.SetEdge(FL.GetE_C1(), FL.GetE_C2());
		BR.SetEdge(E_BUFF1.GetE_C1(), E_BUFF1.GetE_C2());
		BL.SetEdge(E_BUFF2.GetE_C2(), E_BUFF2.GetE_C1());
		FL.SetEdge(E_BUFF3.GetE_C2(), E_BUFF3.GetE_C1());
	}
	void TurnEprime()
	{
		//Centers: FRONT -> LEFT -> BACK -> RIGHT -> FRONT; Edges: FR -> FL -> BL -> BR -> FR.
		Center Cen_BUFF1, Cen_BUFF2, Cen_BUFF3;
		Edge E_BUFF1, E_BUFF2, E_BUFF3;
		Cen_BUFF1.SetCenter(BACK.GetCenter());
		Cen_BUFF2.SetCenter(LEFT.GetCenter());
		Cen_BUFF3.SetCenter(FRONT.GetCenter());
		E_BUFF1.SetEdge(BL.GetE_C1(), BL.GetE_C2());
		E_BUFF2.SetEdge(FL.GetE_C1(), FL.GetE_C2());
		E_BUFF3.SetEdge(FR.GetE_C1(), FR.GetE_C2());
		FRONT.SetCenter(RIGHT.GetCenter());
		RIGHT.SetCenter(Cen_BUFF1.GetCenter());
		BACK.SetCenter(Cen_BUFF2.GetCenter());
		LEFT.SetCenter(Cen_BUFF3.GetCenter());
		FR.SetEdge(BR.GetE_C1(), BR.GetE_C2());
		BR.SetEdge(E_BUFF1.GetE_C2(), E_BUFF1.GetE_C1());
		BL.SetEdge(E_BUFF2.GetE_C2(), E_BUFF2.GetE_C1());
		FL.SetEdge(E_BUFF3.GetE_C1(), E_BUFF3.GetE_C2());
	}
	void TurnS()
	{
		//Centers: UP -> RIGHT -> DOWN -> LEFT -> UP; Edges: RU -> RD -> LD -> LU -> RU.
		Center Cen_BUFF1, Cen_BUFF2, Cen_BUFF3;
		Edge E_BUFF1, E_BUFF2, E_BUFF3;
		Cen_BUFF1.SetCenter(UP.GetCenter());
		Cen_BUFF2.SetCenter(RIGHT.GetCenter());
		Cen_BUFF3.SetCenter(DOWN.GetCenter());
		E_BUFF1.SetEdge(RU.GetE_C1(), RU.GetE_C2());
		E_BUFF2.SetEdge(RD.GetE_C1(), RD.GetE_C2());
		E_BUFF3.SetEdge(LD.GetE_C1(), LD.GetE_C2());
		UP.SetCenter(LEFT.GetCenter());
		RIGHT.SetCenter(Cen_BUFF1.GetCenter());
		DOWN.SetCenter(Cen_BUFF2.GetCenter());
		LEFT.SetCenter(Cen_BUFF3.GetCenter());
		RU.SetEdge(LU.GetE_C1(), LU.GetE_C2());
		RD.SetEdge(E_BUFF1.GetE_C1(), E_BUFF1.GetE_C2());
		LD.SetEdge(E_BUFF2.GetE_C1(), E_BUFF2.GetE_C2());
		LU.SetEdge(E_BUFF3.GetE_C1(), E_BUFF3.GetE_C2());
	}
	void TurnSprime()
	{
		//Centers: UP -> LEFT -> DOWN -> RIGHT -> UP; Edges: RU -> LU -> LD -> RD -> RU.
		Center Cen_BUFF1, Cen_BUFF2, Cen_BUFF3;
		Edge E_BUFF1, E_BUFF2, E_BUFF3;
		Cen_BUFF1.SetCenter(DOWN.GetCenter());
		Cen_BUFF2.SetCenter(LEFT.GetCenter());
		Cen_BUFF3.SetCenter(UP.GetCenter());
		E_BUFF1.SetEdge(LD.GetE_C1(), LD.GetE_C2());
		E_BUFF2.SetEdge(LU.GetE_C1(), LU.GetE_C2());
		E_BUFF3.SetEdge(RU.GetE_C1(), RU.GetE_C2());
		UP.SetCenter(RIGHT.GetCenter());
		RIGHT.SetCenter(Cen_BUFF1.GetCenter());
		DOWN.SetCenter(Cen_BUFF2.GetCenter());
		LEFT.SetCenter(Cen_BUFF3.GetCenter());
		RU.SetEdge(RD.GetE_C1(), RD.GetE_C2());
		RD.SetEdge(E_BUFF1.GetE_C1(), E_BUFF1.GetE_C2());
		LD.SetEdge(E_BUFF2.GetE_C1(), E_BUFF2.GetE_C2());
		LU.SetEdge(E_BUFF3.GetE_C1(), E_BUFF3.GetE_C2());
	}
	void TurnX()
	{
		TurnR();
		TurnLprime();
		TurnMprime();
	}
	void TurnXprime()
	{
		TurnRprime();
		TurnL();
		TurnM();
	}
	void TurnY()
	{
		TurnEprime();
		TurnU();
		TurnDprime();
	}
	void TurnYprime()
	{
		TurnE();
		TurnUprime();
		TurnD();
	}
	void TurnZ()
	{
		TurnF();
		TurnS();
		TurnBprime();
	}
	void TurnZprime()
	{
		TurnFprime();
		TurnSprime();
		TurnB();
	}
	void Turnr()
	{
		TurnMprime();
		TurnR();
	}
	void Turnrprime()
	{
		TurnM();
		TurnRprime();
	}
	void Turnl()
	{
		TurnM();
		TurnL();
	}
	void Turnlprime()
	{
		TurnMprime();
		TurnLprime();
	}
	void Turnu()
	{
		TurnU();
		TurnEprime();
	}
	void Turnuprime()
	{
		TurnUprime();
		TurnE();
	}
	void Turnd()
	{
		TurnE();
		TurnD();
	}
	void Turndprime()
	{
		TurnEprime();
		TurnDprime();
	}
	void Turnf()
	{
		TurnF();
		TurnS();
	}
	void Turnfprime()
	{
		TurnFprime();
		TurnSprime();
	}
	void Turnb()
	{
		TurnB();
		TurnSprime();
	}
	void Turnbprime()
	{
		TurnBprime();
		TurnS();
	}
	void TurnR2()
	{
		TurnR();
		TurnR();
	}
	void TurnL2()
	{
		TurnL();
		TurnL();
	}
	void TurnU2()
	{
		TurnU();
		TurnU();
	}
	void TurnD2()
	{
		TurnD();
		TurnD();
	}
	void TurnF2()
	{
		TurnF();
		TurnF();
	}
	void TurnB2()
	{
		TurnB();
		TurnB();
	}
	void TurnM2()
	{
		TurnM();
		TurnM();
	}
	void TurnS2()
	{
		TurnS();
		TurnS();
	}
	void TurnE2()
	{
		TurnE();
		TurnE();
	}
	void TurnX2()
	{
		TurnX();
		TurnX();
	}
	void TurnY2()
	{
		TurnY();
		TurnY();
	}
	void TurnZ2()
	{
		TurnZ();
		TurnZ();
	}
	void Turnr2()
	{
		Turnr();
		Turnr();
	}
	void Turnl2()
	{
		Turnl();
		Turnl();
	}
	void Turnu2()
	{
		Turnu();
		Turnu();
	}
	void Turnd2()
	{
		Turnd();
		Turnd();
	}
	void Turnf2()
	{
		Turnf();
		Turnf();
	}
	void Turnb2()
	{
		Turnb();
		Turnb();
	}
	int SetScramble(std::string Scramble)
	{
		int n = 0;
		for (int i = 0; i <= Scramble.length(); i++)
		{
			if (Scramble[i] == 'L' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
			{
				TurnL();
				n++;
			}
			else if (Scramble[i] == 'R' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
			{
				TurnR();
				n++;
			}
			else if (Scramble[i] == 'U' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
			{
				TurnU();
				n++;
			}
			else if (Scramble[i] == 'D' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
			{
				TurnD();
				n++;
			}
			else if (Scramble[i] == 'F' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
			{
				TurnF();
				n++;
			}
			else if (Scramble[i] == 'B' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
			{
				TurnB();
				n++;
			}
			else if (Scramble[i] == 'L' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
			{
				TurnLprime();
				n++;
			}
			else if (Scramble[i] == 'R' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
			{
				TurnRprime();
				n++;
			}
			else if (Scramble[i] == 'U' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
			{
				TurnUprime();
				n++;
			}
			else if (Scramble[i] == 'D' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
			{
				TurnDprime();
				n++;
			}
			else if (Scramble[i] == 'F' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
			{
				TurnFprime();
				n++;
			}
			else if (Scramble[i] == 'B' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
			{
				TurnBprime();
				n++;
			}
			else if (Scramble[i] == 'L' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
			{
				TurnL2();
				n++;
			}
			else if (Scramble[i] == 'R' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
			{
				TurnR2();
				n++;
			}
			else if (Scramble[i] == 'U' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
			{
				TurnU2();
				n++;
			}
			else if (Scramble[i] == 'D' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
			{
				TurnD2();
				n++;
			}
			else if (Scramble[i] == 'F' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
			{
				TurnF2();
				n++;
			}
			else if (Scramble[i] == 'B' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
			{
				TurnB2();
				n++;
			}
			else if (Scramble[i] == 'l' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
			{
				Turnl2();
				n++;
			}
			else if (Scramble[i] == 'r' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
			{
				Turnr2();
				n++;
			}
			else if (Scramble[i] == 'u' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
			{
				Turnu2();
				n++;
			}
			else if (Scramble[i] == 'd' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
			{
				Turnd2();
				n++;
			}
			else if (Scramble[i] == 'f' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
			{
				Turnf2();
				n++;
			}
			else if (Scramble[i] == 'b' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
			{
				Turnb2();
				n++;
			}
			else if (Scramble[i] == 'l' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
			{
				Turnl();
				n++;
			}
			else if (Scramble[i] == 'r' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
			{
				Turnr();
				n++;
			}
			else if (Scramble[i] == 'u' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
			{
				Turnu();
				n++;
			}
			else if (Scramble[i] == 'd' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
			{
				Turnd();
				n++;
			}
			else if (Scramble[i] == 'f' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
			{
				Turnf();
				n++;
			}
			else if (Scramble[i] == 'b' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
			{
				Turnb();
				n++;
			}
			else if (Scramble[i] == 'l' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
			{
				Turnlprime();
				n++;
			}
			else if (Scramble[i] == 'r' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
			{
				Turnrprime();
				n++;
			}
			else if (Scramble[i] == 'u' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
			{
				Turnuprime();
				n++;
			}
			else if (Scramble[i] == 'd' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
			{
				Turndprime();
				n++;
			}
			else if (Scramble[i] == 'f' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
			{
				Turnfprime();
				n++;
			}
			else if (Scramble[i] == 'b' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
			{
				Turnbprime();
				n++;
			}
			else if (Scramble[i] == 'M' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
			{
				TurnM2();
				n++;
			}
			else if (Scramble[i] == 'E' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
			{
				TurnE2();
				n++;
			}
			else if (Scramble[i] == 'S' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
			{
				TurnS2();
				n++;
			}
			else if (Scramble[i] == 'x' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
			{
				TurnX2();
				n++;
			}
			else if (Scramble[i] == 'y' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
			{
				TurnY2();
				n++;
			}
			else if (Scramble[i] == 'z' && Scramble[i + 1] == '2' && Scramble[i + 1] != '\'')
			{
				TurnZ2();
				n++;
			}
			else if (Scramble[i] == 'M' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
			{
				TurnM();
				n++;
			}
			else if (Scramble[i] == 'E' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
			{
				TurnE();
				n++;
			}
			else if (Scramble[i] == 'S' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
			{
				TurnS();
				n++;
			}
			else if (Scramble[i] == 'x' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
			{
				TurnX();
				n++;
			}
			else if (Scramble[i] == 'y' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
			{
				TurnY();
				n++;
			}
			else if (Scramble[i] == 'z' && Scramble[i + 1] != '\'' && Scramble[i + 1] != '2')
			{
				TurnZ();
				n++;
			}
			else if (Scramble[i] == 'M' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
			{
				TurnMprime();
				n++;
			}
			else if (Scramble[i] == 'E' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
			{
				TurnEprime();
				n++;
			}
			else if (Scramble[i] == 'S' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
			{
				TurnSprime();
				n++;
			}
			else if (Scramble[i] == 'x' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
			{
				TurnXprime();
				n++;
			}
			else if (Scramble[i] == 'y' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
			{
				TurnYprime();
				n++;
			}
			else if (Scramble[i] == 'z' && Scramble[i + 1] == '\'' && Scramble[i + 1] != '2')
			{
				TurnZprime();
				n++;
			}
		}
		return n;
		//std::cout << Scramble << std::endl;
	}
	Cube()
	{
		SetSolveState();
	}
	Cube(std::string Scramble)
	{
		SetSolveState();
		SetScramble(Scramble);
		std::cout << "Scramble: " << Scramble << "\n";
	}
	bool IsEqualTo(Cube a)
	{
		if (FRU.IsEqualTo(a.FRU)
			&& FLU.IsEqualTo(a.FLU)
			&& FRD.IsEqualTo(a.FRD)
			&& FLD.IsEqualTo(a.FLD)
			&& BRU.IsEqualTo(a.BRU)
			&& BLU.IsEqualTo(a.BLU)
			&& BRD.IsEqualTo(a.BRD)
			&& BLD.IsEqualTo(a.BLD)
			&& FU.IsEqualTo(a.FU)
			&& FD.IsEqualTo(a.FD)
			&& FL.IsEqualTo(a.FL)
			&& FR.IsEqualTo(a.FR)
			&& BU.IsEqualTo(a.BU)
			&& BD.IsEqualTo(a.BD)
			&& BL.IsEqualTo(a.BL)
			&& BR.IsEqualTo(a.BR)
			&& RU.IsEqualTo(a.RU)
			&& RD.IsEqualTo(a.RD)
			&& LU.IsEqualTo(a.LU)
			&& LD.IsEqualTo(a.LD)
			&& FRONT.IsEqualTo(a.FRONT)
			&& UP.IsEqualTo(a.UP)
			&& BACK.IsEqualTo(a.BACK)
			&& DOWN.IsEqualTo(a.DOWN)
			&& RIGHT.IsEqualTo(a.RIGHT)
			&& LEFT.IsEqualTo(a.LEFT)
			)
			return true;
		else
			return false;
	}
};