
#include <iostream>


struct Array
{
	int A[10];
	int size;
	int length;
};

void Display(struct Array arr)
{
	int i;
	std::cout << "Elements are\n";
	for (i = 0; i < arr.length; i++)
		std::cout << arr.A[i] << " ";
}

void Insert(struct Array* arr, int index, int x)
{
	int i;
	if (index >= 0 && index <= arr->length)
	{
		for (i = arr->length; i > index; i--)
			arr->A[i] = arr->A[i - 1];
		arr->A[index] = x;
		arr->length++;
	}
}

void Append(struct Array* arr, int x)
{
	if (arr->length < arr->size)
		arr->A[arr->length++] = x;
}

int Delete(struct Array* arr, int index)
{
	int x = 0;
	int i;
	if (index >= 0 && index < arr->length)
	{
		x = arr->A[index];
		for (i = index; i < arr->length - 1; i++)
			arr->A[i] = arr->A[i + 1];
		arr->length--;
		return x;
	}
	return 0;
}
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// linear search
int LinearSearch(struct Array* arr, int key)
{
	int i;
	for (i = 0; i < arr->length; i++)
	{
		if (key == arr->A[i])
		{
			// move to front
			// swap(&arr->A[i], &arr->A[0]);
			// transposition
			// swap(&arr->A[i], &arr->A[i - 1]);
			return i;
		}
	}
	return -1;
}
// binary search
int BinarySearch(struct Array arr, int key)
{
	int l, mid, h;
	l = 0;
	h = arr.length - 1;
	while (l <= h)
	{
		mid = (l + h) / 2;
		if (key == arr.A[mid])
			return mid;
		else if (key < arr.A[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

//sort array
void SortArray(struct Array* arr)
{
	int i, j;
	for (i = 0; i < arr->length - 1; i++)
	{
		for (j = i + 1; j < arr->length; j++)
		{
			if (arr->A[i] > arr->A[j])
			{
				swap(&arr->A[i], &arr->A[j]);
			}
		}
	}
}

int main()
{
    struct Array arr = { {2,3,4,5,6}, 10, 5 };
	Insert(&arr, 2, 10);
	Append(&arr, 12);
	Delete(&arr, 3);
	Display(arr);
	std::cout << std::endl;
	std::cout << LinearSearch(&arr, 5) << std::endl;
	SortArray(&arr);
	Display(arr);
	std::cout << BinarySearch(arr, 5) << std::endl;
	return 0;
}

