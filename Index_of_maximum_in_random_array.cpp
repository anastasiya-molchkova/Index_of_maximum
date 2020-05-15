/* Ввести целое число N. Создать массив из N целых чисел (сгенерировать рандомно). 
Определить индекс наибольшего элемента массива. */

#include <iostream>
#include <ctime>     // чтобы в randomize опираться на время запуска программы
#include <vector>

unsigned get_array_size()
{
	std::cout << "Введите количество чисел для случайного массива: ";
	int answer;
	std::cin >> answer;
	while (std::cin.fail() || (answer < 1))
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Нужно ввести натуральное число > 1, повторите ввод: ";
		std::cin >> answer;
	}
	return static_cast<unsigned>(answer);
}

int main()
{
	setlocale(LC_CTYPE, "rus");                  // для вывода сообщений пользователю на кириллице
	srand(static_cast<unsigned int>(time(0)));   // аналог randomize с привязкой ко времени запуска

	unsigned array_size{ get_array_size() };     // получаем длину массива от пользователя
	std::vector<unsigned short> array{};         // создаём вектор, т.к. длина массива - не константа компиляции
	unsigned short max{ 0 };                     // переменная для максимального элемента
	unsigned short index_of_max{ 0 };            // переменная для индекса максимального элемента

	std::cout << "Сгенерированный компьютером массив:";
	for (unsigned i = 0; i < array_size; ++i)
	{
		array.push_back(rand() % 1000);           // генерируем числа от 0 до 1000

		// выводим элементы массива не больше 20 в строке:
		if (i % 20 == 0) 
			std::cout << '\n';
		std::cout << array[i] << " ";

		// вычисляем максимальный элемент, запоминаем его индекс:
		if (max < array[i])
		{
			max = array[i];
			index_of_max = i;
		}
	}

    std::cout << "\nИндекс максимального элемента массива: " << index_of_max << std::endl;
	return 0;
}