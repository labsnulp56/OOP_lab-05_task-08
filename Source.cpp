#include <iostream> 

using namespace std;
#define len 20

class Game {
private:
	char game_name[20];
protected:
	char* strcpy(char* destination, const char* source);
public:
	void SetName(char* game_name);
	const char* GetName() const;
};

class Checkers : public Game {
private:
	char che_imit_name[20];
	double che_figure_weight;
	double che_board_weight;
public:
	void SetImitCheName(char* local_name);
	void ShowAllCheImit();
	void SetCheFigureWeight(double figure_weight);
	void SetCheBoardWeight(double board_weight);
	double GetCheFigureWeight(Checkers &obj);
	double GetCheBoardWeight(Checkers &obj);
	friend void quick_object(Checkers items[], int count);		/*!!!! why only with checkers???*/
	friend void qs_obj(Checkers items[], int left, int right);	/*!!!! why only with checkers???*/
	friend double WeightSum(Checkers items[], int count);		/*!!!! why only with checkers???*/
};


class Domino : public Game {
private:
	char dom_imit_name[20];
	double dom_figure_weight;
	double dom_box_weight;
public:
	void SetImitDomName(char* local_name);
	void ShowAllDomImit();
	void SetDomFigureWeight(double figure_weight);
	void SetDomBoxWeight(double board_weight);
	double GetDomFigureWeight(Domino &obj);
	double GetDomBoxdWeight(Domino &obj);
	friend void quick_object(Domino items[], int count);		/*!!!! why only with domino???*/
	friend void qs_obj(Domino items[], int left, int right);	/*!!!! why only with domino???*/
	friend double WeightSum(Domino items[], int count);
};

int main()
{
	system("color F1");
	const int arr_size = 4;
	char temp_name[20];
	double temp_board_weight;
	double temp_figure_weight;
	register int i = 0;
	Checkers check_arr[arr_size];
	Domino dom_arr[arr_size];


	for (i = 0; i < arr_size; i++)
	{
		cout << "Input Checkers name of game" << endl;
		cin >> temp_name;
		check_arr[i].SetImitCheName(temp_name);
		cout << "input Checkers board weight" << endl;
		cin >> temp_board_weight;
		check_arr[i].SetCheBoardWeight(temp_board_weight);
		cout << "input Checkers figure weight" << endl;
		cin >> temp_figure_weight;
		check_arr[i].SetCheFigureWeight(temp_figure_weight);
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	qs_obj(check_arr, 0, arr_size);

	for (i = 0; i < arr_size; i++)
	{
		cout << "Checkers Name of game is " << check_arr[i].GetName() << endl;
		cout << "Checkers Board weight is " << check_arr[i].GetCheBoardWeight(check_arr[i]) << endl;
		cout << "Checkers Figure weight is " << check_arr[i].GetCheFigureWeight(check_arr[i]) << endl;
		cout << "------------------" << endl;
	}
	cout << "Checkers Sum of all weights = " << WeightSum(check_arr, arr_size) << endl;
	/*Domino*/
	for (i = 0; i < arr_size; i++)
	{
		cout << "Input Domino name of game" << endl;
		cin >> temp_name;
		dom_arr[i].SetImitDomName(temp_name);
		cout << "input Domino board weight" << endl;
		cin >> temp_board_weight;
		dom_arr[i].SetDomBoxWeight(temp_board_weight);
		cout << "input Domino figure weight" << endl;
		cin >> temp_figure_weight;
		dom_arr[i].SetDomFigureWeight(temp_figure_weight);
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	qs_obj(dom_arr, 0, arr_size);

	for (i = 0; i < arr_size; i++)
	{
		cout << "Domino Name of game is " << dom_arr[i].GetName() << endl;
		cout << "Domino Box weight is " << dom_arr[i].GetDomBoxdWeight(dom_arr[i]) << endl;
		cout << "Domino Figure weight is " << dom_arr[i].GetDomFigureWeight(dom_arr[i]) << endl;
		cout << "------------------" << endl;
	}
	cout << "Domino Sum of all weights = " << WeightSum(dom_arr, arr_size) << endl;

	system("pause");
	return 0;
}


/*The beginning of description Game functions*/
void Game::SetName(char* game_name)
{
	strcpy(this->game_name, game_name);
}

const char* Game::GetName() const {
	return this->game_name;
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
/*The end of description Game functions*/

/*The beginning of description Domino functions*/
void Domino::SetImitDomName(char* local_name)
{
	SetName(local_name);
	strcpy(dom_imit_name, this->GetName());
}

void Domino::ShowAllDomImit()
{
	GetName();
}

void Domino::SetDomFigureWeight(double figure_weight)
{
	this->dom_figure_weight = figure_weight;
}

void Domino::SetDomBoxWeight(double box_weight)
{
	this->dom_box_weight = box_weight;
}

double Domino::GetDomFigureWeight(Domino &obj)
{
	return this->dom_figure_weight;
}

double Domino::GetDomBoxdWeight(Domino &obj)
{
	return this->dom_box_weight;
}

double WeightSum(Domino items[], int count)
{
	register int i = 0;
	double sum = 0;
	for (; i < count; i++)
	{
		sum += items[i].GetDomFigureWeight(items[i]);
	}
	return sum;
}
/*The end of description Domino functions*/

/*The beginning of description Checkers functions*/
void Checkers::SetImitCheName(char* local_name)
{
	SetName(local_name);
	strcpy(che_imit_name, this->GetName());
}

void Checkers::ShowAllCheImit() {
	GetName();
}

void Checkers::SetCheFigureWeight(double figure_weight)
{
	this->che_figure_weight = figure_weight;
}

void Checkers::SetCheBoardWeight(double board_weight)
{
	this->che_board_weight = board_weight;
}

double Checkers::GetCheFigureWeight(Checkers &obj)
{
	return this->che_figure_weight;
}

double Checkers::GetCheBoardWeight(Checkers &obj)
{
	return this->che_board_weight;
}

double WeightSum(Checkers items[], int count)
{
	register int i = 0;
	double sum = 0;
	for (; i < count; i++)
	{
		sum += items[i].GetCheFigureWeight(items[i]);
	}
	return sum;
}
/*The end of description Checkers functions*/

/*The beginning of description sorting functions*/
void quick_object(Checkers items[], int count)
{
	qs_obj(items, 0, count - 1);
}

void qs_obj(Checkers items[], int left, int right)
{
	register int i, j;
	double x;
	Checkers temp;
	i = left; j = right + 1;
	x = items[(left + right) / 2].GetCheFigureWeight(items[(left + right) / 2]);
	do {
		while ((items[i].GetCheFigureWeight(items[i]) > x) && (i < right)) i++;
		while ((x > items[j].GetCheFigureWeight(items[i])) && (j > left)) j--;
		if (i <= j) {
			temp = items[i];
			items[i] = items[j];
			items[j] = temp;
			i++; j--;
		}
	} while (i <= j);
	if (left < j) qs_obj(items, left, j);
	if (i < right) qs_obj(items, i, right);
}
/*The end of description sorting functions*/

/*The beginning of description sorting functions*/
void quick_object(Domino items[], int count)
{
	qs_obj(items, 0, count - 1);
}

void qs_obj(Domino items[], int left, int right)
{
	register int i, j;
	double x;
	Domino temp;
	i = left; j = right + 1;
	x = items[(left + right) / 2].GetDomFigureWeight(items[(left + right) / 2]);
	do {
		while ((items[i].GetDomFigureWeight(items[i]) > x) && (i < right)) i++;
		while ((x > items[j].GetDomFigureWeight(items[i])) && (j > left)) j--;
		if (i <= j) {
			temp = items[i];
			items[i] = items[j];
			items[j] = temp;
			i++; j--;
		}
	} while (i <= j);
	if (left < j) qs_obj(items, left, j);
	if (i < right) qs_obj(items, i, right);
}
/*The end of description sorting functions*/

/*
Data for testing
+-+-+-+-+-+-+-+-

Check_name_19
19
19
Check_name_31
31
31
Check_name_11
11
11
Check_name_40
40
40
Domino_name_5
5
5
Domino_name_41
41
41
Domino_name_9
9
9
Domino_name_31
31
31

+-+-+-+-+-+-+-+-
*/