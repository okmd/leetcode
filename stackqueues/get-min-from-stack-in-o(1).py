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


s = SpecialStack()
values = [1, 2, 3, 8, 9, 0, 3]
for v in values:
    s.push(v)
print(s.get_min())
