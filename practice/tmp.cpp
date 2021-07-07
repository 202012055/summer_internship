#include <array>
#include <vector>

#include <iterator>
#include<iostream>

int main()
{
    int c_array[5] = {6,3,5,6,7};
    std::array<int, 5> cpp_array = {};
    std::vector<int> cpp_dynarray(5);

    auto c_array_begin = std::begin(c_array); // = c_array + 0
    std::cout<<*(std::end(c_array)-1)<<std::endl;
    auto c_array_end = std::end(c_array);     // = c_array + 5

    auto cpp_array_begin = std::begin(cpp_array); // = cpp_array.begin()
    auto cpp_array_end = std::end(cpp_array);     // = cpp_array.end()

    auto cpp_dynarray_begin = std::begin(cpp_dynarray); // = cpp_dynarray.begin()
    auto cpp_dynarray_end = std::end(cpp_dynarray);     // = cpp_dynarray.end()
}
