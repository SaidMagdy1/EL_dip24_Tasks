import requests
from bs4 import BeautifulSoup

# URL of the page you want to scrape
url = "https://poe.com/chat/3dk5j41vosfj1wdbsvu"

# Send a GET request to the URL
response = requests.get(url)

# Parse the HTML content using BeautifulSoup
soup = BeautifulSoup(response.content, "html.parser")

# Find the section containing the response from "You"
section = soup.find_all("div", {"class":"MarkdownContainer__Tz3HQ"})

# Extract the text from the section
#response_text = section.text

#response_text = section.get_text().strip()

# Print the response
print(response.text)


# from bs4 import BeautifulSoup
# import requests

# chatP = requests.get("https://poe.com/chat/3dk5j41vosfj1wdbsvu")
# contentP=chatP.content

# soup=BeautifulSoup(contentP,"lxml")

# chatText=soup.find("div",{"class":"Markdown_markdownContainer__Tz3HQ"})


# print(chatText)

