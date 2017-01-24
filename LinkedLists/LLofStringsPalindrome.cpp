#include <string>
#include <iostream>
using namespace std;
struct Node
{
    std::string data;
    struct Node* next;
};

struct Node* newNode(/*const char* data*/std::string data)
{
    struct Node* node = new Node;
    node->data = data;
    node->next = NULL;
    return node;
}

bool isPalindromUtil(std::string str)
{
    int len = str.length();
    for(int i = 0; i < len; i++)
    {
        if (str[i] != str[len-i-1])
            return false;
    }
    return true;
}

bool isPalindrome(struct Node* head)
{
    std::string str = "";
    while (head != NULL)
    {
        str.append(head->data);
        head = head->next;
    }
    return isPalindromUtil(str);
}

void printLL(struct Node* head)
{
    struct Node* temp = head;
    for(; temp != NULL; temp = temp->next)
        std::cout<<" ->"<<temp->data;
    std::cout<<"[NULL]\n";
    
}

int main()
{
    struct Node* head = newNode("a");
    head->next = newNode("bc");
    head->next->next = newNode("d");
    head->next->next->next = newNode("dcb");
    head->next->next->next->next = newNode("a");

    printLL(head);

    isPalindrome(head) ? std::cout<<"true\n" : std::cout<<"False\n";
    return 0;
}
