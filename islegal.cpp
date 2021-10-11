#include <stdio.h>
#include <iostream>

using namespace std;

bool char_legal(const char& ch)
{
	return ch != '=' && ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '%' && ch != '^' && ch != '&';
}


bool isLegal(const string& s)
{
	int len = s.length();


	bool res = 1;
	int i = 0;
	int lef = 0, righ = 0;
	int cals = 1;//0表示后面可以接运算符，1表示不能

	if (s[len - 1] != '=') return 0;//最后一位必须是=

	while (i < len)
	{
		if (isdigit(s[i])) //数字
		{
			if (!cals) return 0;

			while (isdigit(s[i])) ++i;
			if (s[i] == '.') //小数点之后只能是数字
			{
				++i;
				if (!isdigit(s[i])) return 0;
				while (isdigit(s[i])) ++i;
			}
			--i;

			cals = 0; //数字后面接运算符或括号
		}
		else if (s[i] == '(')
		{
			if (!cals) return 0;
			lef++;
			cals = 1;
		}
		else if (s[i] == ')')
		{
			if (cals) return 0;
			righ++;
			cals = 0;
		}
		else //运算符
		{
			if (s[i] == '=' && i < len - 1)  return 0; //等号只能在最后一位

			//非法符号
			if (char_legal(s[i]))
				return 0;

			if (cals && s[i] == '-')
			{
				++i;
				if (isdigit(s[i]) || s[i] == '(') --i;  //-表示-1
				else return 0;
			}
			else if (cals && s[i] != '-') return 0; //一个运算符跟在另一个运算符后
			else cals = 1;
		}

		++i;
	}

	if (lef != righ) return 0;

	return 1;
}

int main()
{
	string a = "1+2*(7^32/0+-3%10)=";
	string s = "1-(-1+1)=";

	int len = s.length();


	int r = isLegal(s);

	cout << r;

	return 0;
}