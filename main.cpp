#include "Matrix.hpp"
#include "Vector.hpp"

int     main(void) {
    // int tab1[12] = {1,1,2,2,
    //                 1,2,1,2,
    //                 1,2,1,2};
    // std::vector<std::vector<int>>  tab2{ { 1, 2, 3 }, 
    //                      { 4, 5, 6 }, 
    //                      { 7, 8, 9, 4 } };


    Vector<double> e1(3,{1., 0., 0.});
    Vector<double> e2(3,{0., 1., 0.});
    Vector<double> e3(3,{0., 0., 1.});
    Vector<double> v1(3,{1., 2., 3.});
    Vector<double> v2(3,{0., 10., -100.});
    Vector<double> v3;

    v3 = v1 + v2;

    std::cout << v1 << v3;

    std::cout << linear_combinaison<double>({e1,e2,e3}, {10.,-2.,0.5})
                << linear_combinaison<double>({v1,v2}, {10.,-2.});

   return 1;
}
