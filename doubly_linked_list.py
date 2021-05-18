class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.prev = None
        self.next = None


class DoublyLinkedList:
    def __init__(self) -> None:
        self.head = None

    def insert_head(self, data):
        node = Node(data)
        if self.head is None:
            self.head = node
        else:
            node.next = self.head
            self.head.prev = node
            self.head = node

    def insert_tail(self, data):
        node = Node(data)
        temp = self.head
        if temp is None:
            self.head = node
        else:
            while temp.next is not None:
                temp = temp.next
            temp.next = node
            node.prev = temp

    def delete_head(self, data):
        temp = self.head
        if temp is None:
            return
        elif temp.data == data:
            self.head = temp.next
            self.head.prev = None
            temp.next = None
            del temp

    def deleteNode(self, data):
        temp = self.head
        if temp is None:
            return

        if temp.data == data:
            self.delete_head(data)
            return

        while temp.next is not None:
            if temp.data == data:
                temp.prev.next = temp.next
                temp.next.prev = temp.prev
                temp.prev = temp.next = None
                del temp
                return
            temp = temp.next

        if temp.data == data:
            temp.prev.next = None
            del temp

    def printlist(self):
        temp = self.head
        while temp is not None:
            print(temp.data, end="->")
            temp = temp.next
        print("NULL")


dllist = DoublyLinkedList()

for i in range(1, 7):
    dllist.insert_tail(i)

dllist.printlist()
dllist.deleteNode(data=4)
dllist.printlist()
