#include <string>
#include <vector>
#include <iostream>
using namespace std;




class Node {

public:
	Node* previ;
	Node* next;
	Node* friend1;
	int value;
	int child_num = 0;

	Node(int n) {
		this->previ = NULL;
		this->next = NULL;
		this->friend1 = NULL;
		this->value = n;
		this->child_num = 0;
	}
};


class calcul
{
public:
	Node* cur;
	Node* front;
	Node* left;
	Node* left_front;
	Node* right;
	Node* right_front;
	Node* midium;
	Node* midium_front;

	int n = 0;
	int answer = 0;

	Node* min_address;
	int min = 0;
	int min_index = 0;



	Node* pop(Node* here)
	{
		try {

			//cout << "pop" << endl;
			if (n > 1) {
				n--;

				if (here->previ == NULL)
				{
					here->next->previ = NULL;
					front = here->next;
					return here;
				}

				else if (here->next == NULL)
				{
					here->previ->next = NULL;
					return here->previ;
				}


				else
				{
					here->previ->next = here->next;
					here->next->previ = here->previ;
					return here->next;
				}
			}


			else
				return here;

		}
		catch (exception e)
		{
			cout << "pop error" << endl;
			e.what();
		}

	}




	calcul(vector<int> a)
	{
		try {

			int n1 = a.size();

			n = a.size();
			this->answer = 0;
			min = a[0];
			min_index = 0;

			this->right = NULL;
			this->left = NULL;
			this->midium = NULL;

			///////
			for (int i = 0; i < n1; i++)
			{
				if (min > a[i])
				{
					min = a[i];
					min_index = i;
				}

			}

			if (min_index == 0 || min_index == n1 - 1)
				this->answer = 2; //because min

			else
				this->answer = 3;



			int left_min = a[0];
			for (int i = 1; i < min_index; i++)
			{
				if (a[i] < left_min)
				{
					this->answer++;
					left_min = a[i];
				}
			}


			
			int right_min  = 0;

			if (n1 - 1 > 0)
				right_min = a[n1 - 1];

			for (int i = n1-2; i > min_index ; i--)
			{
				if (a[i] < right_min)
				{
					this->answer++;
					right_min = a[i];
				}
			}

			//this->print();

		}
		catch (exception e)
		{
			cout << "calcur error" << endl;
			e.what();
		}

	}

	void print()
	{
		Node* exe = front;
		Node* test = front;
		this->answer = 0;


		while (exe->next != NULL)
		{
			cout << exe->value << " ";

			if (exe->value < test->value)
			{
				test = exe;
			}

			exe = exe->next;
			this->answer++;
		}

		this->answer++;
		

		cout << exe->value << " " << endl;


		if (exe->value < test->value)
		{
			test = exe;
		}

		this->answer += test->child_num;

	}

};



// a_len은 배열 a의 길이입니다.
int solution(vector<int> a) {
	int answer = 0;
	calcul* cal1 = new calcul(a);
	answer = cal1->answer;
	cout << answer << endl;

	return answer;
}


vector<int> a1 = { 9,-1,-5 };

int main(void)
{
	solution(a1);

	system("pause");
}