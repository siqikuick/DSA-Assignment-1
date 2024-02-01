import heapq


class Passenger:
    def __init__(self, name, passport, dob, status):
        self.name = name
        self.passport = passport
        self.dob = dob
        self.status = status


class Flights:
    def __init__(self, flight_no, capacity, depart, arrival):
        self.flight_no = flight_no
        self.capacity = capacity
        self.depart = depart
        self.arrival = arrival


flights = {"f001": {
        "confirmed": [("John Doe", "123456789", "1990-01-01", "Gold")],
        "Waiting": []

    }, "f002": {
        "confirmed": [("John Doe", "123456789", "1990-01-01", "Gold")],
        "Waiting": []
    }, "f003": {
        "confirmed": [("John Doe", "123456789", "1990-01-01", "Gold"), ("John Doe", "123456789", "1990-01-01", "Gold")],
        "Waiting": []
    }
}
flight_info = [["f001", 2, "Singapore", "Korea"], ["f002", 2, "Singapore", "Korea"], ["f003", 2, "Singapore", "Korea"]]


def sort_waiting_list(waiting_list):
    # Define a custom order for membership status
    membership_order = {"gold": 1, "silver": 2, "non-member": 3}

    # Sort the waiting list based on membership status
    sorted_waiting_list = sorted(waiting_list, key=lambda x: membership_order[x[0]])

    return sorted_waiting_list


def add_passenger_to_flight(passenger, flight):
    flight_key = flight.flight_no  # Use flight_no as the key
    if len(flight_info) == 0:
        flight_info.append(list(flight.__dict__.values()))
    else:
        for i in flight_info:
            if flight_key != i[0]:
                flight_info.append(list(flight.__dict__.values()))

    if flight_key not in flights:
        flights[flight_key] = {"confirmed": [], "waiting": []}

    if len(flights[flight_key]["confirmed"]) < flight.capacity:
        flights[flight_key]["confirmed"].append(tuple(passenger.__dict__.values()))
    else:
        heapq.heappush(flights[flight_key]["waiting"], (passenger.status, tuple(passenger.__dict__.values())))

    for key, value in flights.items():
        value["waiting"] = sort_waiting_list(value["waiting"])

    return flights


def retrieve_passenger_info(flight):
    key = flights.keys()
    for i in key:
        if i == flight:
            print(flights[i]["confirmed"])


def assign_seat_from_waiting(flight):
    key = flights.keys()
    for i in key:
        for j in flight_info:
            if i == flight:
                if j[0] == flight:
                    if len(flights[flight]["confirmed"]) < j[1]:
                        next_passenger = flights[i]["waiting"].pop()
                        flights[flight]["confirmed"].append(next_passenger)
    return flights


def calculate_occupancy_rate():
    flight_key = flights.keys()
    high_occupancy = []
    highest_rate = 0

    for j in flight_info:
        if j[0] in flight_key:
            rate = len(flights[j[0]]["confirmed"]) / j[1]

            if rate > highest_rate:
                highest_rate = rate
                high_occupancy = [[j[0], highest_rate]]  # Reset the list with a new highest value
            elif rate == highest_rate:
                high_occupancy.append([j[0], highest_rate])  # Append if it's equal to the highest value

    print(high_occupancy)


def remove_Passenger(flight, passenger):
    for i in flights:
        if i == flight:
            for x in flights[i]["confirmed"]:
                if x[0] == passenger:
                    flights[i]["confirmed"].remove(x)
    return flights


def main():

    print("---------FlyHigh airline reservation system-----------\n")
    print("1. Add new passenger to a flight \n")
    print("2. Retrieve information of all the passengers on a flight \n")
    print("3. Assignment seats to those on the waiting list \n")
    print("4. List flights with the highest occupancy rate \n")
    print("5. Remove a passenger from a flight \n")
    print("6. Exit \n")

    while True:
        command = input("Enter a command (1-5): ")

        if command == '1':
            print("Input Name, Passport number, Date of birth, and Membership status <Gold, Silver, Non-member>\n")
            print("Please input in the following format \n")
            print("Example: John Doe, 123456789, 1990-01-01, Gold \n")
            passenger = input("Passenger information: \n")
            print("Input Flight number, Maximum capacity, Departure (location, date and time), Arrival (location, date and time) \n")
            print("Please input in the following format \n")
            print("Example: F001, 200, Singapore 2024-01-23 10:00am, Seoul South Korea 2024-01-23 16:00pm \n")
            flight = input("Flight information: \n")
            passenger_split = passenger.split(",")
            flight_split = flight.split(",")
            psg = Passenger(passenger_split[0].strip().lower(), passenger_split[1], passenger_split[2], passenger_split[3].strip().lower())
            flt = Flights(flight_split[0].strip().lower(), int(flight_split[1].strip()), flight_split[2].strip(), flight_split[3].strip())
            print(add_passenger_to_flight(psg,flt))
        elif command == "2":
            inp = input("Which Flight do you want to find: \n")
            retrieve_passenger_info(inp.lower())
        elif command == "3":
            assign_flight = input("Which flight do you want to assign a seat from waiting: \n")
            print(assign_seat_from_waiting(assign_flight.strip().lower()))
        elif command == "4":
            calculate_occupancy_rate()
        elif command == "5":
            inpt = input("Which flight do you want to amend: \n")
            pasg = input("Which passenger do you want to remove: \n")
            print(remove_Passenger(inpt.strip().lower(), pasg.strip().lower()))
        elif command == "6":
            break



main()
