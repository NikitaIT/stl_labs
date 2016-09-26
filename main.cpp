#include <iostream>
#include "forward_list.h"
using namespace std;

typedef forward_list<int> int_fw_list;

std::ostream& operator<<(std::ostream& ostr,const int_fw_list& list)
{
    for (auto &i : list) {
        ostr << " " << i;
    }
    return ostr;
}

int main()
{
    cout << "params!" << endl;
    int a = 100,ielem = 49;
    char q = '1';
    std::vector<int> vector;

    vector.push_back(ielem);

    int_fw_list list,vector_list(vector.begin(),vector.end());

    for(int i=0;i<10;i++)
    {
        list.push_back((int)cin.get());
    }
    //list.contains(q);//¦̵̱ ̵̱ ̵̱ ̵̱ ̵̱(̢ ̡͇̅└͇̅┘͇̅ (▤8כ−◦
    list.insert(ielem,a);
    list.insert_before(ielem,a);
    cout<<"list.empty(): "<<list.empty()<< endl;
    cout<<"vector.front(): "<<vector.front()<< endl;
    cout<<"list.front(): "<<list.front()<< endl;
    cout<<"list.size(): "<<list.size()<< endl;
    //cout<<list.contains(5)<< endl;//¦̵̱ ̵̱ ̵̱ ̵̱ ̵̱(̢ ̡͇̅└͇̅┘͇̅ (▤8כ−◦
    cout<<"list: "<<list;
    cout<<"vector_list.front(): "<<vector_list.front()<< endl;
    //метод замены на
    int_fw_list::iterator it = list.begin(), ie = list.end();
        for (int count = 0; it != ie; ++it, count++) {
            std::cout << (char)(*it) << std::endl;
            *it = 1;
            std::cout << (*it) << std::endl;
        }
    return 0;
}

