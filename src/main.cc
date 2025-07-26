
#include <stdlib.h>
#include <map>
#include <vector>
#include <iostream>
#include <type_traits>
#ifdef HAVE_ADT_OWNINGPTR_H
#include <llvm/ADT/OwningPtr.h>
#else
#include <memory>
#endif
#ifdef HAVE_LLVM_OPTION_ARG_H
#include <llvm/Option/Arg.h>
#endif
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/ManagedStatic.h>
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/TargetParser/Host.h>
#include <clang/Basic/Version.h>
#include <clang/Basic/Builtins.h>
#include <clang/Basic/FileSystemOptions.h>
#include <clang/Basic/FileManager.h>
#include <clang/Basic/TargetOptions.h>
#include <clang/Basic/TargetInfo.h>
#include <clang/Driver/Compilation.h>
#include <clang/Driver/Driver.h>
#include <clang/Driver/Tool.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Frontend/CompilerInvocation.h>
#include <clang/Basic/DiagnosticOptions.h>
#include <clang/Frontend/TextDiagnosticPrinter.h>
#include <clang/Lex/HeaderSearchOptions.h>
#include <clang/Basic/LangStandard.h>
#include <clang/Lex/PreprocessorOptions.h>
#include <clang/Frontend/FrontendOptions.h>
#include <clang/Frontend/Utils.h>
#include <clang/Lex/HeaderSearch.h>
#include <clang/Lex/Preprocessor.h>
#include <clang/Lex/Pragma.h>
#include <clang/AST/ASTContext.h>
#include <clang/AST/ASTConsumer.h>
#include <clang/Sema/Sema.h>
#include <clang/Sema/SemaDiagnostic.h>
#include <clang/Parse/Parser.h>
#include <clang/Parse/ParseAST.h>

#include <flang/Frontend/CompilerInstance.h>
#include <flang/Frontend/CompilerInvocation.h>
// #include <flang/Basic/DiagnosticOptions.h>
// #include <flang/Frontend/TextDiagnosticPrinter.h>
// #include <flang/Lex/HeaderSearchOptions.h>
// #include <flang/Basic/LangStandard.h>
// #include <flang/Lex/PreprocessorOptions.h>
// #include <flang/Frontend/FrontendOptions.h>
// #include <flang/Frontend/Utils.h>
// #include <flang/Lex/HeaderSearch.h>
// #include <flang/Lex/Preprocessor.h>
// #include <flang/Lex/Pragma.h>
// #include <flang/AST/ASTContext.h>
// #include <flang/AST/ASTConsumer.h>
// #include <flang/Sema/Sema.h>
// #include <flang/Sema/SemaDiagnostic.h>
// #include <flang/Parse/Parser.h>
// #include <flang/Parse/ParseAST.h>

#include <isl/ctx.h>
#include <isl/constraint.h>


#define ARRAY_SIZE(array) (sizeof(array)/sizeof(*array))

int main(int argc, char *argv[])
{
  std::cout << "Hello, world!" <<std::endl;
  return 0;
}
