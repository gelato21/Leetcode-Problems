class Solution {
public:
    // width, height
    int minPossibleHeight(int ind, int height, int currWidth, vector<vector<int>>& books, int maxWidth, vector<vector<int>>& dp){
        if(ind>=books.size()){
            return height;
        }

        if(dp[ind][currWidth]!=-1) return dp[ind][currWidth];

        if(books[ind][0]<=currWidth){
            int placeInSameRow = minPossibleHeight(ind+1, max(height, books[ind][1]), currWidth-books[ind][0], books, maxWidth, dp);
            int placeBelow = height + minPossibleHeight(ind+1, books[ind][1], maxWidth-books[ind][0], books, maxWidth, dp);

            return dp[ind][currWidth]=min(placeInSameRow, placeBelow);
        }
        return dp[ind][currWidth]=height + minPossibleHeight(ind+1, books[ind][1], maxWidth-books[ind][0], books, maxWidth, dp);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<vector<int>> dp(n+1, vector<int>(shelfWidth+1, -1));
        return minPossibleHeight(0, 0, shelfWidth, books, shelfWidth, dp);
    }
};