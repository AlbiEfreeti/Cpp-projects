#include <iostream>
#include <string>
#include <type_traits>

template <typename T, typename T1>  std::string addition(T wert1, T1 wert2)
{

    double calculation;
    std::string calc1;
    if constexpr ((std::is_same<T, int>::value || std::is_same<T, double>::value) &&
        (std::is_same<T1, int>::value || std::is_same<T1, double>::value) && !(std::is_same<T, std::string>::value && std::is_same<T1, std::string>::value)) {
            std::cout << "Es wurde int Werte oder Double Werte eingegeben." << std::endl;
            calculation = wert1 + wert2;
            calc1= std::to_string(calculation);
            return calc1;
        }
    if constexpr (std::is_same<T, std::string>::value && std::is_same<T1, std::string>::value)
    {
        std::cout <<"Es wurden Strings eingegeben. Diese werden aneinandergeknuepft." <<'\n';
        std::string result = (wert1 + wert2);
        return result;
    }
    //now if there is one String and one double/int
    if constexpr (std::is_same<T, std::string>::value && ((std::is_same<T1, int>::value) || (std::is_same<T1, double>::value)))
    {
        std::string convert = std::to_string(wert2);
        calc1 = wert1 + wert2;
        return calc1;
    }
    if constexpr (std::is_same<T1, std::string>::value && ((std::is_same<T, int>::value) || (std::is_same<T, double>::value)))
    {
        std::string convert = std::to_string(wert1);
        calc1 = convert + wert2;
        return calc1;
    }
}

int main()
{
    //Beispielmain(weil ich hunger habe dieses Beispiel)
    std::string erster =  "Abend";
    std::string zweiter = "essen";
    std::cout << addition(erster, zweiter) << '\n';
    int dritter = 4;
    std::string vierter = "Kaese";
    std::cout << addition(dritter, vierter) << '\n';
    double fuenfter = 2.7;
    int sechster = 3;
    std::cout << addition(fuenfter, sechster) << '\n';
    double siebter = 3.67;
    double achter = 4.89;
    std::cout << addition(siebter, achter) << '\n';

}

