// https://leetcode.com/problems/maximize-the-minimum-game-score/
// 3449. Maximize the Minimum Game Score


class Solution {
private:
    vector<int> points;
    vector<long long> currentScore;
    int n;
    
    // Returns the minimum score in the current state
    long long getMinimumScore() {
        long long minScore = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            if (currentScore[i] == 0) return 0;
            minScore = min(minScore, currentScore[i]);
        }
        return minScore;
    }
    
    // Main recursive function
    long long findBestScore(int position, int movesLeft, vector<vector<long long>>& memo) {
        // If no moves left, return current minimum score
        if (movesLeft == 0) {
            return getMinimumScore();
        }
        
        // If we've seen this state before, return cached result
        if (memo[position][movesLeft] != -1) {
            return memo[position][movesLeft];
        }
        
        long long bestPossibleScore = 0;
        
        // Try moving right
        if (position + 1 < n) {
            currentScore[position + 1] += points[position + 1];
            bestPossibleScore = max(bestPossibleScore, 
                                  findBestScore(position + 1, movesLeft - 1, memo));
            currentScore[position + 1] -= points[position + 1];
        }
        
        // Try moving left
        if (position - 1 >= 0) {
            currentScore[position - 1] += points[position - 1];
            bestPossibleScore = max(bestPossibleScore, 
                                  findBestScore(position - 1, movesLeft - 1, memo));
            currentScore[position - 1] -= points[position - 1];
        }
        
        memo[position][movesLeft] = bestPossibleScore;
        return bestPossibleScore;
    }
    
public:
    long long maxScore(vector<int>& input_points, int m) {
        // Initialize class members
        points = input_points;
        n = points.size();
        currentScore = vector<long long>(n, 0);
        
        // Create memoization table with long long type
        vector<vector<long long>> memo(n, vector<long long>(m + 1, -1));
        
        // Make first move to position 0 (required by problem)
        currentScore[0] = points[0];
        
        // Start solving from position 0 with m-1 moves remaining
        return findBestScore(0, m - 1, memo);
    }
};

