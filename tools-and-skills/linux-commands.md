# Linux / Unix Basic Commands

Linux/Unix command line allows developers to interact with the operating system using commands instead of a graphical interface.

This section covers essential commands for:

- Navigating directories
- Managing files and directories
- Viewing and searching files
- Permissions
- Processes
- Pipes and redirection
- Useful system commands

---

## 1. Navigation

Show current directory:

```bash
pwd
```

List files:

```bash
ls
ls -la
```

Change directory:

```bash
cd <directory>
```

Go to parent directory:

```bash
cd ..
```

Go to home directory:

```bash
cd ~
```

Example:

```bash
cd project
pwd
ls
```

---

## 2. Files and Directories

Create a directory:

```bash
mkdir project
```

Create an empty file:

```bash
touch README.md
```

Copy a file:

```bash
cp file.txt backup.txt
```

Copy a directory:

```bash
cp -r project project_backup
```

Move or rename a file:

```bash
mv old.txt new.txt
```

Remove a file:

```bash
rm file.txt
```

Remove a directory:

```bash
rm -r project
```

**Be careful with `rm`: deleted files may not be recoverable easily.**

---

## 3. Viewing Files

Display the contents of a file:

```bash
cat file.txt
```

View a large file page by page:

```bash
less file.txt
```

Show the beginning of a file:

```bash
head file.txt
```

Show the end of a file:

```bash
tail file.txt
```

Follow a file that is being updated:

```bash
tail -f application.log
```

This is especially useful for monitoring log files.

---

## 4. Searching

Search for files or directories:

```bash
find . -name "*.cpp"
```

Search for text inside files:

```bash
grep "error" application.log
```

Case-insensitive search:

```bash
grep -i "error" application.log
```

Recursive search:

```bash
grep -r "TODO" .
```

A common workflow:

```text
find → locate files

grep → search text
```

---

## 5. File Permissions

View permissions:

```bash
ls -l
```

Example:

```text
-rwxr-xr-x  user  user  script.sh
```

Basic permission categories:

```text
r = read
w = write
x = execute
```

Change permissions:

```bash
chmod +x script.sh
```

Run the script:

```bash
./script.sh
```

---

## 6. Processes

List running processes:

```bash
ps
```

More detailed process information:

```bash
ps aux
```

Monitor processes interactively:

```bash
top
```

On systems where it is installed:

```bash
htop
```

Find a process:

```bash
ps aux | grep java
```

Terminate a process:

```bash
kill <PID>
```

Force termination:

```bash
kill -9 <PID>
```

Use `kill -9` only when normal termination does not work.

---

## 7. Pipes

A pipe (`|`) sends the output of one command to another command.

Example:

```bash
ps aux | grep java
```

The output of:

```bash
ps aux
```

becomes the input of:

```bash
grep java
```

Another example:

```bash
ls -la | grep ".cpp"
```

Conceptually:

```text
Command A
    │
    │ output
    ▼
   pipe
    │
    ▼
Command B
```

Pipes allow simple commands to be combined into more powerful operations.

---

## 8. Redirection

Write command output to a file:

```bash
ls > files.txt
```

Append output:

```bash
ls >> files.txt
```

Use a file as input:

```bash
sort < names.txt
```

Redirect errors:

```bash
command 2> error.log
```

Redirect both output and errors:

```bash
command > output.log 2>&1
```

Basic symbols:

```text
>      overwrite file
>>     append to file
<      use file as input
2>     redirect errors
```

---

## 9. Environment Variables

Display an environment variable:

```bash
echo $PATH
```

Set a temporary variable:

```bash
NAME="John"
echo $NAME
```

Display all environment variables:

```bash
env
```

Add a directory to `PATH` temporarily:

```bash
export PATH="$PATH:/path/to/program"
```

Environment variables are commonly used for:

- Configuration
- Program paths
- API configuration
- Runtime settings

Sensitive values should not be hard-coded into source code.

---

## 10. Useful Commands

Check the current user:

```bash
whoami
```

Display the current date:

```bash
date
```

Clear the terminal:

```bash
clear
```

Show command history:

```bash
history
```

Display disk usage:

```bash
df -h
```

Display directory size:

```bash
du -sh .
```

Check network connectivity:

```bash
ping example.com
```

Display the manual for a command:

```bash
man ls
```

Get command help:

```bash
ls --help
```

---

## 11. Command Chaining

Run commands sequentially:

```bash
mkdir project && cd project
```

`&&` means the second command runs only if the first succeeds.

Example:

```bash
mkdir project && cd project && touch README.md
```

Run another command regardless of success:

```bash
command1 ; command2
```

Example:

```text
command1
   │
   ├── success → command2
   │
   └── failure → command2
```

when using `;`.

With `&&`:

```text
command1
   │
   ├── success → command2
   └── failure → stop
```

---

## 12. Common Developer Workflow

A simple workflow for working with a project:

```bash
# Navigate to project
cd project

# Check files
ls -la

# Check Git status
git status

# Search source code
grep -r "TODO" .

# View logs
tail -f application.log
```

For a running program:

```text
Start program
     ↓
Check process
     ↓
Check logs
     ↓
Search for errors
     ↓
Debug the problem
```

---

## 13. Essential Commands

| Purpose | Command |
|---|---|
| Current directory | `pwd` |
| List files | `ls` |
| Change directory | `cd` |
| Create directory | `mkdir` |
| Create file | `touch` |
| Copy | `cp` |
| Move / rename | `mv` |
| Delete | `rm` |
| View file | `cat` |
| View large file | `less` |
| Search files | `find` |
| Search text | `grep` |
| Change permissions | `chmod` |
| List processes | `ps` |
| Monitor processes | `top` |
| Terminate process | `kill` |
| Pipe output | `\|` |
| Redirect output | `>` |
| Show environment | `env` |
| Command history | `history` |
| Disk space | `df -h` |
| Directory size | `du -sh` |
| Command help | `man` |

---

## 14. Key Takeaways

The most important Linux/Unix command-line concepts are:

```text
Navigation
   ↓
File management
   ↓
Searching
   ↓
Permissions
   ↓
Processes
   ↓
Pipes & Redirection
```

A developer does not need to memorize every Linux command.

The important skill is being able to:

- Navigate the filesystem
- Create, copy, move and remove files
- Search files and text
- Understand basic permissions
- Inspect and manage processes
- Combine commands using pipes
- Redirect command output
- Use environment variables
- Read command documentation

These skills are useful when working with:

- Servers
- Development environments
- Containers
- CI/CD systems
- Remote machines
- Debugging and log analysis
