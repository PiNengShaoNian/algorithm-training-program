//自顶向下BinaryExpression解析解法
class Solution {
public:
	enum TokenType {
		Number,
		Minus,
		Add,
		Multi,
		Div,
		EOFToken
	};
	inline int getPrecedence(TokenType c) {
		switch (c) {
		case Add:
		case Minus:
			return 1;
		case Multi:
		case Div:
			return 2;
		}

		return 0;
	}

	struct token {
		TokenType type;
		int val;
	};

	int index = 0;
	string s;
	int n;

	int calculate(string _s) {
		vector<token> tokens;
		s = move(_s);
		n = s.size();

		while (index < n) {
			switch (s[index]) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': {
				int num = readIntger();
				tokens.push_back({
					Number,
					num
					});
				break;
			}
			case ' ':
			case '\n':
				readWhiteSpace();
				break;
			case '+':
				++index;
				tokens.push_back({ Add, 0 });
				break;
			case '-':
				++index;
				tokens.push_back({ Minus, 0 });
				break;
			case '*':
				++index;
				tokens.push_back({ Multi, 0 });
				break;
			case '/':
				++index;
				tokens.push_back({ Div, 0 });
				break;
			default:
				cout << "unknown token at index " << index << " " << s[index] << endl;
				break;
			}
		}

		tokens.push_back({
			EOFToken,
			0
			});

		int tokenIdx = 0;
		return evaluate(tokens, tokenIdx, 0);
	}

	int compute(int left, int right, TokenType op) {
		switch (op) {
		case Add:
			return left + right;
		case Minus:
			return left - right;
		case Multi:
			return left * right;
		case Div:
			return left / right;
		}

		return -1;
	}

	int evaluate(vector<token>& tokens, int& cur, int parentPrecedence) {
		auto& left = tokens[cur++];
		int leftVal = left.val;

		while (cur < tokens.size()) {
			auto& op = tokens[cur];
			int precedence = getPrecedence(op.type);
			if (precedence == 0 || precedence <= parentPrecedence) {
				break;
			}

			++cur;
			int right = evaluate(tokens, cur, precedence);
			leftVal = compute(leftVal, right, op.type);
		}

		return leftVal;
	}

	void printTokens(vector<token>& tokens) {
		cout << "token count " << tokens.size() << endl;
		for (auto& token : tokens) {
			cout << "tokenType" << token.type << " tokenVal " << token.val << endl;
		}
	}

	int readIntger() {
		int ans = 0;
		while (index < n && isdigit(s[index])) {
			ans *= 10;
			ans += s[index] - '0';
			++index;
		}

		return ans;
	}

	void readWhiteSpace() {
		while (index < n && iswblank(s[index])) {
			++index;
		}
	}
};

//没有括号的情况下，简单的栈就能解题
class Solution {
public:
    int calculate(string s) {
        int num = 0;
        char preSign = '+';
        vector<int> stack;
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            if(isdigit(s[i])) {
                num *= 10;
                num += s[i] - '0';
            }

            if((!isdigit(s[i]) && s[i] != ' ') || i == n - 1) {
                switch(preSign) {
                    case '+':
                        stack.push_back(num);
                        break;
                    case '-':
                        stack.push_back(-num);
                        break;
                    case '*':
                        stack.back() *= num;
                        break;
                    case '/':
                        stack.back() /= num;
                        break;
                }
                preSign = s[i];
                num = 0;
            }
        }

        return accumulate(stack.begin(), stack.end(), 0);
    }
};