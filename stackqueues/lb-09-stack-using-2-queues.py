# Create stack from two queues.
from queue import Queue


def push_costly(operations):
    q1 = Queue()
    q2 = Queue()
    for op in operations:
        if op != -1:
            while not q1.empty():
                q2.put(q1.get())
            q1.put(op)
            while not q2.empty():
                q1.put(q2.get())
        else:
            print(f"Popped: {q1.get()}")


def pop_costly(operations):
    q1 = Queue()
    q2 = Queue()
    for op in operations:
        if op != -1:
            q1.put(op)
        else:
            while q1.qsize() > 1:
                q2.put(q1.get())
            print(f"Popped: {q1.get()}")
            while not q2.empty():
                q1.put(q2.get())


operations = [1, 2, 3, -1, 4, 5, -1, -1, -1]
print("Push costly: ")
push_costly(operations)
print("Pop costly: ")
pop_costly(operations)


## ------------- Class -------------------- ##
# pop costly
class Stack:
    def __init__(self) -> None:
        self.q1 = Queue()
        self.q2 = Queue()

    def push(self, val):
        self.q1.put(val)

    def pop(self):
        while self.q1.qsize() > 1:
            self.q2.put(self.q1.get())
        popped = self.q1.get()
        while not self.q2.empty():
            self.q1.put(self.q2.get())
        return popped
    
    def size(self):
        return self.q1.qsize()

print("Uisng class implementation: ")
S = Stack()
for op in operations:
    if op!=-1:
        S.push(op)
    else:
        print(f"Popped: {S.pop()}, size: {S.size()}")