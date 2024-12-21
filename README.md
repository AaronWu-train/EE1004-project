# EE1004-project: BMP Plotter

## Overview

This project is a solution for the "113-1 NTU EE Computer Programming (EE1004-02, Instructor: Yu Tian-Li)" course final project. The BMP Plotter implements geometric drawing functionalities, allowing users to generate BMP images of shapes such as circles, rectangles, triangles, ovals, and diamonds. The code is structured to demonstrate object-oriented programming concepts and effective memory management.

---

## Disclaimer

**Plagiarism Warning**: This project is intended solely for educational reference. Direct copying or submission of this project as your own work is strictly prohibited and could result in severe academic penalties. Please ensure you fully understand the code and write your own implementation where required.

---

## How to Use

### Prerequisites

- **Compiler**: `g++`
- **Tool**: `make`
- **Operating System**: Linux or macOS

### Download the Project
Clone the repository using the following command:

```bash
git clone https://github.com/yourusername/EE1004-project.git
```

Navigate into the project directory:

```bash
cd EE1004-project
```

### Set Your Student ID
Create or update the `.env` file to include your student ID:

```
STUDENT_ID=your_student_id
```

If no `.env` file exists, the default `STUDENT_ID` is `unknown`.

### Build the Project
Run the following command to compile the source code and generate the executable:

```bash
make
```

The main executable will be located at `bin/main`.

### Run Tests
To compile and execute test cases, use the following command:

```bash
make test
```

The test executable will be located at `bin/test`.

### Package the Project
To package the project for submission, run:

```bash
make archive
```

The packaged file will be saved in the `dist/` directory, named `<student_id>.zip`.

### Clean Up Files
To remove all compiled files and directories:

```bash
make clean
```

---

## FAQ

1. **Cannot find the `.env` file?**
   - Create a `.env` file and add the `STUDENT_ID` variable:
     ```
     STUDENT_ID=your_student_id
     ```

2. **Tests are failing?**
   - Verify that the test logic is correct.
   - Ensure all geometric shape drawing functionalities are implemented properly.

3. **Packaging fails?**
   - Check if the `STUDENT_ID` is set in the `.env` file.
   - Ensure all required header files are present in the `src/` directory.

---

## Project Structure

```
├── src/             # Source files
├── tests/           # Test files
├── bin/             # Compiled outputs
├── dist/            # Packaged files
├── include/         # Header files
├── makefile         # Build script
├── .env             # Environment variable configuration file
```

---

## Notes

1. Ensure proper encapsulation when designing classes. Use `private` or `protected` access specifiers appropriately.
2. Manage memory carefully to avoid memory leaks.
3. Follow the APIs strictly as defined in `desktop.h`.
4. Submit only the specified header files as instructed.

---

## License

MIT License

This project is for academic use only. Please ensure proper attribution when referencing this work.
