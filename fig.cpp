// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdexcept>

using namespace std;

const float PI = 3.141592f;

enum class Types_fig
{
	ellipse,
	rectangle,
	trap
};
class Figure
{
public:
	Figure();
	Figure(Types_fig t, float a, float b) : type(t), h1(a), h2(b)
	{
	}
	~Figure();
	Types_fig get_type() const
	{
		return type;
	}
	
	float get_square() const
	{
		switch (type)
		{
		case Types_fig::ellipse:
			return PI*h1*h2;
		case Types_fig::rectangle:
			return h1*h2;
		case Types_fig::trap:
			return (h1+h2)*h_trap/2;
		default:
			break;
		}
	}
	float get_perimetr() const
	{
		switch (type)
		{
		case Types_fig::ellipse:
			return 4*(PI * h1 * h2 + (h1 - h2)* (h1 - h2))/(h1+h2);
		case Types_fig::rectangle:
			return (h1 + h2)*2;
		case Types_fig::trap:
			return 1;
		default:
			break;
		}
	}

	Figure get_rectangle()
	{
		if (type == Types_fig::rectangle)
		{
			return Figure(Types_fig::rectangle, h1, h2);
		}
		else if (type == Types_fig::ellipse)
		{
			return Figure(Types_fig::rectangle, h1, h2);
		}
		else
		{
			return Figure(Types_fig::rectangle, (h1>h2)?h1:h2, h_trap);
		}
	}

private:
	Types_fig type;
	float h1;
	float h2;
	float h_trap;
};

Figure::Figure() : type(Types_fig::ellipse), h1(0), h2(0)
{
}

Figure::~Figure()
{
}

class FigureList
{
public:
	static const int CAPACITY = 10;
	FigureList();
	~FigureList();
	int get_size();
	void insert(int ind, Figure f);
	void del_el(int ind);
	Figure operator[](const int index) const;
	int max_square();

private:
	int arr_size;
	Figure arr[CAPACITY];

};

FigureList::FigureList():arr_size(0)
{
}

FigureList::~FigureList()
{
}

void FigureList::insert(int ind, Figure f)
{
	if (arr_size == CAPACITY)
	{
		throw runtime_error("[FunctionList::add] Capacity is reached.");
	}
	for (int i = arr_size; i > ind; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[ind] = f;
	arr_size++;
}
void FigureList::del_el(int ind)
{
	if ((ind >= arr_size) || (ind < 0))
	{
		throw runtime_error("Index out of range");
	}
	for (int i = ind; i < arr_size; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr_size--;
}
Figure FigureList::operator[](const int index) const 
{
	if ((index < 0) || (index >= arr_size))
		throw out_of_range("Index out of range");
	return arr[index];
}
int FigureList::get_size()
{
	return arr_size;
}
int FigureList::max_square()
{
	if (arr_size == 0)
	{
		throw underflow_error("List is empty");
	}
	float max_sq = arr[0].get_square();
	int ind = 0;
	for (int i = 1; i < arr_size; i++)
	{
		if (arr[i].get_square() > max_sq)
		{
			max_sq = arr[i].get_square();
			ind = i;
		}
	}
	return ind;
}

int main()
{
	Figure a(Types_fig::rectangle, 10, 20);
	Figure b(Types_fig::rectangle, 9, 22);
	Figure c(Types_fig::rectangle, 8, 33);
	Figure d(Types_fig::rectangle, 7, 44);
	Figure e(Types_fig::rectangle, 6, 55);
	FigureList list;
	list.insert(0, a);
	list.insert(1, b);
	list.insert(2, c);
	list.insert(3, d);
	list.insert(4, e);
	list.del_el(7);
	

	

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
