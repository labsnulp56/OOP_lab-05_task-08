#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Game {
private:
	static const int array_size = 20;
	char game_name[array_size];
	double box_weight;
protected:
	double one_figure_weight;
	char* strcpy(char* destination, const char* source);
public:
	void SetName(char* game_name);
	const char* GetName() const;
	void SetFigureWeight(double figure_weight);
	void SetBoxWeight(double box_weight);
	double GetBoxWeight(Game &obj);
	double GetFigureWeight(Game &obj);
	virtual double GetWeight(Game &obj) = 0;
	//friend void quick_object(Game items[], int count);    
	//friend void qs_obj(Game items[], int left, int right);  
	//friend double WeightSum(Game items[], int count);
};

class Checkers : public Game {
private:
	double full_weight;
public:
	double GetWeight(Game &obj) override;
};

class Domino : public Game {
private:
	double full_weight;
public:
	double GetWeight(Game &obj) override;
};

int main(void)
{
	system("color F1");
	const int arr_size = 1;
	char temp_name[20];
	double figure_weight;
	double box_weight;
	register int i = 0;
	Checkers check_arr[arr_size];
	Domino dom_arr[arr_size];
	Game** main_arr = new Game*[arr_size];

	for (i = 0; i < arr_size; i++)
	{
		cout << "Input Checkers name of game" << endl;
		cin >> temp_name;
		check_arr[i].SetName(temp_name);
		cout << "input weight of one Checker" << endl;
		cin >> figure_weight;
		check_arr[i].SetFigureWeight(figure_weight);
		cout << "input  Checker's board weight" << endl;
		cin >> box_weight;
		check_arr[i].SetBoxWeight(box_weight);
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (i = 0; i < arr_size; i++)
	{
		cout << "Checkers Name of game is " << check_arr[i].GetName() << endl;
		cout << "Checkers Board weight is " << check_arr[i].GetWeight(check_arr[i]) << endl;
		cout << "Checkers Figure weight is " << check_arr[i].GetBoxWeight(check_arr[i]) << endl;
		cout << "------------------" << endl;
	}

	for (i = 0; i < arr_size; i++)
	{
		cout << "Input Domino name of game" << endl;
		cin >> temp_name;
		dom_arr[i].SetName(temp_name);
		cout << "input weight of one Domino" << endl;
		cin >> figure_weight;
		dom_arr[i].SetFigureWeight(figure_weight);
		cout << "input Domino board weight" << endl;
		cin >> box_weight;
		dom_arr[i].SetBoxWeight(box_weight);
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (i = 0; i < arr_size; i++)
	{
		cout << "Checkers Name of game is " << dom_arr[i].GetName() << endl;
		cout << "Checkers Board weight is " << dom_arr[i].GetWeight(dom_arr[i]) << endl;
		cout << "Checkers Figure weight is " << dom_arr[i].GetBoxWeight(dom_arr[i]) << endl;
		cout << "------------------" << endl;
	}

	cout << "WARNING!!!" << endl;
		main_arr[0] = new Checkers();

		for (i = 0; i < arr_size; i++)
		{
	
			cout << "Checkers Name of game is " << main_arr[i]->GetName() << endl;
			cout << "Checkers Board weight is " << main_arr[i]->GetWeight(main_arr[i]) << endl;
			cout << "Checkers Figure weight is " << main_arr[i]->GetBoxWeight(main_arr[i]) << endl;
			cout << "------------------" << endl;
		}

		//for (i = 0; i < arr_size; i++)
		//{
		//	delete main_arr[i];
		//}
		//delete[]main_arr;


	system("pause");
	return 0;
}

void Game::SetName(char* game_name)
{
	strcpy(this->game_name, game_name);
}

const char* Game::GetName() const {
	return this->game_name;
}

void Game::SetFigureWeight(double figure_weight)
{
	this->one_figure_weight = figure_weight;
}

void Game::SetBoxWeight(double box_weight)
{
	this->box_weight = box_weight;
}

double  Game::GetBoxWeight(Game &obj)
{
	return this->box_weight;
}

double Game::GetFigureWeight(Game &obj)
{
	return this->one_figure_weight;
}

char* Game::strcpy(char* destination, const char* source)
{
	if (destination == NULL)
		return NULL;
	char *ptr = destination;
	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return ptr;
}
/*--------------------*/

double Checkers::GetWeight(Game &obj)
{
	this->full_weight = GetFigureWeight(obj) * 24;
	return this->full_weight;
}

double Domino::GetWeight(Game &obj)
{
	this->full_weight = GetFigureWeight(obj) * 28;
	return this->full_weight;
}