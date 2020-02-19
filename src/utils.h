#ifndef UTILS_H
#define UTILS_H

#include <stdexcept>
#include <type_traits>

template <typename Integral,
          typename Fake =
          typename std::enable_if<std::is_integral<Integral>::value>::type
          >
unsigned char get_byte(const Integral& value, std::size_t position) {

    std::size_t element_size = sizeof (Integral);
    if(position >= element_size)
        throw std::invalid_argument("wrong position");

    std::size_t shift_size = 8 * ((element_size - 1) - position);
    Integral copy = value >> shift_size;

    return  copy & 0xFF;
}


#endif // UTILS_H
