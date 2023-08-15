#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

int main()
{
    int size1, size2;
    std::cin >> size1;
    std::unordered_set<int> array1;

    for (int i = 0; i < size1; i++)
    {
        int num;
        std::cin >> num;
        array1.insert(num); 
    }

    std::cin >> size2;
    std::vector<int> commonElements;

    for (int i = 0; i < size2; i++)
    {
        int num;
        std::cin >> num;
        if (array1.find(num) != array1.end())
        {
            commonElements.push_back(num);
        }
    }

    if (!commonElements.empty())
    {
        std::sort(commonElements.begin(), commonElements.end());

        std::cout << "Common Elements:";
        for (int element : commonElements)
        {
            std::cout << " " << element;
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Common Elements: None" << std::endl;
    }

    return 0;
}