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

double* read_array(int num)
{
    double* array = new double[num];

    for (int i = 0; i < num; i++)
    {
        std::cin >> array[i];
    }

    return array;
}

int main(int argc, char* argv[])
{
    (void)argc;

    int num = number_for_array(argv[1]);
    double* array_a = read_array(num);
    double* array_b = read_array(num);

    double result = 0.0;

    for (int i = 0; i < num; i++)
    {
        result += array_a[i] * array_b[i];
    }

    std::cout.precision(7);
    std::cout << std::fixed << result << '\n';

    delete[] array_a;
    delete[] array_b;
    return 0;
}
