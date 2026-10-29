#include <iostream>

int main(int ac, char **av)
{
    if(ac < 2)
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
    {
        for(int i = 1; i < ac; i++)
        {
            std::string result = std::string(av[i]);
            for (int j = 0; j < (int)result.size(); j++)
            {
                std::cout << (char) std::toupper(result[j]);
            } 
        }
        std::cout << std::endl;
    }
    return(0);
}