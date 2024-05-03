#include <iostream>

template< typename T >
struct List {
public:

  List()=default;
  List(const List & other)=default;
  ~List()=default;

  struct Node;
  void pushBack(T data);
  void pushFront(T data);
  bool empty();
  void print();
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
  while (go != ending)
  {
    std::cout<< go->data<<" ";
    go = go->next;
  }
  std::cout<< ending->data<<"\n";
}


