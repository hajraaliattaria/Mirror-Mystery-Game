🪞 MIRROR — The Reflection That Learns

### A C++ Interactive Mystery Game

> **The mirror doesn't copy you. It learns you.**

**MIRROR** is a simple choice-based mystery game built in C++. The player interacts with a strange mirror that slowly begins to understand and predict their behavior.

The game uses basic Programming Fundamentals concepts while creating a suspenseful story.

---

## 🎮 How It Works

The player goes through **10 Mirror Memories**.

Each memory contains a different situation and three choices.

The game remembers the player's decisions and uses them to build a simple **Mirror Profile**.

```text
Choice
   ↓
Memory
   ↓
Behavior
   ↓
Mirror Prediction
   ↓
Final Profile
```

---

## 🪞 10 Mirror Memories

1. **The First Reflection** — The reflection moves first.
2. **The Smile** — Your reflection smiles when you don't.
3. **The Prediction** — The mirror predicts your choice.
4. **The Crack** — A strange crack appears.
5. **The Second Reflection** — Another reflection appears.
6. **The Empty Mirror** — Your reflection disappears.
7. **The Message** — The mirror claims it knows you.
8. **The Contradiction** — The reflection does something you didn't.
9. **The Question** — The mirror asks who is real.
10. **The Last Reflection** — The final mystery is revealed.

---

# 📊 Mirror Profile

After Memory #10, the game creates your **Mirror Profile**.

It displays:

```text
================ MIRROR PROFILE ================

Player: Alex

Courage:        7
Curiosity:      12
Trust:           4
Defiance:        8
Predictions:     3

Choice Pattern:

Option 1: 7
Option 2: 12
Option 3: 4

Mirror's Conclusion:

"You keep looking for answers."
```

The profile is based on the player's actual choices.

---

# 🏁 Final Choice

After the Mirror Profile, the mirror gives the player one final decision:

```text
The mirror asks:

"Do you want to see what is behind me?"

1. YES
2. NO
3. BREAK THE MIRROR
```

### Ending 1 — THE REFLECTION

The player chooses **YES**.

The mirror reveals an earlier version of the player.

> "You were never looking at yourself."

> "You were looking at your choices."

### Ending 2 — NOTHING

The player chooses **NO**.

The mirror disappears.

> "You finally made a choice without asking what I would do."

### Ending 3 — THE LOOP

The player chooses **BREAK THE MIRROR**.

The mirror breaks.

Then:

```text
MEMORY #11

"The player broke the mirror."

"The mirror did not break."
```

**THE END.**

---

# 💾 Save System

The game automatically saves progress in:

```text
mirror_save.txt
```

It stores:

- Player name
- Choices
- Memories
- Mirror Profile
- Game progress
- Ending choice

Delete `mirror_save.txt` to start completely over.

---

# 📁 Project Structure

```text
MIRROR/
│
├── main.cpp
├── game.cpp
├── game.h
├── memory.cpp
├── memory.h
├── README.md
```

---

# 🛠️ C++ Concepts

This project demonstrates basic Programming Fundamentals:

- Variables
- Strings
- Arrays
- Structures
- Functions
- Loops
- `if / else`
- User input
- File handling
- Multiple `.cpp` files
- Header files

---


## 🪞 Final Question

> **If your reflection could learn everything about you...**
>
> **would you still trust it?**

---

