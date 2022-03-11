# Implement stack using only single queue

# front -> begining -> insertion-> push
# back  -> end      -> deletion -> pop
# keep on push and top from front
# to pop -> dequeue n-1 elements and remove nth element and enqueue n-1 back to Q.
def stack_1_queue(ops):
    q = []
    for i in ops:
        if i > 0:
            q.insert(0, i)
        elif i == -2:
            print(q[0])
        elif i == -1:
            # dequeue and enqueue n-1
            n = len(q)
            while n > 1:
                n -= 1
                q.insert(0, q.pop())
            print(q.pop())


class Stack:
    def __init__(self):
        self.q = []

    def size(self):
        return len(self.q)

    def empty(self):
        return self.size() == 0

    def push(self, val):
        self.q.insert(0, val)

    def top(self):
        return self.q[0]

    def pop(self):
        n = self.size()
        while n > 1:
            n -= 1
            self.push(self.q.pop())
        return self.q.pop()


if __name__ == "__main__":
    # -1 -> pop
    # -2 -> top
    operations = [1, 2, 3, -1, 4, -1, -2]
    stack_1_queue(operations)

    # stack
    print("STACK:CLASS")
    s = Stack()
    for i in operations:
        if i == -1:
            print(s.pop())
        elif i == -2:
            print(s.top())
        else:
            s.push(i)
