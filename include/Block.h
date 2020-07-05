#include <string>
#include <utility>
#include <vector>

// types are represented by unique integers
typedef unsigned int type;

// type_vectors represent a vector of types
typedef std::vector<type> type_vector;

// tuples represent the type of inputs and outputs of blocks
template <typename T>
using tuple = std::vector<std::pair<type, T>>;

/*
 * Create a pair of some (type, value)
 */
template <typename T>
std::pair<type, T> link(type var, T val) {
  return std::make_pair(var, val);
}

/*
 * Blocks are the building blocks of block code
 */
class Block {
  public:
    /*
     * output some tuple given an input tuple
     * --to be overrided--
     *
     * @param input of block
     * @return output of block
     */
    template <typename T>
    tuple<T> run(tuple<T> input); 

  protected:
    /*
     * typecheck an input tuple with the expected input
     * 
     * @param input of block
     * @return whether it typechecks
     */
    template <typename T>
    bool typeCheck(tuple<T> input) {
      if (input.size() != expected_.size()) {
        return false;
      }
      for (int i = 0; i < input.size(); ++i) {
        if (input[i].first != expected_[i]) {
          return false;
        }
      }
      return true;
    }
    
    // the expected type_vector of block inputs
    type_vector expected_; 
};
