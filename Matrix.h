#pragma once
#include <iostream>
const int DEFAULT_SIZE = 10;
using namespace std;

class Matrix
{
	int itsNumberOfLines; //количество строк
	int itsNumberOfColumns; //количество колонок
	int **pMatrix;
public:
	Matrix(int sizeoflines = DEFAULT_SIZE, int sizeofColumns = DEFAULT_SIZE);//Конструктор
	Matrix(const Matrix& original);//Оператор Копирования
	~Matrix();//Деструктор

	int getNumberOfLines() const; //возвращает количество строк
	int getNumberOfColumns() const;//возвращает количество колонок
	static Matrix Input(); //создание матрицы и ввод элементов
	void set(int i, int j, int value); //Присвоение элементу i, j значения value
	void Create();//Выделение памяти под матрицу
	void Display();//Вывод матрицы на экран
	//Операторы
	Matrix& operator = (const Matrix &); //Оператор присваивания
	Matrix& operator += (const Matrix &); //Сложение, совмещённое с присваиванием
	Matrix& operator -= (const Matrix &); //Вычитание, совмещённое с присваиванием
	const Matrix& operator ++ (); //Префиксный инкремент
	const Matrix& operator -- (); //Префиксный декремент
	const Matrix operator ++ (int); //Постфиксный инкремент
	const Matrix operator -- (int); //Постфиксный декремент
	friend Matrix operator + (const Matrix &, const Matrix &); //Оператор сложения
	friend Matrix operator - (const Matrix &, const Matrix &); //Оператор вычитания
	friend Matrix operator * (const Matrix &, const Matrix &); //Оператор умножения
	friend Matrix operator == (const Matrix &, const Matrix &); //Равенство
	friend Matrix operator != (const Matrix &, const Matrix &); //Неравенство
	friend ostream& operator << (ostream&, const Matrix&);
};

void Matrix::Create() 
{
	pMatrix = new int*[itsNumberOfLines];
	for (int i = 0; i <= itsNumberOfLines; i++) pMatrix[i] = new int[itsNumberOfColumns];
}

Matrix::Matrix(int sizeoflines, int sizeofColumns) : itsNumberOfLines(sizeoflines), itsNumberOfColumns(sizeofColumns) {Create();}

Matrix::Matrix(const Matrix& original)
{
	itsNumberOfLines = original.getNumberOfLines();
	itsNumberOfColumns = original.getNumberOfColumns();
	Create();
	for (int i = 0; i < itsNumberOfLines; i++) {
		for (int j = 0; j < itsNumberOfColumns; j++) {
			pMatrix[i][j] = original.pMatrix[i][j];
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < itsNumberOfLines; i++)
	{
		delete[] pMatrix[i];
	}
}


Matrix Matrix::Input()
{
	int r, c;
	cout << "Enter count of rows :\n";
	cin >> r;
	cout << "Enter count of columns :\n";
	cin >> c;
	Matrix R(r, c);
	int value;
	for (int i = 0; i<r; i++)
	{
		for (int j = 0; j<c; j++)
		{
			std::cout << "Enter (" << i << ',' << j << ") element : ";
			std::cin >> value;
			R.set(i, j, value);
		}
	}
	return R;
}

void Matrix::set(int i, int j, int value)
{
	pMatrix[i][j] = value;
}

int Matrix::getNumberOfLines() const
{
	return itsNumberOfLines;
}

int Matrix::getNumberOfColumns() const
{
	return itsNumberOfColumns;
}

void Matrix::Display()
{
	for (int i = 0; i<itsNumberOfLines; i++)
	{
		for (int j = 0; j<itsNumberOfColumns; j++)
		{
			cout.width(4);
			cout << pMatrix[i][j];
		}
		cout << endl;
	}
}

Matrix& Matrix::operator=(const Matrix &original)
{
	if (this == &original) {
		return *this;
	}
	if (original.getNumberOfLines())
	{
		for (int i = 0; i < itsNumberOfLines; i++) delete[] pMatrix[i];
		itsNumberOfLines = original.getNumberOfLines();
		itsNumberOfColumns = original.getNumberOfColumns();
		Create();
		for (int i = 0; i < itsNumberOfLines; i++) {
			for (int j = 0; j < itsNumberOfColumns; j++) {
				pMatrix[i][j] = original.pMatrix[i][j];
			}
		}
	}
	return *this;
}

Matrix& Matrix::operator+=(const Matrix &original)
{
	if (this == &original) {
		return *this;
	}
	int Lines = original.getNumberOfLines();
	int Columns = original.getNumberOfColumns();
	if ((itsNumberOfLines == Lines) && (itsNumberOfColumns == Columns))
	{
		for (int i = 0; i < itsNumberOfLines; i++)
		{
			for (int j = 0; j < itsNumberOfColumns; j++)
			{
				pMatrix[i][j] += original.pMatrix[i][j];
			}
		}
	}
	else cout << "Matrices do not match" << endl;
	return *this;
}

Matrix& Matrix::operator-=(const Matrix &original)
{
	if (this == &original) {
		return *this;
	}
	int Lines = original.getNumberOfLines();
	int Columns = original.getNumberOfColumns();
	if ((itsNumberOfLines == Lines) && (itsNumberOfColumns == Columns))
	{
		for (int i = 0; i < itsNumberOfLines; i++) {
			for (int j = 0; j < itsNumberOfColumns; j++) {
				pMatrix[i][j] -= original.pMatrix[i][j];
			}
		}
	}
	else cout << "Matrices do not match" << endl;
	return *this;
}

const Matrix& Matrix::operator ++ ()
{
	for (int i = 0; i < itsNumberOfLines; i++) {
		for (int j = 0; j < itsNumberOfColumns; j++) {
			++pMatrix[i][j];
		}
	}
	return *this;
}

const Matrix& Matrix::operator -- ()
{
	for (int i = 0; i < itsNumberOfLines; i++) {
		for (int j = 0; j < itsNumberOfColumns; j++) {
			--pMatrix[i][j];
		}
	}
	return *this;
}

const Matrix Matrix::operator++(int i)
{
	for (int i = 0; i < itsNumberOfLines; i++) {
		for (int j = 0; j < itsNumberOfColumns; j++) {
			++pMatrix[i][j];
		}
	}
	return *this;
}

const Matrix Matrix::operator--(int i)
{
	for (int i = 0; i < itsNumberOfLines; i++) {
		for (int j = 0; j < itsNumberOfColumns; j++) {
			--pMatrix[i][j];
		}
	}
	return *this;
}

Matrix operator + (const Matrix & a, const Matrix & b)
{
	int Lines1 = a.getNumberOfLines();
	int Columns1 = a.getNumberOfColumns();
	int Lines2 = b.getNumberOfLines();
	int Columns2 = b.getNumberOfColumns();
	if ((Lines1 == Lines2) && (Columns1 == Columns2))
	{
		Matrix c(a);
		for (int i = 0; i < Lines1; i++) {
			for (int j = 0; j < Columns1; j++) {
				c.pMatrix[i][j] = a.pMatrix[i][j] + b.pMatrix[i][j];
			}
		}
		return c;
	}
	else cout << "Matrices do not match" << endl;
	return 0;
}

Matrix operator - (const Matrix & a, const Matrix & b)
{
	int Lines1 = a.getNumberOfLines();
	int Columns1 = a.getNumberOfColumns();
	int Lines2 = b.getNumberOfLines();
	int Columns2 = b.getNumberOfColumns();
	if ((Lines1 == Lines2) && (Columns1 == Columns2))
	{
		Matrix c(a);
		for (int i = 0; i < Lines1; i++) {
			for (int j = 0; j < Columns1; j++) {
				c.pMatrix[i][j] = a.pMatrix[i][j] - b.pMatrix[i][j];
			}
		}
		return c;
	}
	else cout << "Matrices do not match" << endl;
	return 0;
}

Matrix operator * (const Matrix & a, const Matrix & b)
{
	int Lines1 = a.getNumberOfLines();
	int Columns1 = a.getNumberOfColumns();
	int Lines2 = b.getNumberOfLines();
	int Columns2 = b.getNumberOfColumns();
	if (Columns1 == Lines2)
	{
		Matrix c(Lines1, Columns2);
		for (int i = 0; i < Lines1; i++)
			for (int j = 0; j < Columns2; j++)
			{
				c.pMatrix[i][j] = 0;
				for (int k = 0; k < Columns1; k++)
					c.pMatrix[i][j] += a.pMatrix[i][k] * b.pMatrix[k][j];
			}
		return c;
	}
	else cout << "Matrices do not match" << endl;
	return 0;
}

Matrix operator == (const Matrix & a, const Matrix & b)
{
	int Lines1 = a.getNumberOfLines();
	int Columns1 = a.getNumberOfColumns();
	int Lines2 = b.getNumberOfLines();
	int Columns2 = b.getNumberOfColumns();
	int k = 0;
	if ((Columns1 == Columns2) && (Lines1 == Lines2)) 
	{
		for (int i = 0; i < Columns1; i++) {
			for (int j = 0; j < Lines1; j++) {
				if (a.pMatrix[i][j] != b.pMatrix[i][j]) k++;
			}
		}
		if (k)
		{
			cout << "Matrices are not equal to each other" << endl;
			return 0;
		}
		else
		{
			cout << "Matrices are equal" << endl;
			return 1;
		}
	}
	else
	{
		cout << "Matrices are not equal to each other" << endl;
		return 0;
	}
}

Matrix operator != (const Matrix & a, const Matrix & b)
{
	int Lines1 = a.getNumberOfLines();
	int Columns1 = a.getNumberOfColumns();
	int Lines2 = b.getNumberOfLines();
	int Columns2 = b.getNumberOfColumns();
	int k = 0;
	if ((Columns1 == Columns2) && (Lines1 == Lines2))
	{
		for (int i = 0; i < Columns1; i++) {
			for (int j = 0; j < Lines1; j++) {
				if (a.pMatrix[i][j] != b.pMatrix[i][j]) k++;
			}
		}
		if (k)
		{
			cout << "Matrices are not equal to each other" << endl;
			return 1;
		}
		else
		{
			cout << "Matrices are equal" << endl;
			return 0;
		}
	}
	else
	{
		cout << "Matrices are not equal to each other" << endl;
		return 1;
	}
}

ostream& operator<<(ostream& out, const Matrix& m)
{
	for (int i = 0; i < m.getNumberOfLines(); i++)
	{
		for (int j = 0; j < m.getNumberOfColumns(); j++)
			out << m.pMatrix[i][j] << ' ';
	}
	return out;
}