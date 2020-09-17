#include <iostream>
using namespace std;

class ScopedBoolSaver {
 public:
  //构造函数的初始化列表，先初始化var_，指针赋值
  ScopedBoolSaver(bool* var, bool new_val) : var_(var), old_val_(*var) {
    *var_ = new_val;
  }
  bool getter() {return old_val_;}
  bool* getterptr() {return var_;}
  ~ScopedBoolSaver() { *var_ = old_val_; }

 private:
  bool* var_;
  bool old_val_;
};

int main(int argc, char const *argv[]) {
	bool varv = false;
	bool* var = &varv;
	bool new_val = true;
	ScopedBoolSaver scb(var,new_val);
	cout<<boolalpha<<scb.getter()<<endl;
	cout<<boolalpha<<var<<" "<<scb.getterptr()<<endl;
	return 0;
}