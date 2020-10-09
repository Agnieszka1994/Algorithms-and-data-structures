using namespace std;

class MinMaxStack {
public:
	vector<int> stack{};
	vector<int> currentMinimum{};
	vector<int> currentMaximum{};
 
	MinMaxStack(){
		vector<int> stack{};
 		vector<int> currentMinimum{};
		vector<int> currentMaximum{};
	}
		
  int peek() {
    if(stack.size() == 0)
    return 0;
		
		return stack.back();
  }

  int pop() {
		   if(stack.size() == 0)
    return 0;
		
		int valuePoped = stack.back();
    stack.pop_back();
		currentMinimum.pop_back();
		currentMaximum.pop_back();
    return valuePoped;
  }

  void push(int number) {
		if(stack.size() >0){
			stack.push_back(number);
			if(number < currentMinimum.back())
			currentMinimum.push_back(number);
		else currentMinimum.push_back(currentMinimum.back());
		
		if(number > currentMaximum.back())
			currentMaximum.push_back(number);
		else currentMaximum.push_back(currentMaximum.back());
		}
		else{
			stack.push_back(number);
			currentMinimum.push_back(number);
			currentMaximum.push_back(number);
		}
  }

  int getMin() {
    if(stack.size() == 0)
    return 0;
    return currentMinimum.back();
  }

  int getMax() {
    if(stack.size() == 0)
    return 0;
    return currentMaximum.back();
  }
};
