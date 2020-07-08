#include <Block.h>

value toValue(float val) {
  return std::make_pair<type, void*>(NUM, &val);
}

value toValue(std::string val) {
  return std::make_pair<type, void*>(TEXT, &val);
}

value toValue(bool val) {
  return std::make_pair<type, void*>(TEXT, &bool);
}

float toInt(value val) {
  return *(float*)val.second;
}

std::string toString(value val) {
  return *(std::string*)val.second;
}

bool toBool(value val) {
  return *(bool*)val.second;
}
