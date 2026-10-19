#include <iostream>
#include <charconv>


int number_for_array(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: wordcounter <N>";
        return 0;
    }

    int number = 0;

    char* start = argv[1];
    char* end = start;

    while (* end != '\0')
    {
        end++;
    }

    std::from_chars(start, end, number);

    return number;
}

int* read_array(int num)
{
    int* array = new int[num];

    for (size_t i = 0; i < num; i++)
    {
        int element;
        std::cin >> element;
        array[i] = element;
    }

    return array;
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

    for (size_t i = 0; i < num; i++)
    {
        int index = (i + num - step) % num;
        std::cout << array[index] << std::endl;
    }
    
    for (size_t i = 0; i < num; i++)
    {
         int index = (i +  num - step) % num;
        std::cout << array[index] << ' ';
    }

    delete[] array;
    return 0;
}