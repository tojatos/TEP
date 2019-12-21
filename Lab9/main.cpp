#include <iostream>
#include <sstream>
#include "constants.h"
#include "mscnproblem.h"
#include "mysmartpointer.h"
#include "random.h"
#include "randomsearch.h"

void test()
{
    MscnProblem problem;
    const int testDCount = 2;
    const int testFCount = 1;
    const int testMCount = 3;
    const int testSCount = 4;
    problem.setDCount(testDCount);
    problem.setFCount(testFCount);
    problem.setMCount(testMCount);
    problem.setSCount(testSCount);

    for(int i = 0; i < testDCount; ++i)
        for(int j = 0; j < testFCount; ++j)
            problem.setInCd(i*testDCount+j, i, j);

    for(int i = 0; i < testFCount; ++i)
        for(int j = 0; j < testMCount; ++j)
            problem.setInCf(i*testFCount+j, i, j);

    for(int i = 0; i < testMCount; ++i)
        for(int j = 0; j < testSCount; ++j)
            problem.setInCm(i*testMCount+j, i, j);

    problem.setInPs(4, 3);
    problem.setInPs(2, 0);
    problem.setInUd(1, 1);
    problem.setInUf(9, 0);
    problem.setInSd(1, 1);
    problem.setInSf(9, 0);
    problem.setInSs(4, 0);
    problem.setInSs(6, 1);

    for(int i = 0; i < testDCount; ++i)
        for(int j = 0; j < testFCount; ++j)
          for(int k = 0; k < 2; ++k)
            problem.setInXdminmax(i*testDCount+j+k, i, j, k);

    for(int i = 0; i < testMCount; ++i)
        for(int j = 0; j < testSCount; ++j)
          for(int k = 0; k < 2; ++k)
            problem.setInXmminmax(i*testMCount+j+k, i, j, k);

    problem.save("test.txt");
    std::ifstream file("test.txt");
    MscnProblem test(file);
    test.save("test2.txt");
    MscnProblem test3;
    test3.save("test3.txt");

    int err;
    MySmartPointer<double> solution(new double[6] {5, 6, 4, 5, 3, 2}, true);
    MySmartPointer<double> solution2(new double[17](), true);

//    std::cerr << problem.constraintsSatisfied(solution.get(), 6, err) << '\n';
//    std::cerr << err << '\n';

    std::cerr << problem.constraintsSatisfied(solution2.get(), 17, err) << '\n';
    std::cerr << problem.getQuality(solution2.get(), 17, err) << '\n';
    std::cerr << problem.getMinMaxValues() << '\n';

//    solution2[0] = -1;

//    std::cerr << problem.constraintsSatisfied(solution2.get(), 17, err) << '\n';
//    std::cerr << err << '\n';
}
void randTest()
{
    MscnProblem p;
    p.setDCount(2);
    p.setFCount(1);
    p.setMCount(2);
    p.setSCount(1);
    p.generateInstance(0);
//    p.save("rand.txt");

//    MySmartPointer<double> solution(new double[6] {5, 6, 4, 5, 3, 2}, true);
    double solution[6] {5, 6, 4, 5, 3, 2};
    MySmartPointer<double> solution2(new double[6](), true);
    MySmartPointer<double> solution3(new double[6] {1, 2, 3, 4, 5, 6}, true);
//    MySmartPointer<double> solution4(new double[6] {100, 2, 3, 4, 5, 100}, true);

    int err;
//    std::cerr << p.constraintsSatisfied(solution.get(), 6, err) << '\n';
    std::cerr << p.getQuality(solution, 6, err) << '\n';
//    std::cout << p.getP(solution) << '\n';
//    std::cout << p.getKt(solution) << '\n';
//    std::cout << p.getKu(solution) << '\n';
//    std::cerr << p.constraintsSatisfied(solution2.get(), 6, err) << '\n';
    std::cerr << p.getQuality(solution2.get(), 6, err) << '\n';
    std::cerr << p.getQuality(solution3.get(), 6, err) << '\n';
//    std::cerr << p.getQuality(solution4.get(), 6, err) << '\n';
}
void modtest()
{
    std::ifstream testbla("testbla.txt");
    MscnProblem p(testbla);
    std::cerr << p;
}
void randSearchTest()
{
    MscnProblem p;
    p.setDCount(2);
    p.setFCount(2);
    p.setMCount(2);
    p.setSCount(3);
    p.generateInstance(0);
    p.setDefaultMinMaxValues();
//    std::cout << p << '\n';
    RandomSearch rs(&p);
    Table<double> result = rs.getBestFound();
    int err;
    std::cerr << "Final fitness: " << p.getQuality(*result, result.size(), err) << '\n';
    std::cerr << "Final solution: " << result << '\n';
}
void tableTest()
{
    auto x = Table<int>(4);
    x[0] = 1;
    x[1] = 3;
    x[2] = 3;
    x[3] = 8;
    std::cerr << x;
    Table<int> k = x;
    std::cerr << k;
    k = Table<int>(4);
    std::cerr << k;
    std::cerr << x;
    k[1] = 2;
    std::cerr << k;
}
int main()
{
//    modtest();
//    test();
//    randTest();
    randSearchTest();
//    tableTest();

    return 0;
}
