Here’s a **compressed, complete guide** combining the past two responses, including the key distinction of pushing branches vs main, and what happens when a remote branch exists and is later merged:

---

# **Git Workflow: Local & Remote, Branches, Direct Push, Merges**

---

## **1. Sync main first**

```bash
git checkout main
git pull origin main
```

* Updates local main with remote.

---

## **2. Work in a branch (recommended)**

```bash
git checkout -b feat/your-feature
git add .
git commit -m "feat: add XYZ"
```

* Branch isolates work.

---

### **Push branch to remote**

```bash
git push -u origin feat/your-feature
```

**What happens:**

* Creates a **new branch on remote** with same commits.
* Remote main is **not affected**.
* Safe for collaboration.
* `-u` sets upstream for future `push/pull`.

**If branch already exists on remote:**

* Git will push your commits on top of the existing remote branch.
* Later, when merged into main, the commits from the branch are combined into main locally and pushed, or via a pull request.

---

### **Direct push to main**

```bash
git checkout main
git push origin main
```

**What happens:**

* Local main commits are copied directly to remote main.
* Risky if others pushed to main: may need `git pull --rebase` first.
* Remote main is **updated immediately**.

---

## **3. Merge feature/fix branch into main**

```bash
git checkout main
git pull origin main        # update main first
git merge feat/your-feature
git push origin main        # update remote main
```

* Commits from the branch are added to main.
* Remote main now includes the branch’s commits.

---

### **4. Clean up merged branches**

```bash
git branch -d feat/your-feature          # delete local branch
git push origin --delete feat/your-feature  # delete remote branch
```

* Keeps repo clean.

---

## **5. Switching mid-work: stash**

```bash
git stash
git checkout main
git pull origin main
git checkout feat/your-feature
git stash pop
```

* Temporarily hides uncommitted changes.

---

## **6. Key rules**

* Always branch off **main**.
* Push branches to remote before merging.
* Merge only after feature is complete.
* Direct main push: safe solo, risky in collaboration.
* Delete merged branches.
* Make sure `git config user.email` matches GitHub (for profile pic).

---

## **7. Remote branch merge workflow**

1. Branch exists on remote (`origin/feat/your-feature`).
2. Locally:

```bash
git checkout main
git pull origin main
git merge feat/your-feature
git push origin main
```

3. Remote main now contains the branch’s commits.

* **Remote branch stays until deleted**.
* This is how remote branches are merged later, even if multiple people worked on them.

---

**Summary:**

**Local branch → push to remote branch → merge into local main → push main → delete branch.**
Direct main push bypasses branch isolation and affects remote main immediately.

---

If you want, I can also make a **tiny diagram showing local vs remote branches, merges, and main updates**, which visually explains exactly what happens at each step.

Do you want me to make that?
