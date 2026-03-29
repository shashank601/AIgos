`git stash` is basically a **temporary hiding place** for your uncommitted changes. It lets you clean your working directory **without committing**.

---

### **Why you need it**

* Git refuses to rebase, switch branches, or pull if you have **uncommitted changes**.
* Sometimes you want to keep your changes but **move to another branch or rebase safely**.
* Stash lets you do that without creating a permanent commit.

---

### **Basic commands**

1. **Save your changes**

```bash id="7kkq0c"
git stash
```

* This saves **all modified and staged files** and resets your working directory to the last commit.
* You can also give it a name:

```bash id="ul26k7"
git stash save "WIP before rebase"
```

---

2. **List stashes**

```bash id="lf56v8"
git stash list
```

Example output:

```
stash@{0}: WIP on main: WIP before rebase
stash@{1}: WIP on feat/queries: fixing bug
```

---

3. **Apply a stash**

```bash id="r8hvna"
git stash apply      # applies the latest stash
git stash apply stash@{1}  # apply a specific stash
```

* Changes are reapplied **without removing the stash**.

---

4. **Apply and remove (pop)**

```bash id="z6l3bn"
git stash pop
```

* Reapplies the changes **and deletes the stash** from the list.

---

5. **Delete a stash without applying**

```bash id="h62z6q"
git stash drop stash@{0}
```

6. **Clear all stashes**

```bash id="vwpl39"
git stash clear
```

---

### **Example workflow with stash**

```bash id="2pvz91"
# You're on main but have uncommitted changes
git stash                 # hide changes
git checkout feat/queries # switch branch safely
git pull origin feat/queries
git checkout main
git stash pop             # restore your changes
```

* Perfect for when you want to **rebase or merge without losing WIP changes**.

---

If you want, I can explain **how stash fits into your “fix wrong commit emails” workflow**, so you can safely rebase without losing anything.

Do you want me to do that?
