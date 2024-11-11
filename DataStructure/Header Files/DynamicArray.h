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

//! \brief ����������� ����������� �������.
const int INITIAL_CAPACITY = 8;

//! \brief ������ ����� �������.
const double GROWTH_FACTOR = 2;

//! \brief �������� ����������� �������.
//! \param array ��������� ������������� �������.
//! \param capacity ����������� �������.
void Resize(DynamicArray* array, int capacity);

//! \brief �������� ������������� �������.
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
int LinearSearch(DynamicArray* array, int value);

//! \brief �������� ����� ������� �������� �� ������������� ��������.
//! \param array ��������� ������������� �������.
//! \param value ��������, ������ �������� ����� �����.
int BinarySearch(DynamicArray* array, int value);

//! \brief ������� ������ �������.
//! \param array ��������� ������������� �������.
void FreeArray(DynamicArray* array);
