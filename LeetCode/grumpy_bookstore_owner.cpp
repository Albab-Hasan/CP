class Solution {
public:
    int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int totalSatisfied = 0;
      
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                totalSatisfied += customers[i];
            }
        }
      
        int maxExtraSatisfied = 0;
        int currentExtraSatisfied = 0;
        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i] == 1) {
                currentExtraSatisfied += customers[i];
            }
        }
        maxExtraSatisfied = currentExtraSatisfied;

        for (int i = minutes; i < n; ++i) {
            if (grumpy[i - minutes] == 1) {
                currentExtraSatisfied -= customers[i - minutes];
            }
            if (grumpy[i] == 1) {
                currentExtraSatisfied += customers[i];
            }
            maxExtraSatisfied = std::max(maxExtraSatisfied, currentExtraSatisfied);
        }

        return totalSatisfied + maxExtraSatisfied;
    }
};
