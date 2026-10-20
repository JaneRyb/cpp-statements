#include <iostream>

int number_for_array(int argc, char* argv[])
{
    char* start = argv[1];
    int number = 0;

    while (* start != '\0')
    {
        number = number * 10 + (* start - '0');
        start++;
    }

    return number;
}

int* read_array(int num)
{
    int* array = new int[num];

    for (size_t i = 0; i < num; i++)
    {
        std::cin >> array[i];
    }

    return array;
}


void reverse_array(int* array, int start, int end)
{
    while (start < end)
    {
        int element = array[start];
        array[start] = array[end];
        array[end] = element;

        start++;
        end--;
    }
}

void remake_array(int* array, int step, int num)
{
    if (step == 0) return;

    reverse_array(array, 0, num - 1);      
    reverse_array(array, 0, step - 1);      
    reverse_array(array, step, num - 1);
}

int main(int argc, char* argv[])
{
    int num = number_for_array(argc, argv);
    int* array = read_array(num);

    int step;
    std::cin >> step;
    step %= num;
    if (step < 0)
    {
        step += num;
    }

    remake_array(array, step, num);

    for (size_t i = 0; i < num; i++)
    {
        std::cout << array[i] << std::endl;
    }
    
    for (size_t i = 0; i < num; i++)
    {
        std::cout << array[i] << ' ';
    }

    delete[] array;
    return 0;
}
