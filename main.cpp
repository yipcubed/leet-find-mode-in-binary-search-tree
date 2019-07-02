#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    void DFS(TreeNode* r, map<int,int>& seen) {
        if (!r) return;
        ++seen[r->val];
        DFS(r->left, seen);
        DFS(r->right, seen);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        if (!root) return v;
        map<int,int> seen;
        DFS(root, seen);
        int mx = INT_MIN;
        for (const auto& p : seen) {
            if (p.second > mx) mx = p.second;
        }
        for (const auto& p : seen) {
            if (p.second == mx) v.push_back(p.first);
        }
        return v;
    }
};

void test1() {
    vector<int> v1{1, -1, 2, -1, -1, 2};
    TreeNode *t1 = new TreeNode(v1, -1);
    cout << "2 ? " << Solution().findMode(t1) << endl;
}

void test2() {

}

void test3() {

}