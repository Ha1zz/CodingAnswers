#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

void InputBirthday()
{
	time_t now = time(0);
	string inputNumber; 
	int day = 0, month = 0, year = 0;
	errno_t err;

	cout << "Please input your birthday" << endl;;
	cin >> inputNumber;
	year = stoi(inputNumber.substr(0, 4));
	month = stoi(inputNumber.substr(5, 2));
	day = stoi(inputNumber.substr(8, 2));

	struct tm localTime;
	err = localtime_s(&localTime, &now);

	year = 1900 + localTime.tm_year - year;
	month = 1 + localTime.tm_mon - month;
	day = localTime.tm_mday - day;

	cout << "You are " << year << " Years," << month << " Months," << day << " Days old" << endl;
}

string ones[] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string tens[] = { "","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety" };

string NumberToWord(long number)
{
	if (number < 10)
	{
		return ones[number];
	}
	else if (number < 20)
	{
		return teens[number - 10];
	}
	else if (number < 100)
	{
		return tens[number / 10] + " " + NumberToWord(number % 10);
	}
	else if (number < 1000)
	{
		return NumberToWord(number / 100) + " hundred " + NumberToWord(number % 100);
	}
	else if (number < 1000000)
	{
		return NumberToWord(number / 1000) + " thousand " + NumberToWord(number % 1000);
	}
	else if (number < 1000000000)
	{
		return NumberToWord(number / 1000000) + " million " + NumberToWord(number % 1000000);
	}
	else if (number < 1000000000000)
	{
		return NumberToWord(number / 1000000000) + " billion " + NumberToWord(number % 1000000000);
	}
}

vector<char> keyPad[] = { {},{},
	{ 'a','b','c' },	
	{ 'd','e','f' },	
	{ 'g','h','i' },	
	{ 'j','k','l' },	
	{'m','n','o' },	
	{ 'p','q','r','s' },	
	{ 't','u','v' },	
	{ 'w','x','y','z' } };

string ReturnLetterFrNumber(vector<char>keyPad[], int input[],string word,int index, int n)
{
	if (index == n)
	{
		return;
	}

	int digit = input[index];
	int length = keyPad[digit].size();

	for (int i = 0; i < length; i++)
	{
		ReturnLetterFrNumber(keyPad, input, word + keyPad[digit][i], index + 1, n);
	}
}


int main()
{
	//ANSWER 1
	//InputBirthday();

	//ANSWER 2
	//long number;
	//string answerWord = "";
	//cout << "Please input the number: " << endl;
	//cin >> number;
	//answerWord = NumberToWord(number);
	//cout << "Number Convert To Word: " << answerWord;

	//ANSWER 3

	
	return 0;
}
