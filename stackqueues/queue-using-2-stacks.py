class stack:
    def __init__(self):
        self.values = []

    def push(self, val):
        self.values.append(val)

    def size(self):
        return len(self.values)

    def isEmpty(self):
        return self.size() == 0

    def pop(self):
        return self.values.pop()

# Enqueue costly.


def enqueue_costly(operations):
    stack1 = stack()
    stack2 = stack()
    # for each elemets
    for op in operations:
        if op != -1:
            while not stack1.isEmpty():
                stack2.push(stack1.pop())

            stack1.push(op)

            while not stack2.isEmpty():
                stack1.push(stack2.pop())
        else:
            print(f"Popped: {stack1.pop()}")

# Dequeue costly.


def dequeue_costly(operations):
    stack1 = stack()
    stack2 = stack()
    # for each elemets
    for op in operations:
        if op != -1:
            stack1.push(op)
        else:
            while stack1.size() > 1:
                stack2.push(stack1.pop())

            print(f"Popped: {stack1.pop()}")

            while not stack2.isEmpty():
                stack1.push(stack2.pop())


# -1 means -> dequeue
# +ve value means enqueue
operations = [1, 2, 3, -1, -1]
print("Enqueue costly method: ")
enqueue_costly(operations)
print("Dequeue costly method: ")
dequeue_costly(operations)
