#include <iostream>

int number_for_array(char* argv)
{
    char* start = argv;
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

    for (int i = 0; i < num; i++)
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
    int num = 0;
    if (argc >= 2) 
    {
        num = number_for_array(argv[1]);
    } 
    else 
    {
        if (!(std::cin >> num)) 
        {
            return 0;
        }
    }
    
    int* array = read_array(num);

    int step;
    std::cin >> step;
    step %= num;
    if (step < 0)
    {
        step += num;
    }

    remake_array(array, step, num);

    for (int i = 0; i < num; i++)
    {
        std::cout << array[i] << std::endl;
    }
    
    for (int i = 0; i < num; i++)
    {
        std::cout << array[i];
        if (i < num - 1) 
        {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;

    delete[] array;
    return 0;
}
