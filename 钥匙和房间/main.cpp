#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution
{
public:
    int visitCount = 0;
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<bool> vis(n, false);
        visitCount = 0;
        deepFirstSearch(rooms, 0, vis);
        return visitCount == n;
    }

    void deepFirstSearch(vector<vector<int>> &rooms, int index, vector<bool> &vis)
    {
        vis[index] = true;
        visitCount++;
        for (auto key : rooms[index])
        {
            if (!vis[key])
                deepFirstSearch(rooms, key, vis);
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> rooms{{1}, {2}, {3}, {}};

    cout << s.canVisitAllRooms(rooms) << endl;
    return 0;
}
