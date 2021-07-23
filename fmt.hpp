#ifndef _FMT_HPP_INCLUDED_LASDKADSLKJALKJDSALKJALKJSKLJDSLKJSLKSJALKJDSDLSKJDSLKDJASLDFKSJSALK
#define _FMT_HPP_INCLUDED_LASDKADSLKJALKJDSALKJALKJSKLJDSLKJSLKSJALKJDSDLSKJDSLKDJASLDFKSJSALK

#include <string>
#include <sstream>
#include <regex>
#include <type_traits>
#include <utility>

namespace fmt
{

    namespace
    {
        // stl containers

        template< typename T, std::size_t N >
        std::string to_string( std::array<T, N> const& val )
        {
            return std::string{""}; // TODO
        }

        template< typename T, typename Alloc >
        std::string to_string( std::vector<T, Alloc> const& val )
        {
            return std::string{""}; // TODO
        }

        template< typename T, typename Alloc >
        std::string to_string( std::deque<T, Alloc> const& val )
        {
            return std::string{""}; // TODO
        }

        template< typename T, typename Alloc >
        std::string to_string( std::forward_list<T, Alloc> const& val )
        {
            return std::string{""}; // TODO
        }

        template< typename T, typename Alloc >
        std::string to_string( std::list<T, Alloc> const& val )
        {
            return std::string{""}; // TODO
        }

        template< typename T, typename C, typename Alloc >
        std::string to_string( std::set<T, C, Alloc> const& val )
        {
            return std::string{""}; // TODO
        }

        template< typename T, typename C, typename Alloc >
        std::string to_string( std::multiset<T, C, Alloc> const& val )
        {
            return std::string{""}; // TODO
        }

        template< typename K, typename H, typename T, typename C, typename Alloc >
        std::string to_string( std::unordered_set<K, H, T, C, Alloc> const& val )
        {
            return std::string{""}; // TODO
        }

        template< typename K, typename H, typename T, typename C, typename Alloc >
        std::string to_string( std::unordered_multiset<K, H, T, C, Alloc> const& val )
        {
            return std::string{""}; // TODO
        }

        template< typename K, typename T, typename C, typename Alloc >
        std::string to_string( std::map<K, T, C, Alloc> const& val )
        {
            return std::string{""}; // TODO
        }

        template< typename K, typename T, typename C, typename Alloc >
        std::string to_string( std::multimap<K, T, C, Alloc> const& val )
        {
            return std::string{""}; // TODO
        }

        template< typename K, typename T, typename H, typename C, typename Alloc >
        std::string to_string( std::unordered_map<K, T, H, C, Alloc> const& val )
        {
            return std::string{""}; // TODO
        }

        template< typename K, typename T, typename H, typename C, typename Alloc >
        std::string to_string( std::unordered_multimap<K, T, H, C, Alloc> const& val )
        {
            return std::string{""}; // TODO
        }

        template< typename K, typename C >
        std::string to_string( std::stack<T, C> const& val )
        {
            return std::string{""}; // TODO
        }

        template< typename K, typename C >
        std::string to_string( std::queue<T, C> const& val )
        {
            return std::string{""}; // TODO
        }

        template< typename K, typename C, typename M >
        std::string to_string( std::priority_queue<T, C, M> const& val )
        {
            return std::string{""}; // TODO
        }

        template< typename A, typename B >
        std::string to_string( std::pair<A, B> const& val )
        {
            return std::string{""}; // TODO
        }

        template< typename ... Args >
        std::string to_string( std::tuple<Args...> const& val )
        {
            return std::string{""}; // TODO
        }

        template< typename ... Args >
        std::string to_string( std::variant<Args...> const& val )
        {
            return std::string{""}; // TODO
        }

        template< typename T >
        std::string to_string( std::optional<T> const& val )
        {
            return std::string{""}; // TODO
        }

        inline std::string to_string( std::any const& val )
        {
            return std::string{""}; // TODO
        }

        template< typename T, typename U >
        std::string to_string( std::shared_ptr<T, U> const& val )
        {
            return std::string{""}; // TODO
        }

        template< typename T >
        std::string to_string( std::unique_ptr<T> const& val )
        {
            return std::string{""}; // TODO
        }

        template< std::size_t N >
        std::string to_string( std::bitset<N> const& val )
        {
            return std::string{""}; // TODO
        }

        template< typename T, typename U >
        std::string to_string( std::time_point<T, U> const& val )
        {
            return std::string{""}; // TODO
        }

        template< typename T, typename U >
        std::string to_string( std::duration<T, U> const& val )
        {
            return std::string{""}; // TODO
        }

        // other cases

        // converts to string
        template <typename U>
        std::string cast_to_string( U const& val )
        {
            std::stringstream ss;
            ss << val;
            return ss.str();
        }

        // detects 'std::to_string( val )'
        template< typename T, typename=void >
        struct has_to_string : std::false_type {};

        template< typename T >
        struct has_to_string<T, std::void_t<decltype(std::to_string(std::declval<T>()))>> : std::true_type {};

        template< typename T >
        constexpr inline bool has_to_string_v = has_to_string<T>::value;

        // detects 'operator <<'
        template< typename, typename = void >
        struct has_ostream : std::false_type {};

        template< typename T >
        struct has_ostream < T, std::void_t < decltype(  std::declval<std::ostream&>()  << std::declval<T const&>() ) > > : std::true_type {};

        template< class T >
        inline constexpr bool has_ostream_v = has_ostream<T>::value;


        // other types
        template< typename T >
        std::string to_string( T const& val )
        {
            if constexpr( has_to_string_v<T> )
            {
                return std::to_string( val );
            }
            else if constexpr( has_ostream_v<T> )
            {
                return cast_to_string( val );
            }
            else
            {
                // reflection, then print, TODO
            }
        }

        inline std::string replace_all(std::string const& input, std::string_view what, std::string_view with)
        {
            std::string ans = input;
            for (std::string::size_type pos{}; ans.npos != (pos = ans.find(what.data(), pos, what.length())); pos += with.length())
                ans.replace(pos, what.length(), with.data(), with.length());
            return ans;
        }

        inline std::string replace_once(std::string const& input, std::string_view what, std::string_view with)
        {
            std::string ans = input;
            for (std::string::size_type pos{}; ans.npos != (pos = ans.find(what.data(), pos, what.length())); pos += with.length())
            {
                ans.replace(pos, what.length(), with.data(), with.length());
                break;
            }
            return ans;
        }

        inline std::string indexed_format( unsigned long, std::string const& format_string )
        {
            return format_string;
        }

        template< typename Arg, typename ... Args >
        inline std::string indexed_format( unsigned long index, std::string const& format_string, Arg const& arg, Args const& ... args )
        {
            std::string const& what = std::string{"{"} + std::to_string(index) + std::string{"}"};
            std::string const& with = to_string( arg );
            std::string updated_format_string = replace_all( format_string, what, with );
            return indexed_format( index+1, updated_format_string, args... );
        }

        inline std::string plain_format( std::string const& format_string )
        {
            return format_string;
        }

        template< typename Arg, typename ... Args >
        inline std::string plain_format( std::string const& format_string, Arg const& arg, Args const& ... args )
        {
            std::string const what{ "{}" };
            std::string const& with = to_string( arg );
            std::string updated_format_string = replace_once( format_string, what, with );
            return plain_format( updated_format_string, args... );
        }

    }// anonymous namespace

    template< typename ... Args >
    inline std::string format( std::string const& format_string, Args const& ... args )
    {
        // TODO: fixed cases such as '{{}}}'
        if ( format_string.find( "{}" ) != std::string::npos )
            return plain_format( format_string, args... );

        return indexed_format( 0UL, format_string, args... );
    }

}//namespace fmt

#endif//_FMT_HPP_INCLUDED_LASDKADSLKJALKJDSALKJALKJSKLJDSLKJSLKSJALKJDSDLSKJDSLKDJASLDFKSJSALK

