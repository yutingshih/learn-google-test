#include <cstddef>
#include <memory>
#include <queue>

#include <gtest/gtest.h>

// class to be tested
template<typename E>
class Queue {
private:
    std::queue<E> q;

public:
    Queue() = default;

    void enqueue(const E& elem) { q.push(elem); }
    void enqueue(E&& elem) { q.push(std::move(elem)); }

    std::unique_ptr<E> dequeue() {
        if (q.empty()) return nullptr;
        E value = std::move(q.front());
        q.pop();
        return std::make_unique<E>(std::move(value));
    }

    size_t size() const { return q.size(); }
};

// fixture class
class QueueTest: public testing::Test {
protected:
    Queue<int> q0;
    Queue<int> q1;
    Queue<int> q2;

    QueueTest() {
        q1.enqueue(1);
        q2.enqueue(2);
        q2.enqueue(3);
    }
};

TEST_F(QueueTest, IsEmptyInitially) {
    EXPECT_EQ(q0.size(), 0);
}

TEST_F(QueueTest, DequeueWorks) {
    auto n = q0.dequeue();
    EXPECT_EQ(n, nullptr) << "not NULL";

    n = q1.dequeue();
    ASSERT_NE(n, nullptr) << "is NULL";
    EXPECT_EQ(*n, 1) << "The element popped is not 1";
    EXPECT_EQ(q1.size(), 0) << "Queue q1 is not empty";

    n = q2.dequeue();
    ASSERT_NE(n, nullptr) << "is NULL";
    EXPECT_EQ(*n, 2) << "The element popped is not 2";
    EXPECT_EQ(q2.size(), 1) << "Queue q2 is empty";
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
