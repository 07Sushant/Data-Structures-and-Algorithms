#include <iostream>
using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;

    int children_tickets = 50;  
    int adult_tickets = X + children_tickets;
    int senior_tickets = 2 * children_tickets;

    cout << "Number of children tickets sold: " << children_tickets << endl;
    cout << "Number of adult tickets sold: " << adult_tickets << endl;
    cout << "Number of senior tickets sold: " << senior_tickets << endl;

    return 0;
}
