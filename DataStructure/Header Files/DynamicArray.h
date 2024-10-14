//! \brief Структура динамического массива.
struct DynamicArray
{
	//! \brief Размер массива.
	int Size;

	//! \brief Вместимость массива.
	int Capacity;

	//! \brief Массив.
	int* Array;
};

const int INITIAL_CAPACITY = 8;
const double GROWTH_FACTOR = 2;

void Resize(DynamicArray* array, int capacity);

DynamicArray* CreateArray();

//! \brief Добавляет элемент в массив.
//! \param array Структура динамического массива.
//! \param index Индекс элемента, куда нужно добавить элемент.
//! \param value Значение элемента.
void AddElement(DynamicArray* array, int index, int value);

//! \brief Удаляет элемент массива по передаваемому индексу.
//! \param array Структура динамического массива.
//! \param index Индекс элемента, который нужно удалить.
void RemoveByIndex(DynamicArray* array, int index);

//! \brief Удаляет значение элемента по его передаваемому значению.
//! \param array Структура динамического массива.
//! \param value Посылаемое значение, которое нужно удалить.
void RemoveByValue(DynamicArray* array, int value);

//! \brief Возвращает элемент по индексу.
//! \param array Структура динамического массива.
//! \param index Индекс, по которому нужно получить значение.
//! \return Возвращает значение, которое находится под индексом.
int GetElement(DynamicArray* array, int index);

//! \brief Сортирует массив(сортировка вставками).
//! \param array Структура динамического массива.
void SortArray(DynamicArray* array);

//! \brief Линейный поиск индекса элемента по передаваемому значению.
//! \param array Структура динамического массива.
//! \param value Значение, индекс которого нужно найти.
void LinearSearch(DynamicArray* array, int value);

//! \brief Бинарный поиск индекса элемента по передаваемому значению.
//! \param array Структура динамического массива.
//! \param value Значение, индекс которого нужно найти.
void BinarySearch(DynamicArray* array, int value);

//! \brief Очистка данных массива.
//! \param array Структура динамического массива.
void FreeArray(DynamicArray* array);

void Print(DynamicArray* array);