#include <iostream>
#include <memory>
#include <vector>

template<typename T>
class Vector {
public:
    //Vector() {
    //}

    Vector(int n_size) : n_size(n_size) {
        data = std::make_unique<T[]>(n_size);
    }

    T& at(size_t pos) const {
        if (pos >= n_size) {
            throw std::out_of_range("Out of range");
        } else {
            return data[pos];
        }
    }
    T* dataa(size_t pos) const {
        if (pos >= n_size) {
            return nullptr;
        } else {
            return data[pos];
        }
    }

    T& front() const {
        if (n_size == 0) {
            throw std::out_of_range("Out of range");
        }
        return data[0];
    }

    T& back() const {
        if (n_size == 0) {
            throw std::out_of_range("Out of range");
        }
        return data[n_size];
    }

    T size() const noexcept {
        return n_size;
    }

private:
    std::shared_ptr<T[]> data;
    int n_size;
public:
    T& operator[]( size_t pos) const {
        return data[pos];
    }
};

int main() {
    Vector<int> vector(5);
    std::cout << "Size:" << vector.size() << '\n';
    vector[1] = 2;
    vector[2] = 5;
    vector[0] = 9;
    for (int a = 0; a < vector.size(); a++) {
        std::cout << vector[a] << ' ';
        std::cout << vector.at(a) << ' ';
    }
    std::cout << '\n';
    std::cout << "Front: " << vector.front() << '\n';
    std::cout << "Back: " << vector.back() << '\n';




    std::vector<int> test(5);
    std::cout << "Size:" << test.size() << '\n';
    test[1] = 2;
    test[2] = 5;
    test[0] = 9;
    for (int a = 0; a < vector.size(); a++) {
        std::cout << test[a] << ' ';
        std::cout << test.at(a) << ' ';
    }
    std::cout << '\n';
    std::cout << "Front: " << test.front() << '\n';
    std::cout << "Back: " << test.back() << '\n';
    //Vector<int> tako(myObject);
    //tako.printData();

    return 0;
}
