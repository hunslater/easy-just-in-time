#include <llvm/IR/Metadata.h>
#include <llvm/IR/Module.h>
#include <llvm/ADT/SmallVector.h>
#include <string>

#include "Utils.h"

using namespace llvm;

std::string easy::GetEntryFunctionName(Module const &M) {
  for (Function const &F : M) {
    MDNode const* MD = F.getMetadata("easy::jit");
    if(!MD && !MD->getNumOperands())
      continue;
    Metadata const* Operand = MD->getOperand(0);

    MDString const *String = dyn_cast<MDString const>(Operand);
    if(String->getString() == "entry")
      return F.getName();
  }
  return "";
}
