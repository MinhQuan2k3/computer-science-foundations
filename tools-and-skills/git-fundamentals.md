# Git

Git is a distributed version control system used to track changes and manage source code.

## 1. Basic Workflow

```text
Working Directory
       │
    git add
       ▼
Staging Area
       │
  git commit
       ▼
Repository
       │
   git push
       ▼
Remote Repository
```

Basic commands:

```bash
git status
git add .
git commit -m "message"
git push
git pull
```

Check commit history:

```bash
git log --oneline
```

---

## 2. Branching

Branches allow developers to work on features independently.

Create and switch to a new branch:

```bash
git switch -c feature/login
```

Switch branch:

```bash
git switch main
```

List branches:

```bash
git branch
```

Delete a branch:

```bash
git branch -d feature/login
```

A simple project workflow:

```text
main
 │
 ├── feature/login
 ├── feature/register
 └── bugfix/login-error
```

---

## 3. Remote Repository

Clone a repository:

```bash
git clone <url>
```

Check remote:

```bash
git remote -v
```

Download remote changes without merging:

```bash
git fetch
```

Download and integrate remote changes:

```bash
git pull
```

Upload local commits:

```bash
git push
```

Push a new branch:

```bash
git push -u origin feature/login
```

---

## 4. Merge

Merge combines changes from one branch into another.

```bash
git switch main
git merge feature/login
```

Example:

```text
A -- B -- C
      \
       D -- E

        ↓ merge

A -- B -- C ------ M
      \          /
       D -- E ---
```

---

## 5. Merge Conflict

A conflict occurs when Git cannot automatically combine changes.

Example:

```text
<<<<<<< HEAD
print("Hello");
=======
print("Hi");
>>>>>>> feature/login
```

Resolve the file manually, then:

```bash
git add <file>
git commit
```

Check unresolved conflicts:

```bash
git status
```

Typical workflow:

```text
git merge
    ↓
Conflict
    ↓
Resolve manually
    ↓
git add
    ↓
git commit
```

---

## 6. Rebase

Rebase moves commits onto a new base.

Before:

```text
A -- B -- C
      \
       D -- E
```

After:

```text
A -- B -- C -- D' -- E'
```

Command:

```bash
git switch feature/login
git rebase main
```

Rebase creates new commits (`D'`, `E'`) because commit history is rewritten.

### Merge vs Rebase

| Merge | Rebase |
|---|---|
| Preserves history | Rewrites history |
| May create merge commit | Creates linear history |
| Safer for shared branches | Better for cleaning local branches |
| Easier to understand | Requires more caution |

**Rule:** Avoid rebasing commits that other developers are already using.

---

## 7. Reset vs Revert

### Reset

Moves the branch pointer and can rewrite local history.

```bash
git reset --soft HEAD~1
git reset HEAD~1
git reset --hard HEAD~1
```

`--hard` can discard local changes, so use it carefully.

### Revert

Creates a new commit that reverses an earlier commit.

```bash
git revert <commit>
```

For shared branches, `revert` is generally safer than `reset`.

```text
Local/private history → reset can be useful

Shared/public history → prefer revert
```

---

## 8. .gitignore

`.gitignore` prevents unwanted files from being tracked.

Example:

```gitignore
# IDE
.idea/
.vscode/

# Build
build/
out/

# Compiled files
*.class
*.o
*.exe

# Environment
.env

# Logs
*.log
```

Do not commit:

```text
API keys
Passwords
Access tokens
Private keys
Environment secrets
```

---

## 9. Recommended Workflow

For a feature:

```bash
# Update main
git switch main
git pull

# Create feature branch
git switch -c feature/my-feature

# Work on the code...

# Review changes
git status
git diff

# Commit
git add .
git commit -m "Implement my feature"

# Push
git push -u origin feature/my-feature
```

Then:

```text
Pull Request
     ↓
Code Review
     ↓
Merge
     ↓
main
```

---

## 10. Essential Commands

| Purpose | Command |
|---|---|
| Check status | `git status` |
| View changes | `git diff` |
| Stage changes | `git add .` |
| Commit | `git commit -m "message"` |
| View history | `git log --oneline` |
| Create branch | `git switch -c <branch>` |
| Switch branch | `git switch <branch>` |
| Merge | `git merge <branch>` |
| Rebase | `git rebase <branch>` |
| Fetch | `git fetch` |
| Pull | `git pull` |
| Push | `git push` |
| Undo with new commit | `git revert <commit>` |
| Reset local history | `git reset` |

---

## 11. Key Takeaways

The most important Git concepts are:

```text
Repository
   │
   ├── Commit
   ├── Branch
   ├── Remote
   ├── Merge
   ├── Conflict
   └── Rebase
```

A developer should understand not only how to use:

```bash
git add
git commit
git push
```

but also **when to use branching, merging, conflict resolution, rebase, reset, and revert**.

The core Git workflow:

```text
Branch
  ↓
Develop
  ↓
Commit
  ↓
Push
  ↓
Pull Request
  ↓
Review
  ↓
Merge
```
