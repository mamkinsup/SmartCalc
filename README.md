
# Smart Calculator

A smart calculator developed using Qt for the graphical interface. The calculator supports basic arithmetic operations, advanced calculations, and includes a user-friendly interface with the ability to plot graphs based on expressions.

The calculator implements calculations using Polish notation with the use of stack and queue.

## Features

- **Basic Operations**: Addition, subtraction, multiplication, and division.
- **Advanced Functions**: Square roots, exponentiation, logarithms, and more.
- **Graph Plotting**: Visualize functions by plotting their graphs.
- **User-Friendly Interface**: Clean and intuitive design built with Qt.

## Notes

1. For proper handling of unary operators (such as minus `-`), they should be enclosed in parentheses, e.g., `(-1)`.
2. For functions like `sin`, `mod`, and others, the correct syntax is to write the function argument in parentheses, e.g., `sin(0.1)` or `mod(5, 2)`.

## Installation

### Prerequisites

- **Qt**: Make sure you have Qt installed on your system. You can download it from the [official website](https://www.qt.io/download).
- **C++ Compiler**: GCC.

### Installation Steps

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/smart-calculator.git
   ```

2. Navigate to the project directory:
   ```bash
   cd smart-calculator/SmartCalc/SmartCalc
   ```

3. Run the makefile:
   ```bash
   make
   ```

After completing these steps, the application will start automatically.

## Usage

- Launch the application and start performing calculations.
- Use the number buttons and operation buttons to input expressions.
- To plot a graph, enter the function in the respective field, and the graph will be displayed on the screen.
