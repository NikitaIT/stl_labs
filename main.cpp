#include <iostream>
#include "forward_list.h"
#include "lisst.h"
#include <list>
#include "cqueue.h"
//#include "treenode.h"
using namespace std;

typedef forward_list<int> int_fw_list;
typedef llist::list<int> int_my_list;

std::ostream& operator<<(std::ostream& ostr,const int_fw_list& list)
{
    for (auto &i : list) {
        ostr << " " << i;
    }
    return ostr;
}

int main()
{
    cout << endl<< "LAB_NOMBER = -1 go end";
    int LAB_NOMBER(0);
    while(LAB_NOMBER!=(-1))
    {
        cout << endl<< "in: LAB_NOMBER = ";
        cin >>LAB_NOMBER;
        switch (LAB_NOMBER) {
        case 1:
        {
            cout << endl<< "LAB1!" << endl;
            int a = 200,ielem = 49,N;
            char q = '1';
            std::vector<int> vector;

            vector.push_back(ielem);

            forward_list<int> list_;
            cout<< endl<< "in: size = ";
            cin >> N;
            cout<< endl<< "in: char_val[" << N << "] = ";
            for(int i=0;i<N;i++)
            {
                list_.push_front((int)cin.get());
                list_.console_log();
            }
            list_.console_log();

            int_fw_list list,vector_list(vector.begin(),vector.end());
            cout<< endl<< "in: char_val[" << N << "] = ";
            for(int i=0;i<N;i++)
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
//            int_fw_list::iterator it = list.begin(), ie = list.end();
//            for (int count = 0; it != ie; ++it, count++) {
//                std::cout << (char)(*it) << std::endl;
//                *it = 1;
//                std::cout << (*it) << std::endl;
//            }
        }
            break;
        case 2:
        {
            cout << endl<< "LAB2!" << endl;
            int_my_list my_list;
            int Nmy_list;
            cout<< "in: size = ";
            cin >> Nmy_list;
            cout<< endl << "in: char_val[" << Nmy_list << "] = "<< endl;;
            for(int i=0;i<Nmy_list;i++)
            {
                int q;
                cin>>q;
                my_list.push_back(q);
                //my_list.console_log();
            }
            cout<< endl<< "out: NORMAL = ";
            my_list.console_log();
            cout<< endl<< "out: REVERSE = ";
            my_list.console_log_r();
            int DEL_NOMBER(0);
            cout<< "in: DEL_NOMBER = ";
            cin>>DEL_NOMBER;
            cout<< endl<< "out: is_del = "<<my_list.del(DEL_NOMBER);
            cout<< endl<< "out: NORMAL = ";
            my_list.console_log();
            cout<< endl<< "out: REVERSE = ";
            my_list.console_log_r();
        }
            break;
        case 3:
        {
            cout << endl<< "LAB3!" << endl;
            int Nc_queue,Enqueue,Nec_queue;
            cout<< "in: size = ";
            cin >> Nc_queue;
            cout<< "in: sizeofin = ";
            cin >> Nec_queue;
            CQueue c_queue(Nc_queue);
            cout<< endl<< "in: char_val[" << Nec_queue << "] = ";
            for(int i=0;i<Nec_queue;i++)
            {
                int w;
                cin>>w;
                c_queue.Enqueue(w);
            }
            cout<< "in: Enqueue = ";
            cin >> Enqueue;
            c_queue.Enqueue(Enqueue);
            cout<< endl<< "out:  Dnqueue = "<< c_queue.Dnqueue();
            cout<< endl<< "out:  Dnqueue = ";
            while(!c_queue.isEmpty())
            {
            cout<< " "<< c_queue.Dnqueue();
            }
            cout<< endl<< "out:  isEmpty = "<< c_queue.isEmpty();
        }
            break;
        case 4:
        {
            cout << endl<< "LAB4!" << endl;
//            struct tnode *root;

//              char word[MAXWORD];
//              root = NULL;
//              cout<< "WORDS = 0 go end"<< endl;
//              cout<< "in: WORDS = ";
//              do {
//                inf *info;
//                scanf("%s",word);
//                info->Fam = word;
//                cout << endl<< "out:  info->Fam = "<<info->Fam;
//                cout << endl<< "out:  word = "<<word;
//                if(word[0])
//                  root = addtree(root, info);
//              }while(word[0]!='0');    // условие выхода – ввод символа ‘0’
//              cout << endl<< "out:  treeprint = "<< endl;
//              treeprint(root);
//              cout << endl<< "out:  treeprint_POSTFIX(LPK) = ";
//              treeprint_POSTFIX(root);
//              cout << endl<< "out:  treeprint_INFIX(LKP) = ";
//              treeprint_INFIX(root);
//              cout << endl<< "out:  treeprint_PREFIX(KLP) = ";
//              treeprint_PREFIX(root);
//              if(find(root,"q")) {
//              cout <<endl<< "out:  find = "<<find(root,"q")->pers->Fam;
//              }else {
//                cout <<endl<< "out:  find = null";
//              }
//              cout << endl;
//              freemem(root);
//              getchar();
//              getchar();

        }
            break;
        default:
            cout << endl<< "netu" << endl;
            break;
        }
    }

    return 0;
}

