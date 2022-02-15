
#include <iostream>
#include <iomanip>

int CheckEven(int num_);

int main()
{
    setlocale(LC_ALL, "Rus");
    std::cout << "Введите размер столбцов (м): ";
    int colsN = 0;
    colsN = CheckEven(colsN);

    std::cout << "Введите строки четного размера (n): ";
    int rowsN = 0;
    rowsN = CheckEven(rowsN);

    // выделение динам памяти под массив чисел a1...an
    int* arrA = new int[rowsN];

    // заполнение элементами
    std::cout << "Введите a1,a2, ... , an:\n";
    for (int i = 0; i < rowsN; i++)
    {
        std::cout << i + 1 << ". ";
        std::cin >> arrA[i];
    }

    // печать a1 ... an
    std::cout << "Номера a1,a2, ... , an: ";
    for (int i = 0; i < rowsN; i++)
    {
        std::cout << arrA[i] << " ";
    }
    std::cout << "\n";

    // выделение памяти под матрциу
    int count = 0; // счетчик для печати столбиков
    int** userMatrix = new int* [rowsN];
    for (int i = 0; i < rowsN; i++) // идем по строкам
    {
        if (i % 2 == 0) // если номер строки нечетный, то увелич счетчик на 2, т.е у нас теперь в этой строке будет 2 столбика и т.д
            count += 2;
        userMatrix[i] = new int[count];
    }

    // заполнение элементами
    count = 0; // обнуляем счетчик
    for (int i = 0; i < rowsN; i++)
    {
        if (i % 2 == 0) // если номер строки нечетный, то увелич счетчик на 2, т.е у нас теперь в этой строке будет 2 столбика и т.д
            count += 2;
        for (int j = 0; j < count; j++) // цикл столбцов от 0 до count, т.е до счетчика
        {
            userMatrix[i][j] = rand() % 100 - 50; // присваиваем элементу матрицы рандомное значение
            std::cout << std::setw(4) << userMatrix[i][j]; // выводим строку матрицы
        }
        std::cout << "\n"; // перенос на новую строку
    }

    // подсчет количества отрицательныъ элементов матрицы в отмеченных строках
    count = 0;
    int countNegativElem = 0; // счетчик для подсчета отриц элементов в отмеч строках
    for (int i = 0; i < rowsN; i++)
    {
        if (i % 2 == 0) // если номер строки нечетный, то увелич счетчик на 2, т.е у нас теперь в этой строке будет 2 столбика и т.д
            count += 2;
        if (arrA[i] > 0) // проверяем ai отмеченная или нет, если да(ai>0), то выполняем следующее:
        {
            for (int j = 0; j < count; j++) // цикл по стобцам
            {
                if (userMatrix[i][j] < 0) // если элемент матрицы < 0, то увеличиваем счетчик
                    countNegativElem++;
            }
        }
    }
    std::cout << "Количество отрицательных элементов: " << countNegativElem;
}

int CheckEven(int num_) // проверка четности
{
    bool isCheck = false;
    std::cin >> num_;
    do {
        if (num_ % 2 == 0)
            isCheck = true;
        else
        {
            std::cout << "Это не четное число! Введите число еще раз!\n";
            std::cin >> num_;
            isCheck = false;
        }
    } while (!isCheck);

    return num_;
}
