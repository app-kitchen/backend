#include <string>
#include <utility>
#include <vector>

// types are represented by unique integers
typedef unsigned int type;

// type_vectors represent a vector of types
typedef std::vector<type> type_vector;

// tuples represent the type of inputs and outputs of blocks
using tuple = std::vector<std::pair<type, char*>>;

/*
 * Create a pair of some (type, value)
 */
std::pair<type, char*> link(type var, char* val) {
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
    virtual tuple run(tuple input) = 0; 

  protected:
    /*
     * constructor to set expected type_vector
     *
     * @param expected type_vector
     */
    Block(type_vector expected);

    /*
     * typecheck an input tuple with the expected input
     * 
     * @param input of block
     * @return whether it typechecks
     */
    bool typeCheck(tuple input) {
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
