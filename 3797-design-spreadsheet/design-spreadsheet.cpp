class Spreadsheet {
    vector<vector<int>>sheet;
public:
Spreadsheet(int rows) {
        sheet.resize(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A'; // Extract column index
        int row = stoi(cell.substr(1)) - 1; // Extract row index (1-based to 0-based)
        sheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        sheet[row][col] = 0;
    }
    
    int getValue(string formula) {
        formula = formula.substr(1); // Remove leading '='
        int pos = formula.find("+");
        string first = formula.substr(0, pos);
        string second = formula.substr(pos + 1);
        int digit1 = 0, digit2 = 0;
        
        // Parse first operand
        if (isalpha(first[0])) {
            int col = first[0] - 'A';
            int row = stoi(first.substr(1)) - 1;
            digit1 = sheet[row][col];
        } else {
            digit1 = stoi(first);
        }
    
        if (isalpha(second[0])) {
            int col = second[0] - 'A';
            int row = stoi(second.substr(1)) - 1;
            digit2 = sheet[row][col];
        } else {
            digit2 = stoi(second);
        }
        
        return digit1 + digit2;
    }
        
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */