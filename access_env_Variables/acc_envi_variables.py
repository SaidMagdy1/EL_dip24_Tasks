#said magdy    G:A3

import os

#list all the environment variables
print("All environment variables: \n -------------------------------------")
for key, value in os.environ.items():
    print(f"{key}: {value}")

print(" -------------------------------------")

#here how to add an environment variable
os.environ['MY_NEW_ENV_VAR'] = 'My new environment variable'
print(f"Value of MY_NEW_ENV_VAR: {os.getenv('MY_NEW_ENV_VAR')}")
