This repository contains my progress on kyopro (competitive programming). Progress on each contests will be stored under subdirectories.

### Environment Setup

We assume Windows11 machine to compile codes in this repository. To work with Windows machine, you will have to:
1. Install LLVM (Clang)
  - You can download an installer archive from [official GitHub release page](https://github.com/llvm/llvm-project/releases). Installing LLVM is just fine as it contains Clang as well. Note you may have to install the latest release to compile the latest Windows C++ runtime below.
  - Make sure to check an option to add LLVM to PATH to allow using from VisualStudio Code console.
2. Install VisualStudio Build Tools
  - Then, you have to install C++ runtime and standard libraries of Windows. Clang is just an compiler, and we need to prepare those libraries by ourselves. There are several options to prepare these libraries (such as MinGW), but I would choose official Microsoft release of these libraries.
  - You can get the installer from [this page](https://visualstudio.microsoft.com/ja/visual-cpp-build-tools/). Check `Desktop C++ Development` and follow the instruction to setup.
3. Prepare VisualStudio Code for C++ development
  - Finally, you will install `C/C++ Extension Pack` to VisualStudio Code to start development using it.
  - In addition, you will need to install `CodeLLDB` to enable debugging using LLVM on VisualStudio Code.
  - You may also want to install `EditorConfig` to auto-format the code using `.editorconfig` file in this repository.
  - This repository contains `.vscode` directory for smooth integration.

### List of Contests

- atcoder_problems: https://kenkoooo.com/atcoder/#/table/
  - training: https://kenkoooo.com/atcoder/#/training
