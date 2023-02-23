#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int detectAndRemoveLoop(Node *head)
{
    if (head == nullptr)
        return 0;

    Node *slowPtr = head, *fastPtr = head;
    while (fastPtr != nullptr && fastPtr->next != nullptr)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if (slowPtr == fastPtr)
        {
            // loop detected
            break;
        }
    }

    if (slowPtr != fastPtr)
        return 0;

    // find the start of the loop
    slowPtr = head;
    while (slowPtr != fastPtr)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
    }

    // remove the loop
    Node *loopPtr = fastPtr;
    while (loopPtr->next != fastPtr)
    {
        loopPtr = loopPtr->next;
    }
    loopPtr->next = nullptr;

    return 1;
}

int main()
{
    int N, X;
    cout << "\nEnter your desired [N] value -> ";
    cin >> N;
    cout << "Enter the values for your linked list [separate by space] -> ";
    int value[N];
    for (int i = 0; i < N; i++)
    {
        cin >> value[i];
    }
    cout << "Enter your desired [X] value -> ";
    cin >> X;

    Node *head = nullptr;
    Node *tail = nullptr;
    Node *loopNode = nullptr;
    for (int i = 0; i < N; ++i)
    {
        Node *newNode = new Node;
        newNode->data = value[i];
        newNode->next = nullptr;
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        if (i == X - 1)
        {
            loopNode = newNode;
        }
    }

    if (loopNode != nullptr)
    {
        tail->next = loopNode;
    }

    int result = detectAndRemoveLoop(head);

    if (result == 1)
    {
        cout << "\nOutput: 1" << endl;
        cout << "----------" << endl;
        cout << "Explanation: This is your linked list..." << endl;
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data;
            if (curr->next != nullptr)
            {
                cout << " -> ";
            }
            else
            {
                cout << endl;
            }
            curr = curr->next;
        }
        cout << "     ^    |" << endl;
        cout << "     |____|" << endl;
        cout << "A loop is present. If you remove it successfully, the answer will be 1.\n"
             << endl;
    }
    else
    {
        cout << "\nOutput: 0" << endl;
        cout << "----------" << endl;
        cout << "Explanation: This is your linked list..." << endl;
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data;
            if (curr->next != nullptr)
            {
                cout << " -> ";
            }
            else
            {
                cout << endl;
            }
            curr = curr->next;
        }
        cout << "No loop found in the linked list.\n"
             << endl;
    }

    // deallocate memory
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
