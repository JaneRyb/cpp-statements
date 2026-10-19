#include <iostream>
#include <charconv>




void comparing(int argc, char* argv[]){

    if (argc < 3)
    {
        std::cerr << "Usage: wordcounter <N>";
        return;
    }

    char* start_1 = argv[1];
    char* end_1 = start_1;

    while (* end_1 != '\0')
    {
        end_1++;
    }

    double number_1 = 0.0;
    std::from_chars(start_1, end_1, number_1);

    char* start_2 = argv[2];
    char* end_2 = start_2;

    while (* end_2 != '\0')
    {
        end_2++;
    }

    double number_2 = 0.0;
    std::from_chars(start_2, end_2, number_2);

    if ((number_1 - number_2) < 1e-10 && (number_1 - number_2) > -1e-10)
    {
        std::cout << "equal";
    }
    else if (number_1 > number_2)
    {
        std::cout << "greater";
    }
    else if (number_1 < number_2)
    {
        std::cout << "less";
    }
}


int main(int argc, char* argv[])
{
    comparing(argc, argv);
    return 0;
}