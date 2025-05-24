# library-management-system
📚 Library Management System (Console-based, C++)
This is a console-based Library Management System coded in C++, designed as a semester project. It features a clean and animated interface, colored output, and hacker-style UI vibes — all running in the terminal using file handling (no database required).

🔧 Features
👤 Login System (Username & Password protected)

➕ Add New Books (with input validation)

🔍 Search Books

📖 Borrow & Return Books

🗑️ Delete Books

📋 View All Books

💾 File Handling for data persistence

🌈 Colored & Animated Console UI for a better UX

💡 Tech Used
C++ (core logic)

File Handling (fstream)

Windows-specific headers (<windows.h>, <conio.h>) for animations and UI effects

Terminal color/animation hacks

✅ Input Validation
The program prevents crashes by checking user inputs (like numeric-only IDs) and avoids infinite loops using manual error handling and cin.clear() techniques.

🧠 Use Cases
Ideal for CS students learning C++

Good starting point to understand file I/O, structs, and basic OOP

Can be extended to GUI (SFML/Qt) or ported to web version (PHP/Python backend)

🚀 How to Run
Clone the repo

Compile using any C++ compiler (like g++, DevC++, Code::Blocks)

Run the executable

Login and start managing the books like a pro librarian 😎

📌 Note
This project was built with student-level focus and practical console logic. It's fully standalone — no database, no external dependencies. Just pure C++ and terminal fun.
