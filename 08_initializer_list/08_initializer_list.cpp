#include <iostream>
using namespace std;


template<typename T>
class Array
{
	T* arr;
	int size;
public:
	Array()
	{
		T = nullptr;
		size = 0;
	}
	explicit Array(int size)
	{
		this->size = size;
		arr = new T[size] {};
	}
	Array(initializer_list<T> list)
	{
		this->size = list.size();
		arr = new T[size];
		int i = 0;
		for (T elem:list)
		{
			arr[i] = elem;
			i++;
		}
	}
	void Fill(initializer_list<T> list)
	{
		if (arr != nullptr)
			delete[]arr;
		this->size = list.size();
		arr = new T[size];
		int i = 0;
		for (T elem : list)
		{
			arr[i] = elem;
			i++;
		}
	}
	~Array()
	{
		if (arr != nullptr)
			delete[]arr;
	}
	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	T maxElement();
	T minElement();

	void BubbleSort();
	 
	int BinarySearch(T key);
	void ChangeEl(int index, T num);


};



int main()
{
	int static_arr[5] = { 1,2,3,4,5 };
	int* dynam_arr = new int[5]{ 5,4,3,2,1 };

	Array arr({ 10 });
	arr.Print();

	Array arr2({ 5, 7, 8, 9, 6, 2, 4, 8 });
	arr2.Print();
	


	

	delete[]dynam_arr;

	arr2.BubbleSort();
	arr2.Print();

}

template<typename T>
T Array<T>::maxElement()
{
	T max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i]>max)
		{
			max = arr[i];
		}
	}
	return max;
}

template<typename T>
T Array<T>::minElement()
{
	T min = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i]<min)
		{
			min = arr[i];
		}
	}
	return min;
}

template<typename T>
void Array<T>::BubbleSort()
{
	T temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;

			}
		}
	}
}

template<typename T>
int Array<T>::BinarySearch(T key) //16
{
	int B = 0, E = size - 1;
	while (true)
	{
		//B = 0, E = 9
		//1 5 7 8 9 15 16 21 47 53 
		// //B = 5, E = 6
		// 15 16 21 47 53 
		int p = (B + E) / 2;
		//p = 7
		if (key > arr[p])
		{
			B = p + 1;
		}
		else if (key < arr[p])
		{
			E = p - 1;
		}
		else if (key == arr[p])
			return p;
		if (B > E) return -1;
	}
}

template<typename T>
void Array<T>::ChangeEl(int index, T num)
{
	if (index > size && index < 0)
	{
		cout << "Error" << endl;
	}
	else
	{
		arr[index] = num;
	}
}
