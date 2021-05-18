from os import system


class Node:
    def __init__(self, data: int):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def length(self):
        temp = self.head
        if temp is None:
            return 0
        else:
            count = 0
            while temp is not None:
                count += 1
                temp = temp.next
            return count

    def insert_at_head(self, data):
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
        else:
            newNode.next = self.head
            self.head = newNode

    def append(self, data):
        if self.head is None:
            self.insert_at_head(data)
            return

        newNode = Node(data)
        temp = self.head
        while temp.next is not None:
            temp = temp.next
        temp.next = newNode

    def deleteNode(self, key):
        temp = self.head
        if temp is None:
            return

        if temp is not None:
            if temp.data == key:
                self.head = temp.next
                temp.next = None
                del temp
                return

        prev = temp
        temp = temp.next
        while temp is not None:
            if temp.data == key:
                break
            prev = prev.next
            temp = temp.next

        if temp is None:
            return

        prev.next = temp.next
        del temp
        return

    def search(self, key):
        temp = self.head
        while temp is not None:
            if temp.data == key:
                return (True, temp)
            temp = temp.next
        return (False, None)

    def reverse(self):
        prev = None
        curr = self.head

        while curr is not None:
            next = curr.next
            curr.next = prev

            prev = curr
            curr = next

        self.head = prev

    def reversek(self, head, k):
        if head is None:
            return None

        currentptr = head
        nextptr = None
        prevptr = None
        count = 0

        while currentptr is not None and count < k:
            nextptr = currentptr.next
            currentptr.next = prevptr
            prevptr = currentptr
            currentptr = nextptr
            count += 1

        if nextptr is not None:
            head.next = self.reversek(nextptr, k)

        return prevptr

    def make_cycle(self, k):
        temp = self.head
        count = 0

        while count < k:
            temp = temp.next
            count += 1

        other = temp.next

        while other.next is not None:
            other = other.next

        other.next = temp

    def cycle_detect(self):
        fast = slow = self.head

        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next

            if fast == slow:
                return True

        return False

    def remove_cycle(self):
        fast = slow = self.head
        flag = False
        while not flag:
            slow = slow.next
            fast = fast.next.next

            if slow == fast:
                flag = True

        fast = self.head

        while fast.next != slow.next:
            slow = slow.next
            fast = fast.next

        slow.next = None

    def appendk(self, k):
        temp = self.head
        size = self.length()

        newHead = newTail = None
        temp = self.head
        k = k % size
        count = 1
        while temp.next is not None:
            if count == size - k:
                newTail = temp
            if count == size - k + 1:
                newHead = temp
            temp = temp.next
            count += 1

        temp.next = self.head
        self.head = newHead
        newTail.next = None

    def intersect(self, other, pos):
        temp1 = self.head
        temp2 = other.head
        while pos > 0:
            temp1 = temp1.next
            pos -= 1

        while temp2.next is not None:
            temp2 = temp2.next

        temp2.next = temp1

    def intersection(self, other):
        size1 = self.length()
        size2 = other.length()

        ptr1 = ptr2 = None

        if size1 > size2:
            d = size1 - size2
            ptr1 = self.head
            ptr2 = other.head
        else:
            d = size2 - size1
            ptr1 = other.head
            ptr2 = self.head

        while d > 0:
            ptr1 = ptr1.next
            if ptr1 is None:
                return -1
            d -= 1

        while ptr1 is not None and ptr2 is not None:

            if ptr1 == ptr2:
                return ptr1.data
            ptr1 = ptr1.next
            ptr2 = ptr2.next

        return -1

    def merge2list(self, other):
        pass

    def even_after_odd(self):
        odd = self.head
        even = self.head.next
        evenStart = even

        while odd.next is not None and even.next is not None:
            odd.next = even.next
            odd = odd.next
            even.next = odd.next
            even = even.next

        odd.next = evenStart

    def printlist(self):
        temp = self.head
        while temp is not None:
            print(temp.data, end='->')
            temp = temp.next
        print('NULL')

    def __repr__(self):
        temp = self.head
        ans = ""
        while temp is not None:
            ans += str(temp.data) + '->'
            temp = temp.next
        ans += 'NULL'
        return ans


system('cls')

llist = LinkedList()

for i in range(1, 7):
    llist.append(i)

print(llist)
llist.even_after_odd()
print(llist)
