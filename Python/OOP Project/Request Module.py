import requests
response = requests.get("https://www.geeksforgeeks.org/")
print(response.status_code)