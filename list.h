#ifndef _LIST_H_
#define _LIST_H_

#include <cstddef>

template <class T>
class List
{
    private:

        class ListNode
        {
            public:
                ListNode();
                ListNode( const T & ndata );
                ~ListNode();
                ListNode * next;
                ListNode * prev;
                const T data;
        };

    public:

        List();
        List( const List<T> & other );
        List<T> & operator=( const List<T> & rhs );

        ~List();

        int get_size() const;
        bool is_empty() const;

        void insertFront( const T & ndata );
        void insertBack( const T & ndata );
        void sort();

    private:

        ListNode * _head;
        ListNode * _tail;
        int _length;

        void copy( const List<T> & other );
        void clear();
};

#endif
