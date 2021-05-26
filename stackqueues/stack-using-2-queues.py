# Create stack from two queues.
from queue import Queue


def push_costly(operations):
    q1 = Queue(10)
    q2 = Queue(10)
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
    q1 = Queue(10)
    q2 = Queue(10)
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
