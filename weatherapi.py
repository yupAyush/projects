
import requests
import json
city= input("enter a name of the city\n")
url=f"https://api.tomorrow.io/v4/weather/realtime?location={city}&apikey=Bza915IIdru0jArXIUKb1T0OerqRr4Om"
r= requests.get(url)
wdic=json.loads(r.text)

print(wdic["data"]["values"]["temperature"])
