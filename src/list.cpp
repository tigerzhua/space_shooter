#include "list.h"

template <class T>
List<T>::List()
	: _head(NULL), _tail(NULL), _length(0){ /* nothing */ }

template <class T>
List<T>::List( const List<T> & other ){
    //TODO
}

template <class T>
List<T> & List<T>::operator=( const List<T> & rhs ){
    //TODO
}

template <class T>
int List<T>::get_size() const{
	return _length;
}

template <class T>
bool List<T>::is_empty() const{
    if ( (_length == 0)&&(_head == NULL)&&(_tail == NULL) )
        return true;

    return false;
}

template <class T>
void List<T>::insertFront( const T & ndata ){
    if(_length == 0){
        _head = new ListNode();
        _head->next = NULL;
        _head->prev = NULL;

        _tail = _head;
    }
    else{
        ListNode * new_head = new ListNode();
        new_head->next = _head;
        new_head->prev = NULL;

        _head->prev = new_head;
        _head = new_head;
    }

    _head->data = ndata;
    _length += 1;
}

template <class T>
void List<T>::insertBack( const T & ndata ){
    if(_length == 0){
        _head = new ListNode();
        _head->next = NULL;
        _head->prev = NULL;

        _tail = _head;
    }
    else{
        ListNode *new_tail = new ListNode();
        new_tail->next = NULL;
        new_tail->prev = _tail;

        _tail->next = new_tail;
        _tail = new_tail;
    }

    _tail->data = ndata;
    _length += 1;
}

