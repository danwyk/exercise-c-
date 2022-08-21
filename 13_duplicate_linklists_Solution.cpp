#include <vector>
#include <string>
#include <iostream>

using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
    public:
        int value;
        LinkedList *next = nullptr;

        LinkedList(int value) { this->value = value; }
        // ~LinkedList(){}
        
};

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList) {
    
    // O(n) Time
    // O(1) Space
    assert(linkedList != nullptr);
    LinkedList *current_node = linkedList;

    while(current_node->next) {

        if(current_node->value == current_node->next->value) {
            current_node->next = current_node->next->next;
            continue;
        }

        current_node = current_node->next;

    } // while

    return linkedList;
} // removeDuplicatesFromLinkedList



int main() {
    // 1 -> 1 -> 1 -> 3 -> 4 -> 4 -> 4 -> 5 -> 6 -> 6
    LinkedList *one = new LinkedList(1);
    LinkedList *one_2 = new LinkedList(1);
    LinkedList *one_3 = new LinkedList(1);

    LinkedList *two = new LinkedList(3);

    LinkedList *three = new LinkedList(4);
    LinkedList *three_2 = new LinkedList(4);
    LinkedList *three_3 = new LinkedList(4);

    LinkedList *four = new LinkedList(5);

    LinkedList *five = new LinkedList(6);
    LinkedList *five_2 = new LinkedList(6);

    one->next = one_2;
    one_2->next = one_3;
    one_3->next = two;
    two->next = three;
    three->next = three_2;
    three_2->next = three_3;
    three_3->next = four;
    four->next = five;
    five->next = five_2;

    LinkedList *new_link_list = removeDuplicatesFromLinkedList(one);
    // LinkedList *new_link_list = one;

    while(new_link_list->next) {
        cout << new_link_list->value << " ";
        new_link_list = new_link_list->next;
    }



} // main
