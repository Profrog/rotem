#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;



string* spliting(string data, char a)
{
	int N = 3;
	int data_length = data.length();

	string* result = new string[N]; // 나중에 전반적으로 쓸 수 있는 것으로 변환

	int index = 0;
	int result_index = 0;

	try {
		
		for(int i = 0 ; i < N ; i++)
		{
			int index_end = data.find(a);
			
			index_end = (index_end == string::npos) ? data_length : index_end;
			result[i] = data.substr(index, index_end);
			data = data.substr(index_end + 1, data_length);
		}
	}

	catch (exception e)
	{
		//cout << e.what() << endl;
	}

	return result;
}


class data_split
{
public:
	string day_a;
	string day_b;
	string day_c;
	data_split* next1;
	
	data_split(string a, string b, string c)
	{
		this->day_a = a;
		this->day_b = b;
		this->day_c = c;
		this->next1 = NULL;
	}

};


class Time_stack
{
public:
	int hour1 = 0;
	int minute1 = 0;
	float second1 = 0;
	Time_stack* starting;
	Time_stack* ending;


	Time_stack()
	{

	}

	Time_stack(int hour, int minute, float start_second, float end_second)
	{
		this->starting = new Time_stack(hour, minute, start_second);
		this->ending = new Time_stack(hour, minute, end_second);
	}


	Time_stack(int hour, int minute, float second)
	{
		this->starting = NULL;
		this->ending = NULL;

		if (second >= 60)
		{
			second -= 60;
			minute += 1;		
		}

		if (minute >= 60)
		{
			minute -= 60;
			hour += 1;
		}


		if (second < 0)
		{
			second += 60;
			minute -= 1;
		}

		if (minute < 0)
		{
			minute += 60;
			hour -= 1;
		}


		this->hour1 = hour;
		this->minute1 = minute;
		this->second1 = second;
	}

	Time_stack* operator+(Time_stack &a) {
		Time_stack* result = new Time_stack(this->hour1 + a.hour1, this->minute1 + a.minute1, this->second1 + a.second1);
		return result;
	}

	Time_stack* operator-(Time_stack &a) {
		Time_stack* result = new Time_stack(this->hour1 - a.hour1, this->minute1 - a.minute1, this->second1 - a.second1);
		return result;
	}

	bool operator<=(Time_stack &a)
	{

		if (this->hour1 < a.hour1)
			return true;

		else if (this->hour1 == a.hour1)
		{
			if (this->minute1 < a.minute1)
				return true;

			else if (this->minute1 == a.minute1)
			{
				if (this->second1 <= a.second1)
					return true;

				else
					return false;
			}
		}

		return false;
	}


	bool operator>=(Time_stack &a)
	{


		if (this->hour1 > a.hour1)
			return true;

		else if (this->hour1 == a.hour1)
		{
			if (this->minute1 > a.minute1)
				return true;

			else if (this->minute1 == a.minute1)
			{
				if (this->second1 >= a.second1)
					return true;

				else
					return false;
			}
		}

		return false;
	}

	bool operator<(Time_stack &a)
	{

		if (this->hour1 < a.hour1)
			return true;

		else if (this->hour1 == a.hour1)
		{
			if (this->minute1 < a.minute1)
				return true;

			else if (this->minute1 == a.minute1)
			{
				if (this->second1 < a.second1)
					return true;

				else
					return false;
			}
		}

		return false;
	}


	bool operator>(Time_stack &a)
	{


		if (this->hour1 > a.hour1)
			return true;

		else if (this->hour1 == a.hour1)
		{
			if (this->minute1 > a.minute1)
				return true;

			else if (this->minute1 == a.minute1)
			{
				if (this->second1 > a.second1)
					return true;

				else
					return false;
			}
		}

		return false;
	}


	void print()
	{
		cout << hour1 << " m" << minute1 << " s" << second1 << endl;

		if (this->starting != NULL)
		{
			this->starting->print();
		}


		else if(this->ending != NULL)
		{
			this->ending->print();
		}
	}
};



class calcurate
{

public:
	int time_stack[24][60][60] = { 0 };
	int max = 0;
	int n = 0;
	Time_stack* stack_01;
	int stack_index = 0;


	calcurate(int n)
	{
		this->make_Timestack(n);
	}


	int getting_max()
	{
		Time_stack* time1 = new Time_stack(0, 0, 0.999);
		max = 0;

		for (int i = 0; i < n; i++)
		{
			Time_stack* example = stack_01[i].starting;	
			Time_stack* example_ending = *example + *time1;
			example->print();
			example_ending->print();


			Time_stack* example2 = stack_01[i].ending;
			Time_stack* example2_ending = *example2 + *time1;
			example2->print();
			example2_ending->print();

			cout << endl;

			int max_exe = 0;
			int max_exe2 = 0;

			for (int j = 0; j < n; j++)
			{
				Time_stack* obj = stack_01[j].starting;
				Time_stack* obj_ending = stack_01[j].ending;

				if (!(*example_ending < *obj || *example > *obj_ending))
				{
					max_exe++;
				}		


				if (!(*example2_ending < *obj || *example2 >= *obj_ending))
				{	
					cout << j << endl;
					max_exe2++;
				}

			}

			max = (max_exe > max) ? max_exe : max;
			max = (max_exe2 > max) ? max_exe2 : max;
		}

		return max;
	}



	void push_Timestack(Time_stack data)
	{
		stack_01[stack_index] = data;
		stack_index++;
	}


	void make_Timestack(int n1)
	{
		this->n = n1;
		stack_01 = new Time_stack[n1];
	}


	void spending(int hour, int minute, float start_second, float end_second)
	{
		//cout << "start " << start_second << " " << end_second << endl;
		
		Time_stack* time = new Time_stack(hour, minute, start_second, end_second);
		this->push_Timestack(*time);
	}



	void plus_traffic(string b, string c)
	{
		string* data = spliting(b , ':');
		string travel = c.substr(0, c.length() - 1);	

		float start_time = stof(data[2]) - stof(travel) + 0.001;
		spending(stoi(data[0]), stoi(data[1]), start_time, stof(data[2]));
	}
};



class SPLIT
{
 public:
	 int n = 0;
	 data_split *d_s;
	 data_split *front;
	 calcurate* cal;

	SPLIT(vector<string> lines)
	{
		n = lines.size();
		for (int i = 0; i < n; i++)
		{
			//string* data = lines[i].split(' ');
			string* data = spliting(lines[i], ' ');

			if (i == 0)
			{
				d_s = new data_split(data[0], data[1], data[2]);
				front = d_s;
			}

			else
			{
				d_s-> next1 = new data_split(data[0], data[1], data[2]);
				d_s = d_s->next1;
			}
		}	
	}

	int print()
	{
		data_split* exe = front;
		cal = new calcurate(n);
		
		int i = 0;
		while (exe->next1 != NULL)
		{
			//cout  << i << exe->day_a << "+" << exe->day_b << "+" << exe->day_c << endl;
			cal->plus_traffic(exe->day_b, exe->day_c);
			exe = exe->next1;
			i++;
		}

		//cout << i << exe->day_a << "+" << exe->day_b << "+" << exe->day_c << endl;
		cal->plus_traffic(exe->day_b, exe->day_c);
		int result = cal->getting_max();

		return result;
		//cout << cal.max << endl;
	}
};




SPLIT *split1;
vector<string> line2 = { 
	"2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s"
 };


vector<string> line3 = {
"2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"
};

vector<string> line4 = { "2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s" };



int solution(vector<string> lines) {
	int answer = 0;
	split1 =  new SPLIT(lines);

	answer = split1->print();
	cout << answer << endl;

	return answer;
}



int main(void)
{
	
	solution(line4);


	system("pause");
	return 0;
}










