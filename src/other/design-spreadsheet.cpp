class Spreadsheet {
 private:
  unordered_map<string, int> cellToValue;

  pair<int, int> getPos(const string &cell) {
    int x = stoi(cell.substr(1));
    int y = cell[0] - 'A';
    return {x, y};
  }

  int getCellValue(string &cell) {
    if (isalpha(cell[0])) {
      return cellToValue.count(cell) ? cellToValue[cell] : 0;
    } else {
      return stoi(cell);
    }
  }

 public:
  Spreadsheet(int rows) {}

  void setCell(string cell, int value) { cellToValue[cell] = value; }

  void resetCell(string cell) { cellToValue[cell] = 0; }

  int getValue(string formula) {
    int i = formula.find('+');
    string cell1 = formula.substr(1, i - 1);
    string cell2 = formula.substr(i + 1);
    return getCellValue(cell1) + getCellValue(cell2);
  }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */