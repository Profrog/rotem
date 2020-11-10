#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
int divide_value = 1000000007;


class NODE
{
public:
	int index = 0;
	int value = 0;

	NODE(int index, int value)
	{
		this->index = index;
		this->value = value % divide_value;
	}

	NODE* operator+(NODE& data)
	{
		NODE* result = new NODE(this->index + 1, this->value + data.value);
		return result;
	}

};


class answer
{
public:

	NODE* first;
	NODE* second;


	int answer1 = 0;


	answer(int n)
	{
		first = new NODE(1, 1);
		second = new NODE(2, 2);

		if (n == 1)
		{
			this->answer1 = 1;
			return;
		}

		else if (n == 2)
		{
			this->answer1 = 2;
			return;
		}



		while (second->index < n)
		{
			NODE* exe = second;
			second = *second + *first;
			first = exe;

			this->answer1 = (second->value);
		}
	}
};


int solution(int n) {
	answer* a = new answer(n);
	int answer = a->answer1;
	cout << answer << endl;
	return answer;
}


int main()
{

	solution(5);
	system("pause");
}