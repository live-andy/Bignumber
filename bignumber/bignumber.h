#pragma once
#ifndef BIGNUMBER_H
#define BIGNUMBER_H
#define BIGNUMBER_ZERO 0
#define BIGNUMBER_MAX 15
#define TRUE 1
#define FALSE 0
#define MAXSIZE 2048
#define DecimalString "0123456789ABCDEF"
#include <iostream>
#include <cstring>



class bignumber
{
public:		//Member Functions
	bignumber();
	bignumber(char *InputNumberString);
	bignumber(short *InputNumberValue, bool NegativeOptition);
	void Absolute(void);
	void ChangeSymbol(void);
	void Clear(void);
	int GetLength(void);
	char *GetNumberString(void);
	short *GetNumberValue(void);
	bool IsNegative(void);
	void Set(char *InputNumberString);
	void Set(short *InputNumberValue, bool NegativeOptition);
	void Show(void);
public:		//Operators
	bignumber& operator=(const bignumber & b);
	short& operator [] (int i) { return NumberValue[MaxIndex - i]; }
	const short& operator [] (int i) const { return NumberValue[MaxIndex - i]; }
private:
	short NumberValue[MAXSIZE];	//由小到大紀錄數值
	bool Negative;
	char *NowPosition;
	int MaxIndex;
};

bignumber operator+(bignumber& a, bignumber& b);
bignumber operator-(bignumber& a, bignumber& b);
bignumber operator*(bignumber& a, bignumber& b);
bignumber operator/(bignumber& a, bignumber& b);
bignumber operator%(bignumber& a, bignumber& b);
bool operator<(bignumber& a, bignumber& b);
bool operator>(bignumber& a, bignumber& b);
bool operator==(bignumber& a, bignumber& b);

#endif