#said magdy G:A3
import requests

#this is the url to get it 
url=requests.get("https://api.ipify.org/?format=json")

print("my current ip is :",url.text)