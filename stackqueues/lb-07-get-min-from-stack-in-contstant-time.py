INT_MAX = 100


class Stack:
    def __init__(self) -> None:
        self.values = []

    def push(self, val):
        self.values.append(val)

    def pop(self):
        return self.values.pop()

    def size(self):
        return len(self.values)

    def top(self):
        return self.values[-1]

    def show(self):
        print("Stack: ")
        for i in self.values:
            print(i, end=" ")
        print()

# O(1) time and O(n) space


class SpecialStack:
    def __init__(self) -> None:
        self.stack = Stack()
        self.minstack = Stack()

    def push(self, val):
        self.stack.push(val)
        top = INT_MAX
        if self.minstack.size() > 0:
            top = self.minstack.top()
        self.minstack.push(min(val, top))

    def pop(self):
        self.stack.pop()
        self.minstack.pop()

    def get_min(self):
        return self.minstack.top()

    def show(self):
        self.stack.show()


# O(1) time and O(1) stack
class SpecialStackOptimized:
    def __init__(self) -> None:
        self.stack = Stack()
        self.min = 0

    def push(self, val):
        if self.stack.size() == 0:
            self.stack.push(val)
            self.min = val
        elif self.min <= val:
            self.stack.push(val)
        else:
            self.stack.push(2*val - self.min)
            self.min = val

    def pop(self):
        if self.stack.size() == 0:
            return -1

        popped = self.stack.pop()
        if self.min > popped:
            self.min = 2*self.min - popped
        return popped

    def get_min(self):
        return self.min

    def show(self):
        self.stack.show()


# Running coe
values = [22, 3, 8, 9, 55, 1, 3, 12]
s = SpecialStack()
so = SpecialStackOptimized()
for v in values:
    s.push(v)
    so.push(v)

s.show()
so.show()

s.pop()
s.pop()
so.pop()
so.pop()

print(s.get_min())
print(so.get_min())
s.show()
so.show()
