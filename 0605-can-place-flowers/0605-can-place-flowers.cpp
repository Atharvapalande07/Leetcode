class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();

        for (int i = 0; i < size; ++i) {
            if (n <= 0) {
                return true;
            }

            if (flowerbed[i] == 0) {
                bool isLeftEmpty = (i == 0 || flowerbed[i -  1] == 0);

                bool isRightEmpty = (i == size - 1 || flowerbed[i + 1] == 0);

                if (isLeftEmpty && isRightEmpty) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }

        return n <= 0;
    }
};