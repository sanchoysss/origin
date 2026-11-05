#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <stdexcept>
#include <iostream>

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

TEST_CASE("Тестирование функция добавления/удаления эл-тов", "list") {
    List test_list;

    SECTION("Проверка функций PushFront и PopFront") {
        test_list.PushFront(10);
        test_list.PushFront(20);

        REQUIRE(test_list.Size() == 2);

        REQUIRE(test_list.PopFront() ==20);
        REQUIRE(test_list.PopFront() == 10);

        REQUIRE(test_list.Size() == 0);
    }

    SECTION("Проверка функций PushBack и PopBack") {
        test_list.PushBack(100);
        test_list.PushBack(200);

        REQUIRE(test_list.Size() == 2);

        REQUIRE(test_list.PopBack() == 200);
        REQUIRE(test_list.PopBack() == 100);

        REQUIRE(test_list.Size() == 0);
    }

    SECTION("Проверка извлечения из пустого списка (Ожидается ошибок)") {
        REQUIRE_THROWS_AS(test_list.PopFront(), std::runtime_error);
        REQUIRE_THROWS_AS(test_list.PopBack(), std::runtime_error);
    }

    SECTION("Сценарий использования нескольких функций") {
        test_list.PushBack(1);
        test_list.PushFront(2);
        test_list.PushBack(3);
    
        REQUIRE(test_list.Size() == 3);

        REQUIRE(test_list.PopFront() == 2);
        REQUIRE(test_list.PopBack() == 3);

        test_list.PushFront(4);

        REQUIRE(test_list.Size() == 2);
        REQUIRE(test_list.PopBack() == 1);
        REQUIRE(test_list.PopFront() == 4);

        REQUIRE(test_list.Empty() == true);
    }


}