#ifndef UTILS_H
#define UTILS_H

#include <stdexcept>
#include <type_traits>
#include <sstream>
#include <tuple>

/**
 * @brief Return concrete byte value from integral value
 *
 * @arg value integral value
 * @arg position byte number
 * @return byte value
 */
template <typename Integral>
typename std::enable_if<std::is_integral<Integral>::value, unsigned char>::type
get_byte(const Integral& value, std::size_t position) {

    std::size_t element_size = sizeof (Integral);
    if(position >= element_size)
        throw std::invalid_argument("wrong position");

    std::size_t shift_size = 8 * ((element_size - 1) - position);
    Integral copy = value >> shift_size;

    return  copy & 0xFF;
}

/**
 * @brief Check if all passed types are same
 *
 * @return true if all types are same
 */
template <class ...T>
struct are_same;

template <typename A, typename B, typename... T>
struct are_same<A, B, T...>
{
    static const bool value = std::is_same<A, B>::value && are_same<B, T...>::value;
};

template <class A>
struct are_same<A>
{
    static const bool value = true;
};


/**
 * @brief Recursive convertion std::tuple to IP formatted string
 *
 * @arg tuple
 * @return IP formatted string
 */
template <typename Tuple, std::size_t Index>
struct tuple_to_string {

    static std::string convert(const Tuple& tuple)
    {
        std::stringstream ss;
        ss << tuple_to_string<Tuple, Index-1>::convert(tuple);
        ss << '.';
        ss << std::get<Index-1>(tuple);
        return ss.str();
    }
};

template <typename Tuple>
struct tuple_to_string<Tuple, 1> {

    static std::string convert(const Tuple& tuple)
    {
        std::stringstream ss;
        ss << std::get<0>(tuple);
        return ss.str();
    }
};


#endif // UTILS_H
