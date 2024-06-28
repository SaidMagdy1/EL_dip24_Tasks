import sqlite3

# Creating the database and table
def create_database():
    conn = sqlite3.connect('employees.db')
    c = conn.cursor()
    c.execute("""CREATE TABLE IF NOT EXISTS employees (
                    id INTEGER PRIMARY KEY,
                    name TEXT,
                    job TEXT,
                    salary REAL
                )""")
    conn.commit()
    conn.close()

# Insert a new employee
def add_employee(name, job, salary):
    conn = sqlite3.connect('employees.db')
    c = conn.cursor()
    c.execute("INSERT INTO employees (name, job, salary) VALUES (?, ?, ?)", (name, job, salary))
    conn.commit()
    conn.close()
    print("Employee added successfully!")

# Update an existing employee
def update_employee(employee_id, name, job, salary):
    conn = sqlite3.connect('employees.db')
    c = conn.cursor()
    c.execute("UPDATE employees SET name = ?, job = ?, salary = ? WHERE id = ?", (name, job, salary, employee_id))
    conn.commit()
    conn.close()
    print("Employee updated successfully!")

# Delete an employee
def delete_employee(employee_id):
    conn = sqlite3.connect('employees.db')
    c = conn.cursor()
    c.execute("DELETE FROM employees WHERE id = ?", (employee_id,))
    conn.commit()
    conn.close()
    print("Employee deleted successfully!")

# List all employees
def list_employees():
    conn = sqlite3.connect('employees.db')
    c = conn.cursor()
    c.execute("SELECT * FROM employees")
    employees = c.fetchall()
    for employee in employees:
        print(f"ID: {employee[0]}, Name: {employee[1]}, Job: {employee[2]}, Salary: {employee[3]}")
    conn.close()

# Main program
if __name__ == "__main__":
    create_database()

    # Add some employees
    add_employee("John Doe", "Software Engineer", 50000.0)
    add_employee("Jane Smith", "Marketing Manager", 45000.0)
    add_employee("Bob Johnson", "Accountant", 55000.0)

    # Update an employee
    update_employee(1, "John Doe", "Senior Software Engineer", 52000.0)

    # Delete an employee
    delete_employee(2)

    # List all employees
    list_employees()