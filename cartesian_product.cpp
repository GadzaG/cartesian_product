#include <iostream>
#include <vector>


using namespace std;


typedef vector<char>        vectorChar;
typedef vector<vectorChar>  vector2d;


void        print_vector(const vectorChar& arr)
{
    for (auto i = arr.begin(); i < arr.end(); i++)
        cout << *i << " ";
    cout << "\n";
}

void        print_vector(const vector2d& arr)
{
    for (auto i = arr.begin(); i < arr.end(); i++)
        print_vector(*i);
}


size_t      get_size(const vector2d& arr)
{
    size_t counter = 1;

    for (auto i = arr.begin(); i < arr.end(); i++)
        counter *= (*i).size();

    return counter;
}

vector2d    algorithm(const vector2d& arr)
{
    size_t size = get_size(arr);
    vector2d result;

    for (size_t glob = 0; glob < size; glob++)
    {
        vectorChar  temp;
        size_t      сomb_number = 1;
        for (size_t i = 0; i < arr.size(); i++)
        {
            int shift = glob / сomb_number;
            int index = shift % arr[i].size();
            temp.push_back(arr[i][index]);
            сomb_number *= arr[i].size();
        }
        result.push_back(temp);
    }
    return result;
}

int     main()
{
    vector2d arr =
    {
        {'a', 'b', 'c'},
        {'1', '2', '3'},
        {'+', '-', '*'}
    };


    print_vector(algorithm(arr));



    cin.get();
    cin.get();
    return 0;
}
