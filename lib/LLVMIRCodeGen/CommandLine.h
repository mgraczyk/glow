/**
 * Copyright (c) Glow Contributors. See CONTRIBUTORS file.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef GLOW_LLVMIRCODEGEN_COMMANDLINE_H
#define GLOW_LLVMIRCODEGEN_COMMANDLINE_H

#include "llvm/Support/CommandLine.h"
#include "llvm/Target/TargetOptions.h"

llvm::cl::OptionCategory &getLLVMBackendCat();

/// Options for specifying the parameters of llvm::EngineBuilder::selectTarget,
/// which is invoked to create llvm::TargetMachine. They are the equivalents of
/// clang's/llvm's -target, -mcpu, -march and -target-feature options.

/// Target to be used by the LLVMBackend. Used as -target=targetA.
extern llvm::cl::opt<std::string> llvmTarget;

/// Architecture to be used by the LLVMBackend. Used as -march=archA.
extern llvm::cl::opt<std::string> llvmArch;

/// CPU to be used by the LLVMBackend. Used as -mcpu=cpuA.
extern llvm::cl::opt<std::string> llvmCPU;

/// Target and CPU features to be used by the LLVMBackend. The features should
/// be comma-separated and prefixed with +.
/// Used as  -target-feature=+featureA,+featureB.
extern llvm::cl::list<std::string> llvmTargetFeatures;

/// Alias for the LLVM Machine attributes.
extern llvm::cl::alias llvmMAttr;

/// External LLVM compiler (e.g. llc) to use for compiling LLVM bitcode into
/// machine code.
extern llvm::cl::opt<std::string> llvmCompiler;

/// Set of options to pass to the external LLVM compiler.
extern llvm::cl::list<std::string> llvmCompilerOptions;

/// Option to set float ABI. Used as -float-abi=<abi-type>.
extern llvm::cl::opt<llvm::FloatABI::ABIType> floatABI;

#endif // GLOW_LLVMIRCODEGEN_COMMANDLINE_H
