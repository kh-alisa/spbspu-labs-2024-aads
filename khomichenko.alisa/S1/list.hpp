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

  class Iterator;
  class ConstIterator;

  Iterator begin() const;
  Iterator end() const;
  ConstIterator cbegin() const;
  ConstIterator cend();

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

template <typename T>
class List<T>::ConstIterator : public std::iterator<std::forward_iterator_tag, T>
{
public:
  friend class List<T>;

  ConstIterator();
  ConstIterator(Node * ptr);
  ConstIterator(const ConstIterator&) = default;
  ~ConstIterator() = default;

  ConstIterator& operator=(const ConstIterator&) = default;
  ConstIterator& operator++();
  ConstIterator operator++(int);

  const T& operator*() const;
  const T* operator->() const;

  bool operator!=(const ConstIterator& list) const;
  bool operator==(const ConstIterator& list) const;

private:
  Node * node;
};

template <typename T>
List<T>::ConstIterator::ConstIterator():
  Node(nullptr)
{}

template <typename T>
List<T>::ConstIterator(Node * ptr):
  Node(ptr)
{}

template <typename T>
typename List<T>::ConstIterator& List<T>::ConstIterator::operator++()
{
  assert(node != nullptr);
  node = node->next;
  return * this;
}

template <typename T>
typename List<T>::ConstIterator& List<T>::ConstIterator::operator++(int)
{
  assert(node != nullptr)
  ConstIterator result (*this);
  ++(*this);
  return result;
}

template <typename T>
T& List<T>::ConstIterator::operator*()
{
  assert (iterator != nullptr);
  return iterator.node->data;
}

template <typename T>
T* List<T>::ConstIterator::operator->()
{
  assert(iterator != nullptr);
  return std::addressof(iterator.node->data);
}

template <typename T>
bool List<T>::ConstIterator::operator==(const Iterator& list) const
{
  return iterator == list.iterator;
}

template <typename T>
bool List<T>::ConstIterator::operator!=(const Iterator& list) const
{
  return !(iterator == list.iterator);
}
