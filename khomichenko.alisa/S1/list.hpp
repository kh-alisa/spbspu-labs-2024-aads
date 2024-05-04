#include <iostream>


template< typename T >
struct List {
public:

  List():
    size(0),
    head(nullptr),
    ending(nullptr)
  {};
  List(const List & other)=default;
  ~List()=default;

  struct Node;
  void pushBack(T data);
  void pushFront(T data);
  bool empty();
  void print();
  void popFront();
  void clear();
  void swap(List * other);
private:
  size_t size;
  Node * head;
  Node * ending;
};



template <typename T>
struct List<T>::Node {
     T data;
     Node * next;
     Node (T value):
        data(value),
        next(nullptr)
     {}
};

template <typename T>
bool List<T>::empty()
{
  return (head == ending);
}

template <typename T>
void List<T>::pushBack(T data)
{
  Node * pushed = new Node(data);
  if (size>0)
  {
    ending->next = pushed;
  }
  else
  {
    head = pushed;
  }
  ending = pushed;
  size += 1;
}

template <typename T>
void List<T>::pushFront(T data)
{
  Node * pushed = new Node(data);
  if (size>0)
  {
    pushed->next = head;
    head = pushed;
  }
  head = pushed;
  size += 1;
}

template <typename T>
void List<T>::print()
{
  Node * go = head;
  while (go != nullptr)
  {
    std::cout<< go->data<<" ";
    go = go->next;
  }
  std::cout<<"\n";
}

template <typename T>
void List<T>::popFront()
{
  if (head == ending)
  {
    delete head;
    head = nullptr;
    ending = nullptr;
  }
  else
  {
  Node * todel = head;
  head = head->next;
  delete todel;
  }
}

template <typename T>
void List<T>::clear()
{
  while (head != nullptr)
  {
    popFront();
  }
}

template <typename T>
void List<T>::swap(List * other)
{
  if (size ==  other->size)
  {
    std::swap(head, other->head);
    std::swap(ending, other->ending);
  }
  else
  {
    std::cerr<<"error: different size\n";
  }
}
