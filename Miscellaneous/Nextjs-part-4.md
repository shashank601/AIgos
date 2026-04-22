They didn’t “avoid” the problem. They **worked around it manually**.

---

# 1) Problem reminder

In **Next.js `pages/`**:

```
navigation → new page file runs → full UI rebuilt
```

So:

* layout resets
* state lost
* duplication risk

---

# 2) How old way handled layouts

They introduced a **shared wrapper manually**.

### `_app.js` (global wrapper)

```cpp
function MyApp({ Component, pageProps }) {
    return (
        <Layout>
            <Component {...pageProps} />
        </Layout>
    );
}
```

What happens:

```
Layout stays
Component changes
```

---

## Does this solve it?

Partially.

* Root layout persists ✅
* But nested layouts? ❌

---

# 3) Nested layout problem

Example:

```
/dashboard
/dashboard/settings
```

You want:

* root layout
* dashboard layout
* page content

---

### In `pages/`, you do this:

```cpp
// dashboard/settings.js
return (
  <RootLayout>
    <DashboardLayout>
      <Settings />
    </DashboardLayout>
  </RootLayout>
);
```

Same repeated in:

* dashboard.js
* analytics.js
* every child page

---

## Problem

* duplication
* no structure enforcement
* easy to forget wrapping
* no hierarchy awareness

---

# 4) State persistence trick

To keep layout state:

```cpp
// layout outside changing component
<MyApp>
   <Sidebar />   // stays mounted
   <Component /> // changes
</MyApp>
```

Works only for:

```
top-level layout
```

Fails for:

```
nested layouts
```

---

# 5) Data fetching workaround

Since data is page-level:

```cpp
getServerSideProps()
```

They:

* fetched everything in page
* passed props down

Problem:

```
overfetching
tight coupling
```

---

# 6) Navigation behavior

To avoid full reload feeling:

* client-side routing (Link)

But internally:

```
page still re-executes
```

So:

* UI looks smooth
* logic still resets

---

# 7) Summary of hacks

Old system used:

1. `_app.js` → global layout
2. manual wrapping → nested layouts
3. prop drilling → data sharing
4. client routing → fake SPA feel

---

# 8) Why this breaks

Because nothing enforces:

```
UI hierarchy
```

You are responsible for:

* structure
* consistency
* state preservation

---

# 9) What `app/` removes

No more:

* manual wrapping
* duplicated layouts
* guessing structure

Because:

```
folder = layout boundary
```

---

# 10) Final reduction

Old way:

```
simulate hierarchy manually
```

New way:

```
hierarchy is the system
```

---

If you still think “old way is fine”, the missing piece is:

→ how bugs appear when layouts diverge across 20+ pages

Next step:
ask:
**“show failure case at scale”**
