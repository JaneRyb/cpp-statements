#include <iostream>


void comparing(int argc, char* argv[])
{

    char* start_1 = argv[1];
    char* start_2 = argv[2];
    bool sign = false;

    if ((* start_1 == '-') && (* start_2 != '-'))
    {
        std::cout << "less";
        return;
    }
    else if ((* start_2 == '-') && (* start_1 != '-'))
    {
        std::cout << "greater";
        return;
    }

    if ((* start_1 == '-') && (* start_2 == '-'))
    {
        sign = true;        
    }

    if ((* start_1 == '+') || (* start_1 == '-'))
    {
        start_1++;
    }

    if ((* start_2 == '+') || (* start_2 == '-'))
    {
        start_2++;
    }

    int len1 = 0;
    while ((start_1[len1] != '\0') && (start_1[len1] != '.')) 
    {
        len1++;
    }

    int len2 = 0;
    while ((start_2[len2] != '\0') && (start_2[len2] != '.'))
    {
        len2++;
    }

    size_t prov = 0;

    if (len1 > len2)
    {
        prov = 1;
    }
    else if (len1 < len2)
    {
        prov = 2;
    }
    else
    {
        while ((* start_1 != '\0') || (* start_2 != '\0'))
        {
            char el_1 = * start_1;
            if (*start_1 == '.' || *start_1 == '\0')
            {
                el_1 = '0';
            } 
            
            char el_2 = * start_2;
            if (*start_2 == '.' || *start_2 == '\0')
            {
                el_2 = '0';
            } 

            if (el_1 == el_2)
            {
                if (* start_1 != '\0')
                {
                    start_1++;
                }
                
                if (* start_2 != '\0')
                {
                    start_2++;
                }
            }
            else if (el_1 > el_2)
            {
                prov = 1;
                break;
            }
            else if (el_1 < el_2)
            {
                prov = 2;
                break;
            }    
        }
    }

    
    if (sign)
    {
        if (prov == 1)
        {
            prov = 2;
        }
        else if (prov == 2)
        {
            prov = 1;
        }
    }

    switch (prov)
    {
    case 0:
        std::cout << "equal";
        break;
    case 1:
        std::cout << "greater";
        break;
    case 2:
        std::cout << "less";
        break;
    }
}


int main(int argc, char* argv[])
{
    comparing(argc, argv);
    return 0;
}
