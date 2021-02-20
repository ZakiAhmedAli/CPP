// template-function.cpp by Bill Weinman <http://bw.org/>
// updated 2020-07-21
#include <iostream>

template <typename T>
T sum ( T a, T b ) {
    return ( a + b);
}

int main() {
    std::cout << sum<int>( 7, 9 ) << std::endl;
    return 0;
}
