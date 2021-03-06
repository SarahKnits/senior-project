#include <memory>
#include <stdexcept>

#include "int-linked-list.hpp"

IntLinkedList::Node::Node(int element) : element(element), next(nullptr) {}

std::shared_ptr<IntLinkedList::IntLinkedList::Node>
IntLinkedList::traverse(size_t num_elements) const {
    std::shared_ptr<Node> current (this->head);

    size_t elements_to_go = num_elements;
    if (num_elements > this->size()) {
        throw std::out_of_range("index out of range");
    }

    while (current->next != nullptr) {
        --elements_to_go;
        current = current->next;
    }

    return current;
}

void IntLinkedList::insert(size_t index, int element) {
    auto current = traverse(index);
    current->next = std::make_shared<Node> (element);
    ++num_nodes;
}

int IntLinkedList::remove(size_t index) {
    // Get the element just before
    auto current = traverse(index - 1);

    int value = current->next->element;
    current->next = current->next->next;

    return value;
}

size_t IntLinkedList::size() const {
    return this->num_nodes;
}
