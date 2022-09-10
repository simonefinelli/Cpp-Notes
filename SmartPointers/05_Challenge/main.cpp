// Section 17
// Challenge

#include <iostream>
#include <memory>
#include <vector>

class Test {
private:
    int data;
public:
    Test()
        : data{0} {
        std::cout << "Test constructor (" << data << ")" << std::endl;
    }
    Test(int data)
        : data {data} {
        std::cout << "Test constructor (" << data << ")" << std::endl;
    }
    int get_data() const {
        return data;
    }
    ~Test() {
        std::cout << "Test destructor (" << data << ")" << std::endl;
    }
};

// function prototypes
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();  // we could transform in auto make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>>&vec);

int main() {
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {  // we could transform in auto make();
    using namespace std;
    return make_unique<vector<shared_ptr<Test>>>();;
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num) {
    using namespace std;

    int n;
    for (int i = 1; i <= num; i++) {
        cout << "Enter data point [" << i << "]: ";
        cin >> n;

        // // first approach
        // auto t = make_shared<Test>(n);
        // vec.push_back(t);

        // second approach - take advantage of the move semantic
        vec.push_back(make_shared<Test>(n));  // that is going to create the r-value (the address)
    }
}

void display(const std::vector<std::shared_ptr<Test>> &vec) {
    using namespace std;

    cout << "\nDisplaying vector data" << endl;
    cout << "=========================" << endl;
    for (const auto &e : vec)
        cout << e->get_data() << endl;
    cout << "=========================" << endl;
}