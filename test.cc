#include "./fmt.hpp"
#include <iostream>
#include <vector>
#include <map>

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

    {
        std::vector<int> arr{ 0, 1,  };
        std::cout << fmt::format( "vector: {}", arr ) << std::endl;
    }

    {
        std::map<int, std::string> arr{ {0, "0"}, {1, "1"}, {2, "2"}, {3, "3"}  };
        std::cout << fmt::format( "map: {}", arr ) << std::endl;
    }

    {
        auto tp = std::make_tuple( 1, 1.01f, '1', 18446744073709551615ULL, s{ 0, 'a' }, s{1, 'A'} );
        std::cout << fmt::format( "tuple: {}", tp ) << std::endl;
    }

    return 0;
}
