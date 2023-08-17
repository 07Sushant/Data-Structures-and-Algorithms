#include <iostream>
#include <vector>
int main()
{
    int n;
    std::cin>>n;
    
    std::vector<double> closingPrices(n);
    for (int i = 0; i < n; ++i)
    {
        std:: cin>> closingPrices[i];
    }
    
    std::cout<<"Updated Array with Positive Closing Prices:";
    for(int i=0; i<n; ++i)
    {
        if(closingPrices[i] > 0)
        {
            std::cout<< " "<<closingPrices[i];
        }
    }std::cout<<std::endl;
    return 0;
}
