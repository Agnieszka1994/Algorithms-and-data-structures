# Airport Connections

This function takes in a list of airports, a list of routes, and a starting airport and returns the minimum number of airport connections that should be added to reach any airport in the list, starting at the starting airport.

The airports are given in the form of three-letter codes like `"WAW"` or `"HKT"`; each route is a one-way flight from one airport to another ex. `["WAW", "CDG"]` (they allow to fly in one direction).

### Sample input
```javascript
airports = ["BGI", "CDG", "DEL", "DOH", "DSM", "EWR", "EYW", "HND", "ICN", 
            "JFK", "LGA", "LHR", "ORD", "SAN", "SFO", "SIN", "TLV", "BUD"]
routes = [
  ["DSM", "ORD"],
  ["ORD", "BGI"],
  ["BGI", "LGA"],
  ["SIN", "CDG"],
  ["CDG", "SIN"],
  ["CDG", "BUD"],
  ["DEL", "DOH"],
  ["DEL", "CDG"],
  ["TLV", "DEL"],
  ["EWR", "HND"],
  ["HND", "ICN"],
  ["HND", "JFK"],
  ["ICN", "JFK"],
  ["JFK", "LGA"],
  ["EYW", "LHR"],
  ["LHR", "SFO"],
  ["SFO", "SAN"],
  ["SFO", "DSM"],
  ["SAN", "EYW"]
]
startingAirport = "LGA"
```
### Sample output
```javascript
3
```
### Space and Time complexity
O(a * (a+r) + a + r + alog(a)) time | O(a + r) space - where a is the number of airports and r is the number of routes.