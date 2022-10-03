#include "Matrix.hpp"
#include <vector>

int     main(void) {
    // int tab1[12] = {1,1,2,2,
    //                 1,2,1,2,
    //                 1,2,1,2};
    // std::vector<std::vector<int>>  tab2{ { 1, 2, 3 }, 
    //                      { 4, 5, 6 }, 
    //                      { 7, 8, 9, 4 } };


    Matrix<int> m2(3,2,{
                        {1,2},
                        {1,2},
                        {1,2}});
//     Matrix<int> m2(3, 4, tab1);
    
//     Matrix<int> m3(tab2);

//     m1.display();
    m2.display();
//     m3.display();

    (void)m2;
    return 1; 
}
