#include "bignumber.h"

bignumber::bignumber()
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		NumberValue[i] = BIGNUMBER_ZERO;
	}
	MaxIndex = 0;
	Negative = FALSE;
}

bignumber::bignumber(char *InputNumberString)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		NumberValue[i] = BIGNUMBER_ZERO;
	}
	char *Finder;
	if (*InputNumberString == '-')
	{
		Negative = TRUE;
		Finder = InputNumberString + 1;
	}
	else
	{
		Negative = FALSE;
		Finder = InputNumberString;
	}
	int IndexFinder = 0;
	while (*(Finder+IndexFinder) != '\0')
	{
		IndexFinder++;
	}
	MaxIndex = IndexFinder - 1;
	int j = 0;
	for (int i = IndexFinder-1; i >= 0; i--)
	{
		if (*(Finder + i) >= '0' && *(Finder + i) <= '9')
		{
			NumberValue[j] = *(Finder + i) - '0';
		}
		else if (*(Finder + i) >= 'A' && *(Finder + i) <= 'F')
		{
			NumberValue[j] = *(Finder + i) - 'A';
		}
		else NumberValue[j] = 0;
		j++;
	}
}

bignumber::bignumber(short *InputNumberValue, bool NegativeOptition)
{
	Negative = NegativeOptition;
	MaxIndex = 0;
	for (int i = 0; i < MAXSIZE; i++)
	{
		NumberValue[i] = InputNumberValue[i];
	}
	for (int i = MAXSIZE - 1; i >= 0; i--)
	{
		if (NumberValue[i] != BIGNUMBER_ZERO)
		{
			MaxIndex = i;
			break;
		}
	}
}

void bignumber::Absolute(void)
{
	Negative = FALSE;
}

void bignumber::ChangeSymbol(void)
{
	Negative = !Negative;
}

void bignumber::Clear(void)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		NumberValue[i] = BIGNUMBER_ZERO;
	}
	MaxIndex = 0;
	Negative = FALSE;
}

int bignumber::GetLength(void)
{
	return MaxIndex+1;
}

char *bignumber::GetNumberString(void)
{
	char *Result;
	char Hexadecimal[] = "0123456789ABCDEF";
	if (Negative)
	{
		Result = new char[MaxIndex + 3];
		Result[0] = '-';
		Result[MaxIndex + 2] = '\0';
		for (int i = MaxIndex; i >= 0; i--)//數字範圍:1~MaxIndex+1
		{
			Result[MaxIndex+1-i] = Hexadecimal[NumberValue[i]];
		}
	}
	else
	{
		Result = new char[MaxIndex + 2];
		Result[MaxIndex + 1] = '\0';
		for (int i = MaxIndex; i >= 0; i--)	//數字範圍:0~MaxIndex
		{
			Result[MaxIndex - i] = Hexadecimal[NumberValue[i]];
		}
	}
	return Result;
}

short *bignumber::GetNumberValue(void)
{
	short *Result;
	Result = new short[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++)
	{
		Result[i] = NumberValue[i];
	}
	return Result;
}

bool bignumber::IsNegative(void)
{
	return Negative;
}

void bignumber::Show(void)
{
	//std::cout << "Negative :" << Negative << "|MAXINDEX : " << MaxIndex << "|" << std::endl;
	char Hexadecimal[] = "0123456789ABCDEF";
	if (Negative) std::cout << '-';
	for (int i = MaxIndex; i >= 0; i--)
	{
		std::cout << Hexadecimal[NumberValue[i]];
	}
	std::cout << std::endl;
}

void bignumber::Set(char *InputNumberString)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		NumberValue[i] = BIGNUMBER_ZERO;
	}
	char *Finder;
	if (*InputNumberString == '-')
	{
		Negative = TRUE;
		Finder = InputNumberString + 1;
	}
	else
	{
		Negative = FALSE;
		Finder = InputNumberString;
	}
	int IndexFinder = 0;
	while (*(Finder + IndexFinder) != '\0')
	{
		IndexFinder++;
	}
	MaxIndex = IndexFinder - 1;
	int j = 0;
	for (int i = IndexFinder - 1; i >= 0; i--)
	{
		if (*(Finder + i) >= '0' && *(Finder + i) <= '9')
		{
			NumberValue[j] = *(Finder + i) - '0';
		}
		else if (*(Finder + i) >= 'A' && *(Finder + i) <= 'F')
		{
			NumberValue[j] = *(Finder + i) - 'A';
		}
		else NumberValue[j] = 0;
		j++;
	}
}
void bignumber::Set(short *InputNumberValue, bool NegativeOptition)
{
	Negative = NegativeOptition;
	MaxIndex = 0;
	for (int i = 0; i < MAXSIZE; i++)
	{
		NumberValue[i] = InputNumberValue[i];
	}
	for (int i = MAXSIZE - 1; i >= 0; i--)
	{
		if (NumberValue[i] != BIGNUMBER_ZERO)
		{
			MaxIndex = i;
			break;
		}
	}
}

bignumber& bignumber::operator=(const bignumber& b)
{
	for (int i = 0; i < MAXSIZE; i++) NumberValue[i] = b.NumberValue[i];
	Negative = b.Negative;
	MaxIndex = b.MaxIndex;
	return *this;
}

bignumber operator+(bignumber& a, bignumber& b)
{
	std::cout << "Now in operator+" << std::endl;
	char Hexadecimal[] = "0123456789ABCDEF";
	short *ResultCatcher = new short[MAXSIZE];
	short *a_number = a.GetNumberValue();
	short *b_number = b.GetNumberValue();
	for (int i = 0; i < MAXSIZE; i++) ResultCatcher[i] = BIGNUMBER_ZERO;
	short Carry = BIGNUMBER_ZERO;
	bool NegativeOption = FALSE;
	if (a.IsNegative() == b.IsNegative())
	{
		NegativeOption = a.IsNegative();
		for (int i = 0; i < MAXSIZE; i++)
		{
			if (a_number[i] + b_number[i] + Carry >= BIGNUMBER_MAX + 1)
			{
				//std::cout << a[MAXSIZE - i] << "|" << b[MAXSIZE - i] << std::endl;
				//std::cin.get();
				ResultCatcher[i] = a_number[i] + b_number[i] + Carry - (BIGNUMBER_MAX + 1);
				Carry = 1;
			}
			else
			{
				//std::cout << a[MAXSIZE - i] << "|" << b[MAXSIZE - i] << std::endl;
				//std::cin.get();
				ResultCatcher[i] = a_number[i] + b_number[i] + Carry;
				Carry = 0;
			}
		}
	}
	else
	{
		if (a.IsNegative()) return b - a;
		else return a - b;
	}
	//for (int i = 0; i < MAXSIZE; i++) std::cout << ResultCatcher[i];
	bignumber Result(ResultCatcher,NegativeOption);
	delete a_number;
	delete b_number;
	return Result;
}

bignumber operator-(bignumber& a,bignumber& b)
{
	bool NegativeResult = FALSE;
	if (a == b)
	{
		bignumber Result;
		return Result;
	}
	if (a.IsNegative() != b.IsNegative())
	{
		b.ChangeSymbol();
		bignumber Result = a + b;
		b.ChangeSymbol();
		return Result;
	}
	else
	{
		short *a_number = a.GetNumberValue();
		short *b_number = b.GetNumberValue();
		short *Result_value = new short[MAXSIZE];
		for (int i = 0; i < MAXSIZE; i++) Result_value[i] = BIGNUMBER_ZERO;
		if (a.IsNegative())		//負負
		{
			if (a > b)
			{
				for (int i = 0; i < MAXSIZE; i++)
				{
					if (b_number[i] < a_number[i])
					{
						b_number[i] += BIGNUMBER_MAX + 1;
						for (int j = i + 1; j < MAXSIZE; j++)
						{
							if (b_number[j] != BIGNUMBER_ZERO)
							{
								b_number[j] -= 1;
								break;
							}
							else
							{
								b_number[j] = BIGNUMBER_MAX;
							}
						}
						Result_value[i] = b_number[i] - a_number[i];
					}
					else
					{
						Result_value[i] = b_number[i] - a_number[i];
					}
				}
				bignumber Result(Result_value,FALSE);
			}
			else
			{
				for (int i = 0; i < MAXSIZE; i++)
				{
					if (a_number[i] < b_number[i])
					{
						a_number[i] += BIGNUMBER_MAX + 1;
						for (int j = i + 1; j < MAXSIZE; j++)
						{
							if (a_number[j] != BIGNUMBER_ZERO)
							{
								a_number[j] -= 1;
								break;
							}
							else
							{
								a_number[j] = BIGNUMBER_MAX;
							}
						}
						Result_value[i] = a_number[i] - b_number[i];
					}
					else
					{
						Result_value[i] = a_number[i] - b_number[i];
					}
				}
				bignumber Result(Result_value, TRUE);
			}
		}
		else                    //正正
		{
			if (b > a)
			{
				for (int i = 0; i < MAXSIZE; i++)
				{
					if (b_number[i] < a_number[i])
					{
						b_number[i] += BIGNUMBER_MAX + 1;
						for (int j = i + 1; j < MAXSIZE; j++)
						{
							if (b_number[j] != BIGNUMBER_ZERO)
							{
								b_number[j] -= 1;
								break;
							}
							else
							{
								b_number[j] = BIGNUMBER_MAX;
							}
						}
						Result_value[i] = b_number[i] - a_number[i];
					}
					else
					{
						Result_value[i] = b_number[i] - a_number[i];
					}
				}
				bignumber Result(Result_value, TRUE);
			}
			else
			{
				for (int i = 0; i < MAXSIZE; i++)
				{
					if (a_number[i] < b_number[i])
					{
						a_number[i] += BIGNUMBER_MAX + 1;
						for (int j = i + 1; j < MAXSIZE; j++)
						{
							if (a_number[j] != BIGNUMBER_ZERO)
							{
								a_number[j] -= 1;
								break;
							}
							else
							{
								a_number[j] = BIGNUMBER_MAX;
							}
						}
						Result_value[i] = a_number[i] - b_number[i];
					}
					else
					{
						Result_value[i] = a_number[i] - b_number[i];
					}
				}
				bignumber Result(Result_value, FALSE);
			}
		}
	}
}

bignumber operator*(bignumber& a, bignumber& b)
{
	bool NegativeOption = TRUE;
	short *Result_Value = new short[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++) Result_Value[i] = BIGNUMBER_ZERO;
	int Length_a = a.GetLength();
	int Length_b = b.GetLength();
	short *a_value = a.GetNumberValue();
	short *b_value = b.GetNumberValue();
	for (int i = 0; i < Length_a; i++)
	{
		for (int j = 0; j < Length_b; j++)
		{
			Result_Value[i + j] += (a_value[i] * b_value[j]);
		}
	}
	short Carry = BIGNUMBER_ZERO;
	short Leaver = BIGNUMBER_ZERO;
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (Result_Value[i] > BIGNUMBER_MAX)
		{
			Result_Value[i + 1] += (Result_Value[i] / (BIGNUMBER_MAX + 1));
			Result_Value[i] = Result_Value[i] % (BIGNUMBER_MAX + 1);
		}
	}
	//for (int i = 0; i < MAXSIZE; i++) std::cout << Result_Value[i];
	if (!(a.IsNegative() ^ b.IsNegative())) NegativeOption = FALSE;
	//std::cout << std::endl << std::endl << NegativeOption << std::endl;
	bignumber Result(Result_Value,NegativeOption);
	return Result;
}

bignumber operator/(bignumber& a, bignumber& b)
{
	bignumber Result;
	return Result;					//uncompleted protect
	short *a_number = a.GetNumberValue();
	short *b_number = b.GetNumberValue();
	if (b == Result ||( a < b && !a.IsNegative() && !b.IsNegative())) return Result;
	if (a.GetLength() == b.GetLength() && a.IsNegative() == b.IsNegative() && b > a) return b;
	if (a == b)
	{
		bignumber One("1");
		delete a_number;
		delete b_number;
		return One;
	}
	short *Result_number = new short[MAXSIZE];

	return Result;
}

bignumber operator%(bignumber& a, bignumber& b)
{
	bignumber Result;
	return Result;
}

bool operator==(bignumber& a,bignumber& b)
{
	if (a.IsNegative() != b.IsNegative()) return FALSE;
	if (a.GetLength() != b.GetLength()) return FALSE;
	short *a_value = a.GetNumberValue();
	short *b_value = b.GetNumberValue();
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (a_value[i] != b_value[i])
		{
			delete a_value;
			delete b_value;
			return FALSE;
		}
	}
	delete a_value;
	delete b_value;
	return TRUE;
}

bool operator>(bignumber& a, bignumber& b)
{
	if (a == b) return FALSE;
	if (a.IsNegative() != b.IsNegative())		//正負或負正
	{
		if (a.IsNegative()) return FALSE;
		else return TRUE;
	}
	else
	{
		if (a.IsNegative())		//負負
		{
			if (a.GetLength() > b.GetLength())
			{
				return FALSE;
			}
			else if (a.GetLength() < b.GetLength())
			{
				return TRUE;
			}
			else
			{
				short *a_value = a.GetNumberValue();
				short *b_value = b.GetNumberValue();
				for (int i = MAXSIZE - 1; i >= 0; i--)
				{
					if (a_value[i] < b_value[i])
					{
						delete a_value;
						delete b_value;
						return TRUE;
					}
					else if (a_value[i] > b_value[i])
					{
						delete a_value;
						delete b_value;
						return FALSE;
					}
					else;
				}
				return FALSE;
			}
			
		}
		else                   //正正
		{
			if (a.GetLength() > b.GetLength())
			{
				return TRUE;
			}
			else if (a.GetLength() < b.GetLength())
			{
				return FALSE;
			}
			else
			{
				short *a_value = a.GetNumberValue();
				short *b_value = b.GetNumberValue();
				for (int i = MAXSIZE - 1; i >= 0; i--)
				{
					if (a_value[i] < b_value[i])
					{
						delete a_value;
						delete b_value;
						return FALSE;
					}
					else if (a_value[i] > b_value[i])
					{
						delete a_value;
						delete b_value;
						return TRUE;
					}
					else;
				}
				return FALSE;
			}
		}
	}
}

bool operator<(bignumber& a, bignumber& b)
{
	if (a == b) return FALSE;
	else return !(a>b);
}