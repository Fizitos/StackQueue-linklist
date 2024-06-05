#include <iostream>
#include <string.h>
using namespace std;

struct Produk {
    int id;
    string name;
    Produk* next;
};


struct Stack {
    Produk* top;
};

void initializeStack(Stack& stack) {
    stack.top = nullptr;
}

bool isEmptyStack(Stack& stack) {
    return stack.top == nullptr;
}

void push(Stack& stack, int id, string name) {
    Produk* newProduk = new Produk;
    newProduk->id = id;
    newProduk->name = name;
    newProduk->next = stack.top;
    stack.top = newProduk;
    cout << "Pushed produk: " << name << " onto stack" << endl;
}

Produk* pop(Stack& stack) {
    if (isEmptyStack(stack)) {
        cout << "Popped stack kosong/empty" << endl;
        return nullptr;
    }
    Produk* poppedProduk = stack.top;
    stack.top = stack.top->next;
    cout << "Popped produk: " << poppedProduk->name << " from stack" << endl;
    return poppedProduk;
}

Produk* peek(Stack& stack) {
    if (isEmptyStack(stack)) {
        cout << "Stack is empty" << endl;
        return nullptr;
    }
    return stack.top;
}


struct Queue {
    Produk* front;
    Produk* rear;
};

void initializeQueue(Queue& queue) {
    queue.front = queue.rear = nullptr;
}

bool isEmptyQueue(Queue& queue) {
    return queue.front == nullptr;
}

void enqueue(Queue& queue, int id, string name) {
    Produk* newProduk = new Produk;
    newProduk->id = id;
    newProduk->name = name;
    newProduk->next = nullptr;
    if (queue.rear == nullptr) {
        queue.front = queue.rear = newProduk;
    } else {
        queue.rear->next = newProduk;
        queue.rear = newProduk;
    }
    cout << "Enqueued produk: " << name << " into queue" << endl;
}

Produk* dequeue(Queue& queue) {
    if (isEmptyQueue(queue)) {
        cout << "Dequeued queue kosong/empty" << endl;
        return nullptr;
    }
    Produk* dequeuedProduk = queue.front;
    queue.front = queue.front->next;
    if (queue.front == nullptr) {
        queue.rear = nullptr;
    }
    cout << "Dequeued produk: " << dequeuedProduk->name << " from queue" << endl;
    return dequeuedProduk;
}

Produk* front(Queue& queue) {
    if (isEmptyQueue(queue)) {
        cout << "Queue kosong" << endl;
        return nullptr;
    }
    return queue.front;
}

int main() {
    // Stack
    Stack stack;
    initializeStack(stack);
    push(stack, 1, "kopikapalaja");
    push(stack, 2, "shampopanto");
    push(stack, 3, "permengodzila");
    Produk* topProduk = peek(stack);
    if (topProduk) {
        cout << "Top produk di stack : " << topProduk->name << endl;
    }
    Produk* temp;
    temp = pop(stack);
    delete temp;
    temp = pop(stack);
    delete temp;
    temp = pop(stack);
    delete temp;
    temp = pop(stack); 
    delete temp;

    // Queue
    Queue queue;
    initializeQueue(queue);
    enqueue(queue, 1, "kopikapalaja");
    enqueue(queue, 2, "shampopanto");
    enqueue(queue, 3, "permengodzila");
    Produk* frontProduk = front(queue);
    if (frontProduk) {
        cout << "Front produk di queue : " << frontProduk->name << endl;
    }
    temp = dequeue(queue);
    delete temp;
    temp = dequeue(queue);
    delete temp;
    temp = dequeue(queue);
    delete temp;
    temp = dequeue(queue);
    delete temp;

    return 0;
}

