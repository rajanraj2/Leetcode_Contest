// https://leetcode.com/problems/design-spreadsheet/
// 3484. Design Spreadsheet


class Spreadsheet {
    public:
        vector<vector<int>> arr;
    
        int helper(const string& str) {
            if (isdigit(str[0])) return stoi(str);        
            int c = str[0] - 'A';
            int r = stoi(str.substr(1)) - 1;
            return arr[r][c];
        }
    
        Spreadsheet(int rows) {
            arr = vector<vector<int>>(rows, vector<int>(26, 0));
        }
        
        void setCell(string cell, int value) {
            int col = cell[0] - 'A';
            int row = stoi(cell.substr(1)) - 1;
            arr[row][col] = value;
        }
        
        void resetCell(string cell) {
            int col = cell[0] - 'A';
            int row = stoi(cell.substr(1)) - 1;
            arr[row][col] = 0;
        }
        
        int getValue(string formula) {
            int pos = formula.find('+');
            string first = formula.substr(1, pos);
            string second = formula.substr(pos + 1);
            int result = helper(first) + helper(second);
            return result;
        }
    };
    
    /**
     * Your Spreadsheet object will be instantiated and called as such:
     * Spreadsheet* obj = new Spreadsheet(rows);
     * obj->setCell(cell,value);
     * obj->resetCell(cell);
     * int param_3 = obj->getValue(formula);
     */