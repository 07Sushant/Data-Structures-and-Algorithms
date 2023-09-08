class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class CircularLinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            self.head.next = self.head
        else:
            temp = self.head
            while temp.next != self.head:
                temp = temp.next
            temp.next = new_node
            new_node.next = self.head

    def delete(self, value):
        if not self.head:
            return

        if self.head.data == value:
            temp = self.head
            while temp.next != self.head:
                temp = temp.next
            if temp == self.head:
                self.head = None
            else:
                self.head = self.head.next
                temp.next = self.head
            return

        current = self.head
        prev = None
        while current.next != self.head:
            if current.data == value:
                break
            prev = current
            current = current.next

        if current.data != value:
            print("Value not found in the linked list!")
            return

        prev.next = current.next

    def display(self):
        if not self.head:
            return

        temp = self.head
        while True:
            print(temp.data, end=" ")
            temp = temp.next
            if temp == self.head:
                break
        print()


if __name__ == "__main__":
    n = int(input())
    elements = list(map(int, input().split()))
    value_to_delete = int(input())

    linked_list = CircularLinkedList()

    for element in elements:
        linked_list.append(element)

    print("Linked list before deletion")
    linked_list.display()
    linked_list.delete(value_to_delete)
    print("Linked list after deletion")
    linked_list.display()
