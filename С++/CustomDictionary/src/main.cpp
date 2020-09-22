#include <list>
#include <iostream>

/**
*Test dicitionary key class
*
*Value can only be assigned on construction
*
*Has overloaded comparrison and stream output operators
*/
class A {
private:
    int num;
public:
    A(int number) : num(number) {}
    bool operator== (const A& other) const {
        return num == other.num;
    }
    friend std::ostream& operator<< (std::ostream& out, const A& a) {
        return out << a.num;
    }
};

/**
*Test dicitionary value class
*
*May have different type from key class and only needs stream output operator
*/
class B {
private:
    char symb;
public:
    B(char symbol) : symb(symbol) {}
    friend std::ostream& operator<< (std::ostream& out, const B& b) {
        return out << b.symb;
    }
};

/**Exception class*/
template <class TKey>
class MyException {
private:
    TKey key;
public:
    /*May only recieve key on constructor*/
    MyException(const TKey& key) : key(key) {}

    /*Returns held key*/
    const TKey& GetKey() const noexcept {
        return key;
    }
};

/**Dictionary class*/
template <class TKey, class TValue>
class MyDict {
private:
    /**
    *Dictionary container
    *
    *Uses STL list container as base
    *
    *Uses std::pair of two classes as elements
    */
    std::list <std::pair<TKey, TValue>> dictionary;
public:
    MyDict() = default;

    /**Init constructor*/
    MyDict(const TKey& key, const TValue& value) {
        dictionary.push_back(std::make_pair(key, value));
    }

    ~MyDict() = default;

    /**Go through list and check if can find matching key*/
    bool IsSet(const TKey& key) const {
        for (const auto& member : dictionary)
            if (member.first == key)
                return true;
        return false;
    }

    /**
     * Go through list and check for matching key
     * If matching key found, replace value by new one
     * If not found, push new pair of key and value to back of the list
     */
    void Set(const TKey& key, const TValue& value) {
        for (auto& member : dictionary)
            if (member.first == key) {
                member.second = value;
                return;
            }
        dictionary.push_back(std::make_pair(key, value));
    }

    /**
     * Go through list and check for matching key
     * If matching key found, return it's paired value
     * If not, throw exception
     */
    const TValue& Get(const TKey& key) const {
        for (const auto& member : dictionary)
            if (member.first == key)
                return member.second;
        throw MyException<TKey>(key);
    }

    /**
     * Go through list and print pairs of keys and values. 
     * Requires template classes to have an overloaded stream output operator
     */
    void Print() {
        for (const auto& member : dictionary)
            std::cout << member.first << " : " << member.second << std::endl;
    }
};

int main() {
    //Init dictionary
    MyDict<A, B> dict;

    //Fill dictionary with elements
    unsigned elementsAmount = 10;
    for (unsigned i = 0; i < elementsAmount; i++)
        dict.Set(i * 10, i + 'A');

    //Output dictionary contents
    std::cout << "Initialized dictionary:" << std::endl;
    dict.Print();

    //Different functionality tests
    std::cout << std::endl << "Get element with key 40: " << dict.Get(40) << std::endl;
    std::cout << "Check if dictionary has element with key 100: " << dict.IsSet(100) << std::endl;
    std::cout << "Check if dictionary has element with key 30: " << dict.IsSet(30) << std::endl;
    std::cout << "Set element with key 150 and value 'B'" << std::endl;
    dict.Set(150, 'B');
    std::cout << "Check if dictionary has element with key 150: " << dict.IsSet(150) << std::endl;
    std::cout << "Get element with key 150: " << dict.Get(150) << std::endl;
    try {
        std::cout << "Try to get element with key 378:" << std::endl;
        std::cout << dict.Get(378) << std::endl;
    }
    catch (MyException <A>& except) {
        std::cerr << "Couldn't find dictionary element with matching key: " << except.GetKey() << std::endl;
    }

    return 0;
}