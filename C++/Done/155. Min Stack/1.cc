#include <vector>
using namespace std;

// approach: 2 stacks
// time: O(1)
// space: O(n)

class MinStack {
    int min = 0;
    vector<int> stack; // a stack pushed values
    vector<int> mins; // a stack of min-so-far after every push

public:
    MinStack() {}
    
    void push(int val) {
        stack.emplace_back(val);

        if (mins.size() == 0 || val < mins.back()) mins.emplace_back(val);
        else mins.emplace_back(mins.back());
    }
    
    void pop() {
        stack.pop_back();
        mins.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return mins.back();
    }
};
