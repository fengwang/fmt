#include "./fmt.hpp"
#include <iostream>
#include <vector>
#include <map>

struct s
{
    int x;
    char c;
    int * ptr;
};

int global_int;

struct nest
{
    s a;
    s b;
    s c;
};


int main()
{
    {
        std::cout << fmt::format( "The answer is {}.", 42 ) << std::endl;
        std::cout << fmt::format( "{1}, {0}.", "world", "Hello" ) << std::endl;
        std::cout << fmt::format( "struct {}.", s{12, 'a', &global_int} ) << std::endl;
    }

    {
        std::cout << fmt::format( "The answer is {}.", 42, "reductant argument" ) << std::endl;
        std::cout << fmt::format( "{1}, {0}.", "world", "Hello", "reductant argument" ) << std::endl;

        std::cout << fmt::format( "{1}, {0} --> {3}, {4}, {5}.", "world", "Hello" ) << std::endl;
    }

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
        auto tp = std::make_tuple( 1, 1.01f, '1', 18446744073709551615ULL, s{ 0, 'a', &global_int }, s{1, 'A', nullptr} );
        std::cout << fmt::format( "tuple: {}", tp ) << std::endl;
    }

    {
        nest n{{0, '0', nullptr}, {1, '1', &global_int}, {2, '2', nullptr}};
        std::cout << fmt::format( "nest struct -- {}", n) << std::endl;
    }

    {
        std::optional<int> o0;
        std::optional<int> o1 = 1;
        std::cout << fmt::format( "std::optional -- o0: {}, o1: {}", o0, o1) << std::endl;
    }

    {
        std::any a0;
        std::any a1 = 1;
        std::cout << fmt::format( "std::any -- a0: {}, a1: {}", a0, a1) << std::endl;
    }

    {
        std::shared_ptr<int> o0;
        auto o1 = std::make_shared<int>( 1 );
        std::cout << fmt::format( "std::shared_ptr -- o0: {}, o1: {}", o0, o1) << std::endl;
    }

    {
        std::vector<std::string> arr{ "0", "11", "222", "3333", "44444" };
        std::cout << fmt::format( "vector of strings: {}", arr ) << std::endl;
    }

    return 0;
}
