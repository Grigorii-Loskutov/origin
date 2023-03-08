#pragma once
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>

#include <iostream>
#include <exception>

struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }
    //добавил функцию получения значения головы списка
    int get_head() {
        return m_head->next->value;
    }
    //добавил функцию получения значения хвоста списка
    int get_tail() {
        return m_tail->prev->value;
    }
private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};

TEST_CASE("test List", "") {
    List test_var = List();
    CHECK(test_var.Empty() == true);
    test_var.PushFront(13);
    test_var.PushFront(10);
    test_var.PushBack(14);
    std::cout << test_var.get_head();
    std::cout << test_var.get_tail();
    CHECK(test_var.get_head() == 10);
    CHECK(test_var.get_tail() == 14);
    CHECK(test_var.Size() == 3);
    test_var.PopBack();
    CHECK(test_var.get_tail() == 13);
    test_var.PushBack(15);
    test_var.PopFront();
    CHECK(test_var.get_head() == 13);
    test_var.PopFront();
    test_var.PopFront();
    try {
        test_var.PopFront();
    }
    catch (const std::exception& ex) {
        std::string except = ex.what();
        CHECK(except == "list is empty");

        //std::cout << ex.what() << std::endl;
    }
    try {
        test_var.PopBack();
    }
    catch (const std::exception& ex) {
        std::string except = ex.what();
        CHECK(except == "list is empty");

        //std::cout << ex.what() << std::endl;
    }

}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}