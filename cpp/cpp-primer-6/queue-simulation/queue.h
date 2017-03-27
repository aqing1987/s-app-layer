// queue.h -- interface for a queue
// A queue is an abstract data type (ADT) that holds an ordered sequence of
// items. New items are added to the rear of the queue, and items can be removed
// from the front. the queue is a FIFO (first in, first out) structure.
#ifndef QUEUE_H_
#define QUEUE_H_

// This queue will contain Customer items
class Customer {
private:
  long arrive; // arrival time for customer
  int processtime; // processing time for customer

public:
  Customer() {
    arrive = processtime = 0;
  }
  void set(long when);
  long when() const {
    return arrive;
  }
  int ptime() const {
    return processtime;
  }
};

typedef Customer Item;

class Queue {
private:
  // class scope definitions
  // Node is a nested structure definition local to this class
  struct Node {
    Item item; // data stored in the node
    struct Node *next; // pointer to next node
  };
  enum {
    Q_SIZE = 10,
  };

  // private class members
  Node *front; // pointer to front of Queue
  Node *rear; // pointer to rear of Queue
  int items; // current number of itmes in Queue
  const int qsize; // maximum number of items in Queue

  // preemptive definition to prevent public copying
  // This has two effects.
  // First, it overrides the default method definitions that otherwise would
  // be generated automatically.
  // Second, because these methods are private, they can't be used by the world
  // at large. That is, if nip and tuck are Queue objects, the compiler won't
  // allow the following:
  // Queue snick(nip); // not allowed
  // tuck = nip; // not allowed
  // Therefore, instead of being faced with mysterious runtime malfunctions in
  // the future, you'll get an easier-to-trace compiler error, stating that
  // these methods aren't accessible.
  Queue(const Queue &q) : qsize(0) {}
  Queue & operator=(const Queue &q) {
    return *this;
  }

public:
  Queue(int qs = Q_SIZE); // create queue with a qs limit
  ~Queue();
  bool isempty() const;
  bool isfull() const;
  int queuecount() const;
  bool enqueue(const Item &item); // add item to end
  bool dequeue(Item &item); // remove item from front
};

#endif /* QUEUE_H_ */