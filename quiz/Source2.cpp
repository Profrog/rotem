#include <string>
#include <vector>
#include <iostream>

using namespace std;


class node
{
public:
	node* front;
	node* back;
	int data = 0;
	int answer = 0;

	node(int data)
	{
		this->front = NULL;
		this->back = NULL;
		this->data = data;
		this->answer = 0;
	}

	node(int data, int answer)
	{
		this->front = NULL;
		this->back = NULL;
		this->data = data;
		this->answer = answer;
	}

};




class calculator
{
public:

	int index = 0;
	int return_value = 1;
	int original_value = 0;
	int max = 9;
	int n;
	int sum = 0;
	int last_num = 0;
	int i = 0;

	node* first;
	node* current;
	node* end;


	void back_push(node* a)
	{
		//cout << "back_push" <<first->data << " "<< first->answer << endl;

		try {

			if (a->front == NULL && n > 1)
			{
				first = a->back;
				a->back->front = NULL;
				end->back = a;
				a->front = end;
				a->back = NULL;

				end = a;
				current = first;
				return;
			}


		}

		catch (exception e)
		{
			e.what();
		}
	}



	void pop(node *a)
	{
		//cout << "pop" << first->data << " " << first->answer << endl;


		try {

			this->n--;
			this->i = -1;
			this->sum -= a->data;
			this->last_num = a->data;

			if (a->front == NULL)
			{
				first = a->back;
				a->back->front = NULL;
				return_value++;
				current = first;
				return;
			}

			else if (a->back == NULL)
			{
				end = a->front;
				a->front->back = NULL;
				return_value++;
				return;
			}

			else
			{
				a->front->back = a->back;
				a->back->front = a->front;
				return_value++;
				current = a->back;
				return;
			}


		}

		catch (exception e)
		{
			e.what();
		}
	}


	calculator(vector<int> data1, int index) {
		this->index = index;
		original_value = data1[index];
		this->n = data1.size();
		this->sum = 0;


		for (int i = 0; i < n; i++)
		{
			sum += data1[i];

			if (i == 0)
			{
				current = new node(data1[i]);

				if (i == index)
					current->answer = 1;

				first = current;
				end = current;
			}

			else
			{
				current->back = new node(data1[i]);

				if (i == index)
					current->back->answer = 1;

				current->back->front = current;
				current = current->back;
				end = current;
			}
		}


		while (max > 0)
		{
			//cout << max << endl;

			current = first;

			for (this->i = 0; this->i < this->n; (this->i)++)
			{
				if (current->data == max)
				{
					if (current->answer > 0)
					{
						return;
					}

					else
					{
						//cout << i << " " << n << endl;
						pop(current);

					}
				}

				else
				{
					back_push(current);
				}
			}

			max--;
		}

		//return_value++;
	}


};

int solution(vector<int> priorities, int location) {

	calculator* exe = new calculator(priorities, location);
	int answer = exe->return_value;
	return answer;
}

vector<int> data1 = { 2, 1, 3, 2 };
vector<int> data2 = { 1, 1, 9, 1, 1, 1 };


int main(void)
{
	//cout << solution(data1, 2) << endl;
	cout << solution(data2, 1) << endl;


	system("pause");
}
