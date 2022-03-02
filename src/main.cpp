#include <memory>
#include <iostream>

class A
{
public:
    A()
    {
        std::cout << "A c-tor (" << this << ")\n";
    }
    ~A()
    {
        std::cout << "A d-tor (" << this << ")\n";
    }
    A(const A&) = default;
    A& operator=(const A&) = delete;
};

class B
{
public:
    B(const std::shared_ptr<A>& a1, const std::shared_ptr<A>& a2)
        : m_a1(a1), m_a2(a2)
    {
    }

private:
    std::shared_ptr<A> m_a1;
    std::shared_ptr<A> m_a2;
};


int main()
{
    // std::shared_ptr<A> sp1
    auto sp1 = std::make_shared<A>();
    std::cout << "sp1 points to: " << sp1.get() << " ref count: " << sp1.use_count() << '\n';
    auto sp2 = std::make_shared<A>();
    std::cout << "sp2 points to: " << sp2.get() << " ref count: " << sp2.use_count() << '\n';
    // auto sp3 = sp1;
    sp1 = sp2;
    // sp1.reset(sp2.get()); // BAD
    std::cout << "sp1 points to: " << sp1.get() << " ref count: " << sp1.use_count() << '\n';
    std::cout << "sp2 points to: " << sp2.get() << " ref count: " << sp2.use_count() << '\n';
    sp2.reset();
    std::cout << "sp1 points to: " << sp1.get() << " ref count: " << sp1.use_count() << '\n';
    std::cout << "sp2 points to: " << sp2.get() << " ref count: " << sp2.use_count() << '\n';

    auto x1 = std::make_shared<A>();
    auto x2 = std::make_shared<A>();

    auto b1 = std::make_shared<B>(x1, x2);
    x1 = nullptr;
    x2 = nullptr;
    b1.reset();
}
