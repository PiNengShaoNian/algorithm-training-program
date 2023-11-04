regex ipv4("^(?:(?:25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]?\\d)($|(?!\\.$)\\.)){4}$");
regex ipv6("^(?:(?:[\\da-fA-F]{1,4})($|(?!:$):)){8}$");
class Solution {
 public:
  string validIPAddress(const string& queryIP) {
    return regex_search(queryIP, ipv4)   ? "IPv4"
           : regex_search(queryIP, ipv6) ? "IPv6"
                                         : "Neither";
  }
};