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

double* read_array(int num)
{
    double* array = new double[num];

    for (size_t i = 0; i < num; i++)
    {
        double element;
        std::cin >> element;
        array[i] = element;
    }

    return array;
}

int main(int argc, char* argv[])
{
    int num = number_for_array(argc, argv);
    double* array_a = read_array(num);
    double* array_b = read_array(num);

    double result = 0;

    for (size_t i = 0; i < num; i++)
    {
        result += array_a[i] * array_b[i];
    }

    std::cout.precision(6);
    std::cout << std::fixed << result;

    delete[] array_a;
    delete[] array_b;
    return 0;
}