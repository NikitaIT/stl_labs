#include <iostream>
#include "forward_list.h"
using namespace std;

std::ostream& operator<<(std::ostream& ostr, const forward_list<int>& list)
{
    for (auto &i : list) {
        ostr << " " << i;
    }
    return ostr;
}

int main()
{
    cout << "Hello World!" << endl;
    std::vector<int> vector;
    vector.push_back(300);
    forward_list<int> list,vector_list(vector.begin(),vector.end());
    for(int i=0;i<10;i++)
    {
        list.push_back((int)cin.get());
    }
    char q = '1';
    //list.contains(q);//¦̵̱ ̵̱ ̵̱ ̵̱ ̵̱(̢ ̡͇̅└͇̅┘͇̅ (▤8כ−◦
    int a = 100;
    //list.insert(list.begin(),a);//¦̵̱ ̵̱ ̵̱ ̵̱ ̵̱(̢ ̡͇̅└͇̅┘͇̅ (▤8כ−◦
    cout<<"list.empty(): "<<list.empty()<< endl;
    cout<<"vector.front(): "<<vector.front()<< endl;
    cout<<"list.front(): "<<list.front()<< endl;
    cout<<"list.size(): "<<list.size()<< endl;
    //cout<<list.contains(5)<< endl;//¦̵̱ ̵̱ ̵̱ ̵̱ ̵̱(̢ ̡͇̅└͇̅┘͇̅ (▤8כ−◦
    cout<<"list: "<<list;
    cout<<"vector_list.front(): "<<vector_list.front()<< endl;
    //метод замены на
    forward_list<int>::iterator it = list.begin(), ie = list.end();
        for (int count = 0; it != ie; ++it, count++) {
            std::cout << (char)(*it) << std::endl;
            *it = 1;
            std::cout << (*it) << std::endl;
        }
    return 0;
}

