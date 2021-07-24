# `fmt::format` Reinvented
------

#### interface


```cpp
template< typename ... Args >
inline std::string format( std::string const& format_string, Args const& ... args );
```

As is to the `format_string`, this library

+ enables `{}`

```cpp
auto s = fmt::format( "The answer is {}", 42 );
auto s = fmt::format( "{}, {}!", "Hello", "world" );
```

+ enables `{d+}`

```cpp
auto s = fmt::format( "{1}, {0}!", "world", "Hello" );
```

+ ommits additional format indicator

```cpp
auto s= fmt::format( "{1}, {0} --> {3}, {4}, {5}.", "world", "Hello" );
```

This produces `Hello, world --> {3}, {4}, {5}.`

As is to the `args`, this library

+ enables custom class that has `begin` and `end` methods defined:

```cpp
std::vector<int> v{ 1, 2, 3, 4, 5 };
auto s = fmt::format( "{}", v );

std::map<int, std::string> m{ {0, "00"}, {1, "11"}, {2, "22"} };
auto s = fmt::format( "{}", std::make_pair( v, m ) );
```

+ enables type/class that supports `std::to_string( type )` interface

```cpp
auto s = fmt::format( "{}", 1 );
```

+ enables type/class that supports `operator <<`

```cpp
std::complex<int> c{ 1, 2, };
auto s = fmt::format( "{}", c );
```

+ enables `std::pair` and `std::tuple`

```cpp
auto tp = std::make_tuple( 1, '1', 120, std::make_tuple( 1, '1', 12.0 ) );
auto s = fmt::format( "{}", tp );
```

+ enables custom type/class that has a aggravated constructor

```cpp
struct s
{
    int a;
    char ch;
    int* p;
};

int global_int;

auto s = fmt::format( "{}", std::make_tuple( s{1, '1', &global_int}, 1, s{2, '2', nullptr} ) );
```

+ enables some other STL containers such as `std::optional`, `std::any`, `std::shared_ptr`, `std::unique_ptr`.

```cpp
std::shared_ptr<int> o0;
auto o1 = std::make_shared<int>( 1 );
std::cout << fmt::format( "std::shared_ptr -- o0: {}, o1: {}", o0, o1) << std::endl;
```

+ ommits additional arguments

```cpp
auto s = fmt::format( "The answer is {}.", 42, "reductant argument" );
auto s = fmt::format( "{1}, {0}.", "world", "Hello", "reductant argument" );
```

