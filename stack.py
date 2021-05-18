
class Stack:
    def __init__(self) -> None:
        self.stack_limit = 100
        self.__arr = [None]*self.stack_limit
        self.__top = -1

    def push(self, val):
        if self.__top >= self.stack_limit-1:
            print("Stack Overflow")

        self.__top += 1
        self.__arr[self.__top] = val

    def pop(self):
        if self.__top == -1:
            print("Stack is alredy empty")

        self.__top -= 1

    def empty(self):
        if self.__top == -1:
            return True
        return False

    def top(self):
        if self.__top == -1:
            print("Stack is alredy empty")
            return -1
        return self.__arr[self.__top]


def postfix_evaluation(exp):
    stack = Stack()
    for i in exp:
        if i in ['+', '-', '/', '*']:
            op2 = int(stack.top())
            stack.pop()
            op1 = int(stack.top())
            stack.pop()
            op = None
            if i == '+':
                op = op1 + op2
            elif i == '-':
                op = op1 - op2
            elif i == '*':
                op = op1 * op2
            else:
                op = op1 / op2
            stack.push(op)
        else:
            stack.push(int(i))
    ans = stack.top()
    stack.pop()
    return ans


def prefix_evaluation(exp):
    stack = Stack()
    for i in reversed(exp):
        if i in ['+', '-', '/', '*']:
            op1 = int(stack.top())
            stack.pop()
            op2 = int(stack.top())
            stack.pop()
            op = None
            if i == '+':
                op = op1 + op2
            elif i == '-':
                op = op1 - op2
            elif i == '*':
                op = op1 * op2
            else:
                op = op1 / op2
            stack.push(op)
        else:
            stack.push(int(i))
    ans = stack.top()
    stack.pop()
    return ans


def precedence(op):
    if op == '^':
        return 3
    elif op in ["*", "/"]:
        return 2
    elif op in ["+", "-"]:
        return 1
    else:
        return -1


def infix_postfix(exp):
    stack = Stack()
    ans = ""
    for char in exp:
        if (char >= 'a' and char <= 'z') or (char >= 'A' and char <= 'Z'):
            ans += char
        elif char == '(':
            stack.push(char)
        elif char == ')':
            while (not stack.empty()) and stack.top() != '(':
                ans += stack.top()
                stack.pop()

            if not stack.empty():
                stack.pop()
        else:
            while (not stack.empty()) and precedence(stack.top()) > precedence(char):
                ans += stack.top()
                stack.pop()
            stack.push(char)

    while not stack.empty():
        ans += stack.top()
        stack.pop()

    return ans


def infix_prefix(exp):
    exp = list(reversed(exp))
    for i in range(len(exp)):
        if exp[i] == '(':
            exp[i] = ')'
        elif exp[i] == ')':
            exp[i] = '('
    exp1 = ''.join(exp)
    ans = infix_postfix(exp1)
    ans = ''.join(list(reversed(ans)))
    return ans


def balanced_parathesis(exp):
    st = Stack()
    for char in exp:
        if char in ['[', '(', '{']:
            st.push(char)
        elif char in [']', ')', '}']:
            if char == ']' and (not st.empty()) and st.top() == '[':
                st.pop()
            elif char == ')' and (not st.empty()) and st.top() == '(':
                st.pop()
            elif char == '}' and (not st.empty()) and st.top() == '{':
                st.pop()
            else:
                return False
    if st.empty():
        return True
    return False


def redundant_braces(exp):
    st = Stack()
    for char in exp:
        if char in ['(', '+', '-', '/', '*']:
            st.push(char)
        elif char == ')':
            if st.top() == '(':
                return True
            while st.top() in ['+', '-', '/', '*']:
                st.pop()
            st.pop()
    return False


def stock_span(prices):
    ans = list()
    st = Stack()
    for price in prices:
        days = 1
        while (not st.empty()) and st.top()[0] <= price:
            days += st.top()[1]
            st.pop()
        st.push([price, days])
        ans.append(days)
    return ans


print(stock_span(prices=[100, 80, 60, 70, 60, 75, 85]))
