#ifndef QUICK_SELECT_ALGO_H
#define QUICK_SELECT_ALGO_H

#include <vector>
#include <iostream>
#include <utility>

#include <chrono>
#include <thread>

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
        std::cout << "Less Iterator: " << lessIterator;
        while (list[lessIterator] < list[start] && lessIterator < end)
        {
            lessIterator++;
            std::cout << " " << lessIterator;
        }
        std::cout << '\n';

        std::cout << "Large Iterator: " << largeIterator;
        while (list[largeIterator] > list[start] && largeIterator > start)
        {
            largeIterator--;
            std::cout << " " << largeIterator;
        }
        std::cout << '\n';

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
const Type quickSelect(std::vector<Type> &list, int nthSmallest)
{
    int pivotIndex = 0;
    std::cout << "*******Running quickSelect******\n";
    if (list.size() < nthSmallest || nthSmallest < 1)
    {
        std::cout << "Number of elements are not enough!! or Invalid Input!!"
                  << "\n";
        return -1;
    }

    int prevPivotIndex = pivotIndex;
    int endIndex = list.size() - 1;
    int startIndex = pivotIndex;

    do
    {
        prevPivotIndex = pivotIndex;
        std::cout << "Start Index: " << startIndex << " End Index: " << endIndex << " Pivot Index: " << pivotIndex << '\n';
        pivotIndex = quickSelectOperation(list, startIndex, endIndex);
        if (pivotIndex == prevPivotIndex)
        {
            startIndex = startIndex + 1;
        }
        else if (pivotIndex > (nthSmallest - 1))
        {
            endIndex = pivotIndex;
        }
        else if (pivotIndex < (nthSmallest - 1))
        {
            startIndex = pivotIndex;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    } while (pivotIndex != (nthSmallest - 1));

    return list[pivotIndex];
}

#endif /*QUICK_SELECT_ALGO_H*/