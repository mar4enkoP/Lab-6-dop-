#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void ArrayOutput(int mas[],int size)
{
	for (int i = 0; i < size; ++i) {
		cout << mas[i] << " ";
	}
	cout << endl;
}
void ArrayOutput(double mas[], int size)
{
	for (int i = 0; i < size; ++i) {
		cout << mas[i] << " ";
	}
	cout << endl;
}

double* InsertElement(double* array, int arraySize, int position, int value) {
	double* newArray = new double[arraySize + 1];

	for (int i = 0; i < arraySize; i++) {
		newArray[i < position ? i : i + 1] = array[i];
	}

	newArray[position] = value;
	return newArray;
}

void TaskVariant()
{
	//подсчет варианта
	int K, N, Z;
	K = 0;
	N = 0;
	cout << "Variant:\n";
	cin >> N;
	for (K = 1; K <= 3; K++)
	{
		Z = (N + (K - 1) * 25) % 23;
		cout << "Z(" << K << ") = " << Z;
		cout << "\n\n";
	}
	cout << "\n\n";
}
void Task11()
{
    //Удалить из массива все повторяющиеся элементы, оставив их первые вхождения, то есть в
	//массиве должны остаться только разные элементы.
	int n;
	cout << "n="; 
	cin >> n;

	int* a = new int[n];

	cout << "Enter " << n << " elements:\n";
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] == a[j])
			{
				for (int k = j; k < n; k++)
					a[k] = a[k + 1];
				n--;
				j--;
			}

	ArrayOutput(a, n);

	delete[]a;

	cout << "\n";
	system("pause");
}
void Task13()
{
	//Данные о росте 25 учеников класса, упорядоченные по убыванию, записаны в массиве.В начале
	//учебного года в класс поступили два новых ученика.Получить аналогичный массив,
	//учитывающий рост новых учеников.Каков должен быть максимальный размер исходного
	//массива ?
	const int size = 25;//ответ
	const int size2 = 27;
	int mas[size] = { 197,195,194,193,192,191,190,188,187,186,185,184,183,181,180,178,176,173,170,169,167,164,162,160,152 };
	int mas2[size2];

	ArrayOutput(mas, size);

	for (int i = 0; i < size2; ++i) 
	{
		 mas2[i] = mas[i];
	}
	mas2[25] = { 200 };//26
	mas2[26] = { 199 };//27

	for (int i = 1; i < size2; ++i)
	{
		for (int r = 0; r < size2 - i; r++)
		{
			if (mas2[r] < mas2[r + 1])
			{
				int temp = mas2[r];
				mas2[r] = mas2[r + 1];
				mas2[r + 1] = temp;
			}
		}
	}
	ArrayOutput(mas2, size2);
	cout << "\n";
	system("pause");
}
void Task15()
{
	//Вставить число n между всеми соседними элементами, имеющими одинаковый знак.Каков
	//должен быть максимальный размер исходного массива ?

	int size;
	int x = 0;
	cin >> size;

	double* array = new double[size];

	for (int i = 0; i < size; i++)
		cin >> array[i];

	for (int i = 0; i + 1 < size; i++) {
		if (array[i] * array[i + 1] < 0) {
			array = InsertElement(array, size, i + 1, x);
			++size;
			++i;
		}
	}

	ArrayOutput(array, size);

	cout << endl;

	delete[]array;
	cout << "\n";
	system("pause");
}

int main()
{
	int Num, i;
	for (i = 0; i <= 4; i++)
	{
		cout << "chose 11, 13, 15: ";
		cin >> Num;
		switch (Num)
		{
		case 11:
			Task11();
			break;
		case 13:
			Task13();
			break;
		case 15:
			Task15();
			break;

		case 000:
			TaskVariant();
			break;

		default:
			break;
		}
	}
}
