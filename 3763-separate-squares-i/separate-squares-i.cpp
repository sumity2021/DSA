
class Solution {
    double total_area(double max_y, vector<vector<int>>& squares) {
        int n = squares.size();
        double area = 0.0;
        for (int i = 0; i < n; i++) {
            double temp = min(max_y, (double)squares[i][1] + squares[i][2]);
            double length = max(0.0, temp - squares[i][1]);  
            double breadth = squares[i][2];
            area += (length * breadth);
        }
        return area;
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        double total = total_area(1e18, squares);  
        double l = 0.0, r = 1e9;
        
        while (r - l > 1e-6) {   
            double mid = (l + r) / 2.0;
            if (2 * total_area(mid, squares) >= total) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return l; 
    }
};
