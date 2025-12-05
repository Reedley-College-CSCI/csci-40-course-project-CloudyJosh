[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/7mdzU3H2)
# CS1 Final Project - [Project Title]

## 1. Overview
- What problem does your project solve?  
- Briefly describe the purpose and key features of your program.  

Problem Solved: Helps car owners track vehicle details, maintenance events, and performance metrics, preventing lost records and forgotten service schedules.

Purpose and Key Features:
Add new cars with make, model, year, mileage, fuel efficiency, and top speed.
Log maintenance records including type, date, and cost.
Display organized car summaries with maintenance history.
Sort cars by year or mileage.
Save and load data to maintain records across program runs.

## 2. Design Decisions
- What fundamental programming constructs and data types did you use, and why?  
- Why did you choose to structure your data using structs?  
- How did you implement searching and sorting? What algorithms did you use and why?  
- How do you ensure data persistence between program runs?  
- Did you consider alternative approaches? If so, why did you not use them?  

I used arrays for storing cars and maintenance records. Loops, conditionals, and functions handle program flow and user interaction. Strings store text data, integers track counts and user selections, doubles store numeric values.

Car and Maintenance structs group related data together, making it easier to manage complex records
Linear search finds cars by make and model. Nested loops implement selection-style sorting by year and mileage. Chosen for simplicity due to small data size.
I used file I/O with structured text files (cars.txt) to save and load car data between program runs.
Considered vectors for dynamic storage but arrays met project requirements and provided fixed limits.

## 3. Testing Summary
- **Structured Testing Log:** Include a table with test cases, expected output, actual output, and pass/fail status.  
- What testing methods did you use?  
- Provide examples of test inputs (valid and invalid) and describe how your program responds.  

| Test Case            | Input                     | Expected Output                     | Actual Output            | Pass/Fail |
| -------------------- | ------------------------- | ----------------------------------- | ------------------------ | --------- |
| Add Car              | Toyota Camry 2015         | Car added successfully              | Car added successfully   | Pass      |
| Log Maintenance      | Oil Change 2025-12-01 $40 | Maintenance logged                  | Maintenance logged       | Pass      |
| Display Summary      | N/A                       | List of car details and maintenance | List displayed correctly | Pass      |
| Sort by Year         | Multiple cars             | Sorted by oldest to newest          | Sorted correctly         | Pass      |
| Sort by Mileage      | Multiple cars             | Sorted by lowest to highest mileage | Sorted correctly         | Pass      |
| Invalid Int Input    | Letter instead of number  | Prompts user until valid            | Prompts correctly        | Pass      |
| Invalid Double Input | Letter instead of number  | Prompts user until valid            | Prompts correctly        | Pass      |

I used manual testing for valid/invalid inputs, boundary tests for maximum cars (50) and maintenance entries (10 per car)
Invalid numeric input prompts user to retry until valid.
Logging maintenance for non-existent car outputs “Car not found.”
Exceeding max cars or maintenance entries triggers a warning message.

## 4. Technical Walkthrough
- Explain the main functionality of your program.  
- **Include a link to your required video demonstration** showcasing how the project works (**3-7 minutes**). 
    Make sure it shareable without approval needed.

Main Program Flow:
Load saved data from file.
Display menu and prompt user for action.
Execute user action (add car, log maintenance, display summary, sort).
Repeat until user exits.
Save data to file for future use.

## 5. Challenges and Lessons Learned
- What challenges did you encounter while working on this project?  
- What key lessons did you learn about programming and problem-solving?  

Challenges: Validating user input to prevent crashes from invalid numbers. Parsing and saving structured data in text files without dynamic containers. Keeping arrays within defined limits while maintaining data integrity.

Importance of modular design with clear function responsibilities. Proper input validation improves user experience and prevents runtime errors. File I/O management is essential for data persistence.

## 6. Future Improvements
- If you had more time, what changes or enhancements would you make?  
Use dynamic containers like vectors to allow more cars and maintenance records. Add reporting for total maintenance costs per car. Implement date validation and maintenance reminders. Improve user interface for readability and ease of navigation.
