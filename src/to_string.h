#ifndef TO_STRING_H
#define TO_STRING_H

#include <string>
#include <iostream>
#include <exception>
#include <type_traits>

template <typename T,
          typename Fake =
          typename std::enable_if<std::is_integral<T>::value>::type
          >
unsigned char get_byte(const T& value, std::size_t position) {

    std::size_t element_size = sizeof (T);
    if(position >= element_size)
        throw std::invalid_argument("wrong position");

    std::size_t shift_size = 8 * ((element_size - 1) - position);
    T copy = value >> shift_size;

    return  copy & 0xFF;
}

template <typename T,
          typename Fake =
          typename std::enable_if<std::is_integral<T>::value>::type
          >
std::string to_string(const T& arg) {

    std::string result;
    std::size_t element_size = sizeof (T);

    for(std::size_t i = 0; i < element_size; ++i) {

        result += std::to_string(get_byte(arg, i));
        if(i < (element_size - 1))
            result.push_back('.');
    }

    std::cout << "result: " << result << std::endl;
    return result;
}

#endif // TO_STRING_H
