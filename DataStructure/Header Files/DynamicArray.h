//! \brief ��������� ������������� �������.
struct DynamicArray
{
	//! \brief ������ �������.
	int Size;

	//! \brief ����������� �������.
	int Capacity;

	//! \brief ������.
	int* Array;
};

const int INITIAL_CAPACITY = 8;
const double GROWTH_FACTOR = 2;

void Resize(DynamicArray* array, int capacity);

DynamicArray* CreateArray();

//! \brief ��������� ������� � ������.
//! \param array ��������� ������������� �������.
//! \param index ������ ��������, ���� ����� �������� �������.
//! \param value �������� ��������.
void AddElement(DynamicArray* array, int index, int value);

//! \brief ������� ������� ������� �� ������������� �������.
//! \param array ��������� ������������� �������.
//! \param index ������ ��������, ������� ����� �������.
void RemoveByIndex(DynamicArray* array, int index);

//! \brief ������� �������� �������� �� ��� ������������� ��������.
//! \param array ��������� ������������� �������.
//! \param value ���������� ��������, ������� ����� �������.
void RemoveByValue(DynamicArray* array, int value);

//! \brief ���������� ������� �� �������.
//! \param array ��������� ������������� �������.
//! \param index ������, �� �������� ����� �������� ��������.
//! \return ���������� ��������, ������� ��������� ��� ��������.
int GetElement(DynamicArray* array, int index);

//! \brief ��������� ������(���������� ���������).
//! \param array ��������� ������������� �������.
void SortArray(DynamicArray* array);

//! \brief �������� ����� ������� �������� �� ������������� ��������.
//! \param array ��������� ������������� �������.
//! \param value ��������, ������ �������� ����� �����.
void LinearSearch(DynamicArray* array, int value);

//! \brief �������� ����� ������� �������� �� ������������� ��������.
//! \param array ��������� ������������� �������.
//! \param value ��������, ������ �������� ����� �����.
void BinarySearch(DynamicArray* array, int value);

//! \brief ������� ������ �������.
//! \param array ��������� ������������� �������.
void FreeArray(DynamicArray* array);

void Print(DynamicArray* array);