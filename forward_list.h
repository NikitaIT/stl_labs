#ifndef FORWARD_LIST
#define FORWARD_LIST

//#include <iterator>
#include <algorithm>
#include <assert.h>

// http://ru.cppreference.com/w/cpp/container/forward_list
/*  forward_list
 *  первый параметр - тип данных
 *  второй параметр - распределитель памяти typename Allocator = std::allocator<T>
 */
template< typename T >
class forward_list{
public:
    typedef T value_type;
    //typedef Allocator allocator_type;
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
        //гавнокод гавнокод гавнокод гавнокод ¦̵̱ ̵̱ ̵̱ ̵̱ ̵̱(̢ ̡͇̅└͇̅┘͇̅ (▤8כ−◦
        void insert_after( value_type val){
            Node * new_node = new Node(val);
            new_node->_next = _next;
            _next = new_node;
        }
        //гавнокод гавнокод гавнокод гавнокод ¦̵̱ ̵̱ ̵̱ ̵̱ ̵̱(̢ ̡͇̅└͇̅┘͇̅ (▤8כ−◦
    };
    Node * _head;
    size_type _nelems;

public:
    //Конструктор по умолчанию
    forward_list() throw():_head(0), _nelems(0){}
    bool empty() const throw(){ return size() == 0; }
    size_type size() const throw(){ return _nelems; }

private:
    Node * last() throw(){
        if(empty()) return 0;
        Node *p = _head;
        while (p->_next)
            p = p->_next;
        return p;
    }
public:
    void push_back(const value_type & val)
    {
        Node *p = last();
        if(!p)
            _head = new Node(val);
        else
            p->_next = new Node(val);
        ++_nelems;
    }
    void clear() throw(){
        while(_head){
            Node *p = _head->_next;
            delete _head;
            _head = p;
        }
        _nelems = 0;
    }
    void swap(forward_list & lst) throw(){
        std::swap(_head, lst._head);
        std::swap(_nelems, lst._nelems);
    }
    void sort();
    ~forward_list() throw(){ clear(); }

    //friend class iterator;
    //Джон Лакош: реализация паттерна Iterator на "интуитивных" операторах.
    class iterator{
        Node * _current;
    public:
        iterator(Node *p) throw():_current(p){}
        bool operator==(const iterator & iter)const throw(){ return _current == iter._current; }
        bool operator!=(const iterator & iter)const throw(){ return !(*this == iter); }
        iterator & operator++(){
            _current = _current->_next;
            return *this;
        }
        iterator operator++(int){
            // RAII(захват ресурса есть инициализация)
            iterator temp(*this);
            operator++();
            return temp;
        }
        value_type & operator*()throw(){ return _current->_val; }
        value_type operator*() const{ return _current->_val; }
        value_type operator->(){ return _current->_val; }
        const value_type operator->() const{ return _current->_val; }
        //гавнокод гавнокод гавнокод гавнокод ¦̵̱ ̵̱ ̵̱ ̵̱ ̵̱(̢ ̡͇̅└͇̅┘͇̅ (▤8כ−◦
        //        Node * getnext(){return _current->_next;}
        //        void setnext(Node next){_current->_next = next;}
        //гавнокод гавнокод гавнокод гавнокод ¦̵̱ ̵̱ ̵̱ ̵̱ ̵̱(̢ ̡͇̅└͇̅┘͇̅ (▤8כ−◦
    };

    typedef const iterator const_iterator;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;

    //    bool contains(const value_type & value) const {
    //            for (const_iterator & b = begin(); b != end(); b++) {
    //                if (*b == value) return true;
    //            }
    //            return false;
    //        }
    //гавнокод гавнокод гавнокод гавнокод ¦̵̱ ̵̱ ̵̱ ̵̱ ̵̱(̢ ̡͇̅└͇̅┘͇̅ (▤8כ−◦
    //    iterator insert(const_iterator pos, const_reference value){
    //        Node *p = new Node(value);
    //        p->_next = pos.getnext();
    //        pos.setnext(p);
    //        ++_nelems;
    //        return pos++;
    //    }
    //гавнокод гавнокод гавнокод гавнокод ¦̵̱ ̵̱ ̵̱ ̵̱ ̵̱(̢ ̡͇̅└͇̅┘͇̅ (▤8כ−◦
        bool insert(reference find_value, const_reference value){
            for (iterator & b = begin(); b != end(); b++) {
                if (*b == find_value) {
                    b.setnext();

                    return true;
                }
            }
            return false;
        }
    //гавнокод гавнокод гавнокод гавнокод ¦̵̱ ̵̱ ̵̱ ̵̱ ̵̱(̢ ̡͇̅└͇̅┘͇̅ (▤8כ−◦
    //    iterator insert_after( const_iterator pos, const_reference value ){
    //        if (pos != end()) pos++;
    //        insert(pos, value);
    //        return pos;
    //    }
    //гавнокод гавнокод гавнокод гавнокод ¦̵̱ ̵̱ ̵̱ ̵̱ ̵̱(̢ ̡͇̅└͇̅┘͇̅ (▤8כ−◦
    //    iterator insert_before( const_iterator pos, const_reference value ){
    //        const_iterator & b = begin();
    //        const_iterator & before_pos;
    //        while ((b != pos)&&(b != end())){
    //            before_pos=b;
    //            b++;
    //        }
    //        insert(before_pos, value);
    //        return pos;
    //    }

    reference front() {
        assert(_head != 0);
        return _head->_val;
    }
    const_reference front() const {
        assert(_head != 0);
        return _head->_val;
    }
    iterator begin() throw(){ return iterator(_head); }
    iterator end() throw(){ return iterator(0); }
    const_iterator begin() const throw(){ return iterator(_head); }
    const_iterator end() const throw(){ return iterator(0); }
    //Конструктор копирования:
    forward_list(const forward_list & lst):_head(0), _nelems(0){
        for(iterator i = lst.begin(); i != lst.end(); ++i)
            push_back(*i);
    }
    //Перегрузка присваивания
    forward_list & operator=(const forward_list & lst){
        forward_list(lst).swap(*this);
        return *this;
    }
public:
    //Конструктор преобразования:
    template<class U>
    forward_list(const forward_list<U> &lst):_head(0), _nelems(0){
        for(typename forward_list<U>::iterator iter = lst.begin(); iter != lst.end(); ++iter)
            push_back(*iter);
    }

    template<class U>
    forward_list & operator=(const forward_list<U> &lst){
        forward_list(lst).swap(*this);
        return *this;
    }

    template<class Iter>
    forward_list(Iter first, Iter last):_head(0), _nelems(0){
        for(;first!=last; ++first)
            push_back(*first);
    }
};

#endif // FORWARD_LIST

