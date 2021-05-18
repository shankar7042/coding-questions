# Using List
class Queue:
    def __init__(self):
        self.__queue_limit = 100
        self.__arr = [None]*self.queue_limit
        self.__front = self.__back = -1

    def push(self, val):
        if self.__back == self.__queue_limit - 1:
            print("Queue Overflow")
            return

        self.__back += 1
        self.__arr[self.__back] = val

        if self.__front == -1:
            self.__front += 1

    def pop(self):
        if self.__front == -1 or self.__front > self.__back:
            print("No elements in the queue")
            return

        self.__front += 1

    def peek(self):
        if self.__front == -1 or self.__front > self.__back:
            print("No elements in the queue")
            return

        return self.__arr[self.__front]

    def empty(self):
        if self.__front == -1 or self.__front > self.__back:
            return True
        return False


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class QueueLList:
    def __init__(self) -> None:
        self.front = None
        self.back = None

    def push(self, val):
        newNode = Node(val)

        if self.front is None:
            self.front = newNode
            self.back = newNode
            return

        self.back.next = newNode
        self.back = newNode

    def pop(self):
        if self.front is None:
            print("Queue is empty")
            return

        temp = self.front
        self.front = self.front.next

        del temp

    def peek(self):
        if self.front is None:
            print("Queue is empty")
            return

        return self.front.data

    def empty(self):
        if self.front is None:
            return True
        return False


q = QueueLList()
q.push(1)
q.push(2)
q.push(3)
q.push(4)

print(q.peek())
q.pop()

print(q.peek())
q.pop()

print(q.peek())
q.pop()


print(q.peek())
q.pop()

print(q.empty())
