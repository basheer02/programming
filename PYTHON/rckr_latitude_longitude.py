import requests, math
from collections import defaultdict
from itertools import combinations

# URL of the JSON data
url = "https://cdn.jsdelivr.net/gh/apilayer/restcountries@3dc0fb110cd97bce9ddf27b3e8e1f7fbe115dc3c/src/main/resources/countriesV2.json"

# Fetch the data
response = requests.get(url)

data = {}

popLimit = 277500

# Check if the request was successful
if response.status_code == 200:
    countries_data = response.json()  # Convert to Python list/dictionary
else:
    print("Failed to fetch the data.")
    exit()

currency_to_countries = defaultdict(list)

# Populate the dictionary
for country in countries_data:
    currencies = country.get("currencies", [])
    for currency in currencies:
        currency_code = currency.get("code")
        if currency_code:  # Ensure currency code is valid
            currency_to_countries[currency_code].append(country["name"])


exclusive_currency_countries = [countries[0] for code, countries in currency_to_countries.items() if len(countries) == 1]

#print(currency_to_countries)

country_coords = []
c = 1

for country in countries_data:
    name = country.get("name", "Unknown")
    latlng = country.get("latlng", [])
    population = country.get("population", "Unknown")
    if population >= popLimit and name in exclusive_currency_countries and c <= 20:
        data[name] = [latlng[0],latlng[1],population]
        c += 1
        #print(f"Country: {name}, Latitude/Longitude: {latlng}, Population : {population}")

#sorted_countries = sorted(data.items(), key=lambda x: x[1][2], reverse=True)
for key, val in data.items():
    print(key, " : ", val)
    country_coords.append((val[0],val[1]))

print(country_coords)


def haversine(lat1, lon1, lat2, lon2):
    # Convert degrees to radians
    lat1, lon1, lat2, lon2 = map(math.radians, [lat1, lon1, lat2, lon2])
    
    # Haversine formula
    dlat = lat2 - lat1
    dlon = lon2 - lon1

    a = math.sin(dlat / 2)**2 + math.cos(lat1) * math.cos(lat2) * math.sin(dlon / 2)**2
    c = 2 * math.asin(math.sqrt(a))
    r = 6371  # Radius of Earth in kilometers
    return round(c * r,2)


total_distance = 0

for i in range(len(country_coords) - 1):
    lat1, lon1 = country_coords[i]
    lat2, lon2 = country_coords[i + 1]
    distance = round(haversine(lat1, lon1, lat2, lon2),2)
    total_distance += distance
    print(f"Distance from Country {i+1} to Country {i+2}: {distance:.2f} km")

print(f"\nTotal distance between all consecutive countries: {total_distance} km")

total_distance = 0 
for (lat1, lon1), (lat2, lon2) in combinations(country_coords, 2):
    #print(lat1, lon1, lat2, lon2)
    total_distance += haversine(lat1, lon1, lat2, lon2)

print(f"\nTotal sum of distances between all pairs of countries: {total_distance} km")