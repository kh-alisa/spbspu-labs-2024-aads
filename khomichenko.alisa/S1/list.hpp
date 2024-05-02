#include <iostream>

template< typename T >
struct List {
public:

  List();
  List(const List & other);
  ~List();

  void pushBack(T data);
  bool empty();

private:
  size_t size;
  struct Node;
  Node * head;
  Node * ending;
};

template <typename U>
struct List<U>::Node {
     U data;
     Node * next;
     Node (U data, Node * next = nullptr);
};

template <typename T>
bool List<T>::empty()
{
  return (head == ending);
}

template <typename T>
void List<T>::pushBack(T data)
{
  List<T>::Node * pushed = new List<T>::Node(data);
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

