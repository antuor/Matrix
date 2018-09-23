#include "Matrix.h"
#include "Stack.h"
using namespace std;


void menuFunc() {
	Matrix F;
	CMyStack<Matrix> Stack;
	Stack.Push(Matrix::Input());
	int choice;
	int pos = 0, num = 0;
	bool flag = true;

	while (flag != false) {
		cout << "*******************************\n";
		cout << " 1 - Addition.\n";
		cout << " 2 - Multiplication.\n";
		cout << " 3 - Increment.\n";
		cout << " 4 - Decrement.\n";
		cout << " 5 - Comparison.\n";
		cout << " 6 - Print.\n";
		cout << " 7 - Exit.\n";
		cout << " Enter your choice and press return: ";

		cin >> choice;
		switch (choice) {
		case 1: // проверка сложения матриц
			F = Stack.Pop();
			Stack.Push(Matrix::Input());
			F = F + Stack.Pop();
			Stack.Push(F);
			F.Display();
			break;
		case 2: // умножение матриц
			F = Stack.Pop();
			Stack.Push(Matrix::Input());
			F = F * Stack.Pop();
			Stack.Push(F);
			F.Display();
			break;
		case 3: // Проверка инкремента
			F = Stack.Pop();
			F++;
			Stack.Push(F);
			F.Display();
			break;
		case 4: // Проверка декремента
			F = Stack.Pop();
			--F;
			Stack.Push(F);
			F.Display();
			break;
		case 5: // Сравнение матриц
			F = Stack.Pop();
			Stack.Push(Matrix::Input());
			F == Stack.Pop();
			Stack.Push(F);
			break;
		case 6: // Вывод матрицы 
			F = Stack.Pop();
			F.Display();
			Stack.Push(F);
			break;
		case 7: //Выход
			cout << "*******************************\n";
			cout << "End of Program.\n";
			flag = false;
			break;
		default:
			cout << "Not a Valid Choice. \n";
			cout << "Choose again.\n";
			break;
		}
	}
}