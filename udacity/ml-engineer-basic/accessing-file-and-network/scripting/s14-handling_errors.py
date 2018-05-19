def party_planner(cookies, people):
    leftovers = None
    num_each = None

    try:
        num_each = cookies // people
        leftovers = cookies % people
    except ZeroDivisionError as e:
        print("Oops, you entered 0 people will be attending.")
        print("Please enter a good number of people for a party.")
        print("ZeroDivisionError occured: {}".format(e))

    return(num_each, leftovers)

party_planner(10, 0)
party_planner(10, 3)