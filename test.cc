#include "./fmt.hpp"
#include <iostream>

struct s
{
    int x;
    char c;
};


int main()
{
    std::cout << fmt::format( "The answer is {}.", 42 ) << std::endl;
    std::cout << fmt::format( "{1}, {0}.", "world", "Hello" ) << std::endl;
    std::cout << fmt::format( "struct {}.", s{12, 'a'} ) << std::endl;

    {
        std::array< int, 5 > arr{ 0, 1, 2, 3, 4 };
        std::cout << fmt::format( "array: {}", arr ) << std::endl;
    }

    return 0;
}
