# Student Grade Management System (Optimized Version v2.0)

A fully-functional student grade management system developed in C, supporting various operations such as adding, deleting, updating, and querying student information.

## 📋 Features

### Core Features
1. **Add Student Information** - Supports batch input of student data with automatic duplicate ID checking
2. **Delete Student Information** - Delete students by ID with confirmation prompt
3. **Update Student Information** - Supports updating all student information including ID, name, class, gender, and scores
4. **Query Student Information** - Query by student ID or name
5. **Display Student Information** - Display all students in table format
6. **Sort Function** - Sort by ID, English score, C language score, total score, or average score
7. **Score Statistics** - Display student with highest score
8. **Score Grouping** - Group students by score threshold
9. **Class Summary** - Calculate statistics by class including average, highest, and lowest scores
10. **Data Export** - Export data to CSV file

## 🏗️ Project Structure

```
student-grade-management/
├── main.c                  # Main program
├── student.h               # Student structure definition
├── file_ops.h              # File operations
├── menu.h                  # Menu display
├── input.h                 # Data input
├── delete.h                # Delete function
├── update.h                # Update function
├── query.h                 # Query function
├── display.h               # Display function
├── sort.h                  # Sort function
├── statistics.h            # Statistics function
├── utility.h               # Utility functions
└── README.md               # Project documentation
```

## 💻 Environment Requirements

- **Compiler**: Visual Studio 2022 or other standard C compiler
- **Operating System**: Windows / Linux / macOS
- **C Standard**: C99 or higher

## 🚀 Getting Started

### Compile and Run in VS2022

1. **Create New Project**
   - Open Visual Studio 2022
   - Select "Create new project" → "Empty Project" (C++ framework)
   - Project name: `StudentGradeManagement`

2. **Add Source Files**
   - Add all `.h` files and `main.c` to the project
   - In VS: Right-click project → Add → Existing Items

3. **Configure Project**
   - Right-click project properties
   - C/C++ → General → Add include directories if needed
   - Ensure include paths are correct

4. **Compile and Run**
   ```
   Press Ctrl+F5 to compile and run
   Or
   Press F5 for debug run
   ```

### Command Line Compilation

**Windows (GCC):**
```bash
gcc -o student_system main.c
.\student_system
```

**Linux/macOS:**
```bash
gcc -o student_system main.c
./student_system
```

## 📝 Usage Examples

### Add Student Information
```
Select menu option 1
Enter Student ID: 001
Enter Name: John Smith
Enter Class: 21 Computer Science Class 1
Enter Gender: Male
Enter English Score: 85.5
Enter C Language Score: 92.0
```

### Query Student Information
```
Select menu option 4
Select query method: 1 (by Student ID)
Enter Student ID: 001
```

### Sort Display
```
Select menu option 6
Select sort method: 4 (by Total Score)
```

## 🔧 Improvements

Key optimizations compared to original version:

- ✅ **Modular Design** - Functions separated into different header files for better maintainability
- ✅ **Enhanced Error Handling** - Comprehensive error messages and exception handling
- ✅ **Code Standards** - Unified naming conventions with English documentation
- ✅ **Feature Expansion** - Added class summary, CSV export functionality
- ✅ **Bug Fixes** - Fixed original bugs (e.g., stu[i] vs stu[m] issues)
- ✅ **UI Improvement** - Enhanced menu interface and user experience
- ✅ **Cross-Platform** - Support for Windows, Linux, macOS
- ✅ **VS2022 Compatible** - Fully compatible with Visual Studio 2022

## 📊 Data Storage

- **Format**: Binary file (`students.dat`)
- **Location**: Program execution directory
- **Export**: Supports CSV format (`students_export.csv`)

## 🐛 Known Issues

- Current version supports maximum 100 students
- Binary files are not cross-platform compatible (different systems may have different binary formats)

## 🔮 Future Plans

- [ ] Support more students (using dynamic memory)
- [ ] Database integration
- [ ] Web interface
- [ ] Password protection
- [ ] More detailed score analysis

## 📄 License

MIT License

## 🤝 Contributing

Welcome to submit Issues and Pull Requests!

## 📧 Contact

For questions or suggestions, please contact the developer.
