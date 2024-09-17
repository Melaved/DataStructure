//1 задание 

//1.1
//#include <iostream>
//using namespace std;
//
//void Breakpoints()
//{
//	double add = 1.0;
//	double sum = 0.0;
//	for (int i = 0; i < 10; i++)
//	{
//		sum += add * i;
//		//cout << sum<<endl;
//		add *= 1.1;
//	}
//	cout << "Total sum is " << sum;
//}
//
//int main()
//{
//	Breakpoints();
//}

//1.2
//#include <iostream>
//using namespace std;
//
//void Breakpoints()
//{
//	double add = 1.0;
//	double sum = 0.0;
//	for (int i = 0; i < 1000; i++)
//	{
//		sum += add * i;
//		//cout << sum<<endl;
//		if (i % 3 == 0) 
//		{
//			add *= 1.3;
//		}
//		else
//		{
//			add /= 3.0;
//		}
//	}
//	cout << "Total sum is " << sum;
//}
//
//int main()
//{
//	Breakpoints();
//}

//2 задание

//2.1
//#include <iostream>
//using namespace std;
//
//int main() 
//{
//	int arrayNumbers[10] = { 1,43,4,-754,321,0,34,13,-3,-10 };
//	cout << "Source array is: " << endl;
//	for (int i = 0; i < size(arrayNumbers);i++)
//	{
//		cout << arrayNumbers[i]<<' ';
//	}
//
//	for (int i = 0; i < size(arrayNumbers); i++)
//	{
//		bool flag = true;
//		for (int j = 0; j < size(arrayNumbers) - 1; j++)
//		{
//			if (arrayNumbers[j] > arrayNumbers[j + 1])
//			{
//				flag = false;
//				swap(arrayNumbers[j], arrayNumbers[j + 1]);
//			}
//		}
//		if (flag) 
//		{
//			break;
//		}
//	}
//
//	cout << "Sorted array is:" << endl;
//	for (int i = 0; i < size(arrayNumbers); i++)
//  {
//		cout << arrayNumbers[i] << ' ';
//	}
//}

//2.2
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	double arrayNumbers[12] = { 1.0, 13.4, 15.5, 76.2, 1.4, 123.3, -42.4, 
//		-54.6,876.4, 4324.4, 12.1,0.0 };
//
//	double searchingValue;
//
//	int counter = 0;
//
//	cout << "Source array is:" << endl;
//
//	for (int i = 0; i <= size(arrayNumbers); i++)
//	{
//		cout << arrayNumbers[i] << ' ';
//	}
//
//	cout <<endl<< "Enter searching number: ";
//	cin >> searchingValue;
//
//	for (int i = 0; i <= size(arrayNumbers); i++)
//	{
//		if (searchingValue > arrayNumbers[i])
//		{
//			counter++;
//		}
//	}
//	cout << "Elements of array more than " << searchingValue <<" is: " << counter;
//}

//2.3
//#include <iostream>
//using namespace std;
//
//int main() 
//{
//	char arrayChar[8];
//
//	cout << "Enter array of 8 chars" << endl;
//
//	for (int i = 0; i < size(arrayChar); i++) {
//		cout << "arrayChar[" << i << "]: ";
//		cin >> arrayChar[i];
//		cout << endl;
//	}
//
//	cout << "Your array is:" << endl;
//
//	for (int i = 0; i < size(arrayChar); i++) {
//		cout << arrayChar[i] << " ";
//	}
//
//	cout <<endl<< "All letters in your array:" << endl;
//
//	for (int i = 0; i < size(arrayChar); i++) 
//	{
//		if (arrayChar[i] >= 'a' && arrayChar[i] <= 'z')
//		{
//			cout << arrayChar[i] << " ";
//		}
//	}
//}


//3 zadanie

//3.1,3.2
//#include <iostream>
//using namespace std;
//
////Возводит число base в степень exponent 
//double GetPower(double base, int exponent)
//{
//	double degree;
//
//	degree = base;
//
//	for (int i = 0; i < exponent-1; i++) 
//	{
//		base *= degree;
//	}
//	return base;
//}
//
//void DemoGetPower(double base, int exponent) 
//{
//	//cin >> base >> exponent;
//	cout << base << " " << "^ " << exponent<< " = " << GetPower(base, exponent)<< endl;
//}
//
//int main() 
//{
//	DemoGetPower(3.0, 2);
//	DemoGetPower(2.0, 4);
//	DemoGetPower(5.0, 4);
//}

//3.3,3.4
// 
//#include <iostream>
//using namespace std;
//
//void RoundToTens(int& value) 
//{
//	int remainder = value % 10;
//
//	int result;
//
//	if (remainder < 5)
//	{
//		result = (value / 10) * 10;
//	}
//	else 
//	{
//		result = (value / 10 + 1) * 10;
//	}
//
//	cout << "For " << value << " value is " << result << endl;
//}
//
//int main() 
//{
//
//	int number1 = 154;
//	int number2 = 168;
//	int number3 = 357;
//	RoundToTens(number1);
//	RoundToTens(number2);
//	RoundToTens(number3);
//
//}


//4 zadanie

//4.1
//#include <iostream>
//using namespace std;
//
//int main() 
//{
//	int a = 5;
//	int b = 4;
//	cout << "Addres of a: " << &a << endl;
//	cout << "Addres of b: " << &b << endl;
//
//	double c = 13.5;
//	cout << "Addres of c: " << &c << endl;
//
//	bool d = true;
//	cout << "Addres of d: " << &d << endl;
//
//}

//4.2
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int a[10] = { 1, 2, 7, -1, 5, 3, -1, 7, 1, 6 };
//	cout << "Size of int type: " << sizeof(int) << endl;
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << "Address of a[" << i << "]: " << &a[i] << endl;
//	}
//
//	cout << endl;
//
//	cout << "Size of double type: " << sizeof(double) << endl;
//
//	double b[10] = { 1.0, 2.0, 7.0, -1.0, 5.0, 3.5, -1.8, 7.2, 1.9, 6.2 };
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << "Address of b[" << i << "]: " << &b[i] << endl;
//	}
//}

//4.3
//#include <iostream>
//using namespace std;
//
//int main() 
//{
//	int a = 5;
//	int& b = a;
//
//	cout << "Address of a: " << &a << endl;
//	cout << "Address of b: " << &b << endl;
//	
//	b = 7;
//	cout << "Value of a: " << a << endl;
//
//
//}

//4.4
//#include <iostream>
//using namespace std;
//
//void Foo(double& a)
//{
//	cout << "Address of a in Foo(): " << &a << endl;
//	cout << "Value of a in Foo(): " << a << endl;
//
//	a = 15.0;
//	cout << "New value of a in Foo(): " << a << endl;
//}
//
//int main() 
//{
//	double a = 5.0;
//	cout << "Address of a in main(): " << &a << endl;
//	cout << "Value of a in main(): " << a << endl;
//	cout << endl;
//	Foo(a);
//	cout << endl;
//	cout << "Value of a in main(): " << a << endl;
//}

//4.5
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int a = 5;
//	int* pointer = &a;
//	cout << "Address of a: " << &a << endl;
//	cout << "Address in pointer: " << pointer << endl;
//	cout << "Address of pointer: " << &pointer << endl;
//
//	cout << endl;
//	*pointer = 7;
//	cout << "Value in a: " << a << endl;
//	cout << "Value by pointer address: " << *pointer << endl;
//}

//4.6
//#include <iostream>
//using namespace std;
//
//void Foo(double* a)
//{
//	cout << "Address in pointer: " << a << endl;
//
//	cout << "Address of pointer: " << &a << endl;
//
//	cout << "Value in pointer address: " << *a << endl;
//
//	*a = 15.0;
//
//	cout << "New value in pointer address: " << *a << endl;
//}
//
//int main() 
//{
//	double value = 5.0;
//
//	double* pointer = &value;
//
//	cout << "Address of value in main(): " << &value << endl;
//
//	cout << "Address in pointer in main(): " << pointer << endl;
//
//	cout << "Address of pointer in main(): " << &pointer << endl;
//
//	cout << "Value of a in main(): " << value << endl;
//
//	cout << endl;
//
//	Foo(pointer);
//
//	cout << endl;
//
//	cout << "Value of a in main(): " << value << endl;
//}

// 5 zadanie

//5/1
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	const int size = 5;
//	double* arr = new double[size];
//	for (int i = 0; i < size; i++) 
//	{
//		arr[i] = i * 1.1;
//	}
//
//	cout << "Array of double:" << endl;
//
//	for (int i = 0; i < size; i++) 
//	{
//		cout << arr[i] << " ";
//	}
//
//	cout << endl;
//	delete[] arr;
//	
//}

//5.2
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	bool* arr = new bool[5];
//	
//	arr[0] = true;
//	arr[1] = false;
//	arr[2] = true;
//	arr[3] = false;
//	arr[4] = true;
//
//	cout << "Array of bool:" << endl;
//
//	for (int i = 0; i < 5; i++)
//	{
//		cout << boolalpha <<arr[i] << " ";
//	}
//
//	cout << endl;
//	delete[] arr;
//
//}

//5.3
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int size;
//	cout << "Enter char array size: ";
//	cin >> size;
//	char* arr = new char[size];
//	for (int i=0; i < size; i++) 
//	{
//		cout << "Enter a["<<i<<"]: ";
//		cin >> arr[i];
//	}
//
//	cout << "Your char array is:" << endl;
//
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << " ";
//	}
//
//	delete[] arr;
//}

//5.4
//#include <iostream>;
//using namespace std;
//
//void bubbleSort(double* arr, int size) {
//    for (int i = 0; i < size - 1; ++i) {
//        for (int j = 0; j < size - i - 1; ++j) {
//            if (arr[j] > arr[j + 1]) {
//  
//                swap(arr[j], arr[j + 1]);
//
//            }
//        }
//    }
//}
//
//int main() 
//{
//    double* arrayDouble = new double[10];
//    arrayDouble[0] = 1.0;
//    arrayDouble[1] = 15.0;
//    arrayDouble[2] = -8.2;
//    arrayDouble[3] = -3.5;
//    arrayDouble[4] = 12.6;
//    arrayDouble[5] = 38.4;
//    arrayDouble[6] = -0.5;
//    arrayDouble[7] = 4.5;
//    arrayDouble[8] = 16.7;
//    arrayDouble[9] = 4.5;
//
//    cout << "Array of double:"<<endl;
//    for (int i = 0; i < 10; i++) 
//    {
//        cout << arrayDouble[i] << " ";
//    }
//
//    bubbleSort(arrayDouble, 10);
//
//    cout << "Sorted array of double:" << endl;
//    for (int i = 0; i < 10; i++)
//    {
//        cout << arrayDouble[i] << " ";
//    }
//
//    delete[] arrayDouble;
//}


//5.5
//#include <iostream>
//using namespace std;
//
//int indexFound(int* arr, int size,int value1) 
//{
//	for (int i = 0; i < size; i++)
//	{
//		if (arr[i] == value1)
//		{
//			return i;
//		}
//	}
//}
//
//int main()
//{
//	int* arrayInt = new int[10];
//	int value;
//	arrayInt[0] = 1;
//	arrayInt[1] = 15;
//	arrayInt[2] = -8;
//	arrayInt[3] = -3;
//	arrayInt[4] = 12;
//	arrayInt[5] = 38;
//	arrayInt[6] = 0;
//	arrayInt[7] = 4;
//	arrayInt[8] = 16;
//	arrayInt[9] = 4;
//	cout << "Int array:" << endl;
//	for (int i = 0; i < 10; i++) 
//	{
//		cout << arrayInt[i] << " ";
//	}
//	cout << endl;
//	cout << "Enter searching value: ";
//	cin >> value;
//	int findValue = indexFound(arrayInt, 10, value);
//	cout << "Index of searching value " << value << " is " << findValue;
//
//	delete[] arrayInt;
//}

//5.6
//#include <iostream>
//using namespace std;
//
//int letterCounter(char* arr, int size) 
//{
//	int counter = 0;
//	for (int i = 0; i < size; i++) 
//	{
//		if (arr[i] >= 'a' && arr[i] <= 'z') {
//			counter++;
//		}
//	}
//	return counter;
//}
//
//int main() 
//{
//	char* arrayChar = new char[15];
//    arrayChar[0] = 'a';
//    arrayChar[1] = '5';
//    arrayChar[2] = 'm';
//    arrayChar[3] = 'i';
//    arrayChar[4] = '%';
//    arrayChar[5] = '!';
//    arrayChar[6] = 's';
//    arrayChar[7] = 'p';
//    arrayChar[8] = '*';
//    arrayChar[9] = '9';
//    arrayChar[10] = 'f';
//    arrayChar[11] = '^';
//    arrayChar[12] = ';';
//    arrayChar[13] = 'q';
//    arrayChar[14] = 'k';
//
//    cout << "Char array is:" << endl;
//
//    for (int i = 0; i < 15; i++) 
//    {
//        cout << arrayChar[i] << " ";
//    }
//
//    cout << endl;
//
//    int alphabetLetters = letterCounter(arrayChar, 15);
//
//    cout << "Letters count in array: " << alphabetLetters;
//}

//5.7
//#include <iostream>
//using namespace std;
//
//int* MakeRandomArray(int arraySize)
//{
//	int* arr = new int[arraySize];
//	for (int i = 0; i < arraySize; ++i) {
//		arr[i] = rand() % 101; // Случайные значения от 0 до 100
//	}
//
//	return arr;
//}
//
//int main() 
//{
//	int size1 = 5;
//	int size2 = 8;
//	int size3 = 13;
//
//	int* array1 = MakeRandomArray(size1);
//
//	int* array2 = MakeRandomArray(size2);
//
//	int* array3 = MakeRandomArray(size3);
//
//    cout << "Random array of 5:" << endl;
//    for (int i = 0; i < size1; ++i) {
//        cout << array1[i] << " ";
//    }
//    cout << endl;
//
//    cout << "Random array of 8:" << endl;
//    for (int i = 0; i < size2; ++i) {
//        cout << array2[i] << " ";
//    }
//    cout << endl;
//
//    cout << "Random array of 13:" << endl;
//    for (int i = 0; i < size3; ++i) {
//        cout << array3[i] << " ";
//    }
//    cout << endl;
//
//    // Освобождаем память
//    delete[] array1;
//    delete[] array2;
//    delete[] array3;
//}

//5.8
//#include <iostream>
//using namespace std;
//
//// Функция для чтения массива целых чисел
//int* ReadArray(int count)
//{
//    int* values = new int[count]; // Выделяем память под массив
//    cout << "Введите " << count << " целых чисел:" << endl;
//    for (int i = 0; i < count; i++) {
//        cin >> values[i]; // Читаем значения
//    }
//    return values; // Возвращаем указатель на массив
//}
//
//// Функция для подсчета положительных значений в массиве
//int CountPositiveValues(int* values, int count)
//{
//    int result = 0; // Счетчик положительных значений
//    for (int i = 0; i < count; i++) {
//        if (values[i] > 0) { // Проверяем, положительное ли значение
//            result++;
//        }
//    }
//    return result; // Возвращаем количество положительных значений
//}
//
//int main()
//{   
//    setlocale(LC_ALL, "Russian");
//    // Читаем первый массив размером 15
//    int count = 15;
//    int* values = ReadArray(count);
//    cout << "Количество положительных значений: " << CountPositiveValues(values, count) << endl;
//
//    delete[] values;
//    // Читаем второй массив размером 20
//    count = 20;
//    values = ReadArray(count);
//    cout << "Количество положительных значений: " << CountPositiveValues(values, count) << endl;
//
//    // Освобождаем выделенную память
//    delete[] values;
//
//    return 0;
//}
//Ошибки: корректность ввода(мб введут не то что надо, 
// заполнение массива чем либо(0?) если пользователь не введет все значения и массив не заполнится


//7 zadanie
//
//#include <iostream>
//#include <string>
//using namespace std;
//
//
////! \brief Структура, описывающая человека.
///*!
// * В данной структуре хранится информация о имени, фамилии и возрасте человека.
// */
//struct Person
//{
//    //! Имя человека.
//    string FirstName;
//
//    //! Фамилия человека.
//    string LastName;
//
//    //! Возраст человека.
//    unsigned Age;
//};
//
// // Функция для вывода информации о человеке
//void WritePerson(const Person& person)
//{
//    cout << "First Name: " + person.FirstName
//        + "; Last Name: " + person.LastName
//        + "; Age: " + to_string(person.Age)
//        << endl;
//}
//
//const int PeopleCount = 5;
//
////! \brief Создает массив людей.
////! \return Массив указателей на объекты структуры человека \see Person.
//Person** CreatePeopleArray()
//{
//    Person** people = new Person * [PeopleCount];
//
//    people[0] = new Person();
//    people[0]->FirstName = "Casey";
//    people[0]->LastName = "Aguilar";
//    people[0]->Age = 30;
//
//    people[1] = new Person();
//    people[1]->FirstName = "Brock";
//    people[1]->LastName = "Curtis";
//    people[1]->Age = 19;
//
//    people[2] = new Person();
//    people[2]->FirstName = "Blake";
//    people[2]->LastName = "Diaz";
//    people[2]->Age = 21;
//
//    people[3] = new Person();
//    people[3]->FirstName = "Cristian";
//    people[3]->LastName = "Evans";
//    people[3]->Age = 55;
//
//    people[4] = new Person();
//    people[4]->FirstName = "Les";
//    people[4]->LastName = "Foss";
//    people[4]->Age = 4;
//
//    return people;
//}
//
//void ClearPerson(Person* person)
//{
//    delete person;
//}
//
//// Очищает массив людей
//void ClearPeople(Person** people, int itemsCount)
//{
//    for (int i = 0; i < itemsCount; i++)
//    {
//        ClearPerson(people[i]);
//    }
//    delete[] people;
//}
//
//void FindPersonByLastName() {
//    Person** people = CreatePeopleArray();
//
//    // Вывод информации о каждом человеке
//    for (int i = 0; i < PeopleCount; i++) {
//        WritePerson(*people[i]);
//    }
//
//    string lastName;
//    cout << "Enter last name: ";
//    cin >> lastName;
//
//    int foundIndex = -1;
//
//    //линейный поиск
//    for (int i = 0; i < PeopleCount; i++) {
//        if (people[i]->LastName == lastName) {
//            foundIndex = i;
//            break; 
//        }
//    }
//
//    // Проверка результата поиска
//    if (foundIndex == -1) {
//        cout << "Could not find a person by last name: " << lastName << endl;
//    }
//    else {
//        cout << "A person's last name " << lastName
//            << " was found. Its index in the array is " << foundIndex << endl;
//    }
//
//    ClearPeople(people, PeopleCount);
//}
//
//int main() 
//{
//    FindPersonByLastName();
//}