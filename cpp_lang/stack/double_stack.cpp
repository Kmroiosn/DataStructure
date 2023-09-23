#include <iostream>

/// @brief Bidirectional stack: a data structure in which a stack is arranged at each end of the same array.
///        双向栈，在同一个数组中两端分别布置一个栈的数据结构
/// @author Kmroiosn
/// @tparam Ty Data type
/// @tparam _MaxCount Length for array
template <typename Ty, int _MaxCount>
struct double_stack {
    enum { Left, Right };

    int top[2], bot[2];

    Ty* v; // The array where stack is arranged at each end of it.

    double_stack() : v(new Ty[_MaxCount])
    {   // Initialization
        top[Left] = -1;
        bot[Left] = -1;

        top[Right] = _MaxCount;
        bot[Right] = _MaxCount;
    }

    ~double_stack()
    {   // Destructor, free stack memory
        delete[] v;
    }

    // return bool: is left end stack empty
    bool left_empty() {
        return top[Left] == bot[Left];
    }

    // return bool: is right end stack empty
    bool right_empty() {
        return top[Right] == bot[Right];
    }

    int left_count() const noexcept {
        return top[Left] - bot[Left];
    }

    int right_count() const noexcept {
        return bot[Right] - top[Right];
    }

    bool full() const noexcept {
        return left_count() + right_count() == _MaxCount;
    }

    void lpush(const Ty& item) {
        if (full()) {
            std::cout << "Stack is full! Ignoring data push!" << std::endl;
        }
        else {
            v[++top[Left]] = item;
        }
    }

    void rpush(const Ty& item) {
        if (full()) {
            std::cout << "Stack is full! Ignoring data push!" << std::endl;
        }
        else {
            v[--top[Right]] = item;
        }
    }

    Ty ltop() const noexcept {
        return v[top[Left]];
    }

    Ty rtop() const noexcept {
        return v[top[Right]];
    }

    void lpop() noexcept {
        top[Left] = left_empty() ? top[Left] : top[Left] - 1;
    }

    void rpop() noexcept {
        top[Right] = right_empty() ? top[Right] : top[Right] + 1;
    }
};

template <typename ... Args>
void print(Args&&... args) {
    (std::cout << ... << args) << std::endl;
}

int main() {
    double_stack<int, 5> dbs;

    print("Is left stack empty: ", std::boolalpha, dbs.left_empty());
    print("Is right stack empty: ", std::boolalpha, dbs.right_empty());

    print("Add data:");

    dbs.lpush(5);
    dbs.lpush(7);

    dbs.rpush(10);
    dbs.rpush(1);
    dbs.rpush(3);

    print("Is stack full: ", std::boolalpha, dbs.full());

    print("Popping data:");

    while (true) {
        if (dbs.left_empty()) break;
        print("Left stack top: ", dbs.ltop());
        dbs.lpop();
    }

    while (true) {
        if (dbs.right_empty()) break;
        print("Right stack top: ", dbs.rtop());
        dbs.rpop();
    }

    print("Is left stack empty: ", std::boolalpha, dbs.left_empty());
    print("Is right stack empty: ", std::boolalpha, dbs.right_empty());
}