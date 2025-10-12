class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    long numeratorLong = numerator;
    long denominatorLong = denominator;
    if (numeratorLong % denominatorLong == 0) {
      return to_string(numeratorLong / denominatorLong);
    }

    string ans;
    if (numeratorLong < 0 ^ denominatorLong < 0) {
      ans.push_back('-');
    }

    numeratorLong = abs(numeratorLong);
    denominatorLong = abs(denominatorLong);
    long integerPart = numeratorLong / denominatorLong;
    ans += to_string(integerPart);
    ans.push_back('.');

    string fractionPart;
    unordered_map<long, int> remainderIndexMap;
    long remainder = numeratorLong % denominatorLong;
    int index = 0;
    while (remainder != 0 && !remainderIndexMap.count(remainder)) {
      remainderIndexMap[remainder] = index;
      remainder *= 10;
      fractionPart += to_string(remainder / denominatorLong);
      remainder %= denominatorLong;
      index++;
    }
    if (remainder != 0) {
      int insertIndex = remainderIndexMap[remainder];
      fractionPart = fractionPart.substr(0, insertIndex) + '(' +
                     fractionPart.substr(insertIndex);
      fractionPart.push_back(')');
    }
    ans += fractionPart;

    return ans;
  }
};

class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    long long a = numerator;
    long long b = denominator;
    string sign = a * b < 0 ? "-" : "";
    a = abs(a);
    b = abs(b);

    long long q = a / b;
    long long r = a % b;
    if (r == 0) {
      return sign + to_string(q);
    }

    string ans = sign + to_string(q) + ".";
    unordered_map<long long, int> r_to_pos = {{r, ans.size()}};
    while (r) {
      r *= 10;
      q = r / b;
      r %= b;
      ans += '0' + q;
      if (r_to_pos.contains(r)) {
        int pos = r_to_pos[r];
        return ans.substr(0, pos) + "(" + ans.substr(pos) + ")";
      }
      r_to_pos[r] = ans.size();
    }
    return ans;
  }
};