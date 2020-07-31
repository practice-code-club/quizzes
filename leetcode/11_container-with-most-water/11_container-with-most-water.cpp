#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int maxArea(vector<int>& height) {

        int leftIndex = 0;
        int rightIndex = height.size() - 1;

        int volume = height.at(leftIndex);
        int maxVolume = volume;

        while (true) {
            leftIndex++;
            volume = min(height.at(leftIndex), height.at(rightIndex)) * (rightIndex - leftIndex);
            if (volume > maxVolume) maxVolume = volume;
            if (rightIndex == leftIndex) return maxVolume;

            rightIndex--;
            volume = min(height.at(leftIndex), height.at(rightIndex)) * (rightIndex - leftIndex);
            if (volume > maxVolume) maxVolume = volume;
            if (rightIndex == leftIndex) return maxVolume;
        }

    }
};

int main()
{
    vector<int> test = { 1,8,6,2,5,4,8,3,7 };

    Solution solution;

    cout << solution.maxArea(test) << endl;


    for (auto& i : test) {
        cout << i << endl;
    }
}