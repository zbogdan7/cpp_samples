#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    const int SIZE1 = 10, SIZE2 = 5, SIZE3 = 20;
    int a1[SIZE1] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int a2[SIZE2] = { 4, 5, 6, 7, 8 };
    int a3[SIZE2] = { 4, 5, 6, 11, 15 };
    std::ostream_iterator<int> output(cout, " ");

    cout<<"a1 consists: ";
    std::copy(a1, a1 + SIZE1, output);
    cout<<"\na2 consists: ";
    std::copy(a2, a2 + SIZE2, output);
    cout<<"\na3 consists: ";
    std::copy(a3, a3 + SIZE2, output);

    if(std::includes(a1, a1 + SIZE1, a2, a2 + SIZE2))
        cout<<"\na1 includes a2";
    else
        cout<<"\na1 does not include a2.";

    if(std::includes(a1, a1 + SIZE1, a3, a3 + SIZE2))
        cout<<"\na1 includes a3.";
    else
        cout<<"\na1 does not include a3.";

    int difference[SIZE1];
    int *ptr = std::set_difference(a1, a1 + SIZE1, a2, a2 + SIZE2, difference);
    cout<<"\nset_difference for a1 and a2: ";
    std::copy(difference, ptr, output);

    int intersection[SIZE1];
    ptr = std::set_intersection(a1, a1 + SIZE1, a2, a2 + SIZE2, intersection);
    cout<<"\nset intersection for a1 and a2: ";
    std::copy(intersection, ptr, output);

    int symmetric_difference[SIZE1];
    ptr = std::set_symmetric_difference(a1, a1 + SIZE1, a2, a2 + SIZE2, symmetric_difference);
    cout<<"\nset symmetric difference for a1 and a1: ";
    std::copy(symmetric_difference, ptr, output);

    int unionSet[SIZE3];
    ptr = std::set_union(a1, a1 + SIZE1, a3, a3 + SIZE2, unionSet);
    cout<<"\nset_union for a1 and a3: ";
    std::copy(unionSet, ptr, output);

    cout<<endl;
    return 0;

}
