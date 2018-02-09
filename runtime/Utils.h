#ifndef UTILS
#define UTILS

#include <string>

namespace llvm {
  class Module;
}

namespace easy {

std::string GetEntryFunctionName(llvm::Module const &M);

}

#endif
