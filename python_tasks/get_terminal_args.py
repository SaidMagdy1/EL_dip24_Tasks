#said magdy G:A3
import sys

print("*"*30)

print("arguments passed throug terminal as list :",sys.argv) #arguments as List 
print("*"*30)
if __name__ == "__main__":     #this only excute we U run this file not for importing 
    # Get the command-line arguments
    arguments = sys.argv

    # Print the arguments
    print("Command-line arguments:")
    for arg in arguments:
        print(arg)
print("*"*30)
# U can remove file name by sys.arg[0]