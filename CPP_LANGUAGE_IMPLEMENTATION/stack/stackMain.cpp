#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // 定义栈的最大容量

class Stack {
private:
    int top; // 标记当前栈顶元素下标
    int data[MAX_SIZE]; // 存放栈的数据

public:
    Stack() { // 构造函数，初始化栈顶为 -1
        top = -1;
    }

    bool isEmpty() { // 判断栈是否为空
        return top == -1;
    }

    bool isFull() { // 判断栈是否已满
        return top == MAX_SIZE - 1;
    }

    void push(int item) { // 将元素压入栈中
        if (isFull()) { // 如果栈已满，则无法入栈
            cout << "Stack Overflow!" << endl;
            return;
        }
        data[++top] = item; // 否则将元素加入到栈顶
    }

    int pop() { // 弹出栈顶元素
        if (isEmpty()) { // 如果栈为空，则无法弹出元素
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return data[top--]; // 返回栈顶元素，并将栈顶指针减1
    }

    int peek() { // 返回栈顶元素
        if (isEmpty()) { // 如果栈为空，则返回-1
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return data[top];
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "栈顶元素为：" << stack.peek() << endl; // 输出 30

    stack.pop();

    cout << "栈顶元素为：" << stack.peek() << endl; // 输出 20

    return 0;
}