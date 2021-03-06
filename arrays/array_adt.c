#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct Array
{
    int *arr;
    int size;
    int length;
};

void display(struct Array *array);
void insert(struct Array *array, int element, int at_idx);
void add(struct Array *array, int element);
void delete(struct Array *array, int at_idx);
int get(struct Array *array, int idx);
int set(struct Array *array, int idx, int elem);
int max(struct Array *array);
int min(struct Array *array);
int avg(struct Array *array);
int sum(struct Array *array);
void reverse(struct Array *array);
bool linear_search(struct Array *array, int target);
bool binary_search(struct Array *array, int target);
void bubble_sort(struct Array *array);
bool is_sorted_asc(struct Array *array);
bool is_sorted_desc(struct Array *array);

int main()
{
    struct Array array;

    printf("Enter size of the array: ");
    scanf("%d", &array.size);

    array.arr = (int *)malloc(array.size * sizeof(array.arr));
    array.length = 0;

    insert(&array, 1, 0);
    insert(&array, 5, 1);
    insert(&array, 2, 2);
    insert(&array, 6, 3);
    insert(&array, 3, 4);
    insert(&array, 7, 5);
    insert(&array, 4, 6);
    insert(&array, 1, 0);
    insert(&array, 5, 1);
    insert(&array, 2, 2);
    insert(&array, 6, 3);
    insert(&array, 3, 4);
    insert(&array, 7, 5);
    insert(&array, 4, 6);
    
    return 0;
}

void swap(struct Array *array, int fromIdx, int toIdx)
{
    int tempToIdxVal = (*array).arr[toIdx];
    (*array).arr[toIdx] = (*array).arr[fromIdx];
    (*array).arr[fromIdx] = tempToIdxVal;
}

void bubble_sort(struct Array *array)
{
    for (int outer = 0; outer < (*array).length; outer += 1)
    {
        for (int inner = outer + 1; inner < (*array).length; inner += 1)
        {
            if ((*array).arr[outer] > (*array).arr[inner])
                swap(array, outer, inner);
        }
    }
}

void display(struct Array *array)
{
    for (int i = 0; i < (*array).length; i += 1)
        printf("%d\n", (*array).arr[i]);
}

void insert(struct Array *array, int element, int at_idx)
{
    if (at_idx < 0 || at_idx > (*array).length)
        return;

    for (int i = (*array).length; i > at_idx; i -= 1)
        (*array).arr[i] = (*array).arr[i - 1];

    (*array).arr[at_idx] = element;
    (*array).length += 1;
}

void delete(struct Array *array, int at_idx)
{
    if (at_idx < 0 || at_idx > (*array).size)
        return;

    for (int i = at_idx; i < (*array).length; i += 1)
        (*array).arr[i] = (*array).arr[i + 1];

    (*array).length -= 1;
}

void add(struct Array *array, int element)
{
    if ((*array).length < (*array).size)
    {
        (*array).arr[(*array).length] = element;
        (*array).length += 1;
    }
}

bool linear_search(struct Array *array, int target)
{
    for (int i = 0; i < (*array).length; i += 1)
        if((*array).arr[i] == target)
            return true;

    return false;
}

bool binary_search(struct Array *array, int target)
{
    if ((*array).length < 0)
        return false;

    int lowerBound = 0,
        upperBound = (*array).length - 1,
        middle = (lowerBound + upperBound) / 2;

    while (lowerBound <= upperBound)
    {
        if ((*array).arr[middle] == target)
            return true;

        if ((*array).arr[middle] < target)
        {
            lowerBound = middle + 1;
            middle = (lowerBound + upperBound) / 2;
        }
        else
        {
            upperBound = middle - 1;
            middle = (lowerBound + upperBound) / 2;
        }
    }

    return false;
}

int get(struct Array *array, int idx)
{
    if (idx > ((*array).length - 1) || idx < 0)
        return -1;

    return (*array).arr[idx];
}

int set(struct Array *array, int idx, int elem)
{
    if (idx > ((*array).length - 1) || idx < 0)
        return -1;

    (*array).arr[idx] = elem;
    return elem;
}

int max(struct Array *array)
{
    if ((*array).length < 1)
        return -1;

    int max = (*array).arr[0];

    for (int i = 1; i < (*array).length; i += 1)
        if ((*array).arr[i] > max)
            max = (*array).arr[i];

    return max;
}

int min(struct Array *array)
{
    if ((*array).length < 1)
        return -1;

    int min = (*array).arr[0];

    for (int i = 1; i < (*array).length; i += 1)
        if ((*array).arr[i] < min)
            min = (*array).arr[i];

    return min;
}

int avg(struct Array *array)
{
    if ((*array).length < 1)
        return -1;

    int avg = 0;
    int temp_acc = 0;

    for (int i = 0; i < (*array).length; i += 1)
        temp_acc += (*array).arr[i];

    avg = temp_acc / (*array).length;

    return avg;
}

int sum(struct Array *array)
{
    if ((*array).length < 1)
        return -1;

    int total = 0;

    for (int i = 0; i < (*array).length; i += 1)
        total += (*array).arr[i];

    return total;
}

void reverse(struct Array *array)
{
    if ((*array).length < 1)
        return;

    int temp_storage;

    for (int i = 0; i < (*array).length / 2; i += 1)
    {
        temp_storage = (*array).arr[i];
        (*array).arr[i] = (*array).arr[(*array).length - 1 - i];
        (*array).arr[(*array).length - 1 - i] = temp_storage;
    }
}

bool is_sorted_asc(struct Array *array)
{
    for (int i = 0; i < (*array).length; i += 1)
        if ((*array).arr[i] > (*array).arr[i + 1])
            return false;

    return true;
}

bool is_sorted_desc(struct Array *array)
{
    for(int i = 0; i < (*array).length; i += 1)
        if ((*array).arr[i] < (*array).arr[i + 1])
            return false;
    
    return true;
}