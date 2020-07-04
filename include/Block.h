#include <string>
#include <utility>
#include <vector>

typedef int type;
typedef std::vector<type> type_vector;

template <typename T>
using tuple = std::vector<std::pair<type, T>>;

class Block {
  public:
    virtual tuple run(tuple input) = 0; 
  protected:
    bool typeCheck(tuple input) {
      for (int i = 0; i < input.size(); ++i) {
        if (input[i].first != expected_[i]) {
          return false;
        }
      }
      return true;
    }
    type_vector expected_; 
};
