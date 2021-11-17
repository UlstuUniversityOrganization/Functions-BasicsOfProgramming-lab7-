#include <stdio.h>

void InputArray(int** array, int* elementsCount)
{
	printf("Enter elements count of the array:");
	scanf_s("%d", elementsCount);
	printf("\n");

	*array = new int[*elementsCount];

	printf("Enter elements:\n");
	for (int i = 0; i < *elementsCount; i++)
	{
		printf("%d element:", i + 1);
		scanf_s("%d", &(*array)[i]);
	}
}

void OutputArray(int* array, int elementsCount)
{
	printf("This is your array:\n");
	for (int i = 0; i < elementsCount; i++)
	{
		printf("%d ", array[i]);
	}
}

void TaskD(int* array, int elementsCount, int** newArray, int* newElementsCount)
{
	int min = array[0];
	int max = array[0];

	int minId = 0;
	int maxId = 0;

	for (int i = 0; i < elementsCount; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
			minId = i;
		}

		if (array[i] > max)
		{
			max = array[i];
			maxId = i;
		}
	}

	*newElementsCount = 0;
	for (int i = minId + 1; i < maxId; i++)
		if ((array[i] % 2) != 0)
			++* newElementsCount;
	if (maxId >= minId)
		* newElementsCount += elementsCount - ((maxId - 1) - minId);
	else
		*newElementsCount += elementsCount - ((minId - 1) - maxId);

	*newArray = new int[*newElementsCount];

	int j = 0;
	for (int i = 0; i < elementsCount; i++)
	{

		if (i > minId && i < maxId)
		{
			if ((array[i] % 2) != 0)
			{
				(*newArray)[j] = array[i];
				j++;
			}
		}
		else
		{
			(*newArray)[j] = array[i];
			j++;
		}
	}
}

void UpdateArray(int** array, int* elementsCount)
{
	int min = (*array)[0];
	int max = (*array)[0];

	int minId = 0;
	int maxId = 0;

	for (int i = 0; i < *elementsCount; i++)
	{
		if ((*array)[i] < min)
		{
			min = (*array)[i];
			minId = i;
		}

		if ((*array)[i] > max)
		{
			max = (*array)[i];
			maxId = i;
		}
	}

	int newElementsCount = 0;
	for (int i = minId + 1; i < maxId; i++)
		if (((*array)[i] % 2) != 0)
			newElementsCount++;
	if (maxId >= minId)
		newElementsCount += *elementsCount - ((maxId - 1) - minId);
	else
		newElementsCount += *elementsCount - ((minId - 1) - maxId);

	int* tempArray = new int[newElementsCount];

	if (minId >= maxId)
	{
		int tempNum = minId;
		minId = maxId;
		maxId = tempNum;
	}
	int j = 0;
	for (int i = 0; i < *elementsCount; i++)
	{
			if (i > minId && i < maxId)
			{
				if (((*array)[i] % 2) != 0)
				{
					(tempArray)[j] = (*array)[i];
					j++;
				}
			}
			else
			{
				(tempArray)[j] = (*array)[i];
				j++;
			}
	}

	delete[(*elementsCount)] *array;
	*array = tempArray;
	*elementsCount = newElementsCount;
}

int main()
{
	int* num;
	int elementsCount;

	InputArray(&num, &elementsCount);
	UpdateArray(&num, &elementsCount);
	printf("\n");
	OutputArray(num, elementsCount);

	return 0;
}