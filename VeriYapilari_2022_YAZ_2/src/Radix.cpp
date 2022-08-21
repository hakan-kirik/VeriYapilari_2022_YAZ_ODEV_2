

#include "Radix.hpp"


int Radix::MaxStepNumber() {
    int max = 0;
    for (int i = 0; i < length; i++) {
        if (StepCount(numbers[i]) > max) max = StepCount(numbers[i]);
    }
    return max;
}

int Radix::StepCount(int number) {
    number = abs(number);
    int basamak = 0;
    if (number == 0)basamak = 1;
    while (number > 0) {
        basamak++;
        number /= 10;
    }
    return basamak;
}

Radix::Radix(Queue *queue) {
    int index = 0;
    this->numbers = new int[queue->count()];
    this->length = queue->count();
    while (!queue->isEmpty()) {
        int number = queue->peek();

        numbers[index] = number;
        queue->dequeue();
        index++;
    }

    queues = new Queue*[10];
    for (int j = 0; j < 10; j++) {
        queues[j] = new Queue();
    }
    maxStep = MaxStepNumber();
}

Queue* Radix::Sort() {
    int numberIndex = 0;
    // read from array once and add to queues
    for (; numberIndex < length; numberIndex++) {
        int stepValue = numbers[numberIndex] % 10;
        int num = numbers[numberIndex];
        queues[stepValue]->enqueue(num);
    }

    //i starting from 1 because of first digit processed
    for (int i = 1; i < maxStep; i++) {
        int arr[10];
        for (int i = 0; i < 10; i++) {
            arr[i] = queues[i]->count();
        }
        for (int index = 0; index < 10; index++) {
            int len = arr[index];
            for (; len > 0; len--) {
                int number = queues[index]->peek();
                queues[index]->dequeue();
                int stepValue = (number / intPow(10, i)) % 10;
                queues[stepValue]->enqueue(number);

            }
        }
    }
    Queue* ordered = new Queue();
    numberIndex = 0;
    for (int index = 0; index < 10; index++) {
        while (!queues[index]->isEmpty()) {
            int number = queues[index]->peek();
            ordered->enqueue(number);
            queues[index]->dequeue();
        }
    }

    return ordered;
}
Radix::intPow(int val, int pow) {

    if (pow <= 0)
        return 1;
    return val * intPow(val, pow - 1);

}

Radix::~Radix() {
    delete [] numbers;
    for (int i = 0; i < 10; i++) delete queues[i];
    delete [] queues;
}
