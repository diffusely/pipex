# pipex

> A simplified shell pipe emulator written in C as part of the 42 curriculum.

---

## 📌 About

**Pipex** is a 42 project that replicates shell behavior using UNIX system calls. It focuses on executing two or more commands with input/output redirection and piping, similar to how the shell processes commands like:


🛠️ Build
make # builds mandatory version
make bonus # builds bonus version (multi-pipe & here_doc support)

▶️ Usage Example
Mandatory Version
./pipex file1 "cat" "wc -l" file2

Bonus Version (Multiple Commands)
./pipex file1 "grep a" "sort" "uniq" file2

Bonus Version (here_doc)
./pipex here_doc END "cat" "wc -c" file2
