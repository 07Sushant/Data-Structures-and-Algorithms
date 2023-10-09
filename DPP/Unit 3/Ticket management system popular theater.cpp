#include <iostream>
#define max 5

int insertq(int queue[max], int& rear, int data)
{
    if (rear == max - 1)
    return 0;
    else
    {
        rear++;
        queue[rear] = data;
        return 1;
    }
}

int delq(int queue[max], int& front, int& rear, int& data)
{
    if (front == rear)
    {
        data = -1; 
        return 0; 
    }
    else
    {
        front++;
        data = queue[front];
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
        return 1; 
    }
}

void display(int queue[max], int front, int rear)
{
    if (front == rear)
    {
        std::cout << "Queue is empty." << std::endl;
    }
    else
    {
        std::cout << "Elements in the queue are: ";
        for (int i = front + 1; i <= rear; i++)
        {
            std::cout << queue[i] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
int queue[max], data;
int front, rear, reply, option;
front = rear = -1;

while (1)
{
    if (!(std::cin >> option))
        break;

    switch (option)
    {
        case 1:
            if (!(std::cin >> data))
                break;

            reply = insertq(queue, rear, data);
            if (reply == 0)
                std::cout << "Queue is full." << std::endl;
            else
                std::cout << data << " is inserted in the queue." << std::endl;
            break;

        case 2:
            reply = delq(queue, front, rear, data);
            if (reply == 0)
            {
                std::cout << "Queue is empty." << std::endl;
            }
            else
            {
                std::cout << "Deleted number is: " << data << std::endl;
            }
            break;

        case 3:
            display(queue, front, rear);
            break;

        default:
            std::cout << "Invalid option." << std::endl;
            break;
    }
}

return 0;
}