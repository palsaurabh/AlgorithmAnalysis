#ifndef QUICK_SELECT_ALGO_H
#define QUICK_SELECT_ALGO_H

#include <vector>
#include <iostream>
#include <utility>

template <typename Type>
int quickSelectOperation(std::vector<Type> &list, int start, int end)
{
    if (start >= end)
    {
        return -1;
    }
    /*Take start as pivot*/
    int lessIterator = start + 1;
    int largeIterator = end;

    for (auto &element : list)
    {
        std::cout << element << ' ';
    }
    std::cout << '\n';

    do
    {
        std::cout<<"Less Iterator: "<< lessIterator;
        while (list[lessIterator] < list[start] && lessIterator < end)
        {
            lessIterator++;
            std::cout<<" "<<lessIterator;
        }
        std::cout<<'\n';

        std::cout<<"Large Iterator: "<< largeIterator;
        while (list[largeIterator] > list[start] && largeIterator > start)
        {
            largeIterator--;
            std::cout<<" "<<largeIterator;
        }
        std::cout<<'\n';

        if (largeIterator > lessIterator)
        {
            std::swap(list[largeIterator], list[lessIterator]);
        }
        else
        {
            std::swap(list[start], list[largeIterator]);
            break;
        }

        for (auto &element : list)
        {
            std::cout << element << ' ';
        }
        std::cout << '\n';
    } while (true);

    for (auto &element : list)
    {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    return (largeIterator);
}

template <typename Type>
const Type quickSelect(std::vector<Type> &list, int nthLargest)
{
    int pivotIndex = 0;
    if (list.size() < nthLargest)
    {
        std::cout << "Number of elements are not enough!!"
                  << "\n";
        return -1;
    }

    pivotIndex = quickSelectOperation(list, pivotIndex, list.size() - 1);
    while(pivotIndex != (nthLargest - 1))
    {
        if(pivotIndex > (nthLargest - 1))
            pivotIndex = quickSelectOperation(list, 0, pivotIndex);
        else
            pivotIndex = quickSelectOperation(list, pivotIndex, list.size() - 1);
    }

    return list[pivotIndex];
}

#endif /*QUICK_SELECT_ALGO_H*/