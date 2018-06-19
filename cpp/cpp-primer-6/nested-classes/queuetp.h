// queue template with a nested class
#ifndef QUEUETP_H_
#define QUEUETP_H_

template <class Item>
class QueueTP {
 public:
  QueueTP(int qs = Q_SIZE);
  ~QueueTP();

  bool isEmpty() const {
    return items == 0;
  }

  bool isFull() const {
    return items == qsize;
  }

  int QueueCount() const {
    return items;
  }

  bool Enqueue(const Item& item); // add item to end
  bool Dequeue(Item& item); // remove item from front

 private:
  enum {Q_SIZE = 10};

  // Node is nested class definition
  // Node is defined in terms of the generic type Item.
  class Node {
   public:
    Item item;
    Node* next;
    Node(const Item& i): item(i), next(0) {}
  };

  Node* front; // pointer to front of Queue
  Node* rear; // pointer to rear of Queue
  int items; // current number of items in queue
  const int qsize; // maximum number of items in Queue
  QueueTP(const QueueTP& q): qsize(0) {}
  QueueTP& operator= (const QueueTP& q) { return *this;}
};

// QueueTP methods
template <class Item>
QueueTP<Item>::QueueTP(int qs): qsize(qs) {
  front = rear = 0;
  items = 0;
}

template <class Item>
QueueTP<Item>::~QueueTP() {
  Node* temp;

  while (front != 0) { // while queue is not yet empty
    temp = front; // save address of front item
    front = front->next; // reset pointer to next item
    delete temp; // delete former front
  }
}

// Add item to queue
template <class Item>
bool QueueTP<Item>::Enqueue(const Item& item) {
  if (isFull())
    return false;

  Node* add = new Node(item); // create node
  // on failure, new throws std::bad_alloc exception

  items++;
  if (front == 0) // if queue is empty
    front = add; // place item at front
  else
    rear->next = add; // else place at rear

  rear = add; // have rear point to new node
  return true;
}

// place front item into item variable and remove from queue
template <class Item>
bool QueueTP<Item>::Dequeue(Item& item) {
  if (front == 0)
    return false;

  item = front->item; // set item to first item in queue
  items--;

  Node* temp = front; // save location of first item
  front = front->next; // reset front to next item
  delete temp; // delete former first item

  if (items == 0)
    rear = 0;

  return true;
}

#endif /* QUEUETP_H_ */
