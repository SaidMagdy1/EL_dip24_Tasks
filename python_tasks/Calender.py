#said magdy    G:A3
import calendar

# Get the current year and month
year = int(input("Enter the year : "))
month = int(input("Enter the month : "))

print(" ************** ")
print(" ")
# Print the calendar for the given year and month
print(calendar.month(year, month))