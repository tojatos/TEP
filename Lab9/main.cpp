#include <iostream>
#include <sstream>
#include "constants.h"
#include "mscnproblem.h"
#include "mysmartpointer.h"

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
            problem.setInEf(i*testFCount+j, i, j);

    for(int i = 0; i < testMCount; ++i)
        for(int j = 0; j < testSCount; ++j)
            problem.setInCm(i*testMCount+j, i, j);

    problem.setInPs(4, 3);
    problem.setInPs(2, 0);
    problem.setInUd(1, 1);
    problem.setInUf(9, 0);

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
    std::cerr << err << '\n';

//    solution2[0] = -1;

//    std::cerr << problem.constraintsSatisfied(solution2.get(), 17, err) << '\n';
//    std::cerr << err << '\n';
}

int main()
{
    test();
    return 0;
}
