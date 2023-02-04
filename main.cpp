#include <iostream>
#include <experimental/random>
typedef double some_type; // int can be switch on something that isn't bool

using std::cout;
using std::endl;

int main() {
    const int N = 1000; //scalable to limits of int what is reasonably big
    some_type in_data[N];
    for (int i = 0; i < N;++i) in_data[i] = std::experimental::randint(32, 126); //numbers are good to convert into char

    some_type out_data[N] {0};
    short size = sizeof(some_type);

    int small_n = N/(8/size);
    short remainder = N%(8/size);

    double * in_point = (double*)in_data;
    double * out_point = (double*)out_data;

    for(int i = 0;i < small_n;i++){
        *out_point++ = *in_point++;
    }
    for(int i = remainder; i > 0;i--){
        out_data[N-remainder] = in_data[N-remainder];
    }

    for (some_type t : in_data)
    {
        cout << t << ' ';
    }
    cout << endl << endl;
    for (some_type t : out_data)
    {
        cout << t << ' ';
    }
}
