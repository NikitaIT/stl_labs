#ifndef LL
#define LL
#include <algorithm>
template< typename T >
class forward_list{
public:
    typedef T value_type;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
private:
    struct Node
    {
        value_type _val;
        Node * _next;
        Node(const value_type &val)
            :_val(val), _next(0)
        {}
    };
    Node * _head;
    size_type _nelems;
public:
    forward_list() throw():_head(0), _nelems(0){}
    bool empty() const throw(){ return size() == 0; }
    size_type size() const throw(){ return _nelems; }
    void push_front(const value_type & val)
    {
        if(empty())
            _head = new Node(val);
        else
        {
            Node *new_node = new Node(val);
            new_node->_next = _head;
            _head = new_node;
        }

        ++_nelems;
    }
    void print(){
        Node * temp = _head;
        for(int i=0;i<_nelems;i++)
        {
            std::cout <<temp->_val << std::endl;
            temp = temp->_next;
        }

    }
    ~forward_list() throw(){ }
};

#endif // LL

