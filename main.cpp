#include "Matrix.hpp"
#include "Vector.hpp"

int     main(void) {
    // int tab1[12] = {1,1,2,2,
    //                 1,2,1,2,
    //                 1,2,1,2};
    // std::vector<std::vector<int>>  tab2{ { 1, 2, 3 }, 
    //                      { 4, 5, 6 }, 
    //                      { 7, 8, 9, 4 } };


    // Vector<double> e1(3,{1., 0., 0.});
    // Vector<double> e2(3,{0., 1., 0.});
    // Vector<double> e3(3,{0., 0., 1.});
    // Vector<double> v1(3,{1., 2., 3.});
    // Vector<double> v2(3,{0., 10., -100.});
    // Vector<double> v3;

    // v3 = v1 + v2;

    // std::cout << v1 << v3;

    // std::cout << linear_combinaison<double>({e1,e2,e3}, {10.,-2.,0.5})
    //             << linear_combinaison<double>({v1,v2}, {10.,-2.});

    // std::cout << lerp(0., 1., 0.) << std::endl;
    // std::cout << lerp(0., 1., 1.) << std::endl;
    // std::cout << lerp(0., 1., 0.5) << std::endl;
    // std::cout << lerp(21., 42., 0.3) << std::endl;
    // std::cout << lerp(Vector<float>(2, {2., 1.}), Vector<float>(2, {4., 2.}), 0.3);
    // {2.6}
    // {1.3}
    // std::cout << lerp(Matrix<float>(2, 2, {{2., 1.}, {3., 4.}}), Matrix<float>(2, 2, {{20.,10.}, {30., 40.}}), 0.5);
    // [[11., 5.5]
    // [16.5, 22.]]

    // Vector<float> u(2, {0., 0.});
    // Vector<float> v(2, {1., 1.});
    // std::cout << (u * v) << std::endl;
    // // 0.0
    // u = Vector<float>(2, {1., 1.});
    // v = Vector<float>(2, {1., 1.});
    // std::cout << (u * v) << std::endl;
    // // 2.0
    // u = Vector<float>(2, {-1., 6});
    // v = Vector<float>(2, {3., 2.});
    // std::cout << (u * v) << std::endl;
    // 9.0

    // Vector<float> u(3, {0., 0., 0.});
    // std::cout << u.norm1() << " " << u.norm() << " " << u.normInf() << std::endl;
    // // 0.0, 0.0, 0.0
    // u = Vector<float>(3, {1., 2., 3.});
    // std::cout << u.norm1() << " " << u.norm() << " " << u.normInf() << std::endl;
    // // 6.0, 3.74165738, 3.0
    // u = Vector<float>(2,{-1., -2.});
    // std::cout << u.norm1() << " "  << u.norm() << " " << u.normInf() << std::endl;
    // // 3.0, 2.236067977, 2.0
    // Vector<float>   u(2, {1., 0.});
    // Vector<float>   v(2, {1., 0.});
    // std::cout << angle_cos<float>(u, v) << std::endl;
    // // 1.0
    // u = Vector<float>(2, {1., 0.});
    // v = Vector<float>(2, {0., 1.});
    // std::cout << angle_cos<float>(u, v) << std::endl;
    // // 0.0
    // u = Vector<float>(2, {-1., 1.});
    // v = Vector<float>(2, { 1., -1.});
    // std::cout << angle_cos<float>(u, v) << std::endl;
    // // -1.0
    // u = Vector<float>(2, {2., 1.});
    // v = Vector<float>(2, {4., 2.});
    // std::cout << angle_cos<float>(u, v) << std::endl;
    // // 1.0
    // u = Vector<float>(3 ,{1., 2., 3.});
    // v = Vector<float>(3 ,{4., 5., 6.});
    // std::cout << angle_cos<float>(u, v) << std::endl;
    // // 0.974631846
    // Vector<float> u(3, {0., 0., 1.});
    // Vector<float> v(3, {1., 0., 0.});
    // std::cout << cross_product(u, v);
    // // [0.]
    // // [1.]
    // // [0.]
    // u = Vector<float>(3, {1., 2., 3.});
    // v = Vector<float>(3, {4., 5., 6.});
    // std::cout << cross_product(u, v);
    // // [-3.]
    // // [6.]
    // // [-3.]
    // u = Vector<float>(3, {4., 2., -3.});
    // v = Vector<float>(3, {-2., -5., 16.});
    // std::cout << cross_product(u, v);
    // // [17.]
    // // [-58.]
    // // [-16.]
    // Matrix<float> u(2,2,{
    // {1., 0.},
    // {0., 1.},
    // });
    // Vector<float> v(2,{4., 2.});
    // std::cout << (u * v); 
    // // {4.}
    // // {2.}
    // u = Matrix<float>(2,2,{
    // {2., 0.},
    // {0., 2.},
    // });
    // v = Vector<float>(2,{4., 2.});
    // std::cout << (u * v); 
    // // {8.}
    // // {4.}
    // u = Matrix<float>(2,2,{
    // {2., -2.},
    // {-2., 2.},
    // });
    // v = Vector<float>(2,{4., 2.});
    // std::cout << (u * v); 
    // // {4.}
    // // {-4.}
    // u = Matrix<float>(2,2,{
    // {1., 0.},
    // {0., 1.},
    // });
    // Matrix<float> t(2,2,{
    // {1., 0.},
    // {0., 1.},
    // });
    // std::cout << (u * t); 

    // // {1., 0.}
    // // {0., 1.}
    // u = Matrix<float>(2,2,{
    // {1., 0.},
    // {0., 1.},
    // });
    // t = Matrix<float>(2,2,{
    // {2., 1.},
    // {4., 2.},
    // });
    // std::cout << (u * t);    
    // // {2., 1.}
    // // {4., 2.}
    // u = Matrix<float>(2,2,{
    // {3., -5.},
    // {6., 8.},
    // });
    // t = Matrix<float>(2,2,{
    // {2., 1.},
    // {4., 2.},
    // });
    // std::cout << (u * t); 
    // // {-14., -7.]
    // // {44., 22.]
    // auto u = Matrix<float>(2,2,{
    // {1., 0.},
    // {0., 1.},
    // });
    // std::cout << u.trace() << std::endl;
    // // 2.0
    // u = Matrix<float>(3,3,{
    // {2., -5., 0.},
    // {4., 3., 7.},
    // {-2., 3., 4.},
    // });
    // std::cout << u.trace() << std::endl;
    // // 9.0
    // u = Matrix<float>(3,3,{
    // {-2., -8., 4.},
    // {1., -23., 4.},
    // {0., 6., 4.},
    // });
    // // std::cout << u.trace() << std::endl;
    // std::cout << u.transpose();
    // // -21.0
    // Matrix<float> u(3, 3,{
    // {1., 0., 0.},
    // {0., 1., 0.},
    // {0., 0., 1.},
    // });
    // std::cout << u.fer();
    // // {1.0, 0.0, 0.0}
    // // {0.0, 1.0, 0.0}
    // // {0.0, 0.0, 1.0}
    // u = Matrix<float>(2, 2,{
    // {1., 2.},
    // {3., 4.},
    // });
    // std::cout << u.fer();
    // // {1.0, 0.0}
    // // {0.0, 1.0}
    // u = Matrix<float>(2,2,{
    // {1., 2.},
    // {2., 4.},
    // });
    // std::cout << u.fer();
    // // {1.0, 2.0}
    // // {0.0, 0.0}
    // u = Matrix<float>(3,5,{
    // {8., 5., -2., 4., 28.},
    // {4., 2.5, 20., 4., -4.},
    // {8., 5., 1., 4., 17.},
    // });
    // std::cout << u.fer();
    // {1.0, 0.625, 0.0, 0.0, -12.1666667}
    // {0.0, 0.0, 1.0, 0.0, -3.6666667}
    // {0.0, 0.0, 0.0, 1.0, 29.5 }
    // auto u = Matrix<float>(2,2,{
    // { 1., -1.},
    // {-1., 1.},
    // });
    // std::cout << u.determinant() << std::endl;
    // // 0.0
    // u = Matrix<float>(3,3,{
    // {2., 0., 0.},
    // {0., 2., 0.},
    // {0., 0., 2.},
    // });
    // std::cout << u.determinant() << std::endl;
    // // 8.0
    // u = Matrix<float>(3,3,{
    // {8., 5., -2.},
    // {4., 7., 20.},
    // {7., 6., 1.},
    // });
    // std::cout << u.determinant() << std::endl;
    // // -174.0
    // u = Matrix<float>(4,4,{
    // { 8., 5., -2., 4.},
    // { 4., 2.5, 20., 4.},
    // { 8., 5., 1., 4.},
    // {28., -4., 17., 1.},
    // });
    // std::cout << u.determinant() << std::endl;
    // // 1032
    auto u = Matrix<float>(3,3,{
    {1., 0., 0.},
    {0., 1., 0.},
    {0., 0., 1.},
    });
    std::cout << u.inverse();
    // {1.0, 0.0, 0.0}
    // {0.0, 1.0, 0.0}
    // {0.0, 0.0, 1.0}
    u = Matrix<float>(3,3,{
    {2., 0., 0.},
    {0., 2., 0.},
    {0., 0., 2.},
    });
    std::cout << u.inverse();
    // {0.5, 0.0, 0.0}
    // {0.0, 0.5, 0.0}
    // {0.0, 0.0, 0.5}
    u = Matrix<float>(3,3,{
    {8., 5., -2.},
    {4., 7., 20.},
    {7., 6., 1.},
    });
    
    std::cout << u.inverse();
    // {0.649425287, 0.097701149, -0.655172414}
    // {-0.781609195, -0.126436782, 0.965517241}
    // {0.143678161, 0.074712644, -0.206896552}


    return 1;
}

