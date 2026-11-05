#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <stdexcept>

struct ListNode {
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next) {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }
    int value;
    ListNode* prev;
    ListNode* next;
};

class List {
public:
    List() : m_head(new ListNode(0)), m_size(0), m_tail(new ListNode(0, m_head)) {}
    virtual ~List() { Clear(); delete m_head; delete m_tail; }

    bool Empty() { return m_size == 0; }
    unsigned long Size() { return m_size; }

    void PushFront(int value) { new ListNode(value, m_head, m_head->next); ++m_size; }
    void PushBack(int value) { new ListNode(value, m_tail->prev, m_tail); ++m_size; }

    int PopFront() {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack() {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear() {
        auto current = m_head->next;
        while (current != m_tail) {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node) {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};


TEST_CASE("Тестирование базовых функций", "[list]") {
    List test_list;

    SECTION("Новый список должен быть пустым") {
        REQUIRE(test_list.Empty() == true);
        REQUIRE(test_list.Size() == 0);
    }

    SECTION("При добавлении элементов должен изменяться размер") {
        test_list.PushBack(10);
        test_list.PushFront(20);
        REQUIRE(test_list.Empty() == false);
        REQUIRE(test_list.Size() == 2);
    }

    SECTION("Clear должен полностью очищать список") {
        test_list.PushBack(5);
        test_list.Clear();
        REQUIRE(test_list.Empty() == true);
        REQUIRE(test_list.Size() == 0);
    }
}
