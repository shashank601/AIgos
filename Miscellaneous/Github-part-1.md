Got it. I’ve gone through everything we’ve discussed. Here’s a **comprehensive, no-fluff guide** for your Git workflow, branch management, and commit/email hygiene. Think of this as your **“never get lost in Git again” manual** for your repo.

---

# 🗂 Git & Branch Workflow Guide for Your Chat Application Repo

---

## **1. Repository Setup**

* Default branch = `main` (never use `master` anymore).
* Feature branches = `feat/<name>`
* Fix branches = `fix/<name>`

Example branch names:

```text
feat/queries
fix/schema
```

* Remote repository has `main`. Old `master` should be deleted.

---

### **Check current state**

```bash
# See current branch
git status

# List all local branches
git branch

# List all remote branches
git branch -r

# List local and tracking info
git branch -vv
```

---

## **2. Cleanup old branches**

### 2a. Delete local branches

```bash
git branch -d feat/queries    # if fully merged
git branch -d fix/schema

# If Git complains, force delete
git branch -D feat/queries
git branch -D fix/schema
```

### 2b. Delete remote branches

```bash
git push origin --delete feat/queries
git push origin --delete fix/schema
```

* After this, only `main` remains locally and remotely.

---

## **3. Correct Git user/email settings**

* GitHub links commits to profile via **email** in commit metadata.

Check current settings:

```bash
git config --global user.name
git config --global user.email
git config user.name       # local override
git config user.email      # local override
```

Set correct global values:

```bash
git config --global user.name "Shashank"
git config --global user.email "shashank3fr@gmail.com"
```

* This ensures **new commits** show your GitHub avatar.

---

## **4. Fixing old commits with wrong emails**

1. **Check your commit history and emails**

```bash
git log --format="%h %an %ae"
```

* Look for commits with wrong emails (`shashank601@gmail.com`).

2. **Handle uncommitted changes first**

```bash
# Option A: commit changes temporarily
git add .
git commit -m "WIP: temporary save before rebase"

# Option B: stash changes
git stash
```

3. **Interactive rebase from root**

```bash
git rebase -i --root
```

* In the editor, replace `pick` with `edit` for commits with wrong email.
* For each commit stopped at, amend author:

```bash
git commit --amend --author="Shashank <shashank3fr@gmail.com>"
git rebase --continue
```

4. **After rebase**: restore stashed changes (if used)

```bash
git stash pop
```

5. **Force push updated branch**

```bash
git push origin main --force
```

* This updates GitHub with correct emails and shows your avatar.

---

## **5. Feature workflow**

```bash
# 1. Start from main
git checkout main
git pull origin main

# 2. Create feature branch
git checkout -b feat/your-feature

# 3. Work on branch
# add/commit changes
git add .
git commit -m "feat: description of work"

# 4. Push feature branch
git push -u origin feat/your-feature

# 5. Merge into main when done
git checkout main
git pull origin main      # ensure up to date
git merge feat/your-feature
git push origin main

# 6. Delete feature branch
git branch -d feat/your-feature
git push origin --delete feat/your-feature
```

* Always do **PRs if collaborating**, or merge directly if solo.
* Keeps main clean and linear.

---

## **6. Empty folders**

* Git does not track empty folders.
* Use a placeholder `.gitkeep` file:

```bash
touch folder/.gitkeep
git add .
git commit -m "keep empty folder"
git push
```

* This ensures folders show up on GitHub.

---

## **7. Master vs Main confusion**

* Always use **main** as default branch.
* Delete `master` locally and remotely:

```bash
git branch -D master           # local
git push origin --delete master  # remote
```

* Rename local master to main if needed:

```bash
git branch -m master main
git push -u origin main
```

* Don’t push to master anymore.

---

## **8. Quick sanity checks**

```bash
git status               # current branch and changes
git branch -vv           # local vs remote tracking
git log --oneline --graph  # visualize commits
git remote -v            # confirm remote URLs
```

---

## **9. Handling WIP commits during rebase**

* Temporary commit: `git commit -m "WIP: temporary save before rebase"`
* Or stash: `git stash` / `git stash pop`
* Prevents conflicts or Git refusing the rebase.

---

## **10. GitHub avatar & commit display**

* Commit **email must match GitHub account**.
* Wrong email → no profile pic.
* Correct email globally ensures **all future commits show your avatar**.
* Past commits can be rewritten via rebase to fix.

---

## ✅ Summary

* **Default branch:** main
* **Feature/fix branches:** short-lived, merge to main
* **Emails:** must match GitHub
* **Rebase:** use `--root` to fix past commits
* **Delete old branches:** locally & remotely once merged
* **Empty folders:** add `.gitkeep`

Following this keeps your repo **linear, predictable, and clean**.

---

If you want, I can also make a **ready-to-run “Git cleanup + rebase + email fix” script** for your repo that fixes everything in one go, so you never have to think about this again.

Do you want me to do that?
