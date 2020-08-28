#include <deque>
#include <iostream>
#include <queue>

using std::cout;
using std::deque;
using std::endl;
using std::queue;

class MaxQueue
{
private:
    queue<int> q;
    deque<int> maxQ;

public:
    MaxQueue()
    {
    }

    int max_value()
    {
        return maxQ.size() ? maxQ.front() : -1;
    }

    void push_back(int value)
    {
        q.push(value);
        while (maxQ.size() && maxQ.back() < value)
        {
            maxQ.pop_back();
        }
        maxQ.push_back(value);
    }

    int pop_front()
    {
        if (q.empty())
            return -1;
        int top = q.front();
        q.pop();
        while (maxQ.size() && maxQ.front() == top)
        {
            maxQ.pop_front();
        }
        return top;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

