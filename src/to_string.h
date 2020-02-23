#ifndef TO_STRING_H
#define TO_STRING_H

#include "utils.h"


#include <string>
#include <sstream>
#include <type_traits>
#include <tuple>

template <typename Integral>
typename std::enable_if<std::is_integral<Integral>::value, std::string>::type
to_string(const Integral& arg) {

    std::string result;
    std::size_t element_size = sizeof (Integral);

    for(std::size_t i = 0; i < element_size; ++i) {

        result += std::to_string(get_byte(arg, i));
        if(i < (element_size - 1))
            result.push_back('.');
    }

    return result;
}

template <typename Container>
decltype (
        std::begin(std::declval<Container>()),
        std::end(std::declval<Container>()),
        std::string()
        ) to_string(const Container& arg) {

    std::stringstream ss;
    std::size_t index = 0;
    for(const auto& elem : arg) {
        ss << elem;
        if(index++ < (arg.size() - 1))
            ss << '.';
    }

    return ss.str();
}

std::string to_string(const std::string& arg) {
    return arg;
}

template <typename ... Args>
typename std::enable_if<are_same<Args...>::value, std::string>::type
to_string(const std::tuple<Args...> arg)
{
    return tuple_to_string<std::tuple<Args...>,
            sizeof... (Args)>::convert(arg);
}



#endif // TO_STRING_H
