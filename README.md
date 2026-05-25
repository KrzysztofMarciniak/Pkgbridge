# 📦 pkgbridge

pkgbridge is a Linux package translation tool that converts package definitions between different systems using a unified intermediate representation (IR).

---

## 📚 Libraries

pkgbridge uses a small set of carefully chosen dependencies to keep the system lightweight, fast, and modular.

### 🧭 Core dependencies

* **CLI11**
  Used for command-line parsing and subcommand routing.

* **spdlog**
  High-performance logging library used for debugging and system tracing during parsing and transformation stages.

* **JSON library (required for IR processing)**
  pkgbridge requires a JSON backend for reading and writing the intermediate representation (IR).
  The JSON implementation is abstracted through `json_service`, allowing multiple backends.

  Supported / planned implementations:

  * **yyjson** *(recommended)* `[ ]`
  * **cJSON** `[ ]`

* *(more backends may be added in the future)*


## 🧠 Core Idea

pkgbridge translates package formats through a shared IR format called **pkgbridge IR** (JSON-based).

### Example Pipeline

```text 
Gentoo ebuild
      ↓
pkgbridge IR (JSON)
      ↓
Debian package format
```

---

## ⚙️ Supported Flow (initial goal)

* **Input:** Gentoo ebuild
* **Intermediate:** pkgbridge IR (.pkgbridge JSON)
* **Output:** Debian package metadata

---

## 📦 pkgbridge IR format

The IR is a structured JSON representation of a package, used as the single source of truth during translation.

(w.i.p.) Example:

```json 
{
  "name": "kde",
  "version": "6.0",
  "description": "KDE desktop environment",
  "deps": {
    "runtime": ["qt", "xcb"],
    "build": ["cmake", "ninja"]
  },
  "source": {
    "url": "https://example.org/kde.tar.xz"
  }
}
```

---

## 🏗️ Architecture

`json_service` serves as an abstraction layer between the JSON library and the rest of the system. This allows pkgbridge to remain independent of any specific JSON implementation (such as yyjson or others), making it possible to replace or extend the underlying library without changing core logic.

```text 
commands/
   ├── in/gentoo        → parses ebuild → IR
   ├── out/debian       → IR → Debian format
   ├── out/pkgbridge    → IR debug output

services/
   ├── package_service
   ├── transform_service
```

---

## 🛠 Build

```bash 
make # make debug
./pkgbridge
# sudo make install
```

