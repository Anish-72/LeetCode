class Solution {
public:
    int maxNumberOfFamilies(int n, std::vector<std::vector<int>>& reservedSeats) {
        std::unordered_map<int, int> reserved;

        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                reserved[row] |= (1 << (col - 1));
            }
        }

        // Each completely empty row fits 2 families
        int total = (n - static_cast<int>(reserved.size())) * 2;

        const int LEFT_MASK   = 0b0000011110; // Seats 2, 3, 4, 5
        const int RIGHT_MASK  = 0b0111100000; // Seats 6, 7, 8, 9
        const int MIDDLE_MASK = 0b0001111000; // Seats 4, 5, 6, 7

        for (const auto& [row, mask] : reserved) {
            bool left = (mask & LEFT_MASK) == 0;
            bool right = (mask & RIGHT_MASK) == 0;
            bool middle = (mask & MIDDLE_MASK) == 0;

            if (left && right) {
                total += 2;
            } else if (left || right || middle) {
                total += 1;
            }
        }

        return total;
    }
};